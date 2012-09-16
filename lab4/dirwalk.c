//to print the files included in a folder give as a command line arguement

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

struct dirent *dptr;

int none()
 	{ //printf("\njksfksf\n");
	  return(1);
	}

int funct(char *name)
        { DIR *dirp;
	  dirp = opendir(name);

	  //size_t file = open(name , )
	  if(dirp == NULL)
	  	{ printf("%s\n" , name);
		  closedir(dirp);
		  return(0);
	        }
	  
	  dptr = readdir(dirp);
	  strcat(name , "/");
	  char temp[100] , n[100];
	  strcpy(temp , name);
	  strcpy(n , name);
	  
	  while(dptr != NULL)
	  	{ char t[100];
	          strcpy(temp , n);
		  strcat(temp , dptr->d_name);
		  printf("%s\n" , temp);
		  if((strcmp(dptr->d_name , ".") == 0) || (strcmp(dptr->d_name , "..") == 0))
		  	{ //printf("\nsfdbsjf\n");
			  dptr = readdir(dirp);
			  continue;
			  //funct(temp);
		       }

		  size_t file = open(temp , O_RDONLY);
		  struct stat f_s;
		  fstat(file , &f_s);

		  (S_ISDIR(f_s.st_mode) ? funct(temp) : none());		  
		  dptr = readdir(dirp);
	        }

           printf("%s\n" , name);
   	   closedir(dirp);

	   return(0);
        }  

int main(int argc, char **argv)
{
   DIR *dirp;

   if(argc < 2)
   	{ printf("ERROR");
	  return(1);
        }

   funct(argv[1]);
   return(0);
}
