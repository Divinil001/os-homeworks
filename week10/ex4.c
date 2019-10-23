#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define BUFF 100

int main(){
    
    DIR* d = opendir("tmp");
    if(d == NULL){
        printf("Error: Cannot open \"tmp\" folder\n");
        return 0;
    }

    struct dirent* dir;

    int inodes[BUFF];
    int inodesFreq[BUFF];
    char** filenames[BUFF];
    int num = 0;

    for (size_t i = 0; i < BUFF; i++)
    {
        inodesFreq[i] = 0;
        inodes[i] = -1;
        filenames[i] = (char**)malloc(sizeof(char*) * BUFF);
    }
    
    FILE* file = fopen("ex4.txt", "w+");

    while(dir = readdir(d)){
        if(!strcmp(dir->d_name, "."))
            continue;
        if(!strcmp(dir->d_name, ".."))
            continue;
        
        char directory_name[100] = "tmp/";

        struct stat file_stat;
        strcat(directory_name, dir->d_name);
        int ret = stat(directory_name, &file_stat);
        if(ret < 0){
            printf("Error: Cannot get information about the file \"%s\"\n", directory_name);
            return 0;
        }
        int inode = file_stat.st_ino;

        int found = 0;
        for (size_t i = 0; i < num; i++)
        {
            if(inodes[i] == inode){
                inodesFreq[i]++;
                filenames[i][inodesFreq[i]-1] = (char*)malloc(sizeof(char) * BUFF);
                strcpy(filenames[i][inodesFreq[i]-1], dir->d_name);
                found = 1;
                break;
            }
        }
        if(found == 0){
            inodes[num] = inode;
            inodesFreq[num] = 1;
            filenames[num][0] = (char*)malloc(sizeof(char) * BUFF);
            strcpy(filenames[num][0], dir->d_name);
            num++;
        }   
    }

    for (size_t i = 0; i < num; i++)
    {
        if(inodesFreq[i] < 2)
            continue;
        fprintf(file, "%d : %d\n", inodes[i], inodesFreq[i]);
        for (size_t j = 0; j < inodesFreq[i]; j++)
        {
            fprintf(file, "    %s\n", filenames[i][j]);
        }
        
    }
    
    fclose(file);
    closedir(d);
    return 0;
}