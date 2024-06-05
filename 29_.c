#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
struct element {
    int i;
    struct element* next;
};

// Funkcja zamieniaj¹ca wartoœci na wartoœæ bezwzglêdn¹ w liœcie bez g³owy
void bezwzglednaBezGlowy(struct element* head) {
    struct element* current = head;
    while (current != NULL) {
        if (current->i < 0) {
            current->i = -(current->i);
        }
        current = current->next;
    }
}

// Funkcja pomocnicza do dodawania elementów do listy
void dodajNaPoczatek(struct element** head, int wartosc) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    if (nowyElement == NULL) {
        printf("B³¹d alokacji pamiêci!\n");
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

// Funkcja usuwaj¹ca ca³¹ listê z pamiêci
void usunListe(struct element* head) {
    struct element* current = head;
    while (current != NULL) {
        struct element* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Tworzymy pust¹ listê bez g³owy
    struct element* Lista = NULL;

    // Dodajemy kilka elementów do listy
    dodajNaPoczatek(&Lista, -5);
    dodajNaPoczatek(&Lista, 3);
    dodajNaPoczatek(&Lista, -10);
    dodajNaPoczatek(&Lista, 7);

    // Wypisujemy listê przed zamian¹ wartoœci
    printf("Lista przed: ");
    wypiszListe(Lista);

    // Zamieniamy wartoœci na wartoœæ bezwzglêdn¹
    bezwzglednaBezGlowy(Lista);

    // Wypisujemy listê po zamianie wartoœci
    printf("Lista po: ");
    wypiszListe(Lista);

    // Usuwamy listê z pamiêci
    usunListe(Lista);

    return 0;
}
