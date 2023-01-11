@echo off
SETLOCAL

set CC=gcc.exe
set LNK=link.exe





:: ========================================
:: ========================================
:: ========================================

goto main

:: ========================================
:: ========================================
:: ========================================





:: =====================
:all
	call :common
	call :server
	call :client
	call :link

	EXIT /B 0
:: =====================





:: =====================
:client

	echo:
	echo "Attempting build of client module..."
	echo:

	echo "...Client.	skip.
	:: %CC% -Wall -I include/ src/fm_client/client.c src/fm_client/client.c

	echo "...Main.	skip.
	:: %CC% -Wall -I include/ src/fm_client/main.c src/fm_client/main.c

	echo "Finished."
	echo:

	echo:
	EXIT /B 0
:: =====================





:: =====================
:server

	echo:
	echo "Attempting build of server module..."
	echo:

	echo "...Server.	skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c common/server.c -o bin/server.o


	echo "...Portio.	skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c common/portio.c -o bin/portio.o


	echo "...Main.	skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c common/main.c -o bin/main.o

	echo "Finished."
	echo:

	echo:
	EXIT /B 0
:: =====================





:: =====================
:common
	echo:
	echo "Attempting build of common modules..."
	echo:

	echo "...Logger."
	%CC% -Wall -g -mwin32 -I include/ -c common/logger.c -o bin/logger.o


	echo "...Config.""
	%CC% -Wall -g -mwin32 -I include/ -c common/config.c -o bin/config.o


	echo "...Cipher."
	%CC% -Wall -g -mwin32 -I include/ -c common/cipher.c -o bin/cipher.o


	echo "...Thread.		skip."
	:: %CC% -Wall -g -mwin32 -I include/ -c common/thread.c -o bin/thread.o


	echo "...Enet_engine. 	skip."
	:: %CC% -Wall -g -mwin32 -I include/ -c common/enet_engine.c -o bin/enet_engine.o


	echo "...Client. 		skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c common/client.c -o bin/client.o

	echo:
	echo "Finished."

	echo:
	EXIT /B 0
:: =====================





:: =====================
:link
	echo:
	echo "Unimplemented."
	echo:

	:: gcc -l all objects and libraries to produce exe.
	:: internal dependencies

	:: gcc - rest of libraries.
	:: external dependencies

	echo:
	EXIT /B 0
:: =====================





:: =====================
:main
	call :%1

	EXIT /B %ERRORLEVEL% 
:: ====================
