#ifndef BTC_H_INCLUDED
#define BTC_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct
{
        char Id[20];
        char name[50];
        char mail[50];
        char nb[15];
        char region[20];
        char adress[50];
        int type;
        int year;
        int capacity;
        int services[3];
} btc;

int add(char *filename, btc b );
int modify( char *filename, char a[], btc nouv );
int Delete(char *filename, char a[] );
btc search(char *filename, char a[] );
int isAllNonDigits(const char *str);
int is_numeric(const char *chaine);

#endif // BTC_H_INCLUDED

