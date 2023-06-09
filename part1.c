#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
int global_data;
pthread_cond_t cond;
pthread_mutex_t lock; 
#include "slow_functions.h"

int main(int argc, char * argv[])
{
if (argc > 1){
}
global_data=0;
pthread_t write1;
pthread_t read1;

int read_id1;
int count=0;

for (count=0;count<10;count++) {
if (pthread_create(&write1,NULL,slow_function1,NULL)) {
    fprintf(stderr,"Error creating thread");
    return 1;
}
}
if (pthread_create(&read1,NULL,slow_function2,&read_id1)) {
    fprintf(stderr,"Error creating thread");
    return 1;
}


pthread_exit(NULL);

return 0;
}