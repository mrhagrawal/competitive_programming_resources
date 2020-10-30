//Jatin Kumar
//jatiny17

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define print1(a) cout<<a<<"\n";
#define print2(a,b) cout<<a<<" "<<b<<"\n";
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define print4(a,b,c,d) cout<<a<<" "<< b <<" "<<c<<" "<<d<<"\n";
#define s(a) sort(a.begin(),a.end());
#define lli long long int 
#define ulli unsigned long long int 
#define dd long double
#define pi pair<lli,lli>
#define pp pair<lli,pi>
#define pb push_back
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

//***************************************************//
vector<lli> g[100001];
bool v[100001];
lli intime[100001];
lli parent[100001];
bool ans[100001];
lli low[100001];
lli t=1;

void dfs(lli n,lli p)
{
	intime[n]=t;
	low[n]=t;

	t++;
	v[n]=true;
	lli c=0;

	// cout<<n<<" ";

	for(lli i=0;i<g[n].size();i++)
	{
		if(!v[g[n][i]])
		{
			dfs(g[n][i],n);
			c++;

			low[n]=min(low[n],low[g[n][i]]);

			if(parent[n]==n&&c>1)
			ans[n]=true;

			if(intime[n]<=low[g[n][i]]&&parent[n]!=n)
			ans[n]=true;
		}

		else
		{
			if(g[n][i]!=p)
				low[n]=min(low[n],intime[g[n][i]]);
		}
	}
}

int main()
{
    fast;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif

   	lli n,m;
   	cin>>n>>m;

   	while(m--)
   	{
   		lli x,y;
   		cin>>x>>y;

   		g[x].pb(y);
   		g[y].pb(x);
   	}

   	memset(v,false,sizeof(v));
   	memset(ans,false,sizeof(ans));
   	parent[0]=0;

   	dfs(0,0);

   	lli ct=0;
   	for(lli i=0;i<n;i++)
   	{
   		if(ans[i])
   			ct++;
   	}

   	cout<<ct<<"\n";

   	for(lli i=0;i<n;i++)
   	{
   		if(ans[i])
   			cout<<i<<" ";
	}

}
