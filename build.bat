:: TODO.

@echo off
:: substitute these and provide path too.
set CC=gcc.exe
set LNK=link.exe

:: =================

:build_all
	build_common()
	build_server()
	build_client()
	link_objs()

:build_client
	gcc -Wall -I include/ src/fm_client/client.c src/fm_client/main.c

:build_server
	gcc -Wall -I include/ src/fm_server/server.c src/fm_server/main.c src/fm_server/fm_device.c

:build_common
	gcc -Wall -I include/ common/thread.c common/config.c common/cipher.c common/client.c common/logger.c common/enet_engine.c

:link_objs
	gcc -l
