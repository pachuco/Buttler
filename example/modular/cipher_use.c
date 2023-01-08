#include <stdio.h>
#include <stdlib.h>

#include "cipher.h"

int main()
{
    printf("Testing Cipher module...\n");

    CIPHER* my_cipher = factory_create_cipher();
    init_cipher(my_cipher);

    set_algorithm(my_cipher, CIPHER_TWOFISH);

    KEY* my_key = create_key("my_key", 512);
    set_key(my_cipher, my_key);

    char * my_plaintext = "testing";
    char my_ciphertext[4096]; //memset
    encrypt(my_cipher, my_plaintext, my_ciphertext, 2);

    char my_reversed_plaintext[4096]; //memset
    decrypt(my_cipher, my_ciphertext, my_reversed_plaintext, 2);

    destruct(my_cipher);

    return 0;
}
