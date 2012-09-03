//copy the contents of arg1 to arg2

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
	{ if(argc < 3)
		{ printf("ERROR: missing file operands\n");
		  return 1;
		}
	  
	  //opening file for reading and writing
	  size_t file1 = open(argv[1] , O_RDONLY);
	  size_t file2 = open(argv[2] , O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);

	  //checks the existence of the file
	  if(file1 == -1)
	  	{ printf("ERROR: file not found\n");
		  return 1;
	        }
	  
	  struct stat read_file;
	  fstat(file1 , &read_file);

	  int read_size = read_file.st_size;
	  char read_buf[read_size];

	  //copying the contents
	  read(file1 , read_buf , read_size);
	  write(file2 , read_buf , read_size);

	  return 0;
	}
