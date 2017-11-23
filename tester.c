#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //needed for strcpy and others
#include <fcntl.h>  //needed for fhandler and open file
#include <unistd.h> //needed for write

#define BUFF_LEN 256
static char retBuff[BUFF_LEN];

//THIS SHIT DONT WORK EVEN IN A MILLION YEARS
//convert argv[] into a string
//missing fread implementation

//user space program in order to test TestChar LKM
int main(int argc, char *argv[]) { //just because CS50 was very annoying about this

	//making sure that the user gives sentence to the device driver
	int fhandler;
	int returnString; int retWrite;
	char buff[BUFF_LEN];
	
	if (strcmp(argv[0], "./tester")) {
		//wordNumber = argc - 1;
		printf("Argc value: %d\n", argc);
		return -1;
	}	

	
	//accessing the LKM
	//FILE *fhandler;
	fhandler = open("/dev/testchar", O_RDWR);

	if (fhandler < 0) {
		printf("Unable to open loadable kernel module TestChar. Closing program\n");
		return -2;
	}
	else {
		printf("LKM successfully opened\n");
	}

	printf("Enter string to send to the device driver: ");
	scanf("%[^\n]%*c", buff);
	retWrite = write(fhandler, buff, strlen(buff));
	if (retWrite < 0) {
		printf("Unable to send string to device driver TestChar");
		return -3;
	}
	
	printf("Now we will return the string plus its length\n");
	returnString = read(fhandler, retBuff, BUFF_LEN);
	if (returnString < 0) {
		printf("Unable to retrieve string from the device driver");
		return -4;
	}
	printf("Your sentence and its size are (including spaces): [%s]\n", retBuff);
	
	//int i;
	//int count = argc;
	//char *buff[strlen(argv(1))+1];
	//printf("Count value: %d\n", count);
	//strcpy(buff, argv[0]);
	//for (i=1; i<count; i++) {
	//	strncat(buff, argv[i], strlen(argv[i]));
	//	strncat(buff, " ", strlen(" "));
	//	malloc();
		//write(fhandler, argv[i], strlen(argv[1]));
		//write(fhandler, " ", strlen(" "));
		//printf("String successfully sent to device\n");
	//}
	
	
	//printf("Entire string: %s\n", buff);
	//printf("Size of string: %ld", sizeof(buff));

	//

	//free(buff);
/*

	write(fhandler, buff, strlen());

*/

	//program ran correctly
	return 0;
}
