// Program to convert numeric values to Alphabetic values as per spreadsheets numbering

#include <bits/stdc++.h>
using namespace std;

void numericToAlpha(int num)
{

    stack<char> st;
    while (num != 0)
    {
        int a = num % 26;
        if (a == 0)
        {
            a = 26;
            num--;
        }

        st.push((char)(a + 64));
        num /= 26;
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    numericToAlpha(1);
    numericToAlpha(26);
    numericToAlpha(27);
    numericToAlpha(255);

    return 0;
}