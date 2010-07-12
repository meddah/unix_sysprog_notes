#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
    int ch;
    int aflag = 0, bflag = 0, cflag = 0, hflag = 0, fflag = 0, oflag = 0, lflag = 0;
    char *barg = NULL;
    char *farg = NULL;
    int i;

    static struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"file", required_argument, NULL, 'f'},
        {"output", required_argument, &oflag, 'o'},
        {"list", optional_argument, NULL, 'l'},
        {0, 0, 0, 0},
    };

    opterr = 0; /* global variable */
    while ((ch = getopt_long(argc, argv, "abh:cf", long_options, NULL)) != -1) {
        switch (ch) {
            case 0:
                if (oflag) 
                    oarg = optarg;
                break;
            case 'a':
                aflag = 1;
                break;
            case 'b':
                bflag = 1;
                barg = optarg;
                break;
            case 'f':
                fflag = 1;
                farg = optarg;
                break;
            case 'c':
                cflag = 1;
                break;
            case 'h':
                hflag = 1;
                break;

            case '?':
                if (optopt == 'b') { /* global variable */
                    fprintf (stderr, "b seçeneğinin argümanı yok\n");
                }
                else if (optopt == 'f') { /* global variable */
                    fprintf (stderr, "--file seçeneğinin argümanını giriniz\n");
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
    printf("%s\n", hflag ? "help seçildi" : "help seçilmedi");
    printf("%s (%s)\n", fflag ? "file seçildi" : "file seçilmedi", farg);

    for (i = optind; i < argc; ++i) {
        printf("Seçeneksiz argüman: %s\n", argv[i]);
    }

    return 0;
}

