#ifndef FILE_ENCRYPTION_DECRYPTION_H
#define FILE_ENCRYPTION_DECRYPTION_H

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include "common.h"

/*********************** FUNCTION DECLARATIONS **********************/

/* Key should be strictly of length 16 */
status encryptFile(FILE *input, FILE *output, unsigned char *key);
status decryptFile(FILE *input, FILE *output, unsigned char *key);

#endif