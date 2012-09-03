//usage of fork in c program

#include <stdio.h>

void child_process()
	{ printf("\nhi : %d\n" , getpid()); 
        }

void parent_process()
	{ printf("\nbye : %d\n" , getpid());
        }

int main(int argc , char **argv[])
	{
 	  printf("\nmain()\n");
 	  int id;
 	  id = fork();

	   if(id == 0) 
   		{ //printf("\nchild process : %d\n" , getpid());
        	 //fork();
		 child_process();
		}
   
 	  else if (id > 0)
   		{ //printf("\nparent process : %d\n" , getpid());
		 //wait();
		 parent_process();
   		}

   	printf("\nend of main : %d\n" , getpid());
   	return 0;
	}	
