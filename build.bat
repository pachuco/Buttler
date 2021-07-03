@echo off

call getcomp.bat rosbe

::must not contain spaces!
set buttiolocation=C:\p_files\prog\_proj\CodeCocks\buttio

set opts=-std=c11 -mconsole -Os -s -Wall -Wextra
set linkinc=-I%buttiolocation%\src\ -L%buttiolocation%\bin\ -Llib\bin\ -Ilib\enet-1.3.17\include
set linkinc=%linkinc% -lenet -lbuttio
set linkinc=%linkinc% -lwinmm -lWs2_32
set errlog=.\buttserve_err.log

xcopy "%buttiolocation%\bin\buttio.sys" .\bin\ /c /Y
del .\bin\buttserve.exe
gcc -o .\bin\buttserve.exe src\buttler-server.c %opts% %linkinc% 2> %errlog%
del .\bin\buttclient.exe
gcc -o .\bin\buttclient.exe src\buttler-client.c %opts% %linkinc% 2> %errlog%

IF %ERRORLEVEL% NEQ 0 (
    echo oops!
    notepad %errlog%
    goto :end
)
for %%R in (%errlog%) do if %%~zR lss 1 del %errlog%
:end