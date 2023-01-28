/*
	Wrapper for whichever cryptography implementation is used.
*/

#ifndef CIPHER_H
#define CIPHER_H

#include <stdio.h>
#include <stdlib.h>

//#include <mbedtls.h>

typedef struct CIPHER CIPHER;

extern CIPHER* global_cipher;

extern const unsigned int CIPHER_RSA;
extern const unsigned int CIPHER_AES;
extern const unsigned int CIPHER_TWOFISH;
extern const unsigned int CIPHER_SERPENT;

typedef struct KEY {
	char* __key;
	int __length;
} KEY;

typedef struct CIPHER {
	KEY* __key;
	int __CHOSEN_ALGORITHM;
} CIPHER;

CIPHER * factory_create_cipher();
KEY* create_key(char* key, int key_size);

int init_cipher(CIPHER* cipher); //TODO
int destruct(CIPHER* cipher); //dealloc pointers

int set_key(CIPHER* cipher, KEY * key);
int set_algorithm(CIPHER* cipher, int ALGORITHM_TYPE);

int encrypt(CIPHER * cipher, char * plaintext_in, char* ciphertext_out, short rounds);
int decrypt(CIPHER * cipher, char * plaintext_in, char* ciphertext_out, short rounds);

int cipher_impl(); //TODO

#endif
