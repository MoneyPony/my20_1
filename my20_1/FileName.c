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
    printf("������� ���������� �����������: ");
    scanf("%d", &sotrCount);
    getchar();
    struct Sotr sotryd[100];
    for (int i = 0; i < sotrCount; ++i)
    {
        printf("\n������� ������ � ���������� %d:\n", i + 1);
        printf("�������: ");
        fgets(sotryd[i].fam, sizeof(sotryd->fam), stdin);
        printf("���: ");
        fgets(sotryd[i].name, sizeof(sotryd->name), stdin);
        printf("��������: ");
        fgets(sotryd[i].otv, sizeof(sotryd->otv), stdin);
        printf("���������: ");
        fgets(sotryd[i].dolg, sizeof(sotryd->dolg), stdin);
        printf("��������: ");
        scanf("%f", &sotryd[i].zp);
        getchar();
        printf("���� ��������:\n");
        printf("����: ");
        scanf("%d", &sotryd[i].day);
        getchar();
        printf("�����: ");
        scanf("%d", &sotryd[i].month);
        getchar();
        printf("���: ");
        scanf("%d", &sotryd[i].year);
        getchar();
    }
    printf("����������, ���������� � ���:\n");
    for (int i = 0; i < sotrCount; ++i)
    {
        if (sotryd[i].month == 5)
        {
            printf("�������: %s", sotryd[i].fam);
            printf("���: %s", sotryd[i].name);
            printf("��������: %s", sotryd[i].otv);
            printf("���������: %s", sotryd[i].dolg);
            printf("��������: %.2f\n", sotryd[i].zp);
            printf("���� ��������: %2d.%d.%4d", sotryd[i].day, sotryd[i].month, sotryd[i].year);
        }
    }
    WriteFile(sotryd, sotrCount);
    float average = Average("sotrydniki.txt");
    printf("������� �������������� �� �����: %f\n", average);
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
        fprintf(file, "�������: %s", sotryd[i].fam);
        fprintf(file, "���: %s", sotryd[i].name);
        fprintf(file, "��������: %s", sotryd[i].otv);
        fprintf(file, "���������: %s", sotryd[i].dolg);
        fprintf(file, "��������: %.2f\n", sotryd[i].zp);
        fprintf(file, "���� ��������: %2d.%d.%4d\n", sotryd[i].day, sotryd[i].month, sotryd[i].year);
        fprintf(file, "------------------------------------------------\n");
    }
    fclose(file);
    return 1;
}

float Average(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �������� ����� %s\n", filename);
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
        printf("� ����� ��� ����� ��� ���������� ��������\n");
    }
    return (float)sum / count;
}