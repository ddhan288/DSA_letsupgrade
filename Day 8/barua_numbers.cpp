/* #include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> b;
    int n;
    cin>>n;
    while(n>0)
    {
        int t;
        cin>>t;
        b.push_back(t);
        n--;
    }
    int c=0;
    for(auto x:b)
    {
        int pro=1;
        int temp=x;
        int p=0;
        while(temp>0)
        {
            int d=temp%10;
            if(d==1)
                p++;
            if(d>1)
                c++;
        }
        if(p>1)
        {
            cout<<"not barua number";
            break;
        }
        else if(c>1)
        {
            cout<<"invalid input";
            break;
        }
        else
        {
            
            for(auto j:b)
            {
                pro=pro*j;
            }
        }
        cout<<pro;
    }
    
}
*/

#include <iostream>
using namespace std;

int main()
{
    unsigned long long int number, answer = 1;
    //int ch='0x0A';
    while(cin >> number){
        answer *= number;
        cout << answer;   
    }
    return 0;
}