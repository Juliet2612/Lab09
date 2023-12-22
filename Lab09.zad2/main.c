#include <stdio.h>
#include <math.h>
#include <windows.h>

double calcY(int n, float x);

int main() {
    int n;
    float x;
    SetConsoleOutputCP(CP_UTF8);

    while (1) {
        printf("Podaj n (wpisz jedną liczbę, aby przerwać): ");
        scanf("%d", &n);

        if (n == 0) {
            printf("Koniec programu.\n");
            break;
        }
        printf("Podaj x: ");
        scanf("%f", &x);

        double wynik = calcY(n, x);
        printf("Wynik dla n=%d, x=%.2f: %.2f\n", n, x, wynik);
    }

    return 0;
}
double calcY(int n, float x) {
    if (n == 2)
        return pow(x, 2);
    else if (n == 1)
        return x;
    else if (n == 3)
        return exp(x);
    else if (n == 4)
        return 2 * x;
    else
        return 1.0;
}
