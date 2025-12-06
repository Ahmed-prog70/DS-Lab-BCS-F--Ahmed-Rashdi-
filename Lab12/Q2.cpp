#include <iostream>
#include <string>
using namespace std;

#define d 256
void rabinkarp(string text, string pattern, int q)
{
    int n = text.length();
    int m = pattern.length();

    if(m == 0 || m > n)
    {
        cout << "no valid pattern to search.\n";
        return;
    }
    int p = 0;
    int t = 0;
    int h = 1;

    for(int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for(int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    cout << "matches at indices: [";
=
    bool first = true;
    bool collided = false;
    for(int i = 0; i <= n - m; i++)
    {
        if(p == t)
        {
            bool ok = true;

            for(int j = 0; j < m; j++)
            {
                if(text[i + j] != pattern[j])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                if(!first) cout << ", ";
                cout << i;
                first = false;
            }
            else
            {
                cout << "\nfalse-positive hash collision at index " << i;
                collided = true;
            }
        }
        if(i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0) t += q;
        }
    }

    cout << "]" << endl;

    if(!collided)
        cout << "no hash collisions occurred.\n";
}
int main()
{
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int q = 101;
    rabinkarp(text, pattern, q);
    return 0;
}
