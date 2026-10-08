#include <iostream>
#include <cmath>

using namespace std;

// один доданок суми
double term(const int N, const int k)
{
    return sqrt(sin(1. * k) * sin(1. * k) + cos(1. * N / k) * cos(1. * N / k));
}

// 1) обчислення на рекурсивному спуску, параметр k спадає (19, 18, ..., N)
//    t - накопичена до цього виклику частина суми
double S1(const int N, const int k, const double t)
{
    if (k < N)
        return t;
    else
        return S1(N, k - 1, t + term(N, k));
}

// 2) обчислення на рекурсивному спуску, параметр k зростає (N, N+1, ..., 19)
double S2(const int N, const int k, const double t)
{
    if (k > 19)
        return t;
    else
        return S2(N, k + 1, t + term(N, k));
}

// 3) обчислення на рекурсивному підйомі, параметр k спадає (19, 18, ..., N)
//    доданок додається ПІСЛЯ повернення з рекурсивного виклику
double S3(const int N, const int k)
{
    if (k < N)
        return 0;
    else
        return term(N, k) + S3(N, k - 1);
}

// 4) обчислення на рекурсивному підйомі, параметр k зростає (N, N+1, ..., 19)
double S4(const int N, const int k)
{
    if (k > 19)
        return 0;
    else
        return term(N, k) + S4(N, k + 1);
}

// 5) ітераційний спосіб - для контролю правильності
double S0(const int N)
{
    double s = 0;
    for (int k = N; k <= 19; k++)
        s += term(N, k);
    return s;
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << "(rec descent, k--) S1 = " << S1(N, 19, 0) << endl;
    cout << "(rec descent, k++) S2 = " << S2(N, N, 0) << endl;
    cout << "(rec ascent,  k--) S3 = " << S3(N, 19) << endl;
    cout << "(rec ascent,  k++) S4 = " << S4(N, N) << endl;
    cout << "(iteration)        S0 = " << S0(N) << endl;

    return 0;
}
