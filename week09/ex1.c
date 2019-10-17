#include <stdio.h>
#include <stdlib.h>

typedef struct Pager{
    int pageNum;
    int* pages;
    char* paccess;

    int hits;
    int misses;
} PAGER;

PAGER* pcreate(int num){
    PAGER* p = (PAGER*)malloc(sizeof(PAGER));
    p->pageNum = num;
    p->pages = (int*)malloc(sizeof(int) * num);
    p->paccess = (char*)malloc(sizeof(char) * num);
    p->hits = p->misses = 0;

    return p;
}

void tick(PAGER* p){
    for(int i=0; i<p->pageNum; ++i)
        p->paccess[i] = p->paccess[i] >> 1;
}

int swapPage(PAGER* p, int idx, int pid){
    p->pages[idx] = pid;
    p->paccess[idx] = 0b10000000;
    p->misses++;
    return 1;
}

int paccess(PAGER* p, int pid){
    int idx = 0;
    char* byte = p->pages[0];
    for(int i=0; i < p->pageNum; ++i){
        if(p->pages[i] == pid){
            p->hits++;
            p->paccess[i] = p->paccess[i] | 0b10000000;
            return 0;
        }
        if(p->paccess[i] < byte){
            idx = i;
            byte = p->paccess[i];
        }
    }    

    return swapPage(p, idx, pid);
}

int main(int argc, char* agrv[]){
    int pagenum = 100;
    PAGER* pager = pcreate(pagenum);

    FILE* fin = fopen("input.txt", "r");

    int tmp = 0;
    while(fscanf(fin, "%d", &tmp) != EOF){
        tick(pager);
        paccess(pager, tmp);
    }

    int h = pager->hits, m  = pager->misses;
    int t = h+m;
    printf("Hit/Miss: %d/%d\n", h,m);


    fclose(fin);

    return 0;
} 
