#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    int fd;

    if ((fd = open("text.txt", O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);        
    }

    printf("Success..\n");

    return 0;
}
