#include <bits/stdc++.h>
using namespace std;
int a,b,c,n;
int m[10010];
bool e;
set<int> ci,ba;



int main ()
{
    cin>>n;
    for(a=0;a<n;a++)
        {
            cin>>m[a];
            ba.insert(m[a]);
        }

    e=1;

    auto it = ba.begin();
    auto ite = ba.begin();
    it++;
    for(a=1;a<n;a++)
    {
        if(*it-*ite>8)
        {e=0;break;}
        it++;
        ite++;
    }
    e=0;

   if(e)
   while(ba.size()>0)
   {
       if(ci.size()==0 && *(ba.begin())>8)
       {
           e=0;break;
       }
   }


}
