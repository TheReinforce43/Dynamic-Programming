#include<bits/stdc++.h>
using namespace std;


int main()
{
    int N,S;
    cin>>N>>S;
    int weight[N+1],value[N+1],dp[N+1][S+1];

    for(int i=0;i<N;i++)
    {
        cin>>weight[i]>>value[i];
    }

    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=S;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(weight[i-1]<=j)
            {
                int option1=dp[i-1][j-weight[i-1]] + value[i-1];
                int option2=dp[i-1][j];
                dp[i][j]=max(option1,option2);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    cout<<dp[N][S]<<"\n";
    return 0;

}