// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

#include <bits/stdc++.h>
using namespace std;

int num_ways(string s, int n)
{

    if (s[0] - 48 == 0)
        return 0;
    if (n <= 1)
        return 1;

    int num = num_ways(s.substr(1), n - 1);
    if ((s[0] - 48) <= 2 && (s[1] - 48) <= 6)
        num += num_ways(s.substr(2), n - 2);
    return (num);
}

int main()
{

    string s = "27";
    int n = s.length();
    int a = num_ways(s, n);
    cout << a << endl;

    return 0;
}