#ifndef BD_H_INCLUDED
#define BD_H_INCLUDED
#include <stdio.h>
typedef struct
{
    char ID[20];
    char city[20];
    char BloodType[4];
    char BloodBank[30];
    int quantity;
    int sign;
    int D,M,Y;
    int Diseases [5];
} BD;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ADD(char *file_name, BD d);
int MODIFY(char *filename, char ID[20], BD nouv);
int DELETE(char *filename, char ID[20]);
BD SEARCH(char *file_name, char ID[20]);
int isNumerical(const char *input);

#endif // BD_H_INCLUDED
