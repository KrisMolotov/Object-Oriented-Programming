#ifndef LAB1_H
#define LAB1_H

namespace lab1
{
    struct Column
    {
        int x;
        int y;
        int number;
        Column* next;
    };

    struct Row
    {
        int x;
        int y;
        int number;
        Row* nextR;
        Column* nextC;
    };

    struct Array
    {
        int m; // число строк
        int n; // число столбцов
        int count; // текущее число элементов в матрице
        Row* arr;
    };

    int getRows(int &a);
    int getColumns(int &a);
    int getElem(int &a);
    int getX(int &a);
    int getY(int &a);
    int ScanArray(Array* t);
    int SearchForAddElement(Array t, Row temp);
    int AddElem(Array* t, Row* temp);
    int* Criterium(Array t);
    int Sum(int a);
    void PrintArray(Array t);
    void PrintResult(int* res, int size);
    void FreeMass(Array* t);
    int Condition(int &a);

    const char *error_message[] = {"Done.", "This cell is already busy", "The matrix is empty"};
}

#endif