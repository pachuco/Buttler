@echo off
SETLOCAL

set CC=gcc.exe
set LNK=link.exe


:: define dependencies here. as well as paths and file/object names...


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
	call :generate

	EXIT /B 0
:: =====================





:: =====================
:client

	echo:
	echo "Attempting build of client module..."
	echo:

	echo "...Input."
        %CC% -Wall -Wno-cpp -g -mwin32 -I include/ -c src/fm_client/input.c -o bin/client/input.o

	echo "...Client."
	%CC% -Wall -Wno-cpp -Llib/enet/x64 -I lib/enet/include -lenet64 -lws2_32 -lwinmm -g -mwin32 -g -mwin32 -I include/ -c src/fm_client/client.c -o bin/client/client.o

	echo "...Main."
	%CC% -Wall -Wno-cpp -Llib/enet/x64 -I lib/enet/include -lenet64 -lws2_32 -lwinmm -g -mwin32 -g -mwin32 -I include/ -c src/fm_client/main.c -o bin/client/main.o

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

	echo "...Server."
	%CC% -Wall -Wno-cpp -Llib/enet/x64 -I lib/enet/include -lenet64 -lws2_32 -lwinmm -g -mwin32 -g -mwin32 -I include/ -c src/fm_server/server.c -o bin/server/server.o


	echo "...Portio."
	%CC% -Wall -Wno-cpp -g -mwin32 -I include/ -c src/fm_server/portio.c -o bin/server/portio.o


	echo "...Main."
	%CC% -Wall -Wno-cpp -I lib/enet/include -lenet64 -lws2_32 -lwinmm -g -mwin32 -g -mwin32 -I include/ -c src/fm_server/main.c -o bin/server/main.o

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
	%CC% -Wall -Wno-cpp -g -mwin32 -I include/ -c common/logger.c -o bin/logger.o


	echo "...Config."
	%CC% -Wall -Wno-cpp -g -mwin32 -I include/ -c common/config.c -o bin/config.o


	echo "...Cipher."
	%CC% -Wall -Wno-cpp -g -mwin32 -I include/ -c common/cipher.c -o bin/cipher.o


	echo "...Thread."
	%CC% -g -Wall -Wno-cpp -mwin32 -I include/ -c common/thread.c -o bin/thread.o


	echo "...Enet_engine."
	%CC% -Wall -Wno-cpp -Llib/enet/x64 -I lib/enet/include -lenet64 -lws2_32 -lwinmm -g -mwin32 -I include/ -c common/enet_engine.c -o bin/enet_engine.o

	echo:
	echo "Finished."

	echo:
	EXIT /B 0
:: =====================





:: =====================
:generate
	echo:
	echo "Merging object files into executables...."
	echo:


	echo "Client exe."
	echo:
	%CC% -Wall -Wno-cpp -Llib/enet/x64 -I lib/enet/include -I include/ -o bin/client/client.exe bin/cipher.o bin/config.o bin/enet_engine.o bin/logger.o bin/thread.o bin/client/client.o bin/client/input.o bin/client/main.o -lenet64 -lws2_32 -lwinmm -g -mwin32

	echo "Server exe."
	echo:
	%CC% -Wall -Wno-cpp -Llib/enet/x64 -I lib/enet/include -I include/ -o bin/server/server.exe bin/cipher.o bin/config.o bin/enet_engine.o bin/logger.o bin/thread.o bin/server/server.o bin/server/portio.o bin/server/main.o -lenet64 -lws2_32 -lwinmm -g -mwin32

	echo "Finished."
	echo:

	echo:
	EXIT /B 0
:: =====================





:: =====================
:main
	call :%1

	EXIT /B %ERRORLEVEL% 
:: ====================
