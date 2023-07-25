#include<stdio.h>
/* 1.What does const mean? Illustrate.
2.Analyze the following code output.
All description is on the Documentation
*/
int main(int arge, char *argv[]){

    int x,y,z;
    x = 2023+ 'A';
    y = 0;
    y += x++;
    z += ++x;
    printf("%d %d %d\n", x,y,z);
    return 0;
}
