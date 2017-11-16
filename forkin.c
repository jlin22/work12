#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  printf("Before Fork\n");
  int f = fork();
  fork();
  if (f == 0){
    printf("Child PID : %d \n", getpid());
    srand(time(NULL));
    int r = rand() % 15 + 5;
    printf("%d \n", r);
    sleep(1);
    
  }
  else{
    int x = 0;
    wait(&x);
  }
  return 0;
  
}
