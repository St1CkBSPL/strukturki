#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
struct element {
    int i;
    struct element* next;
};

// Funkcja zamieniaj�ca warto�ci na warto�� bezwzgl�dn� w li�cie bez g�owy
void bezwzglednaBezGlowy(struct element* head) {
    struct element* current = head;
    while (current != NULL) {
        if (current->i < 0) {
            current->i = -(current->i);
        }
        current = current->next;
    }
}

// Funkcja pomocnicza do dodawania element�w do listy
void dodajNaPoczatek(struct element** head, int wartosc) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    if (nowyElement == NULL) {
        printf("B��d alokacji pami�ci!\n");
        return;
    }
    nowyElement->i = wartosc;
    nowyElement->next = *head;
    *head = nowyElement;
}

// Funkcja pomocnicza do wypisywania listy
void wypiszListe(struct element* head) {
    struct element* current = head;
    while (current != NULL) {
        printf("%d ", current->i);
        current = current->next;
    }
    printf("\n");
}

// Funkcja usuwaj�ca ca�� list� z pami�ci
void usunListe(struct element* head) {
    struct element* current = head;
    while (current != NULL) {
        struct element* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Tworzymy pust� list� bez g�owy
    struct element* Lista = NULL;

    // Dodajemy kilka element�w do listy
    dodajNaPoczatek(&Lista, -5);
    dodajNaPoczatek(&Lista, 3);
    dodajNaPoczatek(&Lista, -10);
    dodajNaPoczatek(&Lista, 7);

    // Wypisujemy list� przed zamian� warto�ci
    printf("Lista przed: ");
    wypiszListe(Lista);

    // Zamieniamy warto�ci na warto�� bezwzgl�dn�
    bezwzglednaBezGlowy(Lista);

    // Wypisujemy list� po zamianie warto�ci
    printf("Lista po: ");
    wypiszListe(Lista);

    // Usuwamy list� z pami�ci
    usunListe(Lista);

    return 0;
}
