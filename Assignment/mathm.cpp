#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int leftRange,rightRange;
        cin>>leftRange>>rightRange;
        int m=1;
        while((leftRange<<m)<=rightRange)
            m++;
        int result=(rightRange/(1<<(m-1))-leftRange+1);
        if(m>1)
            result+=(m - 1)*max(0, (rightRange/(1 << (m - 2)) / 3 - leftRange + 1));
        cout << m << " " << result << endl;
    }
}