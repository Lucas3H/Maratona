#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	pq<int> s;

	int a;
	fr(i, n){
		cin >> a;
		s.push(a);
	}

	int max = 0, c_MAX = 0, ant = s.top(), qt = 0;
	frr(i, n){
		if(ant == s.top()){
			s.pop();
			qt++;
			if(qt > max){
				max = qt;
				c_MAX = ant;
			}
		}
		else{
			ant = s.top();
			s.pop();
			qt = 1;
		}
	}

	cout << c_MAX << endl;

	return 0;	
		
}
