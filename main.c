#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define GPIO2_VALUE 0xe6052008
void somedelay(unsigned long delay);

int main(int argc, char * argv[]){
    volatile unsigned long *pGP2 = (volatile unsigned long *)GPIO2_VALUE;
    unsigned long LedFlashCoutner = 10;
    while(LedFlashCoutner--){
        *pGP2 = 0x55555555;
        somedelay(1);
        *pGP2 = 0xaaaaaaaa;
        somedelay(1);
    }
    return 0;
}

void somedelay(unsigned long delay){
    //7Sec
    //unsigned long tmp = 0xffffff;
    unsigned long tmp = 0x50000;
    for(; delay>0; delay--){
        for(; tmp>0; tmp--){
            ;
        }
    }
}
