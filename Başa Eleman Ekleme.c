# include <stdio.h>
#include <stdlib.h>


struct node
{

    int sayi;
    struct node* sonraki;

};

struct node* baslangic=NULL;

struct node* dugumolustur(int sayi)
{
    struct node* yeniden=(struct node*)malloc(sizeof(struct node));
    yeniden->sayi=sayi;
    yeniden->sonraki=NULL;
    return yeniden;

}

void basaekle(int sayi)
{
    struct node* basaeklenen=dugumolustur(sayi);
    if(baslangic==NULL)
    {
        baslangic=basaeklenen;
        return ;
    }
    else
    {
        struct node* eski_bir=baslangic;
        baslangic=basaeklenen;
        baslangic->sonraki=eski_bir;
    }
}
void yazdir()
{
    struct node* temp=baslangic;

    while(temp!=NULL)
    {
        printf("==> %d",temp->sayi);
        temp=temp->sonraki;

    }
}


int main()
{
    int secim;
    int sayi;


    while(1)
    {


        system("cls");
        printf("1 Basa Ekle");

        printf("secim yapiniz:");
        scanf("%d",&secim);

        switch(secim)
        {
        
        case 1:
            printf("hangi eleman eklenecek: ");
            scanf("%d",&sayi);
            basaekle(sayi);
            yazdir();
            break;

        }
        getch();

    }



}