#ifndef DMS_H_INCLUDED
#define DMS_H_INCLUDED
#include <stdio.h>
typedef struct{ 
    char ID[20];
    char Name [15];
    int sex;
    //0:male,2:female 
    char phone [20];
    int age;
    char region[50];
    int Bloodtype;//1:A,2:B,3:B+;4:B-;5:AB;6:AB+;7:O+;8:O-;int nbdons;}DSM;
}DSM;


//le type de  retour int c'est pour indiquer si la tache a �t� r�alis�e avec succ�s ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable

int ajouter(char *, DSM );
int modifier( char *, char*, DSM );
int supprimer(char *, char* );
DSM chercher(char * s, char* );
int numberOfDonors(char * ,int);

#endif // DMS_H_INCLUDED
