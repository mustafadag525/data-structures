#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char* arananKelime;
    struct Node* onceki;
    struct Node* sonraki;
    int aranmaSayisi;
};

//kelime varmi diye arar bulursa aranma sayisini 1 artýrýr ve 1 döner yoksa 0 dýner
int kelimeOncedenEklenmismi(struct Node* head, char* new_data)
{
    struct Node* suankiEleman = head;
    while (suankiEleman != NULL)
    {
        if (strcmp(suankiEleman->arananKelime,new_data)  == 0)
        {
            suankiEleman->aranmaSayisi++;
            return 1;
        }
        suankiEleman = suankiEleman->onceki;
    }
    return 0;
}


void ekle(struct Node** head_ref,  char* new_data)
{
    struct Node* suankiEleman;
    struct Node* yeniKelime = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref;

    yeniKelime->arananKelime = new_data;
    yeniKelime->aranmaSayisi = 1;

    yeniKelime->onceki = NULL;


    if(kelimeOncedenEklenmismi(*head_ref,new_data) == 1){
        return;
    }

    //liste bos ise
    if (*head_ref == NULL)
    {
        yeniKelime->sonraki = NULL;
        *head_ref = yeniKelime;
        return;
    }
    else if ((*head_ref)->aranmaSayisi >= yeniKelime->aranmaSayisi)
    {
        yeniKelime->onceki = *head_ref;
        yeniKelime->onceki->sonraki = yeniKelime;
        *head_ref = yeniKelime;
    }

    else
    {
        suankiEleman = *head_ref;

        while (suankiEleman->onceki != NULL &&
                suankiEleman->onceki->aranmaSayisi < yeniKelime->aranmaSayisi)
            suankiEleman = suankiEleman->onceki;
        yeniKelime->onceki = suankiEleman->onceki;
        if (suankiEleman->onceki != NULL)
            yeniKelime->onceki->sonraki = yeniKelime;

        suankiEleman->onceki = yeniKelime;
        yeniKelime->sonraki = suankiEleman;
    }
}

void printList(struct Node* node)
{
    struct Node* last;
    while (node != NULL)
    {
        printf(" %s ", node->arananKelime);
        last = node;
        node = node->onceki;
    }
}

int main()
{
    struct Node* head = NULL;

    ekle(&head, "ahmet");
    ekle(&head, "google");
    ekle(&head, "yahoo");
    ekle(&head, "mehmet");

    printList(head);

    getchar();
    return 0;
}