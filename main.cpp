#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    MATRIX<int> M(2, 2);
    M.Print();

    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            M.SetMij(i, j, i + j);

    M.Print();

    MATRIX<int> M2 = M;
    M2.Print();
    MATRIX<int> M3(2, 2);
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            M3.SetMij(i, j, 2);
    M3.Print();
}