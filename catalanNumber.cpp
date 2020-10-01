/* Catalan Number : Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
                    1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
                    2) Count the number of possible Binary Search Trees with n keys etc.
		    The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

*/

#include<iostream>
using namespace std;

// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n)
{
	// Base case
	if (n <= 1) return 1;

	// catalan(n) is sum of catalan(i)*catalan(n-i-1)
	unsigned long int res = 0;
	for (int i=0; i<n; i++)
		res += catalan(i)*catalan(n-i-1);

	return res;
}

// Driver program to test above function
int main()
{
	for (int i=0; i<10; i++)
		cout << catalan(i) << " ";
	return 0;
}

/*
Sample input : 10
Output :1 1 2 5 14 42 132 429 1430 4862

*/
