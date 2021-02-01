// Stack veri yapisi Bir kelimeyi ters cevirme

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define BOYUT 50
char Kelime[BOYUT];
char KelimeStack[BOYUT];

int Top = -1;


bool DoluMu()
{
    if(Top >= 49)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BosMu()
{
    if(Top <= -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(char a)
{
    bool Dolu = DoluMu();
    if(Dolu == false)
    {
        Top = Top + 1;
        KelimeStack[Top] = a;
    }
    else
    {
        printf("\n Stackoverflow....");
        return;
    }
}

char Pop()
{
    bool Bos = BosMu();
    if(Bos == true)
    {
        return 0;
    }
    else
    {
        char a = KelimeStack[Top];
        Top--;
        return a;
    }
}

int main()
{
    printf("\n Bir Kelime Girin ...");
    scanf("%[^\n]s", Kelime);

    for(int i = 0; i < strlen(Kelime); i++)
    {
        Push(Kelime[i]);
    }

    for(int i = 0; i < strlen(Kelime); i++)
    {
        Kelime[i] = Pop();
    }

    printf("\n Ters Cevrilen Kelime: %s", Kelime);

}