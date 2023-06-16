#ifndef CAESAR_H
#define CAESAR_H

// Max size of encrypted buffers
#define MAX_BUF 38

/* Ciphers the input string using the provided shift */

char *caesar_encrypt(char *str, long shift);

/* Deciphers the input ciphered string using the provided shift */

char *caesar_decrypt(char *str, long shift);
#endif