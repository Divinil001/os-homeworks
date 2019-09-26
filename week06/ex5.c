#include <unistd.h>
#include <stdio.h>
#include <signal.h>

pid_t child_pid = -1;

int main(){
	child_pid = fork();
	
	if(child_pid > 0){
		/* Parent */
		sleep(10);
		kill(child_pid, SIGTERM);
	} else {
		/* Child */
		while(1){
			printf("I'm alive\n");
			sleep(1);
		}
	}
	
	return 0;
}
