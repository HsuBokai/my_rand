#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
#include "my_rand.h"

int random_pw(unsigned char dest[], int len)
{
	FILE *fp;
	if ((fp = fopen("/dev/urandom", "r")) == NULL) {
		fprintf(stderr, "Error! Could not open /dev/urandom for read\n");
		return -1;
	}
	int i = 0;
	for (i=0; i<MAXPASSLEN && i<len; ++i) {
		dest[i] = fgetc(fp);
	}
	fclose(fp);
	return 0;
}

/*old
static int srand_called=0;

void random_pw(unsigned char dest[])
{
	size_t len=0;
	unsigned char *p=dest;
	int three_in_a_row=0;
	int arr[128]={0x0};
	// be sure to have called srand exactly one time 
	if(!srand_called)
	{
		srandom(time(NULL));
		srand_called=1;
	}
	*dest=0x0; // int the destination string
	for(len=MINPASSLEN + rand()%(MAXPASSLEN-MINPASSLEN); len; len--, p++) {
		unsigned char *q=dest;
		unsigned choice = rand()%3;
		if(choice == 0) *p = rand()%26 + 'a';
		else if(choice == 1) *p = rand()%26 + 'A';
		else *p = rand()%10 + '0';
		p[1]=0x0;
		arr[*p]++;                         // check values
		if(arr[*p]==3) {
			for(q=dest; q[2]>0 && !three_in_a_row; q++)	
				if(*q==q[1] && q[1]==q[2])
					three_in_a_row=1;
		}
		if(three_in_a_row || arr[*p]> 3 )
			random_pw(dest);        // values do not pass try again
	}
	//return dest;
}
*/
