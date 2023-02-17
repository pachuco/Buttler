## Client .dll/.so API

* Utilizing the agent programmatically.

### Initial usage - Windows

> LoadLibrary(), GetProcAddress(), FreeLibrary() are the main Win32 calls for accessing a DLL's exposed routines.

```c
#include <windows.h>
#include <stdio.h>

typedef int (__cdecl *API_FUNCTION)(LPCWSTR);

int main(int argc, char **argv)
{
	// Error handling required.

	HINSTANCE hInstance = LoadLibrary("buttler_client.dll");
	API_FUNCTION api_func = (API_FUNCTION)GetProcAddress(hinstLib, "a_function");

	(api_func) (L"parameter");

	FreeLibrary(hinstLib);

    return 0;
}


```

### Initial usage - Linux

> dlopen(), dlsym(), dlclose() are the main linux/posix calls for accessing a SO's exposed routines.

```c
#include <dlfcn.h>

int main(int argc, char **argv)
{
	// Erorr handling required.

	int (*fptr)(int);

	void * handle = dlopen("buttler_client.so", RTLD_LOCAL | RTLD_LAZY);
	*(void **)(&fptr) = dlsym(handle, "a_function");

	(*fptr)();

	dlclose(handle);

	return 0;
}

```

### API / Reference

```c
int buttler_connect(char* ip_address, short port);

void buttler_disconnect();

int buttler_opt_in(bool option); //stdbool

int buttler_send(void* struct_data, int dev_id, int u_sec_wait);

int buttler_flush();
```

### Full Example Usage


```c

int main() {
	buttler_connect("127.0.0.1", 3456);
	buttler_opt_in(true);

	//define your struct here to send

	buttler_send(ptr, 3223, 1000);
	buttler_flush();

	buttler_disconnect();
}

```

### SoundBlaster Spec

```c

opl2Write(BYTE reg, BYTE data) {
   outbyte(BASE+0, reg);
   usecWait(4);
   outbyte(BASE+1, data);
   usecWait(23);
}

opl2Write(0x20, 0x01);      //Set the modulator's multiple to 1
opl2Write(0x40, 0x10);      //Set the modulator's level to about 40 dB
opl2Write(0x60, 0xF0);      //Modulator attack:  quick;   decay:   long
opl2Write(0x80, 0x77);      //Modulator sustain: medium;  release: medium
opl2Write(0xA0, 0x98);      //Set voice frequency's LSB (it'll be a D#)
opl2Write(0x23, 0x01);      //Set the carrier's multiple to 1
opl2Write(0x43, 0x00);      //Set the carrier to maximum volume (about 47 dB)
opl2Write(0x63, 0xF0);      //Carrier attack:  quick;   decay:   long
opl2Write(0x83, 0x77);      //Carrier sustain: medium;  release: medium
opl2Write(0xB0, 0x31);      //Turn the voice on; set the octave and freq MSB

buttler_flush();

```

### Remarks

> Make sure the exposed shared library is in the same directory as the program trying to access it, if the path provided is relative.
