#include<iostream>
#include<string.h>
using namespace std;

int bruteforce(int *arr,int val,int n)
{
    if(val==0)return 1;
    else if(val<0)return 0;
    else if(val>=1&&n<=0)
        return 0;
    else
        return bruteforce(arr,val,n-1)+bruteforce(arr,val-arr[n-1],n);


}

int dpcount(int *arr,int val,int m)
{
    int dp[val+1];
    memset(dp,0,sizeof(dp));

    //for(int i=0;i<=val;i++){
    //dp[i]=0;
    //}
    dp[0]=1;

    for(int i=0; i<m; i++)
    {
        for(int j=arr[i]; j<=val; j++)

        {
            //cout<<dp[j]<<"\n";
            dp[j]+=dp[j-arr[i]];
        }

    }
    return dp[val];

}

int main()
{
    int arr[3]= {2,1,3};
    cout<<bruteforce(arr,4,3)<<"\n";
    cout<<dpcount(arr,4,3);
    return 0;
}
