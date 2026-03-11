#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER 1024

void encrypt(const char *filename, const char *efile);

int main(int argc, char *argv[])
{

if (argc < 3)
  {
    printf("usage: %s <file> <encrypted_file_name>\n", argv[0]);
    return 1;
  }


encrypt(argv[1], argv[2]);

return 0;

}

void encrypt(const char *filename, const char *efile)
{
  
  ssize_t bytes;
  char buffer[BUFFER];

  int file = open(filename, O_RDONLY);
  int encrypted_file = open(efile, O_CREAT | O_RDONLY | O_WRONLY | S_IRWXU);
    
  while((bytes = read(file, buffer, sizeof(buffer))) > 0)
  {

    for(int i = 0; i < bytes; i++)
    {
      bytes++;
    }
    write(encrypted_file, buffer, bytes);
  }


// write(efile, buffer, bytes);

close(file);
close(encrypted_file);
}
