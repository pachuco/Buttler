## FM_Client & FM_Server

* Remote Yamaha fm_device with TLS support.

#### Dependencies

> In this repo, precompiled binaries are provided.

> Feel free to build them yourself if you want don't want to use them.

* enet		[v0.0]
* libcthread	[v0.0]
* mbedtls	[v0.0]
* miniaudio	[v0.0]

#### Install

> build.bat all

#### How To Use

> Instructions.

* Run `fm_server -a "0.0.0.0" -p 23`
* Connect locally or remotely with `fm_client -a "127.0.0.1" -p 23`

#### Remarks

> If any.
