#include <iostream>
#include "matrix.h"
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int x, y, x1, y1;
    cout << "������ ⨯� ���� ��६����?" << endl;
    cout << "1: int;    2: float" << endl;
    int p;
    cin >> p;
    if (p == 1) {
        cout << "������ ࠧ��� ��ࢮ� ������: " << endl;
        cin >> x >> y;
        cout << "������ ࠧ��� ��ன ������: " << endl;
        cin >> x1 >> y1;
        cout << "������ ����� ������: " << endl;
        MATRIX<int> A(x, y);
        MATRIX<int> B(x1, y1);

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                int h;
                cin >> h;
                A[i][j] = h;
            }
        }
        cout << "������ ����� ������: " << endl;
        for (int i = 0; i < x1; i++) {
            for (int j = 0; j < y1; j++) {
                int h;
                cin >> h;
                B[i][j] = h;
            }
        }
        int s = 7;
        while (s != 0) {
            cout << "����� ������ �஢��� � ����묨 ����栬�?" << endl;
            cout
                    << "1. ������� ������  2. �������� ������(-�) �� �᫮  3. ��६������ ������  4. �࠭ᮯ��஢��� ������(-�)  5. ������� ������(-�) � �⥯���  0. �������� �믮������ �ணࠬ��"
                    << endl;
            cin >> s;
            if (s == 1) {
                if (x != x1 || y != y1) {
                    cerr << "������� ����� �� ࠢ��" << endl;
                } else {
                    MATRIX<int> M = A + B;
                    M.Print();
                }
            } else if (s == 2) {
                cout << "����� ������ 㬭�����?" << endl;
                cout << "1. ����� ������    2. ����� ������    3. ��� ������" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else
                        cout << "������ �᫮ �� 1 �� 3" << endl;
                }
                if (h == 1) {
                    int o;
                    cout << "������, �� ����� �᫮ 㬭����� ������: " << endl;
                    cin >> o;
                    MATRIX<int> A1 = A * o;
                    A1.Print();
                }
                if (h == 2) {
                    int o;
                    cout << "������, �� ����� �᫮ 㬭����� ������: " << endl;
                    cin >> o;
                    MATRIX<int> B1 = B * o;
                    B1.Print();
                }
                if (h == 3) {
                    int o1, o2;
                    cout << "������, �� ����� �᫠ 㬭����� ������: " << endl;
                    cin >> o1 >> o2;
                    MATRIX<int> A1 = A * o1;
                    MATRIX<int> B1 = B * o2;
                    A1.Print();
                    B1.Print();
                }
            } else if (s == 3) {
                if (x1 != y) {
                    cerr << "��६������ ����� ⮫쪮 ������ ࠧ��� m*n � n*k" << endl;
                } else {
                    MATRIX<int> M = A * B;
                    M.Print();
                }
            } else if (s == 4) {
                cout << "����� ������ �࠭ᯮ��஢���?" << endl;
                cout << "1. ����� ������    2. ����� ������    3. ��� ������" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else
                        cout << "������ �᫮ �� 1 �� 3" << endl;
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
                cout << "����� ������ ������� � �⥯���?" << endl;
                cout << "1. ����� ������    2. ����� ������    3. ��� ������" << endl;
                int h = 0;
                int q = 0;
                while (q != 1) {
                    cin >> h;
                    if (h == 1 || h == 2 || h == 3) {
                        q = 1;
                    } else
                        cout << "������ �᫮ �� 1 �� 3" << endl;
                }
                if (h == 1) {
                    if (x != y) {
                        cerr << "��������� � �⥯��� ����� ⮫쪮 ������� ������" << endl;
                    } else {
                        int o;
                        cout << "������, � ����� �⥯��� ������� ������: " << endl;
                        cin >> o;
                        MATRIX<int> A1 = A ^ o;
                        A1.Print();
                    }
                }
                if (h == 2) {
                    if (x1 != y1) {
                        cerr << "��������� � �⥯��� ����� ⮫쪮 ������� ������" << endl;
                    } else {
                        int o;
                        cout << "������, � ����� �⥯��� ������� ������: " << endl;
                        cin >> o;
                        MATRIX<int> B1 = B ^ o;
                        B1.Print();
                    }
                }
                if (h == 3) {
                    if (x != y || x1 != y1) {
                        cerr << "��������� � �⥯��� ����� ⮫쪮 ������� ������" << endl;
                    } else {
                        int o1, o2;
                        cout << "������, � ����� �⥯��� ������� ������: " << endl;
                        cin >> o1 >> o2;
                        MATRIX<int> A1 = A ^ o1;
                        MATRIX<int> B1 = B ^ o2;
                        A1.Print();
                        B1.Print();
                    }
                }
            } else {
                if (s != 0)
                    cerr << "������ �᫮ �� 0 �� 6" << endl;
            }
        }
    }
    else
    {
        cout << "������ ࠧ��� ��ࢮ� ������: " << endl;
        cin >> x >> y;
        cout << "������ ࠧ��� ��ன ������: " << endl;
        cin >> x1 >> y1;
        cout << "������ ����� ������: " << endl;
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
        cout << "������ ����� ������: " <<endl;
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
            cout << "����� ������ �஢��� � ����묨 ����栬�?" <<endl;
            cout << "1. ������� ������  2. �������� ������(-�) �� �᫮  3. ��६������ ������  4. �࠭ᮯ��஢��� ������(-�)  5. ������� ������(-�) � �⥯���  0. �������� �믮������ �ணࠬ��" <<endl;
            cin >> s;
            if (s == 1)
            {
                if (x != x1 || y != y1)
                {
                    cerr << "������� ����� �� ࠢ��" <<endl;
                }
                else
                {
                    MATRIX<float> M = A + B;
                    M.Print();
                }
            }
            else if (s == 2)
            {
                cout << "����� ������ 㬭�����?" <<endl;
                cout << "1. ����� ������    2. ����� ������    3. ��� ������" <<endl;
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
                        cout << "������ �᫮ �� 1 �� 3" <<endl;
                }
                if (h == 1) {
                    float o;
                    cout << "������, �� ����� �᫮ 㬭����� ������: " << endl;
                    cin >> o;
                    MATRIX<float> A1 = A * o;
                    A1.Print();
                }
                if (h == 2) {
                    float o;
                    cout << "������, �� ����� �᫮ 㬭����� ������: " << endl;
                    cin >> o;
                    MATRIX<float> B1 = B * o;
                    B1.Print();
                }
                if (h == 3) {
                    float o1, o2;
                    cout << "������, �� ����� �᫠ 㬭����� ������: " << endl;
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
                    cerr << "��६������ ����� ⮫쪮 ������ ࠧ��� m*n � n*k" <<endl;
                }
                else
                {
                    MATRIX<float> M = A * B;
                    M.Print();
                }
            }
            else if (s == 4)
            {
                cout << "����� ������ �࠭ᯮ��஢���?" <<endl;
                cout << "1. ����� ������    2. ����� ������    3. ��� ������" <<endl;
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
                        cout << "������ �᫮ �� 1 �� 3" <<endl;
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
                cout << "����� ������ ������� � �⥯���?" <<endl;
                cout << "1. ����� ������    2. ����� ������    3. ��� ������" <<endl;
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
                        cout << "������ �᫮ �� 1 �� 3" <<endl;
                }
                if (h == 1) {
                    if (x != y)
                    {
                        cerr << "��������� � �⥯��� ����� ⮫쪮 ������� ������" <<endl;
                    }
                    else
                    {
                        int o;
                        cout << "������, � ����� �⥯��� ������� ������: " << endl;
                        cin >> o;
                        MATRIX<float> A1 = A ^ o;
                        A1.Print();
                    }
                }
                if (h == 2) {
                    if (x1 != y1)
                    {
                        cerr << "��������� � �⥯��� ����� ⮫쪮 ������� ������" <<endl;
                    }
                    else
                    {
                        int o;
                        cout << "������, � ����� �⥯��� ������� ������: " << endl;
                        cin >> o;
                        MATRIX<float> B1 = B ^ o;
                        B1.Print();
                    }
                }
                if (h == 3)
                {
                    if (x != y || x1 != y1)
                    {
                        cerr << "��������� � �⥯��� ����� ⮫쪮 ������� ������" <<endl;
                    }
                    else
                    {
                        int o1, o2;
                        cout << "������, � ����� �⥯��� ������� ������: " << endl;
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
                    cerr << "������ �᫮ �� 0 �� 6" <<endl;
            }
        }
    }
}