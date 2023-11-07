#include <stdio.h>
#include <string.h>
#include"function.c"
#include"function.h"

/* typedef struct{ 
    char ID[20];
    char Name [15];
    int sex;
    //0:male,2:female 
    char phone [20];
    int age;
    char region[50];
    int Bloodtype;//1:A,2:B,3:B+;4:B-;5:AB;6:AB+;7:O+;8:O-;int nbdons;}DSM;
}DSM;
 */

int main()
{
    DSM d1;
    strcpy(d1.ID,"1234");
    strcpy(d1.Name,"ahmed");
    d1.age=20;
    strcpy(d1.phone,"123456");
    strcpy(d1.region,"tunis");
    d1.Bloodtype=1;
    d1.sex=1;

    DSM d2;
    strcpy(d2.ID,"1235");
    strcpy(d2.Name,"ali");
    d2.age=20;
    strcpy(d2.phone,"123456");
    strcpy(d2.region,"tunis");
    d2.Bloodtype=1;
    d2.sex=1;

    DSM d3;
    strcpy(d3.ID,"1236");
    strcpy(d3.Name,"aymen");
    d3.age=20;
    strcpy(d3.phone,"123456");
    strcpy(d3.region,"tunis");
    d3.Bloodtype=1;
    d3.sex  =1;

    DSM d4;
    strcpy(d4.ID,"1237");
    strcpy(d4.Name,"sami");
    d4.age=20;
    strcpy(d4.phone,"123456");
    strcpy(d4.region,"tunis");
    d4.Bloodtype=1;
    d4.sex=1;

    
    //test ajouter
    ajouter("DSM.txt",d1);
    printf("%s added succesfully!\n",d1.Name);
    ajouter("DSM.txt",d2);
    printf("%s added succesfully!\n",d2.Name);
    ajouter("DSM.txt",d3);
    printf("%s added succesfully!\n",d3.Name);
    ajouter("DSM.txt",d4);
    printf("%s added succesfully!\n",d4.Name);

    //test modifier
    DSM nouveau_d1;
    nouveau_d1=d1;
    strcpy(nouveau_d1.region,"Monastir");

    modifier("DSM.txt","1234",nouveau_d1);
 
    //test supprimer
    supprimer("DSM.txt","1235");
    printf("%s deleted succesfully!\n",d2.Name);

    //test chercher
    char str[20];
    printf("Enter the name of the DSM you want to search for : ");
    scanf("%s",str);
    DSM d=chercher("DSM.txt",str);  
    printf("DSM found :\n");
    printf("ID : %s\n",d.ID);
    printf("Name : %s\n",d.Name);
    printf("Age : %d\n",d.age);
    /*
    //test affiche
    DSM* tab_d = getAll("DSM.txt");
    counter=0;
    while(tab_d!=NULL)
    {   if (d[counter].ID!=NULL)
        {
            printf("DSM found :\n");
            printf("ID : %s\n",d[counter].ID);
            printf("Name : %s\n",d[counter].Name);
            printf("Age : %d\n",d[counter].age);
        }    
        counter++;
    }

*/
    return 0;
}
