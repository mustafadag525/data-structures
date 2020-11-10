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
    struct node* birinci=dugumolustur(1);
    struct node* ikinci=dugumolustur(2);
    struct  node* ucuncu=dugumolustur(3);
    struct node* dorduncu=dugumolustur(4);

    bas_eleman=birinci;
    son_eleman=dorduncu;

    birinci->sonraki=ikinci; // birincinin onceki islemi yapilmaz.basta onceki degere null atamýstýk;

    ikinci->onceki=birinci;
    ikinci->sonraki=ucuncu;
    ucuncu->onceki=ikinci;
    ucuncu->sonraki=dorduncu;
    dorduncu->onceki=ucuncu; // sonraki islemi yapilmaz, basta atamistik;

    yazdir(bas_eleman,1);  //yada printf(bas_eleman,0) yapilabilir;
    yazdir(son_eleman,0);




}