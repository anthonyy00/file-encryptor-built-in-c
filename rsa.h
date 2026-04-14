#ifndef encryptor_h
#define encryptor_h

#include <unistd.h>
#include <fcntl.h>

long long power(long long base, long long exp, long long mod);
long long rsa_encrypt(long long p, long long q, char* text);

#endif
