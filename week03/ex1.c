#include <stdio.h>
int main(){
    int* pc;
    int c;
    c=22;                                       // Output on my PC :
    printf("Address of c:%d\n",&c);             //  Address of c:6422216
    printf("Value of c:%d\n\n",c);              //  Value of c:22
    pc=&c;
    printf("Address of pointer pc:%d\n",pc);    //  Address of pointer pc:6422216
    printf("Content of pointer pc:%d\n\n",*pc); //  Content of pointer pc:22
    c=11;
    printf("Address of pointer pc:%d\n",pc);    //  Address of pointer pc:6422216
    printf("Content of pointer pc:%d\n\n",*pc); //  Content of pointer pc:11
    *pc=2;
    printf("Address of c:%d\n",&c);             //  Address of c:6422216
    printf("Value of c:%d\n\n",c);              //  Value of c:2
    return 0;
}