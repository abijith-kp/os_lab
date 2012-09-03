//implementation of the command uname

#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char **argv)
	{ struct utsname u;
	  uname(&u);

	  printf("OS Name: %s\n" , u.sysname);
	  printf("Release: %s\n" , u.release);
	  printf("Version: %s\n" , u.version);
	  printf("Processor: %s\n" , u.machine);
	  return 1;
	} 

