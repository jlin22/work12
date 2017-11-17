#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  printf("Before Fork\n");
  int f = fork();
  if (!f){
    fork();
  }
  if (f==0){
    srand(getpid());
    int r = rand() % 16 + 5;
    printf("Child PID : %d. I will sleep for %d seconds\n", getpid(), r);
    sleep(r);
    printf("Child %d is finished\n", getpid());
    exit(r);
  }
  else{
    int status = wait(&status);
    printf("Child %d is done sleeping for %d seconds\n", status, WEXITSTATUS(&status));
    printf("Parent %d is done\n", getpid());
  }
  return 0;
  
}
