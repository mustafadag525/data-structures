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

struct node* basaekle(int sayi)
{
    struct node* basaeklenen=dugumolustur(sayi);
    if(baslangic==NULL)
    {
        baslangic=basaeklenen;
    }
    else
    {
        struct node* eski_bir=baslangic;
        baslangic=basaeklenen;
        baslangic->sonraki=eski_bir;
    }

}

struct node* sonaekle(int sayi)
{
    struct node *sonaeklenen=dugumolustur(sayi);
    if(baslangic==NULL)
    {
        baslangic=sonaeklenen;
    }
    struct node* temp=baslangic;
    while(temp->sonraki!=NULL)
    {
        temp=temp->sonraki;
    }
    temp->sonraki=sonaeklenen;

}


void arayaekle(int indis,int sayi)
{
    struct node* arayaekleneneleman=dugumolustur(sayi);
    if(indis==0)
    {
        basaekle(sayi);
    }
    struct node* temp=baslangic;
    int sayac=0;
    while(temp!=NULL)
    {
        if(sayac==indis-1)
        {
            break;
        }
        else
        {
            temp=temp->sonraki;
            sayac++;
        }
    }
    if(sayac+1!=indis)
    {
        printf("Girilen boyutta indis yok!!!");
        return;
    }
    if(temp->sonraki==NULL)
    {
        sonaekle(sayi);
        return;
    }
    struct node* gecici=temp->sonraki;
    temp->sonraki=arayaekleneneleman;
    arayaekleneneleman->sonraki=gecici;



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
    int sayi,secim,indis;

    while(1)
    {
        printf("\n 1 basaekle\n");
        printf("2 sonaekle\n");
        printf("3 araya ekle\n");
        printf("secim yapiniz:");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            printf("sayi gir:");
            scanf("%d",&sayi);
            basaekle(sayi);
            yazdir();
            break;

        case 2:
            printf("sayi gir:");
            scanf("%d",&sayi);
            sonaekle(sayi);
            yazdir();
            break;
        case 3:
            printf("sayi gir:");
            scanf("%d",&sayi);
            printf("hangi indise eklenecek:");
            scanf("%d",&indis);
            arayaekle(indis,sayi);
            yazdir();
            break;
        }
    }
}
