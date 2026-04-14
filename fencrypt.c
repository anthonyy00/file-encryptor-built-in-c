#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"

#define BUFFER 1024

void xor(const char *filename, const char *efile);

int main(int argc, char *argv[])
{

if (argc < 3)
  {
    printf("usage: %s <method> <file> <encrypted_file_name>\n", argv[0]);
    return 1;
  }

if(strcmp(argv[1], "xor") == 0)
xor(argv[2], argv[3]);

if(strcmp(argv[1],"rsa") == 0){
if(argc < 5)
      printf("rsa usage: %s rsa <prime number> <prime number> <file> <encrypted_file_name>\n", argv[0]);
else
    {
    long long p = atoll(argv[2]); // converts a string to a long long int value 
    long long q = atoll(argv[3]);
    rsa_encrypt(p, q, argv[4]);
    }
  }

return 0;

}

void xor(const char *filename, const char *efile)
{
  
  ssize_t bytes;
  char buffer[BUFFER];

  int file = open(filename, O_RDONLY);
  int encrypted_file = open(efile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
  while((bytes = read(file, buffer, sizeof(buffer))) > 0)
  {

    for(int i = 0; i < bytes; i++)
    {
      buffer[i] = buffer[i]^0xAA;
    }
    write(encrypted_file, buffer, bytes);
  }



close(file);
close(encrypted_file);
}


