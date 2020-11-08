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

//sona eleman ekleme;

void sonaekle(int sayi)
{
    struct node* sonaekleneneleman=dugumolustur(sayi);
    if(baslangic==NULL)//hic eleman yoksa eklenen deger ilk eleman olur onu kontrol ederiz
    {
        baslangic=sonaekleneneleman;
    }
    else

    {
        struct node* temp=baslangic;//traverse islemi. Amac tum dugumleri dolasmak;
        while(temp-> sonraki != NULL)//temp null ise son dugume gelmistir;
        {
            temp=temp->sonraki;

        }
        temp->sonraki=sonaekleneneleman;
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
        printf("\n 1\ Sona Eleman Ekle\n");

        printf("secim yapiniz:");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            printf("hangi elemani ekleyeceksiniz: ");
            scanf("%d",&sayi);
            sonaekle(sayi);
            yazdir();
            break;

        }
        getch();

    }



}
