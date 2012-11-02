#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 10

sem_t full_count;
sem_t empty_count;
sem_t mutex;

int counter=1 , flag=0 , size=0;
int queue[BUFFER_SIZE];

int get_counter()
	{ if((counter == 1000) || (counter == 0))
        flag = 1-flag;
		
	  if(flag == 0)
	  { counter++;
	    return(counter);}
	  
	  if(flag == 1)
	  { counter--;
	  return(counter);}
	}


void *producer()
	{ int i , item;

	while(1) {
	   sem_getvalue(&empty_count , &item);
	   sem_getvalue(&full_count , &i);
	  sem_wait(&empty_count);

	  sem_wait(&mutex);
	  queue[size] = get_counter();
	  size++;
	  printf("\nsizep: %d  e_c: %d  f_c: %d\n" , size , item , i);
	  for(i=0; i<size ; i++)
	     printf("\tp%d" , queue[i]);
	  printf("\n");//sem_post(&mutex);
	  sem_post(&mutex);
	  sem_post(&full_count);
	  //sem_post(&mutex);
   }
    }

void *consumer()
	{ int i , item;
	//printf("\ncheck2\n");
	while(1){
	  sem_getvalue(&empty_count , &item);
	  sem_getvalue(&full_count , &i);
	sem_wait(&full_count);
	sem_wait(&mutex);
	  size--;
	  printf("\nsizec: %d  e_c: %d  f_c: %d\n" , size , item , i);
	//printf("\ncheck3\n");
	  for(i=0; i<size ; i++)
	     printf("\tc%d" , queue[i]);
	  printf("\n");
	  sem_post(&mutex);
	  sem_post(&empty_count);
	  //sem_post(&mutex);
   }
    }	   

int main(int argc, char **argv)
	{ pthread_t thread_a , thread_b;

	  sem_init(&full_count , 0 , 0);
	  sem_init(&empty_count , 0 , BUFFER_SIZE-1);
	  sem_init(&mutex , 0 , 1);

	  int i;
	  //for(i=0 ; i<2500 ; i++)
	  	//printf("\n%d\n" , get_counter());
	  pthread_create(&thread_a , NULL , &producer , NULL);
	  printf("\n\nin main()\n\n");
	  pthread_create(&thread_b , NULL , &consumer , NULL);
	  printf("\n\nin main()2\n\n");
	  pthread_join(thread_a , NULL);
	  pthread_join(thread_b , NULL);
	  return 0;
	}
