#include <unistd.h>
#include <stdlib.h>

#define LOOP 5

int main(){
	for(int i = 0; i < LOOP; i++){
		fork();
		sleep(5);
	}
}
