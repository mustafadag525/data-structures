kendisine metin dizisi veri tipinde parametre olarak gelen bir posfix ifadeyi hesaplayan fonksiyonu ve yardımcı fonksiyonları (pop, push fonksiyonlar ) yığın veri yapısında bağlı liste olarak kullanınız 



#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  

struct Stek 
{ 
    int top; 
    unsigned kapasite; 
    int* dizi; 
}; 

struct Stek* createStek( unsigned kapasite ) 
{ 
    struct Stek* Stek = (struct Stek*)  
           malloc(sizeof(struct Stek)); 
  
    if (!Stek)  
        return NULL; 
  
    Stek->top = -1; 
    Stek->kapasite = kapasite; 
  
    Stek->dizi = (int*) malloc(Stek->kapasite *  
                                   sizeof(int)); 
  
    return Stek; 
} 
int isEmpty(struct Stek* Stek) 
{ 
    return Stek->top == -1 ; 
} 
char peek(struct Stek* Stek) 
{ 
    return Stek->dizi[Stek->top]; 
} 
char pop(struct Stek* Stek) 
{ 
    if (!isEmpty(Stek)) 
        return Stek->dizi[Stek->top--] ; 
    return '$'; 
} 
void push(struct Stek* Stek, char op) 
{ 
    Stek->dizi[++Stek->top] = op; 
} 
  

int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') ||  
           (ch >= 'A' && ch <= 'Z'); 
} 

int Prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 
  
  
  
int infixdenPostfixe(char* exp) 
{ 
    int i, k; 

    struct Stek* Stek = createStek(strlen(exp)); 
    if(!Stek) 
        return -1 ; 
  
    for (i = 0, k = -1; exp[i]; ++i) 
    { 
          
      
        if (isOperand(exp[i])) 
            exp[++k] = exp[i]; 
          

        else if (exp[i] == '(') 
            push(Stek, exp[i]); 
          
   
        else if (exp[i] == ')') 
        { 
            while (!isEmpty(Stek) && peek(Stek) != '(') 
                exp[++k] = pop(Stek); 
            if (!isEmpty(Stek) && peek(Stek) != '(') 
                return -1;            
            else
                pop(Stek); 
        } 
        else 
        { 
            while (!isEmpty(Stek) &&  
                 Prec(exp[i]) <= Prec(peek(Stek))) 
                exp[++k] = pop(Stek); 
            push(Stek, exp[i]); 
        } 
  
    } 
  

    while (!isEmpty(Stek)) 
        exp[++k] = pop(Stek ); 
  
    exp[++k] = '\0'; 
    printf( "%s", exp ); 
} 
  

int main() 
{ 
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixdenPostfixe(exp); 
    return 0; 
} 
