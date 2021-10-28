#include <iostream>
#include "matrix.h"
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int x, y, x1, y1;
    cout << "Какого типа будут переменные?" << endl;
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
            cout << "Какую операцию провести с данными матрицами?" << endl;
            cout
                    << "1. Сложить матрицы  2. Умножить матрицу(-ы) на число  3. Перемножить матрицы  4. Трансопнировать матрицу(-ы)  5. Возвести матрицу(-ы) в степень  0. Завершить выполнение программы"
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
                cout << "Какие матрицы умножить?" << endl;
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
                    cout << "Введите, на какое число умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<int> A1 = A * o;
                    A1.Print();
                }
                if (h == 2) {
                    int o;
                    cout << "Введите, на какое число умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<int> B1 = B * o;
                    B1.Print();
                }
                if (h == 3) {
                    int o1, o2;
                    cout << "Введите, на какие числа умножить матрицы: " << endl;
                    cin >> o1 >> o2;
                    MATRIX<int> A1 = A * o1;
                    MATRIX<int> B1 = B * o2;
                    A1.Print();
                    B1.Print();
                }
            } else if (s == 3) {
                if (x1 != y) {
                    cerr << "Перемножать можно только матрицы размера m*n и n*k" << endl;
                } else {
                    MATRIX<int> M = A * B;
                    M.Print();
                }
            } else if (s == 4) {
                cout << "Какие матрицы транспонировать?" << endl;
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
                cout << "Какие матрицы возвести в степени?" << endl;
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
                    if (x != y) {
                        cerr << "Возводить в степени можно только квадратные матрицы" << endl;
                    } else {
                        int o;
                        cout << "Введите, в какую степень возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<int> A1 = A ^ o;
                        A1.Print();
                    }
                }
                if (h == 2) {
                    if (x1 != y1) {
                        cerr << "Возводить в степени можно только квадратные матрицы" << endl;
                    } else {
                        int o;
                        cout << "Введите, в какую степень возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<int> B1 = B ^ o;
                        B1.Print();
                    }
                }
                if (h == 3) {
                    if (x != y || x1 != y1) {
                        cerr << "Возводить в степени можно только квадратные матрицы" << endl;
                    } else {
                        int o1, o2;
                        cout << "Введите, в какие степени возвести матрицы: " << endl;
                        cin >> o1 >> o2;
                        MATRIX<int> A1 = A ^ o1;
                        MATRIX<int> B1 = B ^ o2;
                        A1.Print();
                        B1.Print();
                    }
                }
            } else {
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
            cout << "Какую операцию провести с данными матрицами?" <<endl;
            cout << "1. Сложить матрицы  2. Умножить матрицу(-ы) на число  3. Перемножить матрицы  4. Трансопнировать матрицу(-ы)  5. Возвести матрицу(-ы) в степень  0. Завершить выполнение программы" <<endl;
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
                cout << "Какие матрицы умножить?" <<endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" <<endl;
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
                    cout << "Введите, на какое число умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<float> A1 = A * o;
                    A1.Print();
                }
                if (h == 2) {
                    float o;
                    cout << "Введите, на какое число умножить матрицу: " << endl;
                    cin >> o;
                    MATRIX<float> B1 = B * o;
                    B1.Print();
                }
                if (h == 3) {
                    float o1, o2;
                    cout << "Введите, на какие числа умножить матрицы: " << endl;
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
                    cerr << "Перемножать можно только матрицы размера m*n и n*k" <<endl;
                }
                else
                {
                    MATRIX<float> M = A * B;
                    M.Print();
                }
            }
            else if (s == 4)
            {
                cout << "Какие матрицы транспонировать?" <<endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" <<endl;
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
                cout << "Какие матрицы возвести в степени?" <<endl;
                cout << "1. Первую матрицу    2. Вторую матрицу    3. Обе матрицы" <<endl;
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
                        cerr << "Возводить в степени можно только квадратные матрицы" <<endl;
                    }
                    else
                    {
                        int o;
                        cout << "Введите, в какую степень возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<float> A1 = A ^ o;
                        A1.Print();
                    }
                }
                if (h == 2) {
                    if (x1 != y1)
                    {
                        cerr << "Возводить в степени можно только квадратные матрицы" <<endl;
                    }
                    else
                    {
                        int o;
                        cout << "Введите, в какую степень возвести матрицу: " << endl;
                        cin >> o;
                        MATRIX<float> B1 = B ^ o;
                        B1.Print();
                    }
                }
                if (h == 3)
                {
                    if (x != y || x1 != y1)
                    {
                        cerr << "Возводить в степени можно только квадратные матрицы" <<endl;
                    }
                    else
                    {
                        int o1, o2;
                        cout << "Введите, в какие степени возвести матрицы: " << endl;
                        cin >> o1 >> o2;
                        MATRIX<float> A1 = A ^ o1;
                        MATRIX<float> B1 = B ^ o2;
                        A1.Print();
                        B1.Print();
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