#include <stdio.h>
#include <stdlib.h>

// zad 7.3.1
struct element{
    int i;
    struct element *next;
};

struct element *utworz(){
    return NULL;
};

//zad 7.3.2
void wyczysc(struct element* Lista){
    struct element *wsk = Lista;
    while(Lista != NULL){
        Lista = Lista -> next;
        free(wsk);
        wsk = Lista;
    }
}

//zad 7.3.3
struct element * dodajnapoczatek(struct element* Lista, int a){
    struct element *wsk = malloc(sizeof(struct element));
    wsk -> i=a;
    wsk -> next = Lista;
    return wsk;
}

//zad 7.3.4
struct element *dodajnakoniec(struct element * Lista, int a){
    struct element *wsk;
    if(Lista == NULL){
        Lista = wsk = malloc(sizeof(struct element));
    }
    else{
        wsk = Lista;
        while(wsk->next != NULL){
            wsk = wsk -> next;
        }
        wsk -> next = malloc(sizeof(struct element));
        wsk = wsk -> next;
    }
    wsk -> i = a;
    wsk -> next = NULL;
    return Lista;
};

struct element * dodajodpowiednio(struct * element Lista, struct element * elem, int a)
{
    struct element * wsk = malloc(sizeof(struct element));
    wsk -> i = a;
    if(elem==NULL)
    {
        wsk ->next = Lista;
        Lista = wsk;
    }
    else
    {
        wsk -> next=elem -> next;
        elem -> next = wsk;
    }
    return Lista;
};

//zad 7.3.5
void wypisz(struct element * Lista)
{
    while(Lista != NULL)
    {
        printf("%d, ",Lista->i);
        Lista = Lista -> next;
    }
    printf("\n");
}
// zad 7.3.6
struct element * znajdz(struct element * Lista,int a)
{
    while((Lista!=NULL)&&(Lista->i!=a))
    {
        Lista=Lista->next;
    }
    return Lista;
};
int main()
{
    struct element * lista = utworz();
    lista = dodajnakoniec(lista, 4);
    lista = dodajnakoniec(lista, 2);
    lista = dodajnapoczatek(lista, 1);
    lista = dodajnapoczatek(lista, 7);
    wypisz(lista);
    return 0;
}
