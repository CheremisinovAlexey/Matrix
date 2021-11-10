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
    MATRIX operator*(const MATRIX& N);
    MATRIX operator^(int i);
    MATRIX operator&();
    template<typename Type> friend ostream& operator<<(ostream&, const MATRIX<Type>&);
    template<typename Type> friend istream& operator>>(istream&, MATRIX<Type>&);

    const T* operator[](int i) const {return M[i];}
    T* operator[](int i)
    {
        return M[i];
    }

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
    double det()
    {
        double f, g;
        g = 1;
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                f = -M[i][k] / M[k][k];
                for (int j = 0; j < n; j++) {
                    M[i][j] += M[k][j] * f;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            g *= M[i][i];
        }
        return g;
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
    MATRIX<T> K(m, n);
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            K[i][j] = M[i][j];
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            K[i][j] += N[i][j];
    return K;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator*(int a)
{
    MATRIX<T> K(m, n);
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            K[i][j] = M[i][j];
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            K[i][j] *= a;
    return K;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator*(const MATRIX& N)
{
    MATRIX<T> K(m, N.n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < N.n; j++)
            K[i][j] = 0;
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

template<typename T>
MATRIX<T> MATRIX<T>::operator^(int i)
{
    MATRIX<T> K(m, n);
    MATRIX<T> N(m, n);
    for (int j = 0; j < m; j++)
        for (int k = 0; k < n; k++)
            K[j][k] = N[j][k] = M[j][k];
    for (int j = 0; j < i - 1; j++)
        K = K * N;
    return K;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator&()
{
    MATRIX<T> K(n, m);
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < n; ++ j)
            K[j][i] = M[i][j];
    return K;
}

template<typename T>
ostream& operator<<(ostream& out, const MATRIX<T>& N)
{
    for (int i = 0; i < N.m; i++)
    {
        for (int j = 0; j < N.n; j++)
            out << N[i][j];
    }
    return out;
}

template<typename T>
istream &operator>>(istream& in, MATRIX<T>& N)
{
    for (int i = 0; i < N.m; i++)
    {
        for (int j = 0; j < N.n; j++)
            in >> N[i][j];
    }
    return in;
}
