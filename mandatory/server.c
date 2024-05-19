#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int num)
{
    write(1, "1", 2);
}
void handler1(int num)
{
    write(1, "0", 2);
}
int main()
{
    printf("pid %d\n", getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler1);
    while (1);
}