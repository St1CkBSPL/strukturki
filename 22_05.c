#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
typedef struct element {
    int i;
    struct element *next;
} element;

// Funkcja dodajk
element* dodajk(element *Lista, int a) {
    // Alokacja pamiêci dla nowego elementu
    element *nowyElement = (element*)malloc(sizeof(element));
    if (nowyElement == NULL) {
        printf("B³¹d alokacji pamiêci!\n");
        exit(1);
    }

    // Ustawienie wartoœci pola 'i' nowego elementu
    nowyElement->i = a;
    nowyElement->next = NULL;

    // Sprawdzenie, czy lista jest pusta
    if (Lista == NULL) {
        return nowyElement;  // Jeœli lista by³a pusta, nowy element staje siê pierwszym elementem
    }

    // Znalezienie ostatniego elementu w liœcie
    element *aktualny = Lista;
    while (aktualny->next != NULL) {
        aktualny = aktualny->next;
    }

    // Dodanie nowego elementu na koñcu listy
    aktualny->next = nowyElement;

    // Zwrócenie wskaŸnika do pocz¹tku listy
    return Lista;
}

// Funkcja pomocnicza do drukowania listy (do testowania)
void drukujListe(element *Lista) {
    element *aktualny = Lista;
    while (aktualny != NULL) {
        printf("%d -> ", aktualny->i);
        aktualny = aktualny->next;
    }
    printf("NULL\n");
}

int main() {
    // Tworzenie pustej listy
    element *Lista = NULL;

    // Dodawanie elementów do listy
    Lista = dodajk(Lista, 10);
    Lista = dodajk(Lista, 20);
    Lista = dodajk(Lista, 30);

    // Drukowanie listy
    drukujListe(Lista);

    // Zwolnienie pamiêci (wa¿ne, aby unikn¹æ wycieków pamiêci)
    element *temp;
    while (Lista != NULL) {
        temp = Lista;
        Lista = Lista->next;
        free(temp);
    }

    return 0;
}


