#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


struct Yigin
{
    int suankiKanal;
    unsigned kapasite;
    char** siteler;
    int siteSayisi;
};

struct Yigin* yiginOlustur(unsigned capacity)
{
    struct Yigin* stack = (struct Yigin*)malloc(sizeof(struct Yigin));
    stack->kapasite = capacity;
    stack->suankiKanal = -1;
    stack->siteSayisi = 0;
    stack->siteler = (int*)malloc(stack->kapasite * sizeof(int));
    return stack;
}

int dolumu(struct Yigin* stack)
{
    return stack->suankiKanal == stack->kapasite - 1;
}

int bosmu(struct Yigin* stack)
{
    return stack->suankiKanal == -1;
}

void siteyeGirildi(struct Yigin* stack, char* item)
{
    if (dolumu(stack))
        return;
    stack->siteler[++stack->suankiKanal] = item;
    stack->siteSayisi++;
    printf("%s 'ye girildi\n", item);
}

int geriTusu(struct Yigin* stack)
{
    if (bosmu(stack))
        return INT_MIN;
    stack->suankiKanal--;
    return stack->siteler[stack->suankiKanal];
}

int ileriTusu(struct Yigin* stack)
{
    if (stack->siteSayisi<stack->suankiKanal -1)
        return INT_MIN;
    stack->suankiKanal++;
    return stack->siteler[stack->suankiKanal];
}

int suankiSite(struct Yigin* stack)
{
    if (bosmu(stack))
        return INT_MIN;
    return stack->siteler[stack->suankiKanal];
}

int main()
{
    struct Yigin* stack = yiginOlustur(100);

    siteyeGirildi(stack, "www.google.com");
    siteyeGirildi(stack, "www.hotmail.com");
    siteyeGirildi(stack, "www.yahoo.com");

    printf(" Geri tusuna basildi, gelinen sayfa: %s\n", geriTusu(stack));

    return 0;
}