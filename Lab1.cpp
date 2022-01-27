#include "Lab1.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace lab1;

int getRows(int &a)
{
    cout << "Enter the number of rows, please" << endl;
    do
    {
        cin >> a;
        if(!cin.good())
        {
            cout << "Enter the correct symbol" << endl;
        }
    } while (!cin.good());

    if(a == 0)
    {
        while(a == 0)
        {
            cout << "Zero is unavailable for size" << endl;
            cin.clear();
            cin >> a;
        }
    }
    else if(a < 0)
    {
        while(a < 0)
        {
            cout << "Size can not be negative" << endl;
            cin.clear();
            cin >> a;
        }
    }
    cin.clear();
    return 1;
}

int getColumns(int &a)
{

    cout << "Enter the number of columns, please" << endl;
    do
    {
        cin >> a;
        if(!cin.good())
        {
            cout << "Enter the correct symbol" << endl;
        }
    } while (!cin.good());

    if(a == 0)
    {
        while(a == 0)
        {
            cout << "Zero is unavailable for size" << endl;
            cin.clear();
            cin >> a;
        }
    }
    else if(a < 0)
    {
        while(a < 0)
        {
            cout << "Size can not be negative" << endl;
            cin.clear();
            cin >> a;
        }
    }
    cin.clear();
    return 1;
}

int getElem(int &a)
{

    cout << "Enter the element, please" << endl;
    do
    {
        cin >> a;
        if(!cin.good())
        {
            cout << "Enter the correct symbol" << endl;
        }
    } while (!cin.good());
    if(a == 0)
    {
        while(a == 0)
        {
            cout << "Zero is unavailable for element" << endl;
            cin.clear();
            cin >> a;
        }
    }
    cin.clear();
    return 1;
}

int Condition(int &a)
{
    cout << "Do you want to add element?" << endl;
    cin >> a;
    if(a == 0)
    {
        return 0;
    }
    return 1;
}

int getX(int &a)
{

    cout << "Enter the X coordinate, please" << endl;
    do
    {
        cin >> a;
        if(!cin.good())
        {
            cout << "Enter the correct symbol" << endl;
        }
    } while (!cin.good());
    if(a < 0)
    {
        while(a < 0)
        {
            cout << "X can not be negative" << endl;
            cin.clear();
            cin >> a;
        }
    }
    cin.clear();
    return 1;
}

int getY(int &a)
{

    cout << "Enter the Y coordinate, please" << endl;
    do
    {
        cin >> a;
        if(!cin.good())
        {
            cout << "Enter the correct symbol" << endl;
        }
    } while (!cin.good());
    if(a < 0)
    {
        while(a < 0)
        {
            cout << "Y can not be negative" << endl;
            cin.clear();
            cin >> a;
        }
    }
    cin.clear();
    return 1;
}

int ScanArray(Array* t)
{
    int ind;
    Row* temp = new Row;
    getX(temp->x);
    getY(temp->y);
    getElem(temp->number);
    ind = SearchForAddElement(*t, *temp);
    if(ind == -1)
    {
        return 1;
    }
    AddElem(t, temp);
    t->count += 1;
    delete temp;
    temp = nullptr;
    return 1;
}

int SearchForAddElement(Array t, Row temp)
{
    while(t.arr != nullptr)
    {
        if(t.arr->y == temp.y)
        {
            if(t.arr->x == temp.x)
            {
                if(t.arr->number == 0)
                {
                    return 1;
                }
                cout << error_message[1] << endl;
                return -1;
            }
            Column* dop = t.arr->nextC;
            while(dop != nullptr)
            {
                if(dop->x == temp.x)
                {
                    cout << error_message[1] << endl;
                    dop = nullptr;
                    return -1;
                }
                dop = dop->next;
            }
            dop = nullptr;
        }
        t.arr = t.arr->nextR;
    }
    return 1;
}

int AddElem(Array* t, Row* temp)
{   
    if(t->arr == NULL)
    {
        if(temp->x == 0 && temp->y == 0)
        {
            t->arr = new Row;
            t->arr->x = 0;
            t->arr->y = 0;
            t->arr->number = temp->number;
            t->arr->nextR = nullptr;
            t->arr->nextC = nullptr;
            return 1;
        }
        else if(temp->x == 0 && temp->y !=0)
        {
            t->arr = new Row;
            t->arr->x = 0;
            t->arr->y = 0;
            t->arr->number = 0;
            t->arr->nextC = nullptr;
            t->arr->nextR = new Row;
            t->arr->nextR->number = temp->number;
            t->arr->nextR->x = temp->x;
            t->arr->nextR->y = temp->y;
            t->arr->nextR->nextR = nullptr;
            t->arr->nextR->nextC = nullptr;
            return 1;
        }
        else if(temp->y == 0 && temp->x !=0)
        {
            t->arr = new Row;
            t->arr->x = 0;
            t->arr->y = 0;
            t->arr->number = 0;
            t->arr->nextR = nullptr;
            t->arr->nextC = new Column;
            t->arr->nextC->number = temp->number;
            t->arr->nextC->x = temp->x;
            t->arr->nextC->y = temp->y;
            t->arr->nextC->next = nullptr;
            return 1;
        }
        else if(temp->x != 0 && temp->y!= 0)
        {
            t->arr = new Row;
            t->arr->x = 0;
            t->arr->y = 0;
            t->arr->number = 0;
            t->arr->nextC = nullptr;
            t->arr->nextR = new Row;
            t->arr->nextR->number = 0;
            t->arr->nextR->x = 0;
            t->arr->nextR->y = temp->y;
            t->arr->nextR->nextR = nullptr;
            t->arr->nextR->nextC = new Column;
            t->arr->nextR->nextC->number = temp->number;
            t->arr->nextR->nextC->x = temp->x;
            t->arr->nextR->nextC->y = temp->y;
            t->arr->nextR->nextC->next = nullptr;
            return 1;
        }
    }
    if(temp->y == t->arr->y)
    {
        if(temp->x == t->arr->x)
        {
            t->arr->number = temp->number;
            return 1;
        }
        if(t->arr->nextC == nullptr)
        {
            t->arr->nextC = new Column;
            t->arr->nextC->number = temp->number;
            t->arr->nextC->x = temp->x;
            t->arr->nextC->y = temp->y;
            t->arr->nextC->next = nullptr;
            return 1;
        }
        if(temp->x < t->arr->nextC->x)
        {
            Column* dop = t->arr->nextC;
            Column* elem = new Column;
            elem->number = temp->number;
            elem->x = temp->x;
            elem->y = temp->y;
            t->arr->nextC = elem;
            elem->next = dop;
            return 1;
        }
        Column* dop1 = t->arr->nextC;
        while(dop1->next != nullptr)
        {
            if(temp->x < dop1->next->x)
            {
                Column* dop2 = dop1->next;
                Column* elem = new Column;
                elem->number = temp->number;
                elem->x = temp->x;
                elem->y = temp->y;
                dop1->next = elem;
                elem->next = dop2;
                return 1;
            }   
            dop1 = dop1->next;
        }
        dop1->next = new Column;
        dop1->next->number = temp->number;
        dop1->next->x = temp->x;
        dop1->next->y = temp->y;
        dop1->next->next = nullptr;
        return 1;
    }
    else
    {
        if(t->arr->nextR == nullptr)
        {
            t->arr->nextR = new Row;
            t->arr->nextR->number = 0;
            t->arr->nextR->y = temp->y;
            t->arr->nextR->x = 0;
            t->arr->nextR->nextC = nullptr;
            t->arr->nextR->nextR = nullptr;
            Row* abc = t->arr->nextR;
            if(temp->x == abc->x)
            {
                abc->number = temp->number;
                return 1;
            }
            else
            {
                abc->nextC = new Column;
                abc->nextC->number = temp->number;
                abc->nextC->x = temp->x;
                abc->nextC->y = temp->y;
                abc->nextC->next = nullptr;
                return 1;
            }
        }
        if(temp->y < t->arr->nextR->y)
        {
            Row* a = t->arr->nextR;
            Row* b = new Row;
            b->number = 0;
            b->x = 0;
            b->y = temp->y;
            t->arr->nextR = b;
            b->nextR = a;
            b->nextC = nullptr;
            if(temp->x == b->x)
            {
                b->number = temp->number;
                return 1;
            }
            else
            {
                b->nextC = new Column;
                b->nextC->number = temp->number;
                b->nextC->x = temp->x;
                b->nextC->y = temp->y;
                b->nextC->next = nullptr;
                return 1;
            }
        }
        if(temp->y == t->arr->nextR->y)
        {
            if(temp->x == t->arr->nextR->x)
            {
                t->arr->nextR->number = temp->number;
                return 1;
            }
            if(t->arr->nextR->nextC == nullptr)
            {
                t->arr->nextR->nextC = new Column;
                t->arr->nextR->nextC->number = temp->number;
                t->arr->nextR->nextC->x = temp->x;
                t->arr->nextR->nextC->y = temp->y;
                t->arr->nextR->nextC->next = nullptr;
                return 1;
            }
            if(temp->x < t->arr->nextR->nextC->x)
            {
                Column* dop = t->arr->nextR->nextC;
                Column* elem = new Column;
                elem->number = temp->number;
                elem->x = temp->x;
                elem->y = temp->y;
                t->arr->nextR->nextC = elem;
                elem->next = dop;
                return 1;
            }
            Column* dop1 = t->arr->nextR->nextC;
            while(dop1->next != nullptr)
            {
                if(temp->x < dop1->next->x)
                {
                    Column* dop2 = dop1->next;
                    Column* elem = new Column;
                    elem->number = temp->number;
                    elem->x = temp->x;
                    elem->y = temp->y;
                    dop1->next = elem;
                    elem->next = dop2;
                    return 1;
                }   
                dop1 = dop1->next;
            }
            dop1->next = new Column;
            dop1->next->number = temp->number;
            dop1->next->x = temp->x;
            dop1->next->y = temp->y;
            dop1->next->next = nullptr;
            return 1;
        }
        Row* c = t->arr->nextR;
        while(c->nextR != nullptr)
        {
            if(temp->y < c->nextR->y)
            {
                Row* a = c->nextR;
                Row* b = new Row;
                b->number = 0;
                b->x = 0;
                b->y = temp->y;
                c->nextR = b;
                b->nextR = a;
                b->nextC = nullptr;
                if(temp->x == b->x)
                {
                    b->number = temp->number;
                    return 1;
                }
                else
                {
                    b->nextC = new Column;
                    b->nextC->number = temp->number;
                    b->nextC->x = temp->x;
                    b->nextC->y = temp->y;
                    b->nextC->next = nullptr;
                    return 1;
                }
            }
            c = c->nextR;
        }
        if(temp->y != c->y)
        {
            c->nextR = new Row;
            c->nextR->number = 0;
            c->nextR->x = 0;
            c->nextR->y = temp->y;
            c->nextR->nextR = nullptr;
            c->nextR->nextC = nullptr;
             Row* b = c->nextR;
            if(temp->x == b->x)
            {
                b->number = temp->number;
                return 1;
            }
            else
            {
                b->nextC = new Column;
                b->nextC->number = temp->number;
                b->nextC->x = temp->x;
                b->nextC->y = temp->y;
                b->nextC->next = nullptr;
                return 1;
            }
        }
        else if(temp->y == c->y)
        {
            Row* b = c;
            if(temp->x == b->x)
            {
                b->number = temp->number;
                return 1;
            }
            else
            {
                b->nextC = new Column;
                b->nextC->number = temp->number;
                b->nextC->x = temp->x;
                b->nextC->y = temp->y;
                b->nextC->next = nullptr;
                return 1;
            }
        }
    }
    return 1;
}

int* Criterium(Array t)
{
    int* result = new int[t.m];
    int sum1 = 0, sumMid = 0, sum2 = 0;
    Column* dop;
    if(t.arr == nullptr)
    {
        cout << error_message[2] << endl;
        return nullptr;
    }
    for(int i = 0; i < t.m; ++i)
    {
        if((t.arr) && (t.arr->y == i))
        {
            int elem = t.arr->number;
            sum1 = Sum(elem);
            dop = t.arr->nextC;
            while(dop != nullptr)
            {
                sumMid = Sum(dop->number);
                if(sumMid == sum1)
                {
                    sum2 += sumMid;
                }
                dop = dop->next;
            }
            *(result + i) = sum2;
            t.arr = t.arr->nextR;
            sum2 = 0;
        }
        else
        {
            *(result + i) = 0;
        }
    }
    dop = nullptr;
    return result;
}

int Sum(int a)
{
    int sum = 0;
    while(a != 0)
    {
        sum += a%10;
        a /= 10;
    }
    return sum;
}

void PrintArray(Array t)
{
    if(t.arr != nullptr)
    {
        Column* dop;
        cout << "Original array:" << endl;
        for(int i = 0; i < t.m; ++i)
        {
            if((t.arr) && (t.arr->y == i))
            {
                cout << t.arr->number << " ";
                dop = t.arr->nextC;
                for(int j = 1; j < t.n; ++j)
                {
                    if((dop) && dop->x == j)
                    {
                        cout << dop->number << " ";
                        dop = dop->next;
                    }
                    else
                    {
                        cout << 0 << " ";
                    }
                }
                cout << endl;
                t.arr = t.arr->nextR;
            }
            else
            {
                for (int j = 0; j < t.n; ++j)
                {
                    cout << 0 << " ";
                }
                cout << endl;
            }
        }
        dop = nullptr;
    }
    else
    {
        cout << error_message[2] << endl;
    }
}

void PrintResult(int* res, int size)
{
    cout << "The result vector:" << endl;
    for(int i = 0; i < size; ++i)
    {
        cout << *(res + i) << " ";
    }
    cout << endl;
}

void FreeMass(Array* t)
{
    if(t->arr != nullptr)
    {
        Row* dop = t->arr;
        while(dop != nullptr)
        {
            Column* extra = dop->nextC;
            while(extra != nullptr)
            {
                Column* temp = extra->next;
                delete extra;
                extra = temp;
            }
            Row* ttm = dop->nextR;
            delete dop;
            dop = ttm;
        }
    }
    t->arr->nextR = nullptr;
    t->arr->nextC = nullptr;
    t->arr = nullptr;
}




