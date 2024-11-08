#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>

#define KEYSIZE 16

// Known data
unsigned char known_plaintext[16] = {0x25, 0x50, 0x44, 0x46, 0x2d, 0x31, 0x2e, 0x35, 0x0a, 0x25, 0xd0, 0xd4, 0xc5, 0xd8, 0x0a, 0x34};
unsigned char known_ciphertext[16] = {0xd0, 0x6b, 0xf9, 0xd0, 0xda, 0xb8, 0xe8, 0xef, 0x88, 0x06, 0x60, 0xd2, 0xaf, 0x65, 0xaa, 0x82};
unsigned char original_iv[16] = {0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xA2, 0xB2, 0xC2, 0xD2, 0xE2, 0xF2};

// Function to test each key
int test_key(unsigned char *key) {
    AES_KEY aes_key;
    unsigned char decrypted[16];
    unsigned char iv[16];
    
    // Copy the original IV for each attempt
    memcpy(iv, original_iv, 16);

    // Set the decryption key
    if (AES_set_decrypt_key(key, 128, &aes_key) < 0) {
        return 0;  // Key setup failed
    }

    // Decrypt the known ciphertext block
    AES_cbc_encrypt(known_ciphertext, decrypted, 16, &aes_key, iv, AES_DECRYPT);

    // Check if the decrypted block matches the known plaintext
    return memcmp(decrypted, known_plaintext, 16) == 0;
}

int main(void) {
    time_t start_time = 1524013729; // Adjusted start timestamp
    time_t end_time = 1524020929;   // Adjusted end timestamp
    unsigned char key[KEYSIZE];
    int found = 0;

    // Loop through all timestamps in the 2-hour range
    for (time_t t = start_time; t <= end_time; t++) {
        srand(t);

        // Generate the key
        for (int i = 0; i < KEYSIZE; i++) {
            key[i] = rand() % 256;
        }

        // Test the key
        if (test_key(key)) {
            printf("Found key: ");
            for (int i = 0; i < KEYSIZE; i++) {
                printf("%.2x", key[i]);
            }
            printf("\nTimestamp: %lld\n", (long long)t);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Key not found in the given range.\n");
    }

    return 0;
}
