#include <iostream>
#include "Lab1.hpp"


using namespace lab1;

int main() 
{
    Array mass = {0, 0, 0, NULL};
    int ind;
    getRows(mass.m);
    getColumns(mass.n);
    while(Condition(ind) != 0)
    {
        ScanArray(&mass);
    }
    int* result = Criterium(mass);
    if(result == nullptr)
    {
        FreeMass(&mass);
    }
    else
    {
        PrintArray(mass);
        PrintResult(result, mass.m);
        delete[] result;
        result = nullptr;
        FreeMass(&mass);
    }
    return 0;
}