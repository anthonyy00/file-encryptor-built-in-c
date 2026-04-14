#include "rsa.h"

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


long long rsa_encrypt(long long p, long long q, char * text)
{
  long long n = p * q;
  long long e = 17;

  for (int i = 0; i < text[i] != '\0'; i++)
  {
    text[i] = power(text[i], e, n);
  }


}

void file_handle(const char *filename, const char *e_file)
{
  int file = open(filename, O_RDONLY);
  int e_file = open(efile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  

   
}
