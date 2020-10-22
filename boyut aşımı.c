#include <stdio.h>
#include <stdlib.h>
#define boyut 10

int dizi[boyut];


void elemanekle(int eklenenelaman,int indis)
{
    if(indis > boyut-1)
    {
        printf("\n boyutu astiniz");
        return;
    }

    dizi[indis]=eklenenelaman;
}



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

    elemanekle(1,0);
    elemanekle(4,6);
    elemanekle(7,9);
    elemanekle(1,66);
        yazdir(5);

}