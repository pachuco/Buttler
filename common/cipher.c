/*
	Cipher wrapper implementation.
*/

#include "cipher.h"

const unsigned int CIPHER_RSA = 1;
const unsigned int CIPHER_AES = 2;
const unsigned int CIPHER_TWOFISH = 3;
const unsigned int CIPHER_SERPENT = 4;

CIPHER * factory_create_cipher() {
    return (struct CIPHER*)malloc(sizeof(CIPHER));
}

int init_cipher(CIPHER* cipher) {
    return 0;
}

int destruct(CIPHER* cipher) {

    free(cipher);

    return 0;
}

int set_key(CIPHER* cipher, KEY * key, int size) {
    return 0;
}

int set_algorithm(CIPHER* cipher, int ALGORITHM_TYPE) {
    return 0;
}

int encrypt(CIPHER * cipher, char * message, short rounds) {
	//if cipher->CHOSEN_ALGORITHM == CIPHER_TYPE.TWOFISH...
	//...

	return 0;
}

int decrypt(CIPHER * cipher, char * message, short rounds) {
	//same here as above for encrypt.

	return 0;
}

int cipher_impl() {
    return 0;
}
