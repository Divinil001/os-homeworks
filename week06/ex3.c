#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int signo){
  if(signo != SIGINT)
    return;

  printf("\nSIGINT received!\n");
  exit(0);
}

int main(){
  if(signal(SIGINT, sigint_handler) == SIG_ERR)
    printf("\nCan't catch SIGINT\n");

  while(1)
    sleep(1);

  return 0;
}
