#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100


struct node
{
    char data;
    struct node* SolDugum;
    struct node* SagDugum;

};
struct node* RootNode = NULL;

struct node* Kuyruk[BOYUT];
int front = -1, rear = -1;

void ekle(struct node* Dugum)
{
    if(rear == BOYUT - 1)
    {
        printf("\n Kuyruk Dolu \n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    Kuyruk[rear] = Dugum;

}

struct node* cikan()
{

    if(front == -1 || front > rear)
    {
        printf("\n Kuyruk Bos \n");
        return;
    }
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    struct node* Cikan = Kuyruk[front];
    front++;
    return Cikan;
}


struct node* DugumOlustur(char Data)
{
    struct node* YeniDugum = (struct node*)malloc(sizeof(struct node));
    YeniDugum->data = Data;
    YeniDugum->SolDugum = NULL;
    YeniDugum->SagDugum = NULL;

    return YeniDugum;
}

//sol - root - sag....

void InOrder(struct node* temp)
{
    if(temp == NULL)
        return;

    InOrder(temp->SolDugum);
    printf(" %c ", temp->data);
    InOrder(temp->SagDugum);
}

void InsertNode(struct node* Baslangic, char Eklenecek)
{
    if(RootNode == NULL)
    {
        RootNode = DugumOlustur(Eklenecek);
        return;
    }


    ekle(Baslangic);
        while(front != -1 && front <= rear)
    {
        struct node* temp = Kuyruk[front];
        cikan();
        if(temp->SolDugum == NULL)
        {
            temp->SolDugum = DugumOlustur(Eklenecek);
            break;
        }
        else
        {
            ekle(temp->SolDugum);
        }

        if(temp->SagDugum == NULL)
        {
            temp->SagDugum = DugumOlustur(Eklenecek);
            break;
        }
        else
        {
            ekle(temp->SagDugum);
        }

    }
}


int main()
{
    InsertNode(RootNode, 'A');
    InsertNode(RootNode, 'B');
    InsertNode(RootNode, 'C');

    printf("\n");
    InsertNode(RootNode, '1');
    InsertNode(RootNode, '2');
    InsertNode(RootNode, '3');
    InsertNode(RootNode, '4');


    InOrder(RootNode);

}