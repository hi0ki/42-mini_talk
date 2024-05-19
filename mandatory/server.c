#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    pid_t pid = getpid();

    printf("PID: %d\n", pid);
}