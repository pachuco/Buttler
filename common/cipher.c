/*
	Cipher wrapper implementation.
*/

#include "cipher.h"

CIPHER * factory_create_cipher() {

}

int init_alloc() {

}

int set_key(KEY * key, int size) {

}

int set_algorithm(int ALGORITHM_TYPE) {

}

int encrypt(CIPHER * cipher, char * message) {
	//if cipher->CHOSEN_ALGORITHM == CIPHER_TYPE.TWOFISH...
	//...
}

int decrypt(CIPHER * cipher, char * message) {
	//same here as above for encrypt.
}

int cipher_impl() {

}
