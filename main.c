#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

#include "my_rand.h"


int print_array(unsigned char* buf, unsigned len) {
	int i = 0;
	for(i = 0; i < len; ++i){
		fprintf(stderr, "%02x ", buf[i]);
	}
	fprintf(stderr, "\n");
	return 0;
}

int main(int argc, char *argv[])
{
	printf("helloworld is running !!! \n");

	unsigned char dest[MAXPASSLEN];
	int i = 0;
	for(i = 0; i<10; ++i)
	{
		random_pw(dest, MAXPASSLEN);
		print_array(dest, MAXPASSLEN);	
	}	
	return 0;
}
