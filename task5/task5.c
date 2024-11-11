#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n = 256;  // Start at 256 bytes

    while (1) {  // Infinite loop to test until system performance is affected
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

        // Measure time taken for key generation
        clock_t start_time = clock();
        fread(key, sizeof(unsigned char) * LEN, 1, random);
        clock_t end_time = clock();
        fclose(random);
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Print the generated key size and time taken
        printf("Generated key of size %d bytes (%lld bits) in %.6f seconds:\n", LEN, (long long)LEN*8, time_taken);

        free(key);

        n = pow(2, log2(n) + 1);  // Update n to 2^n
    }
    return 0;
}
