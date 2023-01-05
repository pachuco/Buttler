/*
	Wrapper for whichever cryptography implementation is used.
*/

#ifndef CIPHER_H
#define CIPHER_H

enum CIPHER_TYPE = { RSA = 0, AES = 1, TWOFISH = 2, SERPENT = 3 };

typedef struct KEY {
	char * key,
	int length
} KEY;

typedef struct CIPHER {
	KEY * key,
	int CHOSEN_ALGORITHM
} CIPHER;

CIPHER * factory_create_cipher();

int init_alloc(); //TODO
int destruct(); //dealloc pointers

int set_key(KEY * key, int size);
int set_algorithm(int ALGORITHM_TYPE);

int encrypt(CIPHER * cipher, char * message, short rounds);
int decrypt(CIPHER * cipher, char * message, short rounds);

int cipher_impl(); //TODO

#endif
