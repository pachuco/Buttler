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
int set_key(KEY * key, int size);
int set_algorithm(int ALGORITHM_TYPE);

int encrypt(CIPHER * cipher, char * message);
int decrypt(CIPHER * cipher, char * message);

int cipher_impl(); //TODO

//don't forget to dealloc() all these pointers and from the other files when done with them in it's own functions.

#endif
