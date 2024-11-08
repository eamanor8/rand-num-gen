//
//  task5.c
//
//
//  Created by Angelos Stavrou
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    // for (int n = 256; n <= 8192; n *= 2) {  // Start at 256 bytes and double each iteration
    for (int n = 256; n <= 1024; n *= 2) {  // Start at 256 bytes, double the size twice, then stop
        int LEN = n;

        unsigned char *key = (unsigned char *) malloc(sizeof(unsigned char) * LEN);
        if (key == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        FILE *random = fopen("/dev/urandom", "r");
        if (random == NULL) {
            perror("Failed to open /dev/urandom");
            free(key);
            return 1;
        }

        fread(key, sizeof(unsigned char) * LEN, 1, random);
        fclose(random);

        // Print the generated key in hexadecimal format
        printf("Generated key of size %d bytes (%d bits):\n", LEN, LEN * 8);
        for (int i = 0; i < LEN; i++) {
            printf("%02x", key[i]);
            if (i % 16 == 15) {
                printf("\n"); // Print a newline every 16 bytes for readability
            }
        }
        printf("\n\n");

        free(key);
    }

    return 0;
}
