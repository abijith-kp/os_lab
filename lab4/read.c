//to read from a file starting from argv[3]rd position, till argv[2]nd charactor

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{  char bufffer[256];
   if(argc < 4)
   	return(1);

   size_t file;
   if((file = open(argv[1] , O_RDONLY)) == -1)
   	return(1);

   struct stat file_stat;
   fstat(file , &file_stat);
   int file_size = file_stat.st_size;

   if((atoi(argv[2]) + atoi(argv[3])) > file_size)
   	return(1); 

   //char bufffer[256];
   read(file , bufffer , atoi(argv[3]));
   read(file , bufffer , atoi(argv[2]));
   bufffer[atoi(argv[2])] = '\0';
   printf("%s\n" , bufffer);
   return 0;
}

