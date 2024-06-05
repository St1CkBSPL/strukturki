#include <stdio.h>

void wypelnijZerami(int tablica[][4], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tablica[i][j] = 0;
        }
    }
}

int main() {
    int n = 3; // przyk³adowa liczba wierszy
    int m = 4; // przyk³adowa liczba kolumn
    int tablica[n][m];

    // Wype³nij tablicê zerami
    wypelnijZerami(tablica, n, m);

    // Wydrukuj tablicê dla celów demonstracyjnych
    printf("Tablica wypelniona zerami:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }

    return 0;
}
