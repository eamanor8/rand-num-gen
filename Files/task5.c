//
//  task5.c
//
//
//  Created by Angelos Stavrou
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
    #define LEN 16    // 128 bits

    unsigned char *key = (unsigned char *) malloc(sizeof(unsigned char)*LEN);
    FILE* random = fopen("/dev/urandom", "r");
    fread(key, sizeof(unsigned char)*LEN, 1, random);
    fclose(random);
    return 0;
}
