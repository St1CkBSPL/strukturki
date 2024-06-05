#include <stdio.h>
#include <stdlib.h>

// Definicja struktury elementu listy
typedef struct Element {
    int value;
    struct Element* next;
} Element;

// Funkcja tworz¹ca nowy element listy
Element* createElement(int value) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (!newElement) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newElement->value = value;
    newElement->next = NULL;
    return newElement;
}

// Funkcja ³¹cz¹ca dwie listy naprzemiennie
Element* mergeLists(Element* list1, Element* list2) {
    // Sprawdzenie, czy listy s¹ pustymi wskaŸnikami
    if (!list1 || !list2) {
        return NULL;
    }

    Element* mergedHead = NULL;
    Element* mergedTail = NULL;

    while (list1 && list2) {
        // Dodanie elementu z listy pierwszej
        if (!mergedHead) {
            mergedHead = list1;
            mergedTail = list1;
        } else {
            mergedTail->next = list1;
            mergedTail = mergedTail->next;
        }
        list1 = list1->next;

        // Dodanie elementu z listy drugiej
        mergedTail->next = list2;
        mergedTail = mergedTail->next;
        list2 = list2->next;
    }

    return mergedHead;
}

// Funkcja do wypisywania listy
void printList(Element* head) {
    Element* current = head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Funkcja testuj¹ca
int main() {
    // Tworzenie pierwszej listy
    Element* list1 = createElement(1);
    list1->next = createElement(3);
    list1->next->next = createElement(5);

    // Tworzenie drugiej listy
    Element* list2 = createElement(2);
    list2->next = createElement(4);
    list2->next->next = createElement(6);

    // £¹czenie list naprzemiennie
    Element* mergedList = mergeLists(list1, list2);

    // Wypisanie po³¹czonej listy
    printList(mergedList);

    // Zwolnienie pamiêci (dla uproszczenia pominiête)

    return 0;
}
