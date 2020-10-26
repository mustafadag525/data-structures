#include <stdio.h>
#include <stdlib.h>
#define boyut 10

int dizi[boyut];

void yazdir(int vurgula)
{
    int i;
    for(i=0;i<sizeof(dizi)/sizeof(dizi[0]);i++)
    {
        if(i==vurgula)
        {
            printf("\n %d <======",dizi[i]);
        }
        else
        {
            printf("\n %d",dizi[i]);
        }
    }
}


int main()
{
    yazdir(1);
}
