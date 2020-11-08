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


void bastansil()
{
    if(baslangic->sonraki==NULL)
    {
        baslangic=NULL;
    }
    struct node* ikinci=baslangic->sonraki;
    free(baslangic);
    baslangic=ikinci;

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
bastansil(sayi);
yazdir();
}
