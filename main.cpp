#include <iostream>
#include "matrix.h"
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int x, y, x1, y1;
    cout << "Какой тип переменных использовать?" << endl;
    cout << "1: int;    2: float" << endl;
    int p;
    cin >> p;
    if (p == 1) {
        cout << "Введите размер первой матрицы: " << endl;
        cin >> x >> y;
        cout << "Введите размер второй матрицы: " << endl;
        cin >> x1 >> y1;
        cout << "Введите первую матрицу: " << endl;
        MATRIX<int> A(x, y);
        MATRIX<int> B(x1, y1);

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                int h;
                cin >> h;
                A[i][j] = h;
            }
        }
        cout << "Введите вторую матрицу: " << endl;
        for (int i = 0; i < x1; i++) {
            for (int j = 0; j < y1; j++) {
                int h;
                cin >> h;
                B[i][j] = h;
            }
        }
        int s = 7;
        while (s != 0) {
            cout << "Какое действие произвести с матрицами?" << endl;
            cout
                    << "1. Сложить матрицы   2.Умножить матрицу(-ы) на число   3. Умножить первую матрицу на вторую   4. Транспонировать матрицу(-ы)   5. Возвести матрицу(-ы) в степень   6. Вычислить определители(-ь) матриц(-ы)   0. Завершить выполнение программы"
                    << endl;
            cin >> s;
            if (s == 1) {
                if (x != x1 || y != y1) {
                    cerr << "Размеры матриц не равны" << endl;
                } else {
                    MATRIX<int> M = A + B;
                    M.Print();
                }
            } else if (s == 2) {
                cout << "Какие матрицу умножить?" << endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else
                        cout << "Введите число от 1 до 3" << endl;
                }
                if (h == 1) {
                    int o;
                    cout << "Введите число, на которое нужно умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<int> A1 = A * o;
                    A1.Print();
                }
                if (h == 2) {
                    int o;
                    cout << "Введите число, на которое нужно умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<int> B1 = B * o;
                    B1.Print();
                }
                if (h == 3) {
                    int o1, o2;
                    cout << "Введите числа, на которое нужно умножить матрицы: " << endl;
                    cin >> o1 >> o2;
                    MATRIX<int> A1 = A * o1;
                    MATRIX<int> B1 = B * o2;
                    A1.Print();
                    B1.Print();
                }
            } else if (s == 3) {
                if (x1 != y) {
                    cerr << "Матрицы должны быть размера m*n и n*k" << endl;
                } else {
                    MATRIX<int> M = A * B;
                    M.Print();
                }
            } else if (s == 4) {
                cout << "Какие матрицы транспонировать" << endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else
                        cout << "Введите число от 1 до 3" << endl;
                }
                if (h == 1) {
                    MATRIX<int> A1 = &A;
                    A1.Print();
                }
                if (h == 2) {
                    MATRIX<int> B1 = &B;
                    B1.Print();
                }
                if (h == 3) {
                    MATRIX<int> A1 = &A;
                    MATRIX<int> B1 = &B;
                    A1.Print();
                    B1.Print();
                }
            } else if (s == 5) {
                cout << "Какие матрицы возвести в степень?" << endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else
                        cout << "Введите число от 1 до 3" << endl;
                }
                if (h == 1) {
                    if (x != y)
                    {
                        cerr << "Матрица должна быть размера m*m" << endl;
                    }
                    else {
                        int o;
                        cout << "Введите число, в которое нужно возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<int> A1 = A ^ o;
                        A1.Print();
                    }
                }
                if (h == 2) {
                    if (x1 != y1) {
                        cerr << "Матрица должна быть размера m*m" << endl;
                    } else {
                        int o;
                        cout << "Введите число, в которое нужно возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<int> B1 = B ^ o;
                        B1.Print();
                    }
                }
                if (h == 3) {
                    if (x != y || x1 != y1) {
                        cerr << "Матрицы должны быть размера m*m и n*n" << endl;
                    } else {
                        int o1, o2;
                        cout << "Введите число, в которое нужно возвести матрицу: " << endl;
                        cin >> o1 >> o2;
                        MATRIX<int> A1 = A ^ o1;
                        MATRIX<int> B1 = B ^ o2;
                        A1.Print();
                        B1.Print();
                    }
                }
            }
            else if (s == 6)
            {
                cout << "У каких матриц вычислить определитель?" << endl;
                cout << "1. У первой матрицы    2. У второй матрицы    3. У обеих матриц" << endl;
                int h = 0;
                int q = 0;
                while (q != 1)
                {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3)
                    {
                        q = 1;
                    }
                    else cout << "Введите число от 1 до 3" << endl;
                }
                if (h == 1)
                {
                    if (x != y)
                    {
                        cerr << "Матрица должна быть размера m*m" << endl;
                    }
                    else {
                        int d = A.det();
                        cout << "Определитель первой матрицы: " << d << endl;
                    }
                }
                else if (h == 2)
                {
                    if (x1 != y1)
                    {
                        cerr << "Матрица должна быть размера m*m" << endl;
                    }
                    else {
                        int d1 = B.det();
                        cout << "Определитель второй матрицы: " << d1 << endl;
                    }
                }
                else
                {
                    if (x != y || x1 != y1)
                    {
                        cerr << "Матрицы должны быть размеров m*m и n*n" << endl;
                    }
                    else {
                        int d = A.det();
                        cout << "Определитель первой матрицы: " << d << endl;
                        int d1 = B.det();
                        cout << "Определитель второй матрицы: " << d1 << endl;
                    }
                }
            }
            else {
                if (s != 0)
                    cerr << "Введите число от 0 до 6" << endl;
            }
        }
    }
    else
    {
        cout << "Введите размер первой матрицы: " << endl;
        cin >> x >> y;
        cout << "Введите размер второй матрицы: " << endl;
        cin >> x1 >> y1;
        cout << "Введите первую матрицу: " << endl;
        MATRIX<float> A(x, y);
        MATRIX<float> B(x1, y1);

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                float h;
                cin >> h;
                A[i][j] = h;
            }
        }
        cout << "Введите вторую матрицу: " <<endl;
        for (int i = 0; i < x1; i++)
        {
            for (int j = 0; j < y1; j++)
            {
                float h;
                cin >> h;
                B[i][j] = h;
            }
        }
        int s = 7;
        while (s != 0)
        {
            cout << "Какое действие произвести с матрицами?" <<endl;
            cout << "1. Сложить матрицы   2.Умножить матрицу(-ы) на число   3. Умножить первую матрицу на вторую   4. Транспонировать матрицу(-ы)   5. Возвести матрицу(-ы) в степень   6. Вычислить определители(-ь) матриц(-ы)   0. Завершить выполнение программы" <<endl;
            cin >> s;
            if (s == 1)
            {
                if (x != x1 || y != y1)
                {
                    cerr << "Размеры матриц не равны" <<endl;
                }
                else
                {
                    MATRIX<float> M = A + B;
                    M.Print();
                }
            }
            else if (s == 2)
            {
                cout << "Какие матрицу умножить?" << endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" << endl;
                int h = 0;
                int q = 0;
                while ( q != 1)
                {
                    cin>>h;
                    if (h == 1 || h == 2 || h == 3)
                    {
                        q = 1;
                    }
                    else
                        cout << "Введите число от 1 до 3" <<endl;
                }
                if (h == 1) {
                    float o;
                    cout << "Введите число, на которое нужно умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<float> A1 = A * o;
                    A1.Print();
                }
                if (h == 2) {
                    float o;
                    cout << "Введите число, на которое нужно умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<float> B1 = B * o;
                    B1.Print();
                }
                if (h == 3) {
                    float o1, o2;
                    cout << "Введите числа, на которые нужно умножить матрицы: " << endl;
                    cin >> o1 >> o2;
                    MATRIX<float> A1 = A * o1;
                    MATRIX<float> B1 = B * o2;
                    A1.Print();
                    B1.Print();
                }
            }
            else if (s == 3)
            {
                if (x1 != y)
                {
                    cerr << "Матрицы должны быть размера m*n и n*k" <<endl;
                }
                else
                {
                    MATRIX<float> M = A * B;
                    M.Print();
                }
            }
            else if (s == 4)
            {
                cout << "Какие матрицы транспонировать" << endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" << endl;
                int h = 0;
                int q = 0;
                while ( q != 1)
                {
                    cin>>h;
                    if (h == 1 || h == 2 || h == 3)
                    {
                        q = 1;
                    }
                    else
                        cout << "Введите число от 1 до 3" <<endl;
                }
                if (h == 1) {
                    MATRIX<float> A1 = &A;
                    A1.Print();
                }
                if (h == 2) {
                    MATRIX<float> B1 = &B;
                    B1.Print();
                }
                if (h == 3) {
                    MATRIX<float> A1 = &A;
                    MATRIX<float> B1 = &B;
                    A1.Print();
                    B1.Print();
                }
            }
            else if (s == 5)
            {
                cout << "Какие матрицы возвести в степень?" << endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" << endl;
                int h = 0;
                int q = 0;
                while ( q != 1)
                {
                    cin>>h;
                    if (h == 1 || h == 2 || h == 3)
                    {
                        q = 1;
                    }
                    else
                        cout << "Введите число от 1 до 3" <<endl;
                }
                if (h == 1) {
                    if (x != y)
                    {
                        cerr << "Матрица должна быть размера m*m" <<endl;
                    }
                    else
                    {
                        int o;
                        cout << "Введите число, в которое нужно возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<float> A1 = A ^ o;
                        A1.Print();
                    }
                }
                if (h == 2) {
                    if (x1 != y1)
                    {
                        cerr << "Матрица должна быть размера m*m" <<endl;
                    }
                    else
                    {
                        int o;
                        cout << "Введите число, в которое нужно возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<float> B1 = B ^ o;
                        B1.Print();
                    }
                }
                if (h == 3)
                {
                    if (x != y || x1 != y1)
                    {
                        cerr << "Матрицы должны быть размера m*m и n*n" <<endl;
                    }
                    else
                    {
                        int o1, o2;
                        cout << "Введите числа, в которые нужно возвести матрицы: " << endl;
                        cin >> o1 >> o2;
                        MATRIX<float> A1 = A ^ o1;
                        MATRIX<float> B1 = B ^ o2;
                        A1.Print();
                        B1.Print();
                    }
                }
            }
            else if (s == 6) {

                cout << "У каких матриц вычислить определитель?" << endl;
                cout << "1. У первой матрицы    2. У второй матрицы    3. У обеих матриц" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else cout << "Введите число от 1 до 3" << endl;
                }
                if (h == 1) {
                    if (x != y) {
                        cerr << "Матрица должна быть размера m*m" << endl;
                    } else {
                        double d = A.det();
                        cout << "Определитель первой матрицы: " << d << endl;
                    }
                } else if (h == 2) {
                    if (x1 != y1) {
                        cerr << "Матрица должна быть размера m*m" << endl;
                    } else {
                        double d1 = B.det();
                        cout << "Определитель второй матрицы: " << d1 << endl;
                    }
                } else {
                    if (x != y || x1 != y1) {
                        cerr << "Матрицы должны быть размеров m*m и n*n" << endl;
                    } else {
                        double d = A.det();
                        cout << "Определитель первой матрицы: " << d << endl;
                        double d1 = B.det();
                        cout << "Определитель второй матрицы: " << d1 << endl;
                    }
                }
            }
            else
            {
                if (s != 0)
                    cerr << "Введите число от 0 до 6" <<endl;
            }
        }
    }
}
