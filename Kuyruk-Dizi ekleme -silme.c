#include <stdio.h>
#define BOYUT 5

int Kuyruk[BOYUT];
int front = -1, rear = -1;

void ekle(int sayi)
{
    if(rear == BOYUT - 1)
    {
        printf("\n Kuyruk Dolu \n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    Kuyruk[rear] = sayi;

}

int cýkar()
{

    if(front == -1 || front > rear)
    {
        printf("\n Kuyruk Bos \n");
        return;
    }
    int Cikan = Kuyruk[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
        return Cikan;

    }

    front++;
    return Cikan;
}


void Yazdir()
{
    for(int i = front; i <= rear; i++)
    {
        if(i == front && i == rear)
        {
            printf("\n %d-) %d (front) (rear)", i, Kuyruk[i]);
        }
        else if(front == i)
            printf("\n %d-) %d (front)", i, Kuyruk[i]);
        else if(rear == i)
            printf("\n %d-) %d (rear)", i, Kuyruk[i]);
        else
            printf("\n %d-) %d ", i, Kuyruk[i]);
    }
}

int main()
{
    int sayi, secim;
    while(1)
    {
        printf("\n\n\n 1-) Ekle");
        printf("\n 2-) Cikar  ");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
            printf("\n Sayi girin ..");
            scanf("%d", &sayi);
            ekle(sayi);
            Yazdir();
            break;
        case 2:
            sayi = cýkar();
            printf("\n **** Cikarilan eleman %d ****\n", sayi);
            Yazdir();
            break;
        }
    }
}
