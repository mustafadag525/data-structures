
bir ikili ağaçta toplam düğüm sayısını bulan  özyineleme fonksiyonunu yazınız



#include <stdio.h>
#include <stdlib.h>
struct kokk
{
    int bilgi;
    struct kokk *sol, *sag;
};
struct kokk *createkokk(int key)
{
    struct kokk *newkokk = (struct kokk*)malloc(sizeof(struct kokk));
    newkokk->bilgi = key;
    newkokk->sol = NULL;
    newkokk->sag = NULL;
    return(newkokk);
}
static int count = 0;
int sayikoku(struct kokk *kok)
{
    if(kok != NULL)
    {
        sayikoku(kok->sol);
        count++;
        sayikoku(kok->sag);
    }
    return count;
}

int main()
{
    
    struct kokk *newkokk = createkokk(25);
    newkokk->sol = createkokk(27);
    newkokk->sag = createkokk(19);
    newkokk->sol->sol = createkokk(17);
    newkokk->sol->sag = createkokk(91);
    newkokk->sag->sol = createkokk(13);
    newkokk->sag->sag = createkokk(55);
   
    printf("Agac2deki node sayısı = %d ",sayikoku(newkokk));
    printf("\n");
    count = 0;
 
   
    struct kokk *kokk = createkokk(1);
    kokk->sag = createkokk(2);
    kokk->sag->sag = createkokk(3);
    kokk->sag->sag->sag = createkokk(4);
    kokk->sag->sag->sag->sag = createkokk(5);
    
    printf("Agac2deki node sayısı = %d ",sayikoku(kokk));
    printf("\n");
    count = 0;
 
   
    struct kokk *kok = createkokk(15);
   
    printf("Agac2deki node sayısı = %d",sayikoku(kok));
    return 0;
}
