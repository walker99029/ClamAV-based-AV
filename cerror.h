/*
 *
 * Description: Error Collector.
 *
 * Author: Walker#99029.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

int cerror(char *error) {

    FILE *fd;
    const char errfile[] = "file";
    time_t total_seconds = time(NULL);
    struct tm* ct = localtime(&total_seconds);
    int seconds = ct->tm_sec;
    int minutes = ct->tm_min;
    int hours = ct->tm_hour;


     if((fd = fopen(errfile, "a")) == NULL) {
	printf("Error: Can't open error log.");
	return 1;
     }

     fprintf(fd, "%d:%d:%d -  Error: %s.\n", hours, minutes, seconds, error);
     printf("CERROR: Error: %s", error);
}
