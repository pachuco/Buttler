@echo off

call getcomp.bat rosbe

set outpath=..\bin
set opts=-std=c99 -Os -s -Wall -Wextra -DENET_MINGW_COMPAT
set linkinc=-I.\include
set errlog=%outpath%\enet_err.log

del %outpath%\libenet.a
call :cobj callbacks compress host list packet peer protocol unix win32

ar r %outpath%\libenet.a %outpath%\*.o
del %outpath%\*.o

exit /B 0


:cobj
if "%1" EQU "" exit /B 0
echo compiling %1.c
gcc -o %outpath%\%1.o -c %1.c %linkinc% %opts% 2> %errlog%
call :checkerr
shift /1
goto cobj

:checkerr
IF %ERRORLEVEL% NEQ 0 (
    echo oops!
    notepad %errlog%
    goto :end
)
for %%R in (%errlog%) do if %%~zR lss 1 del %errlog%
:end
exit /B 0