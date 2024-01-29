#include <iostream>
#include <iomanip>
using namespace std;

//возвращает обратную матрицу
double **reverse(double **matr_start, int n)
{
    double a, b, t;
    double *upper = new double[2 * n];

    //создание единичной матрицы
    double **matr_ed = new double *[n];
    for (int i = 0; i < n; i++)
        matr_ed[i] = new double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matr_ed[i][j] = 1;
            else
                matr_ed[i][j] = 0;
        }

    //создание объединенной матрицы матрицы (n*2n)
    double **matr_comb = new double *[n];
    for (int i = 0; i < n; i++)
        matr_comb[i] = new double[2 * n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (2 * n); j++)
        {
            if (j < n)
                matr_comb[i][j] = matr_start[i][j];
            else
                matr_comb[i][j] = matr_ed[i][j - n];
        }

    /* cout << "Combined matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << matr_comb[i][j] << " ";
            if (j == 2)
                cout << "| ";
        }
        cout << endl;
    }
    cout << endl;*/

    //прямой ход (получаем верхнюю треугольную в левой части комбинированной)
    for (int k = 0; k < n; k++)
    {
        //меняет строку с нижней местами по возможности, если встречает на гл диагонали 0
        if ((matr_comb[k][k] == 0) and (k != n - 1))
        {
            for (int i = k + 1; i < n; i++)
            {
                if (matr_comb[i][k] != 0)
                {
                    for (int j = 0; j < n * 2; j++)
                    {
                        t = matr_comb[i][j];
                        matr_comb[i][j] = matr_comb[k][j];
                        matr_comb[k][j] = t;
                    }
                    break;
                }
            }
        }

        //проверка на 0 в диагонали и как следствие наличие обратной матрицы
        if ((matr_comb[k][k] == 0) and (k == n - 1))
        {
            return 0;
        }

        for (int i = k; i < n; i++)
        {
            if (i == k)
                for (int j = 0; j < 2 * n; j++)
                    upper[j] = matr_comb[i][j];  //записываем в uppper верхнюю строчку

            for (int j = k; j < 2 * n; j++)
            {
                if (i == k)
                {
                    if (j == k)
                        a = matr_comb[k][k];
                    matr_comb[i][j] /= a;   //получаем первый элемент матрицы =1, a = первому элементу, дальше с k++ идем лесенкой
                }
                else
                {
                    if (j == k)
                        b = matr_comb[i][j];
                    matr_comb[i][j] -= upper[j]/a * b;  //зануляем элемент следующей строчки под 1
                }
            }
        }
    }

    //cout << "1 step:" << endl;
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << matr_comb[i][j] << " ";
            if (j == 2)
                cout << "| ";
        }
        cout << endl;
    }
    cout << endl;*/

    //обратный ход (результат - левая часть комбы - единичная, правая - обратная)
    for (int k = n - 1; k >= 0; k--)
        for (int i = k; i >= 0; i--)
        {
            if (i == k)
                for (int j = 0; j < 2 * n; j++)
                    upper[j] = matr_comb[i][j];

            for (int j = k; j < 2 * n; j++)
            {                                                        //делаем то же, что и в прямом, только начинаем с противоположного угла, 
                if (i == k)                                          //зануляем выше диагонали
                {
                    if (j == k)
                        a = matr_comb[k][k];
                    matr_comb[i][j] /= a;
                }
                else
                {
                    if (j == k)
                        b = matr_comb[i][j];
                    matr_comb[i][j] -= upper[j]/a * b;
                }
            }
        }

    double **matr_rev = new double *[n];
    for (int i = 0; i < n; i++)
        matr_rev[i] = new double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr_rev[i][j] = matr_comb[i][j + n]; //в  rev записываем правую часть комбы

    return matr_rev;
}

//умножение матриц
void multiple(double **matr1, double **matr2, int n)
{
    double s;

    double **matr = new double *[n];
    for (int i = 0; i < n; i++)
        matr[i] = new double[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s = 0;
            for (int k = 0; k < n; k++)
                s += matr1[i][k] * matr2[k][j];
            matr[i][j] = s;
        }
    }

    cout << "Multiply the inverse by the original: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(8) << fixed << setprecision(2) << matr[i][j] << " ";
        cout << endl;
    }
}

void slau()
{
    cout << "Example: " << endl
         << "a11*x1 + a12*x2 + ... + a(1n)*xn = b1;" << endl
         << "a21*x1 + a22*x2 + ... + a(2n)*xn = b2;" << endl
         << "......................................" << endl
         << "an1*x1 + an2*x2 + ... + a(nn)*xn = bn." << endl
         << endl;

    int n, i, j;

    cout << "Enter the number of equations: ";
    cin >> n;
    cout << endl;

    double **matr = new double *[n];
    for (int i = 0; i < n; i++)
        matr[i] = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter equation(" << i + 1 << ") coefficients: (a" << i + 1 << "1, a" << i + 1 << "2, ... a" << i + 1 << "n)" << endl;
        for (int j = 0; j < n; j++)
            cin >> matr[i][j];
    }

    double **matr_rev = reverse(matr, n);
    double s;
    double *res = new double[n];
    double *b = new double[n];

    cout << "Free coefficiets: (b1,b2, ... bn)" << endl;

    for (int j = 0; j < n; j++)
        cin >> b[j];

    cout << "Your system: " <<endl;
    for (int i=0;i<n;i++) {
    for (int j=0;j<n; j++) {
        if (matr[i][j+1]>0) {
        if (j==n-1) cout <<setprecision(1)<<matr[i][j] << "*x"<<j+1<<" = ";
        else cout <<setprecision(1)<<matr[i][j] << "*x"<<j+1<<" + ";
        }
        else    {
              if (j==n-1) cout <<setprecision(1)<<abs(matr[i][j]) << "*x"<<j+1<<" = ";
        else cout <<setprecision(1)<<abs(matr[i][j]) << "*x"<<j+1<<" - ";
        }
    }
    cout << b[i];
    cout << endl;
    }

//получаем корни, умножим обратную на матррицу свободных членов
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < n; j++)
            s += matr_rev[i][j] * b[j];
        res[i] = s;
    }

    cout << endl
         << "Solution:" << endl;

    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << res[i] << endl;
}
