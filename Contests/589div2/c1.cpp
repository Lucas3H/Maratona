#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MD=1e9+7;
ll x,n,ans=1;
set<int>st;
ll powr(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1) res=(res*x)%MD;
		x=(x*x)%MD;
		y/=2;
	}
	return res;
}
int main()
{
	cin>>x>>n;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(x%i==0)
			{
				st.insert(i);
				x/=i;
			}
		}
	}
	if(x>1) st.insert(x);
	for(auto x:st)
	{
		ll cnt=0,tmp=n,pro=1;
		while(tmp>0)
		{
			cnt+=tmp/x;
			tmp/=x;
		}

		//cout << x << endl;

		cout << cnt << endl;

		ans=(ans*powr(x,cnt))%MD;
	}
	cout<<ans;
	return 0;
}
