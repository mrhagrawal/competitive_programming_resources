// This is one of famous problem in interviews and competetive programming and can be done in O(N) time without using stack


#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
#define LM 1e18
#define ll  long long int
#define ld long double
#define ms(dp,val) memset(dp,val,sizeof(dp))
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) ((i >= min(a, b)) && (i <= max(a, b)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
const ll mod=998244353;
inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< pll > vpi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;

int trap(const vector<int> &A)   // function to calculate the trapped water 
{
    int n=A.size();
    vector<int> grr(n);
    vector<int> grl(n);
    grr[0]=A[0];
    for(int i=1;i<n;i++)
    {
        grr[i]=max(grr[i-1],A[i]); //   for each i max element between 0 to i
    }
    grl[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        grl[i]=max(grl[i+1],A[i]);   //     for each i max element between i to n-1
    }
    int ans;
    for(int i=0;i<n;i++)
    {
        ans+=(min(grr[i],grl[i])-A[i]); 
    }
    return ans;
}


int main()   // main function for input 
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<trap(a);
}
