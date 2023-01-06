:: TODO.

@echo off

set CC=gcc.exe
set LNK=link.exe

:: =================

:all
	call common
	call server
	call client
	call link

:: =================

:: set output directory to /bin for all these commands below

:client
	%CC% -Wall -I include/ src/fm_client/client.c src/fm_client/main.c

:server
	%CC% -Wall -I include/ src/fm_server/server.c src/fm_server/main.c src/fm_server/fm_device.c

:common
	%CC% -Wall -I include/ common/thread.c common/config.c common/cipher.c common/client.c common/logger.c common/enet_engine.c

:link
	exit
	gcc -l all objects and libraries to produce exe.
	:: internal dependencies

	gcc - rest of libraries.
	:: external dependencies

:: =================

call :%1%
