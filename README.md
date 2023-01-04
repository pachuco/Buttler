## FM_Client & FM_Server

* Remote Yamaha fm_device with TLS support.

### Dependencies

> Precompiled binaries are provided in /lib.

> Feel free to build them yourself if you don't want to use them.

* enet		[v1.3.17]
* libcthread	[v20220102-alpha]
* mbedtls	[v0.0]
* miniaudio	[v0.0]

### Install

> build.bat all

### How To Use

* Run `fm_server -a "0.0.0.0" -p 23`
* Connect locally or remotely with `fm_client -a "127.0.0.1" -p 23`

### Remarks

> If any.
