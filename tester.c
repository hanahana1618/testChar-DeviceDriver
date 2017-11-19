#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <fcntl.h>  //needed for fhandler and open file
#include <unistd.h> //needed for write

//THIS SHIT DONT WORK EVEN IN A MILLION YEARS
//convert argv[] into a string
//missing fread implementation

//user space program in order to test TestChar LKM
int main(int argc, char *argv[]) { //just because CS50 was very annoying about this

	//making sure that the user gives sentence to the device driver
	//int wordNumber = 0;
	int fhandler;
	int returnString;
	static char buff[256];

	if (!strcmp(argv[0], "./tester") && argc >= 2) {
		//wordNumber = argc - 1;
		printf("Argc value: %d\n", argc);
	}	
	else {
		printf("Command line arguments not specified correctly. Usage for the program is 'sudo ./tester SENTENCES TO SEND TO DEVICE DRIVER'. Exiting program\n");
		return -1;	
	}

	//char buff[255];
	
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
	
	// fprintf(fp, "%s %s %s %d", "Werrrrrrerer", "are", "in", 2012);

	//send the LKM a string
	//fprintf("");
	//strcat();


	//char *value[256]; int n; //Your sentence can be 256 words long
	//value = "Hello There";

	//printf("%s", value); //this prints: Hello There

	//printf("Enter string in order to pass it to the loadable module: ");
	
	//n = scanf("%ms", &value); //value stored in the pointer value;

	
	//printf("Line before count loop\n");
	int i;
	int count = argc;
	//printf("Count value: %d\n", count);
	for (i=1; i<count; i++) {
		write(fhandler, argv[i], strlen(argv[1]));
		write(fhandler, " ", strlen(" "));
		printf("String successfully sent to device\n");
	}

	printf("Now we will return the string plus its length\n");
	returnString = read(fhandler, buff, 256);
	printf("Your sentence and its size are: %s\n", buff);

	//printf("Read: %s\n", value);

	//on a successful read scanf returns a 1
	/*if (n == 1) {
		printf("Read string %s", value);
		//value needs to be passed to the LKM
		fwrite(value, 1, strlen(value), fhandler);

		//value needs to be freed because it was dynamically allocated
		free(value);
	}
	else {
		printf("Unable to read given string");	
	}
	*/

	//implementation of the read function for the module: returns original string plus length
	//fread
	//fgets(buff, 255, (FILE*)fhandler);
	//printf("Retrieved data: %s\n", buff);

	//close the LKM
	//fclose(fhandler);

	//program ran correctly
	return 0;
}
