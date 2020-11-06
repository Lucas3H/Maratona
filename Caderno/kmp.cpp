// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

vector<int> lps_p(string pat){
	int i = 1, len = 0, tam = pat.size();
	vector<int> lps(tam, 0);
	lps[0] = 0;

	while(i < tam){
		if(pat[i] == pat[len]) lps[i++] = ++len;
		else if(len != 0) len = lps[len-1];
		else lps[i++] = 0;
	}

	return lps;
}


int check(string txt, string pat){
	int i = 0, j = 0, tt = txt.size(), tp = pat.size(), ans;
	vector<int> lps = lps_p(pat);

	while(i < tt){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}

		if(j == tp){
			ans++;
			j = lps[j-1];
		}
		else if(i < n && txt[i] != pat[j]){
			if(j == 0) i++;
			else j = lps[j-1];
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
}