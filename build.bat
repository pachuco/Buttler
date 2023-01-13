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
	:: %CC% -Wall -g -mwin32 -I include/ -c src/fm_client/client.c -o bin/client/client.o

	echo "...Main.	skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c src/fm_client/main.c -o bin/client/main.o

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
	:: %CC% -Wall -g -mwin32 -I include/ -c src/fm_server/server.c -o bin/server/server.o


	echo "...Portio.	skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c src/fm_server/portio.c -o bin/server/portio.o


	echo "...Main.	skip.
	:: %CC% -Wall -g -mwin32 -I include/ -c src/fm_server/main.c -o bin/server/main.o

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


	echo "...Config."
	%CC% -Wall -g -mwin32 -I include/ -c common/config.c -o bin/config.o


	echo "...Cipher."
	%CC% -Wall -g -mwin32 -I include/ -c common/cipher.c -o bin/cipher.o


	echo "...Thread. 		[incompatible pointer warnings, ignore for now]"
	%CC% -g -Wall -Wno-incompatible-pointer-types -mwin32 -I include/ -c common/thread.c -o bin/thread.o


	echo "...Enet_engine.	[incompatible pointer warnings, ignore for now]"
	%CC% -Wall -Wno-incompatible-pointer-types -Wno-switch -Llib/enet/x64 -I lib/enet/include -lenet64 -lws2_32 -lwinmm -g -mwin32 -I include/ -c common/enet_engine.c -o bin/enet_engine.o

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
