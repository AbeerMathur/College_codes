// Rabin Karp Algorithm
#include <bits/stdc++.h>
using namespace std;
#define d 256
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    bool found = false;
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == M)
            {
                if (!found)
                {
                    cout << "Pattern is found at position: " << i + 1 << endl;
                    found = true;
                }
                else
                {
                    break;
                }
            }
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int main()
{
    char txt[100], pat[100];
    cin >> txt;
    cin >> pat;
    int q = INT_MAX;
    search(pat, txt, q);
    return 0;
}