#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
typedef struct element {
    int i;
    struct element *next;
} element;

// Funkcja dodajk
element* dodajk(element *Lista, int a) {
    // Alokacja pami�ci dla nowego elementu
    element *nowyElement = (element*)malloc(sizeof(element));
    if (nowyElement == NULL) {
        printf("B��d alokacji pami�ci!\n");
        exit(1);
    }

    // Ustawienie warto�ci pola 'i' nowego elementu
    nowyElement->i = a;
    nowyElement->next = NULL;

    // Sprawdzenie, czy lista jest pusta
    if (Lista == NULL) {
        return nowyElement;  // Je�li lista by�a pusta, nowy element staje si� pierwszym elementem
    }

    // Znalezienie ostatniego elementu w li�cie
    element *aktualny = Lista;
    while (aktualny->next != NULL) {
        aktualny = aktualny->next;
    }

    // Dodanie nowego elementu na ko�cu listy
    aktualny->next = nowyElement;

    // Zwr�cenie wska�nika do pocz�tku listy
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

    // Dodawanie element�w do listy
    Lista = dodajk(Lista, 10);
    Lista = dodajk(Lista, 20);
    Lista = dodajk(Lista, 30);

    // Drukowanie listy
    drukujListe(Lista);

    // Zwolnienie pami�ci (wa�ne, aby unikn�� wyciek�w pami�ci)
    element *temp;
    while (Lista != NULL) {
        temp = Lista;
        Lista = Lista->next;
        free(temp);
    }

    return 0;
}


