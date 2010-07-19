#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    int fd;

    if ((fd = open("text.txt", O_RDONLY)) == -1) {
        if (errno == ENOENT) {
            fprintf(stderr, "No such file or directory!..\n");
            exit(1);
        }
        
    }

    printf("success..\n");

    return 0;
}
