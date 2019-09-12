#include <unistd.h>
#include <stdio.h>

int main(){
  int n = 42;
  int parentPID = getpid();
  fork();
  int newPID = getpid();

  if(parentPID == newPID){
    printf("Hello from parent [%d - %d]\n", parentPID, n);
  } else {
    printf("Hello from child [%d - %d]\n", newPID, n);
  }
  return 0;
}
