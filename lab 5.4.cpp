#include <iostream>
#include <cmath>

using namespace std;

double S0(const int N)
{
    double s = 0;
    for (int k = 1; k <= N; k++)
        s += (1 + pow(1 + k * k, 0.5)) / (k * k);
    return s;
}

double S1(const int N, const int k)
{
    if (k > N)
        return 0;
    else
        return ((1 + pow(1 + k * k, 0.5)) / (k * k)) + S1(N, k + 1);
}

double S2(const int N, const int k)
{
    if (k < N)
        return 0;
    else
        return ((1 + pow(1 + k * k, 0.5)) / (k * k)) + S2(N, k - 1);
}

double S3(const int N, const int k, double t)
{
    t += (1 + pow(1 + k * k, 0.5)) / (k * k);
    if (k >= N)
        return t;
    else
        return S3(N, k + 1, t);
}

double S4(const int N, const int k, double t)
{
    t = t + (1 + pow(1 + k * k, 0.5)) / (k * k);
    if (k <= N)
        return t;
    else
        return S4(N, k - 1, t);
}

int main()
{
    int N;
    int K = 1;

    cout << "N = "; cin >> N;

    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(N, K) << endl;
    cout << "(rec up --) S2 = " << S2(K, N) << endl;
    cout << "(rec down ++) S3 = " << S3(N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, 0) << endl;
    return 0;
}