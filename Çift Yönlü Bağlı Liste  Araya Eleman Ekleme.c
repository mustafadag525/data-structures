#include <stdio.h>


struct node
{
    int sayi;
    struct node* sonraki;
    struct node* onceki;
};

struct node* bas = NULL;
struct node* son = NULL;

struct node* Olustur(int sayi)
{
    struct node* YeniDugum = (struct node*)malloc(sizeof(struct node));
    YeniDugum->sayi = sayi;
    YeniDugum->sonraki = NULL;
    YeniDugum->onceki = NULL;

    return YeniDugum;
}


void SonaEkle(int sayi)
{
    struct node* SonaEklenecek = Olustur(sayi);

    if(bas == NULL)
    {
        bas = SonaEklenecek;
        return;
    }

    struct node* Temp = bas;
    while(Temp->sonraki != NULL)
    {
        Temp = Temp->sonraki;
    }
    Temp->sonraki = SonaEklenecek;
    SonaEklenecek->onceki = Temp;
    return;
}

void BasaEkle(int sayi)
{
    struct node* BasaEklenecek = Olustur(sayi);
    if(bas == NULL)
    {
        bas = BasaEklenecek;
        return;
    }

    /* 10 20 30 40 (5)*/
    struct node* Eski = bas;
    bas = BasaEklenecek;

    bas->sonraki = Eski;
    Eski->onceki = bas;
    return;
}

void ArayaEkle(int indis, int sayi)
{
    struct node* ArayaEklenecek = Olustur(sayi);

    if(indis == 0)
    {
        BasaEkle(sayi);
        return;
    }

    if(bas == NULL && indis > 0)
    {
        printf("\n Bu konum uygun degil ... ");
        return;
    }

    int counter = 0;
    struct node* Temp = bas;
    int flag = 0;
    while(Temp != NULL)
    {
        if(counter == indis)
        {
            flag = 1;
            break;
        }

        Temp = Temp->sonraki;
        counter++;
    }
    if(flag == 0)
    {
        printf("\n Boyle pozisyon  yok...");
        return;
    }

    if(Temp->sonraki == NULL)
    {
        SonaEkle(sayi);
        return;
    }    struct node* OncekiDugum = Temp->onceki;
    OncekiDugum->sonraki = ArayaEklenecek;
    ArayaEklenecek->onceki = OncekiDugum;
    ArayaEklenecek->sonraki = Temp;
    Temp->onceki = ArayaEklenecek;
}
void Yazdir(struct node* Bas, int ileri)
{
    struct node* temp = Bas;
    printf("\n\n******* Mevcut Liste Yapisi *******\n");
    while(temp != NULL)
    {
        printf(" %d ", temp->sayi);
        if(ileri == 1)
            temp = temp->sonraki;
        else
            temp = temp->onceki;
    }
    printf("\n***********************************");
}



int main()
{
int sayi,indis;
   printf("\n Eklemek istediginiz sayiyi girin ...");
                scanf("%d", &sayi);
                printf("\n Hangi Konuma Ekleyeceksiniz ...");
                scanf("%d", &indis);
                ArayaEkle(indis, sayi);
                Yazdir(bas, 1);
                





}
