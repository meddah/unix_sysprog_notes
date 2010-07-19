#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	int ch;
	int aflag = 0, bflag = 0, cflag = 0, hflag = 0, fflag = 0, oflag = 0;
	int long_index;
	char *barg = NULL;
	char *farg = NULL;
	char *oarg = NULL;
	struct option long_options[] = {
		{"help", no_argument, NULL, 'h'},
		{"file", required_argument, NULL, 'f'},
		{"output", required_argument, &oflag, 1}, 
		{0, 0, 0, 0}
	};
	int i;
		
	opterr = 0;
	
	while ((ch = getopt_long(argc, argv, "ab:c", long_options, &long_index)) != -1) {
		switch (ch) {
			case 0:
				if (*long_options[long_index].flag == 1) 
					oarg = optarg;
				break;
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
			case 'h':
				hflag = 1;
				break;
			case 'f':
				fflag = 1;
				farg = optarg;
				break;
			case '?':
				if (optopt == 'b') 
					fprintf(stderr, "b seçeneğinin argümanı girilmedi!..\n");
				else if (optopt == 'f')
					fprintf(stderr, "--file seçeneğinin argümanı girilmedi!..\n");
				else if (optopt == 1)
					fprintf(stderr, "--output seçeneğinin argümanı girilmedi!..\n");
				else 
					fprintf(stderr, "'-%c': geçersiz seçenek!\n", optopt);
		}
	}
	
	printf("%s\n", aflag ? "a seçildi" : "a seçilmedi");
	printf("%s (%s)\n", bflag ? "b seçildi" : "b seçilmedi", barg);
	printf("%s\n", cflag ? "c seçildi" : "c seçilmedi");
	printf("%s\n", hflag ? "--help seçildi" : "--help seçilmedi");
	printf("%s (%s)\n", fflag ? "--file seçildi" : "--file seçilmedi", farg);
	printf("%s (%s)\n", oflag ? "--output seçildi" : "--output seçilmedi", oarg);
		
	for (i = optind; i < argc; ++i)
		printf("Arümansız seçenek: %s\n", argv[i]);
		 
	return 0;
}










