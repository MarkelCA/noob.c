// C program to illustrate
// command line arguments
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH_CHAR 50

void validate_strings_length(char ** argv, int str_count) {

    /*printf("%s\n", *(argv));*/

    for(int i = 0 ; i < str_count ; i++) {

        char * str = *(argv+i);
        printf("%s - length: %lu\n", str, strlen(str));
    }

}

int main(int argc, char* argv[])
{
    char * programName = argv[0];

    // We ignore program name now that we stored it
    --argc;
    ++argv;
    
    //size_t size = argc * MAX_LENGTH_CHAR;
    //argv = malloc(size);
    //printf("Allocated %zu bytes for %p pointer\n", size, argv);


	printf("Program Name Is: %s\n", programName);

	if(argc == 0)
		printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
	if(argc >= 1)
	{
		printf("\nNumber Of Arguments Passed: %d",argc);
		printf("\n----Following Are The Command Line Arguments Passed----\n");

        validate_strings_length(argv, argc);
	}
	return 0;
}
