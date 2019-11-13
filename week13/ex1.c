#include <stdio.h>
#include <string.h>

#define BUFF 100
#define PROCESSES 5
#define RESOURCES 3

int main(int argc, char *argv[]) {
    char str[BUFF];
    FILE* input;
    FILE* output;
    int existingResources[RESOURCES];
    int availableResources[RESOURCES];
    int allocationMatrix[PROCESSES][RESOURCES];
    int requestMatrix[PROCESSES][RESOURCES];
    int deadlockProcesses[PROCESSES];
    int deadlock = 0;
    int finished[PROCESSES];
    int currentSymbol = 0;
    int canExecute[PROCESSES];
    int changed = 1;

    if (argc < 2) {
        printf("No input filename provided\nUsage: %s filename\n", argv[0]);
        return 0;
    }

    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("File with name \"%s\" not found\nProvide a correct input filename\n", argv[1]);
        return 0;
    }

    /* --------------------------- */
    /* Reading input from the file */

    fgets(str, BUFF, input);
    for (size_t i = 0; i < RESOURCES; i++) {
        existingResources[i] = (int)(str[currentSymbol] - '0');
        currentSymbol += 2;
    }

    currentSymbol = 0;
    fgets(str, BUFF, input);
    fgets(str, BUFF, input);    

    fgets(str, BUFF, input);
    for (size_t i = 0; i < RESOURCES; i++) {
        availableResources[i] = (int)(str[currentSymbol] - '0');
        currentSymbol += 2;
    }
    
    currentSymbol = 0;
    fgets(str, BUFF, input);
    fgets(str, BUFF, input);

    fgets(str, BUFF, input);
    for (size_t i = 0; i < PROCESSES; i++) {
        for (size_t j = 0; j < RESOURCES; j++) {
            allocationMatrix[i][j] = (int)(str[currentSymbol] - '0');
            currentSymbol += 2;
        }

        currentSymbol = 0;
        fgets(str, BUFF, input);
    }

    currentSymbol = 0;

    fgets(str, BUFF, input);
    for (size_t i = 0; i < PROCESSES; i++) {
        for (size_t j = 0; j < RESOURCES; j++) {
            requestMatrix[i][j] = (int)(str[currentSymbol] - '0');
            currentSymbol += 2;
        }

        currentSymbol = 0;
        fgets(str, BUFF, input);
    }

    fclose(input);

    /* --------------- */
    /* Data processing */

    for (size_t i = 0; i < PROCESSES; i++) {
        deadlockProcesses[i] = 0;
        canExecute[i] = 1;
        finished[i] = 0;
    }
    
    while (changed) {
        changed = 0;

        for (size_t i = 0; i < PROCESSES; i++) {
            canExecute[i] = 1;
            for (size_t j = 0; j < RESOURCES; j++) {
                if (requestMatrix[i][j] > availableResources[j]) {
                    canExecute[i] = 0;
                    break;
                }
            }
        }

        for (size_t i = 0; i < PROCESSES; i++) {
            if (canExecute[i] && finished[i] == 0) {
                for (size_t j = 0; j < RESOURCES; j++) {
                    availableResources[j] += allocationMatrix[i][j];
                    allocationMatrix[i][j] = 0;
                    requestMatrix[i][j] = 0;
                    changed = 1;
                    finished[i] = 1;
                }
            }
        }
    }

    for (size_t i = 0; i < PROCESSES; i++) {
        if (finished[i] == 0) {
            deadlockProcesses[i] = 1;
            deadlock = 1;
        }
    }
    
    if (deadlock) {
        output = fopen("output_dl.txt", "w+");

        for (size_t i = 0; i < PROCESSES; i++) {
            if (deadlockProcesses[i]) {
                fprintf(output, "Process %ld is in a deadlock\n", i+1);
            }
        }
        fprintf(output, "(Counting from 1 to %d)", PROCESSES);
    } else {
        output = fopen("output_ok.txt", "w+");

        fprintf(output, "No deadlocks found");
    }

    fclose(output);

    return 0;
}
