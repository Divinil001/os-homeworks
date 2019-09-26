#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(){
  char someString[256] = "Some string";
  char emptyString[256] = "";
  int pipefd[2]; 

  printf("Initial strings:\n%s\n%s\n", someString, emptyString);

  if(pipe(pipefd) == -1){
    printf("Error creating pipe.\n");
    return 1;
  } 

  pid_t cpid = fork();
  if(cpid > 0){
    close(pipefd[0]);
    write(pipefd[1], someString, strlen(someString));
    close(pipefd[1]);
  }
  else {
    char buf;
    int idx = 0;
    close(pipefd[1]);
    while(read(pipefd[0], &buf, 1) > 0)
      emptyString[idx++] = buf;
    close(pipefd[0]);
    emptyString[idx] = '\0';
    printf("New strings:\n%s\n%s\n", someString, emptyString);
  }

  return 0;
}
