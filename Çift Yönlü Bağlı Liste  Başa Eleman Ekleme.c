#include <stdio.h>
#include <stdlib.h>

struct node{
int sayi;
struct node* sonraki;
struct node* onceki;
};
struct node* bas_eleman=NULL;
struct node* son_eleman=NULL;

struct node* dugumolustur(int sayi)
{
    struct node* yenidugum=(struct node*)malloc(sizeof(struct node));
    yenidugum->sayi=sayi;
    yenidugum->sonraki=NULL;
    yenidugum->onceki=NULL;
    return yenidugum;

}

void basekle(int sayi)
{
    struct node* basaeklenen=dugumolustur(sayi);
    if(bas_eleman==NULL)
    {
        bas_eleman=basaeklenen;
        return;
    }
    struct node* eski_sayi=bas_eleman;
    bas_eleman=basaeklenen;
    bas_eleman->sonraki=eski_sayi;
    eski_sayi->onceki=bas_eleman;
    return;

}


void yazdir(struct node* bas,int ileri)
{
    struct node* temp=bas;
    while(temp!=NULL)
    {
        printf(" ,%d ",temp->sayi);
        if(ileri==1)
        {
            temp=temp->sonraki;
        }
        else
            temp=temp->onceki;
    }

}

int main()
{
    int sayi ;
    int secim;
    while(1)
    {
        printf("basaekle\n");
        printf("secim yapiniz:\n");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            printf("sayi gir:");
            scanf("%d",&sayi);
            basaekle(sayi);
            yazdir(bas_eleman,1);
            break;
        }


        }


}