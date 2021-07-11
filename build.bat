@echo off

call getcomp.bat rosbe

::must not contain spaces!
set buttiolocation=C:\p_files\prog\_proj\CodeCocks\buttio

set opts=-std=c11 -mconsole -Os -s -Wall -Wextra
set linkinc=-I%buttiolocation%\src\ -L%buttiolocation%\bin\ -Llib\bin\ -Ilib\enet-1.3.17\include -Ilib\ini_rw-master -Ilib\miniaudio-0.10.35
set linkinc=%linkinc% -linirw -lminiaudio -lenet -lbuttio
set linkinc=%linkinc% -lwinmm -lWs2_32
set errlog=.\buttserve_err.log

xcopy "%buttiolocation%\bin\buttio.sys" .\bin\ /c /Y
call :comp .\bin\buttserve.exe src\buttler-server.c "%opts% %linkinc%" buttserve_err.log
call :comp .\bin\buttclient.exe src\buttler-client.c "%opts% %linkinc%" buttclient_err.log

exit /B 0


:comp
echo compiling %1
del %1
gcc -o %1 %2 %opts% %linkinc% 2> %4
call :checkerr
exit /B 0

:checkerr
IF %ERRORLEVEL% NEQ 0 (
    echo oops!
    notepad %errlog%
    goto :end
)
for %%R in (%errlog%) do if %%~zR lss 1 del %errlog%
:end
exit /B 0