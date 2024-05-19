#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void print_bits(char c)
{
    int i;

    i = 8;
    while(i >= 0)
    {
        if (c % 2 == 0)
            kill(, sig);
        else 
            putchar('1');
        printf(">>>%d<<<<\n", c % 2);
        c = c >> 1;
        i--;
    }
}

int main() {

    unsigned int c = 10;
    
    print_bits(c);
}
/*
    10 = 00010100
    7  = 00000111
    res= 00000010
00000001
00000000
<< 1| 1
*/