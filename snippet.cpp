//Name : Honey Agrawal
//Handle : mrhagrawal
//LinkedIn : http://bit.ly/honeylinkedin
//Email : mr.hagrawal@gmail.com
//College : The LNM Institute of Information Technlogy, Jaipur
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define ld long double
#define li long int
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()


// few useful STL 
typedef vector<lli> vi;
typedef vector<string> vs;
typedef map<lli,lli> mi;
typedef pair<lli,lli> pii;
typedef pair<string, string> pss;
 
/* Uncomment this to find exponentiation as in pow(x,n) for large values modulo m
 
lli modularExponentiation(lli x,lli n,lli M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
 
}
*/
 
/* Uncomment this to find moduloInverse of large number. 
 
lli d,x,y;
 
void extendedEuclid(lli A, lli B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
 
lli modInverse(lli A, lli M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
 
*/
 
 /* Uncomment this to find prime numbers less than equals to n where n<10000000
 
 bool prime[10000000];
 
 void sieveprime(lli n)
 {
   memset(prime, true, sizeof(prime));
   for(int i = 2; i*i <= n; i++)  if(prime[i] == true ) for(int j = i*2; j<=n; j = j+i ) prime[j]= false;
 }
 */
  
 
 int main()
 {
    ios_base::sync_with_stdio(false); //to speed up the I/O
    cin.tie(NULL);
    cout.tie(NULL);

    int t; //for the test cases
    cin>>t;

    while(t--)
    {
    	//code here
    }
 }
