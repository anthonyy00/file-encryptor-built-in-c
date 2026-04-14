#ifndef encryptor_h
#define encryptor_h

#include <unistd.h>
#include <fcntl.h>

long long power(long long base, long long exp, long long mod);
void file_handle(long long p, long long q, const char* filename, const char* e_file);


#endif
