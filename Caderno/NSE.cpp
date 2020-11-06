#include<bits/stdc++.h>

#define MAXN 100010
/*
    Next smaller element / Complexity: N:
    Receive a array v and return an array which contains, for each i,
    the position of the next element that is smaller than v[i].

    For instance: if v = {4, 8, 5, 2, 25}
    Then nse = {2, 5, 2, -1, -1}
*/

class NSE{
    public:
        void nse(int v[], int n, int ret[]){
            for(int i = 0; i < n; i++){
                ret[i] = -1;
            }

            stack<int> s;

            for(int i = 0; i < n; i++){
                while(!s.empty() && v[s.top()] > v[i]){
                    ret[s.top()] = i;
                    s.pop();
                }

				s.push(i);
            }
        }
};
