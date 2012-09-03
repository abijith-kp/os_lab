//gives the disc usage 

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc , char **argv)
	{ if(argc < 2)
		{ printf("ERROR: arguement missing\n");
		  return 1;
		}
	  size_t file = open(argv[1] , O_RDONLY);
	  struct stat file1;
	  
	  fstat(file , &file1);

	  printf("%d	%s\n" , file1.st_size , argv[1]);
	  return 0;
	}
