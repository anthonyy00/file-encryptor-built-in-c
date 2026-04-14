#include "rsa.h"
#define BUFFER 1060

long long power(long long base, long long expo, long long mod) {
    long long res = 1;
    base = base % mod;

    while (expo > 0) {
        if (expo % 2 == 1) {
            res = (res * base) % mod;
        }
        expo = expo >> 1;
        base = (base * base) % mod;
    }
    return res;
}

void file_handle(long long p, long long q,const char *filename, const char *encrypted_file)
{

  long long n = p * q;
  long long e = 17;

  int byte;

  int file = open(filename, O_RDONLY);
  int e_file = open(encrypted_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  char buffer [BUFFER];


  while((byte = read(file, buffer, sizeof(buffer))) > 0)
  {
    for (int i = 0; i < byte; i++)
    {
      buffer[i] = power(buffer[i], e, n);
    }
    write(e_file, buffer, byte);
  }

close(file);
close(e_file);
   
}
