include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101
struct nlist { 
    struct nlist *next; 
    char *name; /* defined name */
    char *defn; /* replacement text */
};
static struct nlist *dict[HASHSIZE]; 
char *stringdublicate(char *s) 
{
    char *p;
    p = (char *) malloc(strlen(s)+1); 
    if (p != NULL)
       strcpy(p, s);
    return p;
}
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
struct nlist *varmi(char *s)
{
    struct nlist *np;
    for (np = dict[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np;
    return NULL;
}
struct nlist *ekle(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = varmi(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = stringdublicate(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = dict[hashval];
        dict[hashval] = np;
    } else 
        free((void *) np->defn); 
    if ((np->defn = strdup(defn)) == NULL)
       return NULL;
    return np;
}
int main()
{
	dict[0]=ekle("ali","anlami yok");
	dict[0]=ekle("ali","anlami yok");
	return 0;
}
