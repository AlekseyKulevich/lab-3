#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void dynamic_array_alloc(int*** mas)
{
 (*mas) = (int**)malloc(8 * sizeof(int*));
    for (int i = 0; i < 8; i++) {
        (*mas)[i] = (int*)malloc(8 * sizeof(int));
    }
    if (!(*mas)) {
        printf("Error with memory");

    }
}

void dynamic_array_free(int** mas, int n)
{
    for (int i = 0; i < n; i++) {
        free(mas[i]);
    }
}

int** coordinates(int** mas)
{
    int num, n, m;

    printf("Введите координаты короля");
    {
        while (!scanf_s("%d", &n) || n > 8 || n < 0)
        {
            printf("Введите допустимое число\n");
            rewind(stdin);
        }
        while (!scanf_s("%d", &m) || m > 8 || m < 0)
        {
            printf("Введите допустимое число\n");
            rewind(stdin);
        }
        mas[n][m] = 1;
    }
    

    printf("Введите кол-во ферзей");
    while (!scanf_s("%d", &num) || num > 64 || num < 0)
    {
        printf("Введите допустимое число\n");
        rewind(stdin);
    }
    for (int i = 0; i < num; i++) {
        printf("Введите координаты %d ферзя", i + 1);
        while (!scanf_s("%d", &n) || n > 8 || n < 0)
        {
            printf("Введите допустимое число\n");
            rewind(stdin);
        }
        while (!scanf_s("%d", &m) || m > 8 || m < 0)
        {
            printf("Введите допустимое число\n");
            rewind(stdin);
        }
        mas[n][m] = 2;
    }
    return mas;
}

void fight(int** mas) {
    int p, q;
    int n = 8;
    int m = 8;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mas[i][j] == 1) {
                q = i;
                p = j;
            }
        }
    }
    for (int i = q; i >= 0; i--) {
        if (mas[i][p] == 2) {
            printf("Король под угрозой от ферзя [%d][%d]", i + 1, p + 1); break;
        }
    }
    for (int i = q; i < n; i++) {
        if (mas[i][p] == 2) { printf("Король под угрозой от ферзя [%d][%d]", i + 1, p + 1); break; }
    }
    for (int j = p; j >= 0; j--) {
        if (mas[q][j] == 2) { printf("Король под угрозой от ферзя [%d][%d]", q + 1, j + 1); break; }
    }
    for (int j = p; j < n; j++) {
        if (mas[q][j] == 2) { printf("Король под угрозой от ферзя [%d][%d]", q + 1, j + 1); break; }
    }

    for (int i = q, j = p; (i >= 0 && j >= 0); (i-- && j--)) {
        if (mas[i][j] == 2) { printf("Король под угрозой от ферзя [%d][%d]", i + 1, j + 1); break; }
    }
    for (int i = q, j = p; (i < n && j < n); (i++ && j++)) {
        if (mas[i][j] == 2) { printf("Король под угрозой от ферзя [%d][%d]", i + 1, j + 1); break; }
    }
    for (int i = q, j = p; (i >= 0 && j < n); (i-- && j++)) {
        if (mas[i][j] == 2) { printf("Король под угрозой от ферзя [%d][%d]", i + 1, j + 1); break; }
    }
    for (int i = q, j = p; (i < n && j >= 0); (i++ && j--)) {
        if (mas[i][j] == 2) { printf("Король под угрозой от ферзя [%d][%d]", i + 1, j + 1); break; }
    }
}


int main()
{
    setlocale(LC_ALL, ".1251"); 
    int n=8, m=8;
    int** mas;
    dynamic_array_alloc(&mas);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mas[i][j] = 0;
        }
    }
    coordinates(mas);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", mas[i][j]);
        }
        printf("\n");
    }
    fight(mas);
    dynamic_array_free(mas, 8);
    
    getchar();
    return 0;
}