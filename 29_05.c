#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
struct element {
    int i;
    struct element* next;
};

// Funkcja usuwaj�ca element wskazywany przez elem z listy
struct element* usunw(struct element* Lista, struct element* elem) {
    if (Lista == NULL || elem == NULL) {
        return Lista;
    }

    // Sprawdzamy, czy pierwszy element listy to ten, kt�ry ma zosta� usuni�ty
    if (Lista == elem) {
        struct element* temp = Lista;
        Lista = Lista->next;
        free(temp);
        return Lista; // Zwracamy now� g�ow� listy
    }

    // Przeszukujemy list� w poszukiwaniu elementu do usuni�cia
    struct element* current = Lista;
    while (current->next != NULL && current->next != elem) {
        current = current->next;
    }

    // Je�eli znaleziono element do usuni�cia
    if (current->next == elem) {
        struct element* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    return Lista;
}

// Funkcja pomocnicza do dodawania element�w do listy (dla test�w)
void dodajNaPoczatek(struct element** head, int wartosc) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    nowyElement->i = wartosc;
    nowyElement->next = *head;
    *head = nowyElement;
}

// Funkcja pomocnicza do wypisywania listy (dla test�w)
void wypiszListe(struct element* head) {
    while (head != NULL) {
        printf("%d ", head->i);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct element* Lista = NULL;
    dodajNaPoczatek(&Lista, 5);
    dodajNaPoczatek(&Lista, 3);
    dodajNaPoczatek(&Lista, 10);
    dodajNaPoczatek(&Lista, 3);
    dodajNaPoczatek(&Lista, 7);

    printf("Lista przed usunieciem: ");
    wypiszListe(Lista);

    // Usuni�cie konkretnego elementu
    struct element* elemDoUsuniecia = Lista->next->next; // Zak�adamy, �e chcemy usun�� trzeci element (o warto�ci 10)
    Lista = usunw(Lista, elemDoUsuniecia);


    printf("Lista po usunieciu elementu: ");
    wypiszListe(Lista);

    // Usuwamy wszystkie pozosta�e elementy z pami�ci
    while (Lista != NULL) {
        struct element* temp = Lista;
        Lista = Lista->next;
        free(temp);
    }

    return 0;
}
