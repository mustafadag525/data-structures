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

void EnQueue(struct node* Dugum)
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

struct node* Dequeue()
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


    EnQueue(Baslangic);
    // Level Order Traversal...
    while(front != -1 && front <= rear)
    {
        struct node* temp = Kuyruk[front];
        Dequeue();
        if(temp->SolDugum == NULL)
        {
            temp->SolDugum = DugumOlustur(Eklenecek);
            break;
        }
        else
        {
            EnQueue(temp->SolDugum);
        }

        if(temp->SagDugum == NULL)
        {
            temp->SagDugum = DugumOlustur(Eklenecek);
            break;
        }
        else
        {
            EnQueue(temp->SagDugum);
        }

    }
}


void LevelOrderTraversal(struct node* root)
{
    front = -1;
    rear = -1;

    EnQueue(root);

    while(front != -1 && front <= rear)
    {
        struct node* temp = Kuyruk[front];
        Dequeue();
        printf(" %c ", temp->data);

        if(temp->SolDugum != NULL)
            EnQueue(temp->SolDugum);
        if(temp->SagDugum != NULL)
            EnQueue(temp->SagDugum);
    }
}


void SondanSil(struct node* Baslangic, struct node* Silinecek)
{
    front = -1;
    rear = -1;

    EnQueue(Baslangic);

    while(front != -1 && front <= rear)
    {
        struct node* temp = Kuyruk[front];
        Dequeue();

        if(temp == Silinecek)
        {
            temp = NULL;
            free(Silinecek);
            return;
        }

        if(temp->SagDugum != NULL)
        {
            if(temp->SagDugum == Silinecek)
            {
                temp->SagDugum = NULL;
                free(Silinecek);
                return;
            }
            else
                EnQueue(temp->SagDugum);
        }

        if(temp->SolDugum != NULL)
        {
            if(temp->SolDugum == Silinecek)
            {
                temp->SolDugum = NULL;
                free(Silinecek);
                return;
            }
            else
                EnQueue(temp->SolDugum);
        }
    }
}


struct node* DugumSil(struct node* root, char c)
{
    front = -1;
    rear = -1;
    // Sadece bir tane dugum varsa burasi calisacak...
    if(root->SolDugum == NULL && root->SagDugum == NULL)
    {
        if(root->data == c)
            return NULL;
        else
            return root;
    }
    struct node* ArananDugum = NULL;
    EnQueue(root);
    struct node* temp = NULL;
    while(front != -1 && front <= rear)
    {
        temp = Kuyruk[front];
        Dequeue();

        if(temp->data == c)
            ArananDugum = temp;
        if(temp->SolDugum != NULL)
            EnQueue(temp->SolDugum);
        if(temp->SagDugum != NULL)
            EnQueue(temp->SagDugum);


    }
    if(ArananDugum != NULL)
    {
        char t = temp->data;
        SondanSil(root, temp);
        ArananDugum->data = t;
    }

    return root;
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
    LevelOrderTraversal(RootNode);
    //InOrder(RootNode);

    printf("\n");
    RootNode = DugumSil(RootNode, 'B');
    LevelOrderTraversal(RootNode);


}
