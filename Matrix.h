#include <iostream>
using namespace std;

template <typename T>
class MATRIX
{
    T** M;
    int m, n;

public:
    MATRIX();
    MATRIX(int x, int y);
    MATRIX operator=(const MATRIX& N);
    MATRIX operator+(const MATRIX& N);
    MATRIX operator*(int);
    MATRIX operator*(MATRIX& N);
    MATRIX operator&();

    int GetMij(int i, int j)
    {
        return M[i][j];
    }

    void SetMij(int i, int j, T z)
    {
        M[i][j] = z;
    }

    void Print()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "-----------------" <<endl;
    }
};

template<typename T>
MATRIX<T>::MATRIX()
{
    n = m = 0;
}

template<typename T>
MATRIX<T>::MATRIX(int x, int y)
{
    m = x;
    n = y;

    M = (T**) new T*[m];

    for (int i = 0; i < m; i++)
        M[i] = (T*) new T[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
}



template<typename T>
MATRIX<T> MATRIX<T>::operator=(const MATRIX& N)
{
    if (n > 0)
    {
        for (int i = 0; i < m; i++)
            delete[] M[i];
    }

    if (m > 0)
    {
        delete[] M;
    }

    m = N.m;
    n = N.n;

    M = (T**) new T*[m];
    for (int i = 0; i < m; i++)
        M[i] = (T*) new T[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = N.M[i][j];
    return *this;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator+(const MATRIX& N)
{
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] += N.M[i][j];
    return *this;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator*(int a)
{
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] *= a;
    return *this;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator*(MATRIX& N)
{
    MATRIX<T> K(m, N.n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < N.n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                K[i][j] += M[i][k] * N[k][j];
            }
        }
    }
    return K;
}