#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
typedef struct element {
    int i;
    struct element *next;
} element;

element* dodajk(element *Lista, int a) {
    element *nowyElement = (element*)malloc(sizeof(element));
    if (nowyElement == NULL) {
        printf("B³¹d alokacji pamiêci!\n");
        exit(1);
    }

    nowyElement->i = a;
    nowyElement->next = NULL;


    if (Lista == NULL) {
        return nowyElement;
    }

    element *aktualny = Lista;
    while (aktualny->next != NULL) {
        aktualny = aktualny->next;
    }

    aktualny->next = nowyElement;


    return Lista;
}
void drukujListe(element *Lista) {
    element *aktualny = Lista;
    printf("{");
    while (aktualny != NULL) {
        printf("%d", aktualny->i);
        if (aktualny->next != NULL) {
            printf(", ");
        }
        aktualny = aktualny->next;
    }
    printf("}\n");
}

int main() {
    element *Lista = NULL;

    Lista = dodajk(Lista, 10);

    drukujListe(Lista);

    element *temp;
    while (Lista != NULL) {
        temp = Lista;
        Lista = Lista->next;
        free(temp);
    }

    return 0;
}
