#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
struct element {
    int i;
    struct element* next;
};

// Funkcja tworz¹ca pust¹ listê z g³ow¹
struct element* utworz() {
    // Alokujemy pamiêæ na wêze³ g³owy
    struct element* head = (struct element*)malloc(sizeof(struct element));
    if (head == NULL) {
        printf("B³¹d alokacji pamiêci!\n");
        return NULL;
    }

    // Ustawiamy wskaŸniki
    head->i = 0; // Pole i w wêŸle g³owy mo¿e byæ dowolne, poniewa¿ nie przechowuje ono danych u¿ytkownika
    head->next = NULL; // Pocz¹tkowo lista jest pusta, wiêc wskaŸnik next jest NULL

    return head;
}

// Funkcja pomocnicza do dodawania elementów do listy (dla testów)
void dodajNaPoczatek(struct element* head, int wartosc) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    if (nowyElement == NULL) {
        printf("B³¹d alokacji pamiêci!\n");
        return;
    }
    nowyElement->i = wartosc;
    nowyElement->next = head->next;
    head->next = nowyElement;
}

// Funkcja pomocnicza do wypisywania listy (dla testów)
void wypiszListe(struct element* head) {
    struct element* current = head->next; // Pomijamy wêze³ g³owy
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
    // Tworzymy pust¹ listê z g³ow¹
    struct element* Lista = utworz();
    if (Lista == NULL) {
        return 1; // Zakoñczenie programu, jeœli nie uda³o siê utworzyæ listy
    }

    // Dodajemy kilka elementów do listy
    dodajNaPoczatek(Lista, 5);
    dodajNaPoczatek(Lista, 3);
    dodajNaPoczatek(Lista, 10);
    dodajNaPoczatek(Lista, 7);
    dodajNaPoczatek(Lista, 9);

    // Wypisujemy listê
    printf("Lista: ");
    wypiszListe(Lista);

    // Usuwamy listê z pamiêci
    usunListe(Lista);

    return 0;
}
