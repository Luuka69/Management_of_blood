#include <stdio.h>
#include <string.h>
#include"BTC.h"

int main()
{
    btc b1= {"34647836","manouba","manoubabtc@gmail.com","90340111","rue_de_carthage",0,2023,15,{0,1,0}},b2= {"34567836","araian","arianaabtc@gmail.com","90340112","rue_de_republic",1,2015,10,{1,1,0}},b3;
    int x=add("btc.txt", b1);
    
    if(x==1)
	{
        printf("\n Adding successful");
	}
    else
	{
	printf("\n Error adding");
	}
        
    x=modify("btc.txt","34647836",b2 );

    if(x==1)
	{
        printf("\n Modification successful");
	}
    else 
	{
	printf("\n Error Modification");
	} 
   
    x=Delete("btc.txt","34567836");

    if(x==1)
	{
        printf("\n Deleteion successful");
	}
    else 
	{
	printf("\n Error deletion");
	}

    b3=search("btc.txt","34647837" );

    if(strcmp(b3.Id, "")==0)
	{
        printf("Not found");
	}

    return 0;
}
