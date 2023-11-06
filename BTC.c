#include "BTC.h"
#include <string.h>
#include <ctype.h>
int i;



/*int isAllNonDigits(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 0; // It's a digit, return false
        }
        str++;
    }
    return 1; // All characters are non-digits, return true
}*/


/*int is_numeric(const char *chaine) {
    for (int i = 0; i < strlen(chaine); i++) {
        if (!isdigit(chaine[i])) {
            return 0;
        }
    }
    return 1;
}*/

int add(char * filename, btc b )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
		
		fprintf(f,"%s %s %s %s %s %s %d %d %d   \n",b.Id,b.name,b.mail,b.nb,b.region,b.adress,b.type,b.year,b.capacity);
		for(i=0;i<3;i++){
        		fprintf(f,"%d   \n",b.services[i]);}
       	
	fclose(f);
        return 1;
    }
    else return 0;
}
int modify( char * filename, char id[], btc nouv )
{
    int tr=0;
    btc b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d  \n",b.Id,b.name,b.mail,b.nb,b.region,b.adress,&b.type,&b.year,&b.capacity,&b.services[0],&b.services[1],&b.services[2])!=EOF)
        {
            if(strcmp(b.Id, id) == 0)
            {
                fprintf(f2,"%s %s %s %s %s %s %d %d %d   \n",nouv.Id,nouv.name,nouv.mail,nouv.nb,nouv.region,nouv.adress,nouv.type,nouv.year,nouv.capacity);
		for(i=0;i<3;i++){
        		fprintf(f2,"%d   \n",b.services[i]);}
                tr=1;
            }
            else{
                fprintf(f2,"%s %s %s %s %s %s %d %d %d   \n",b.Id,b.name,b.mail,b.nb,b.region,b.adress,b.type,b.year,b.capacity);
		for(i=0;i<3;i++){
        		fprintf(f2,"%d \n",b.services[i]);}}

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int Delete(char * filename, char id[])
{
    int tr=0;
    btc b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d  \n",b.Id,b.name,b.mail,b.nb,b.region,b.adress,&b.type,&b.year,&b.capacity,&b.services[0],&b.services[1],&b.services[2])!=EOF)
        {
            if(strcmp(b.Id, id) == 0)
                tr=1;
            else{
                fprintf(f2,"%s %s %s %s %s %s %d %d %d   \n",b.Id,b.name,b.mail,b.nb,b.region,b.adress,b.type,b.year,b.capacity);
		for(i=0;i<3;i++){
        		fprintf(f2,"%d   \n",b.services[i]);}}
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
btc search(char * filename, char id[])
{
    btc b;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d  \n",b.Id,b.name,b.mail,b.nb,b.region,b.adress,&b.type,&b.year,&b.capacity,&b.services[0],&b.services[1],&b.services[2])!=EOF)
        {
            if(strcmp(b.Id, id) == 0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(b.Id, "");
    return b;

}
