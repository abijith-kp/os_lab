//to give the size of each file recursively 

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

struct dirent *dptr;

//just a namesake function
int none()
 	{ //printf("\njksfksf\n");
	  return(1);
	}

int funct(char *name)
        { DIR *dirp;
	  dirp = opendir(name);

	  //size_t file = open(name , )
	  size_t file = open(name , O_RDONLY);
	  struct stat f_s;
	  fstat(file , &f_s);

	  if(dirp == NULL)
	  	{ printf("%s 	%d\n" , name , f_s.st_size);
		  closedir(dirp);
		  return(0);
	        }
	  
	  dptr = readdir(dirp);
	  strcat(name , "/");
	  char temp[100] , n[100];
	  strcpy(temp , name);
	  strcpy(n , name);

	  int size = 0;
	  
	  while(dptr != NULL)
	  	{ char t[100];
	          strcpy(temp , n);
		  strcat(temp , dptr->d_name);
		  file = open(temp , O_RDONLY);
		  fstat(file , &f_s);
		  size = 0;
		  //printf("%s 	%d\n" , temp , f_s.st_size);
		  if((strcmp(dptr->d_name , ".") == 0) || (strcmp(dptr->d_name , "..") == 0))
		  	{ //printf("\nsfdbsjf\n");
			  dptr = readdir(dirp);
			  continue;
			  //funct(temp);
		       }

		  //file = open(temp , O_RDONLY);
		  //fstat(file , &f_s);

		  if(S_ISDIR(f_s.st_mode))
	      	  	{ size += funct(temp);
		        }
		  else
		  	{ size += f_s.st_size;
		        }

		  printf("%s    %d\n" , temp , size);		     
		  dptr = readdir(dirp);
	        }

           printf("%s 	%d\n" , name , size);
   	   closedir(dirp);

	   return(size);
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
