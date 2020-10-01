//0/1 knapsack Implementation

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int w;
	    cin>>w; //Max weight
	    int val[n],wt[n],i,j;
	    for(i=0;i<n;i++)
	        cin>>val[i];    //value array
	     for(i=0;i<n;i++)
	        cin>>wt[i]; //weight array
	   int dp[n+1][w+1];
	  // memset(dp,0,sizeof(dp));
	  for(i=0;i<=n;i++)
	    for(j=0;j<=w;j++)
	       { if(i==0||j==0)
	            dp[i][j]=0;
	       else
	        {if(wt[i-1]>j)
	            dp[i][j]=dp[i-1][j];
	        else
	            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	        }
	       }
	   
	   cout<<dp[n][w]<<endl;  //answer
	}
	return 0;
}
