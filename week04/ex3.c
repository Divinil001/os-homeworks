#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100
#define KGRN "\x1B[32m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

int main(){
	char command[BUFF_SIZE];
	while(1){
		char directory[BUFF_SIZE];
		getcwd(directory, sizeof(directory));
		printf(KGRN "shell" KWHT ":" KCYN "%s" KWHT ": ", directory);
		scanf("%s", command);
		if(strcmp(command, "exit") == 0){
			break;
		} else {
	  	system(command);
		}
	}
	return 0;
}
