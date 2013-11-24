#ifndef MY_RAND_H
#define MY_RAND_H

#define MAXPASSLEN 28

int random_pw(unsigned char dest[], int len);

/*old
#define	MAXPASSLEN	28
#define	MINPASSLEN	27
*/

/*
#ifdef GETPW_C
#define EXTERN extern
#else
#define EXTERN
#endif
*/

#endif
