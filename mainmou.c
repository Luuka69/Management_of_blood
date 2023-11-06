#include <stdio.h>
#include <string.h>
#include "BD.h"

int main() {

    BD d1 = {"5498521", "Ariana", "A", "Ariana's Blood Bank", 5, 17, 2, 2023, 5};
    BD d2 = {"265845", "Ariana", "AB", "Ariana's Blood Bank", 4, 25, 10, 2023, 5};
    BD d3;

    int x = ADD("BD.txt", d1);

    if(x == 1)
        printf("\nThe addition of the donation is successful");
    else
        printf("\nError in addition");

    x = MODIFY("BD.txt", "13", d2);

    if(x == 1)
        printf("\nModification of the donation is successful");
    else
        printf("\nError in modification");

    x = DELETE("BD.txt", "5498521");

    if(x == 1)
        printf("\nThe deletion of donation is successful");
    else
        printf("\nError in deletion");

    d3 = SEARCH("BD.txt","13");

    if(strcmp(d3.ID,"") == 0) {
        printf("\nDonation not found\n");
    } else {
        printf("\nDonation found: ID = %s\n", d3.ID);
    }

    return 0;
}

