struct node{

int  sayi;
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


void sondansil()
{
    struct node* temp=baslangic;
    while(temp->sonraki->sonraki!=NULL)
    {
        temp=temp->sonraki;
    }
    free(temp->sonraki);
    temp->sonraki=NULL;
}





void yazdir()
{
    struct node* temp=baslangic;
    while(temp!=NULL)
    {
        printf("=>%d",temp->sayi);
        temp=temp->sonraki;
    }
}

int main()
{
int sayi;
sondansil(sayi);
yazdir();
}
