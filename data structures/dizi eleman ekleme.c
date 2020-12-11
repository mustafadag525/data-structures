#include <stdio.h>
#include <stdlib.h>
#define boyut 10

int dizi[boyut];


void elemanekle(int eklenenelaman,int indis)
{
    if(indis > sizeof(dizi)/sizeof(dizi[5]))
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

   int index;
   int sayi,secim;

   while(1)
   {
       system("cls");

       printf("\n1\ Eleman ekleme\n");


       printf("lutfen secim yapiniz: ");
       scanf("%d",&secim);

       switch(secim)
       {
       case 1:

        printf("eklemek istediginiz sayiyi girin: ");
        scanf("%d",&sayi);
        printf("hangi indexe atayacaksiniz: ");
        scanf("%d",&index);
        elemanekle(sayi,index);
        yazdir(index);
        getch();

       }
   }
}