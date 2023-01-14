@echo off

goto main

:: ==================================

:clean
	del /f /q "bin\*.o" 2>nul
	del /f /q "bin\server\*.o" 2>nul
	del /f /q "bin\client\*.o" 2>nul

	del /f /q "bin\server\server.exe" 2>nul
	del /f /q "bin\client\client.exe" 2>nul

	EXIT /B %ERRORLEVEL%

:main
	call :clean
	EXIT /B %ERRORLEVEL%

