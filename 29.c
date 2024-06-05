#include <stdio.h>
#include <stdlib.h>

// Definicja struktury element
struct element {
    int i;
    struct element* next;
};

// Funkcja tworz�ca pust� list� z g�ow�
struct element* utworz() {
    // Alokujemy pami�� na w�ze� g�owy
    struct element* head = (struct element*)malloc(sizeof(struct element));
    if (head == NULL) {
        printf("B��d alokacji pami�ci!\n");
        return NULL;
    }

    // Ustawiamy wska�niki
    head->i = 0; // Pole i w w�le g�owy mo�e by� dowolne, poniewa� nie przechowuje ono danych u�ytkownika
    head->next = NULL; // Pocz�tkowo lista jest pusta, wi�c wska�nik next jest NULL

    return head;
}

// Funkcja pomocnicza do dodawania element�w do listy (dla test�w)
void dodajNaPoczatek(struct element* head, int wartosc) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    if (nowyElement == NULL) {
        printf("B��d alokacji pami�ci!\n");
        return;
    }
    nowyElement->i = wartosc;
    nowyElement->next = head->next;
    head->next = nowyElement;
}

// Funkcja pomocnicza do wypisywania listy (dla test�w)
void wypiszListe(struct element* head) {
    struct element* current = head->next; // Pomijamy w�ze� g�owy
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
    // Tworzymy pust� list� z g�ow�
    struct element* Lista = utworz();
    if (Lista == NULL) {
        return 1; // Zako�czenie programu, je�li nie uda�o si� utworzy� listy
    }

    // Dodajemy kilka element�w do listy
    dodajNaPoczatek(Lista, 5);
    dodajNaPoczatek(Lista, 3);
    dodajNaPoczatek(Lista, 10);
    dodajNaPoczatek(Lista, 7);
    dodajNaPoczatek(Lista, 9);

    // Wypisujemy list�
    printf("Lista: ");
    wypiszListe(Lista);

    // Usuwamy list� z pami�ci
    usunListe(Lista);

    return 0;
}
