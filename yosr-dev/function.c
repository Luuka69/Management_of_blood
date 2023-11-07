#include <string.h>
#include "function.h"


int ajouter(char * filename, DSM d )
{
    //check if d.ID exists in DSM.txt if yes return -1

    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        //write in the file f all attributes of DSM d
        fprintf(f,"%s %s %d %s %d %s %d\n", d.ID, d.Name,d.sex,d.phone,d.age,d.region,d.Bloodtype);
        fclose(f);  
        return 1;
    }
    else return 0;
}
int modifier( char * filename, char* id, DSM nouv )
{

    int tr=0;
    DSM d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %s %d\n",d.ID, d.Name,&d.sex,d.phone,&d.age,d.region,&d.Bloodtype)!=EOF)
        {
            if(strcmp(d.ID, id)==0){
                fprintf(f2,"%s %s %d %s %d %s %d\n", nouv.ID, nouv.Name,nouv.sex,nouv.phone,nouv.age,nouv.region,nouv.Bloodtype);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %s %d %s %d\n", d.ID, d.Name,d.sex,d.phone,d.age,d.region,d.Bloodtype);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimer(char * filename, char* id)
{
    int tr=0;
    DSM d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %s %d\n",d.ID, d.Name,&d.sex,d.phone,&d.age,d.region,&d.Bloodtype)!=EOF)
        {
            if(strcmp(d.ID, id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %d %s %d %s %d\n", d.ID, d.Name,d.sex,d.phone,d.age,d.region,d.Bloodtype);        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

DSM chercher(char * filename, char* id)
{
    DSM d;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %s %d\n",d.ID, d.Name,&d.sex,d.phone,&d.age,d.region,&d.Bloodtype)!=EOF)
        {

            if( strcmp(d.ID, id)==0 ){
                break;
            }
        }
    }
    fclose(f);
    return d;

}


int numberOfDonors(char * filename,int bloodType)
{   
    int num_donors=0;
    DSM d;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %s %d\n",d.ID, d.Name,&d.sex,d.phone,&d.age,d.region,&d.Bloodtype)!=EOF)
        {
            if(d.Bloodtype== bloodType) num_donors++;
        }
    }

    fclose(f);
    return num_donors;

}
int avgAgeForBloodType(char * filename,int bloodType)
{   
    int sum=0;
    DSM d;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %s %d\n",d.ID, d.Name,&d.sex,d.phone,&d.age,d.region,&d.Bloodtype)!=EOF)
        {
            if(d.Bloodtype== bloodType) sum+=d.age;
        }
    }

    fclose(f);
    return sum/numberOfDonors(filename,bloodType);

}
