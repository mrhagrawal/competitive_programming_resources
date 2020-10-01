// User : mrhagrawal. 
// Mail : mr.hagrawal@gmail.com
// LinkedIn : http://bit.ly/honeylinkedin

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define mo 1000000007

// lli fact(lli k)
// {
// 	lli ans =1 ;

// 	while(k--)
// 	{
// 		ans *= k;
// 	}

// 	return ans;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,k;
    cin>>t>>k;

    lli dp[100005]={0};
    dp[0] = 1;

    for(int i = 1; i <= 100002; i++)
    {
    	if(i<k)
    	{
    		dp[i] = 1;
    	}

    	else
    	{
    		dp[i] = dp[i-1] + dp[i-k];
    		dp[i] %= mo;
    		// int p = i/k;

    		// for(int y = 0; y <= p; y++)
    		// {
    		// 	lli stp = fact[i%k + (p-y)*k + y];
    		// 	stp = stp/fact[i%k + (p-y)*k];
    		// 	stp = stp/fact[y];
    		// 	dp[i] += stp;
    		// 	dp[i] %= mo;
    		// }
    		
    	}

    	//cout<<dp[i]<<" ";
    }

    lli prefix[100005];
    prefix[0] = 0;
    prefix[1] = dp[1];

    for(int i = 2; i <= 100000; i++)
    {
    	prefix[i] = prefix[i-1]+dp[i];
    	prefix[i] %= mo;
    }


    while(t--)
    {
    	int a,b;
    	cin>>a>>b;
    	lli ans = 0;

    	ans = (prefix[b] - prefix[a-1] + mo )%mo;
    	cout<<ans<<endl;

    }
    return 0;
}