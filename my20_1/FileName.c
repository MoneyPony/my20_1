#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Sotr
{
    char fam[50];
    char name[50];
    char otv[50];
    char dolg[50];
    float zp;
    int day;
    int month;
    int year;
};

int WriteFile(struct Sotr* sotryd, int sotrCount);
float Average(const char* filename);

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");
    int sotrCount;
    printf("Введите количество сотрудников: ");
    scanf("%d", &sotrCount);
    getchar();
    struct Sotr sotryd[100];
    for (int i = 0; i < sotrCount; ++i)
    {
        printf("\nВведите данные о сотруднике %d:\n", i + 1);
        printf("Фамилия: ");
        fgets(sotryd[i].fam, sizeof(sotryd->fam), stdin);
        printf("Имя: ");
        fgets(sotryd[i].name, sizeof(sotryd->name), stdin);
        printf("Отчество: ");
        fgets(sotryd[i].otv, sizeof(sotryd->otv), stdin);
        printf("Должность: ");
        fgets(sotryd[i].dolg, sizeof(sotryd->dolg), stdin);
        printf("Зарплата: ");
        scanf("%f", &sotryd[i].zp);
        getchar();
        printf("Дата рождения:\n");
        printf("День: ");
        scanf("%d", &sotryd[i].day);
        getchar();
        printf("Месяц: ");
        scanf("%d", &sotryd[i].month);
        getchar();
        printf("Год: ");
        scanf("%d", &sotryd[i].year);
        getchar();
    }
    printf("Сотрудники, родившиеся в мае:\n");
    for (int i = 0; i < sotrCount; ++i)
    {
        if (sotryd[i].month == 5)
        {
            printf("Фамилия: %s", sotryd[i].fam);
            printf("Имя: %s", sotryd[i].name);
            printf("Отчество: %s", sotryd[i].otv);
            printf("Должность: %s", sotryd[i].dolg);
            printf("Зарплата: %.2f\n", sotryd[i].zp);
            printf("Дата рождения: %2d.%d.%4d", sotryd[i].day, sotryd[i].month, sotryd[i].year);
        }
    }
    WriteFile(sotryd, sotrCount);
    float average = Average("sotrydniki.txt");
    printf("Среднее арифметическое из файла: %f\n", average);
}

int WriteFile(struct Sotr* sotryd, int sotrCount)
{
    FILE* file = fopen("sotrydniki.txt", "w");
    if (file == NULL)
    {
        return 0;
    }
    for (int i = 0; i < sotrCount; ++i)
    {
        fprintf(file, "Фамилия: %s", sotryd[i].fam);
        fprintf(file, "Имя: %s", sotryd[i].name);
        fprintf(file, "Отчество: %s", sotryd[i].otv);
        fprintf(file, "Должность: %s", sotryd[i].dolg);
        fprintf(file, "Зарплата: %.2f\n", sotryd[i].zp);
        fprintf(file, "Дата рождения: %2d.%d.%4d\n", sotryd[i].day, sotryd[i].month, sotryd[i].year);
        fprintf(file, "------------------------------------------------\n");
    }
    fclose(file);
    return 1;
}

float Average(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла %s\n", filename);
    }
    int sum = 0;
    int count = 0;
    int number;
    while (fscanf(file, "%*[^0123456789-]%d", &number) == 1) {
        sum += number;
        count++;
    }
    fclose(file);
    if (count == 0) {
        printf("В файле нет чисел для вычисления среднего\n");
    }
    return (float)sum / count;
}