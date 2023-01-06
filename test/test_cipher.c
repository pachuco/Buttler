#include "test_runner.h"

#include "cipher.h" //in header file...

int before_test() {

}

int after_test() {

}

//--------------------

when_testing("function encrypt() with a plaintext message and a key...") {
   it_should("produce a predictable ciphertext for this test.") {
      CIPHER* cipher = factory_create_cipher();
      set_algorithm(cipher, ALGORITHM.SERPENT);

      char* message = "this is a plaintext 2474";
      char* key = "arbitrary_KEY";

      encrypt(cipher, message, key, 3);
      
      char* expected_result = "he3heuehefJdhdbhruebd3883Hdhdbs9";
      assert_equals(message, expected_result);
   }
}

when_testing("function decrypt () with a ciphertext message and the correct key...") {
    it_should("produce the plaintext it originally was before encryption.") {
      ...
      ...
    }
}
