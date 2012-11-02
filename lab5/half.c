#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
	{  printf("pid of half: %d\n", getpid());
   	   if(argc == 2)
	   	{  printf("%d\n" , atoi(argv[argc-1])/2);
		   return (0);
		}

	   int i;
	   char *argv_list[100] , val[10] , cmd[100];
	   snprintf(val, sizeof(val), "%d", atoi(argv[argc-1])/2);
	   strcpy(cmd , "./");
	   
	   for(i=1 ; i<argc ; i++)
	   	argv_list[i-1] = argv[i];

	   argv_list[i-1] = NULL;
	   strcat(cmd , argv_list[0]);
	   argv_list[0] = cmd;
	   argv_list[argc-2] = val;
	   
	   execvp(argv_list[0] , argv_list);
	   return (0);
	}
