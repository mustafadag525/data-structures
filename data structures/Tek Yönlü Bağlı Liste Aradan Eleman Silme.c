
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int sayi;
    struct node* sonraki;
};
struct node* baslangic=NULL;
struct node* dugumolustur(int sayi)
{
    struct node* yenidugum=(struct node*)malloc(sizeof(struct node));
    yenidugum->sayi=sayi;
    yenidugum->sonraki=NULL;
    return yenidugum;

}


void aradansil(int index)
{
    struct node* temp=baslangic;
    int sayac=0;
    while(temp!=NULL)
    {
        if(sayac==index-1)
        
            break;
        temp=temp->sonraki;
        sayac++;
    }
    struct node* gecici=temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki=gecici;
    
}





void yazdir()
{
    struct node* temp=baslangic;
    while(temp!=NULL)
    {
        printf("=> %d",temp->sayi);
        temp=temp->sonraki;
    }
}



int main(

int index;
printf("hangi pozisyondaki eleman silinecek");
scanf("%d",&index);
aradansil();
yazdir();