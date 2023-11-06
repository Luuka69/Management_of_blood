#include "BD.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*int isNumerical(const char *chaine) {
    for (int i = 0; i < strlen(chaine); i++) {
        if (!isdigit(chaine[i])) {
            return 0;
        }
    }
    return 1;
}*/

int ADD(char *filename, BD d) {
    FILE *f = fopen(filename, "a");

    if (f != NULL) {
        
            fprintf(f, "%s %s %s %s %d %d %d %d %d %d %d\n", d.ID, d.city, d.BloodType, d.BloodBank, d.quantity, d.sign, d.D, d.M, d.Y, d.Diseases[0], d.Diseases[1]);
            fclose(f);
            return 1;
        
    }

    return 0;
}

int MODIFY(char *filename, char ID[], BD nouv) {
    int tr = 0;
    BD d;

    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f!= NULL && f2!= NULL) {
        while (fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d\n", d.ID, d.city, d.BloodType, d.BloodBank, &d.quantity, &d.sign, &d.D, &d.M, &d.Y, &d.Diseases[0], &d.Diseases[1]) != EOF) {
            if (strcmp(d.ID, ID) == 0) {
          
                    fprintf(f2, "%s %s %s %s %d %d %d %d %d %d %d\n", nouv.ID, nouv.city, nouv.BloodType, nouv.BloodBank, nouv.quantity, nouv.sign, nouv.D, nouv.M, nouv.Y, nouv.Diseases[0], nouv.Diseases[1]);
                    tr = 1;
                } else {
                    fprintf(f2, "%s %s %s %s %d %d %d %d %d %d %d\n", d.ID, d.city, d.BloodType, d.BloodBank, d.quantity, d.sign, d.D, d.M, d.Y, d.Diseases[0], d.Diseases[1]);
                
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int DELETE(char *filename, char ID[]) {
    int tr = 0;
    BD d;

    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %s %s %d %d %d %d %d %d %d\n", d.ID, d.city, d.BloodType, d.BloodBank, &d.quantity, &d.sign, &d.D, &d.M, &d.Y, &d.Diseases[0], &d.Diseases[1]) != EOF) {
            if (strcmp(d.ID, ID) == 0) {
                tr = 1;
            } else {
                fprintf(f2, "%s %s %s %s %d %d %d %d %d %d %d\n", d.ID, d.city, d.BloodType, d.BloodBank, d.quantity, d.sign, d.D, d.M, d.Y, d.Diseases[0], d.Diseases[1]);
            }
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);

    return tr;
}

BD SEARCH(char *filename, char ID[]) {
    BD d;
    int tr = 0;

    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        while (fscanf(f, "%s %s %s %s %d %d %d %d %d %d %d\n", d.ID, d.city, d.BloodType, d.BloodBank, &d.quantity, &d.sign, &d.D, &d.M, &d.Y, &d.Diseases[0], &d.Diseases[1]) != EOF) {
            if (strcmp(d.ID, ID) == 0) {
                tr = 1;
                break;
            }
        }
    }

    fclose(f);

    if (tr == 0) {
        strcpy(d.ID, "");
        }

    return d;
}

