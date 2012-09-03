//implementation of command "ls -l"

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv)
	{ if(argc < 2)
	  	return 1;

	  size_t file = open(argv[1] , O_RDONLY);
	  if(file == -1)
	  	{ printf("ERROR: file not found\n");
		  return 1;
		}

	  struct stat file_stat;
	  fstat(file , &file_stat);


	  //checks wheather a directory or not
	  printf( S_ISDIR(file_stat.st_mode) ? "d" : "-");

	  //gives the permission of the file
	  printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
	  printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
	  printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
	  printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
	  printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
	  printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
	  printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
	  printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
	  printf( (file_stat.st_mode & S_IXOTH) ? "x. " : "-. ");
	  
	  //number of links to the file
	  printf("%d " , file_stat.st_nlink);

	  //to find the group id and use id
	  struct passwd *pw = getpwuid(file_stat.st_uid);
	  struct group  *gr = getgrgid(file_stat.st_gid);
	  printf("%s " , pw->pw_name);
	  printf("%s " , gr->gr_name);

	  //gives the size of the file
	  printf("%d " , (int)file_stat.st_size);

	  //to print the last acess time and the file name
	  printf("%s %s\n" , ctime(&file_stat.st_atime) , argv[1]);

	  return 0;
	}
