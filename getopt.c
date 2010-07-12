#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ch;
    int aflag = 0, bflag = 0, cflag = 0;
    char *barg = NULL;
    int i;

    opterr = 0; /* global variable */
    while ((ch = getopt(argc, argv, "ab:c")) != -1) {
        switch (ch) {
            case 'a':
                aflag = 1;
                break;
            case 'b':
                bflag = 1;
                barg = optarg;
                break;
            case 'c':
                cflag = 1;
                break;
            case '?':
                if (optopt == 'b') { /* global variable */
                    fprintf (stderr, "b seçeneğinin argümanı yok");
                }
                else {
                    fprintf(stderr, "-%c: gerçersiz seçenek.", optopt); 
                }

                break;
        }
    }

    printf("%s\n", aflag ? "a seçildi" : "a seçilmedi");
    printf("%s (%s)\n", bflag ? "b seçildi" : "b seçilmedi", barg);
    printf("%s\n", cflag ? "c seçildi" : "c seçilmedi");

    for (i = optind; i < argc; ++i) {
        printf("Seçeneksiz argüman: %s\n", argv[i]);
    }

    return 0;
}

