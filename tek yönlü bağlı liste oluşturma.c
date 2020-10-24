# include <stdio.h>
#include <stdlib.h>


struct node
{
    int sayi;
    struct node* sonraki;
};
struct node* baslangic=NULL;


struct node* olustur(int sayi)
{
    struct node* yenidugum=(struct node*)malloc(sizeof(struct node));
    yenidugum->sayi=sayi;
    yenidugum->sonraki=NULL;
    return yenidugum;



}



int main()
{
    baslangic=olustur(1);
    struct node* ikinci=olustur(2);
    struct node* ucuncu=olustur(3);
    struct node* dorduncu=olustur(4);
    baslangic->sonraki=ikinci;
    ikinci->sonraki=ucuncu;
    ucuncu->sonraki=dorduncu;

    struct node* temp=baslangic;
    while(temp!=NULL)
    {
        printf("%d ",temp->sayi);
        temp=temp->sonraki;
    }

}