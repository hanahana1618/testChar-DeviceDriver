#include "tester.h"

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
	

	//program ran correctly
	return 0;
}
