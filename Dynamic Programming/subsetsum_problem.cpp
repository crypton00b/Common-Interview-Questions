#include<iostream>
using namespace std;

bool issubsetsum(int *arr,int n,int sum)
{
    if(sum==0)//if the sum is 0 in bw,then it means that there is a soln
        return true;

    if(n==0&&sum!=0)//if all the elements got over and still the sum >0,then no soln
        return false;

    if(arr[n-1]>sum)return issubsetsum(arr,n-1,sum);//if the value itself is > than the sum,then ignore the case

    return issubsetsum(arr,n-1,sum)||issubsetsum(arr,n-1,sum-arr[n-1]);//if any of the solution is true in backtracking,then return true


}

bool dp_problem(int *arr,int n,int sum)
{
    bool dp[sum+1][n+1];//the 2-d array dp[i][j] gives true if there is a sum that equals i for the values from arr[0....j-1]
    for(int i=0; i<=n; i++)
    {
        dp[0][i]=true;// if any number of values give a sum 0,then it is true
    }
    for(int i=1; i<=sum; i++)
    {
        dp[i][0]=false;

    }

    for( int i=1; i<=n; i++)
    {

        for(int j=1; j<=sum; j++)
        {
            dp[i][j]=dp[i][j-1];
            if(i>=arr[j-1])
            {

                dp[i][j]=dp[i][j]||dp[i-arr[j-1]][j-1];
            }

        }

    }
    return dp[sum][n];
}



int main()
{
    int arr[5]= {2,-2,4,5,-3};
    if(issubsetsum(arr,5,6))
    cout<<"yes";
    else
    cout<<"No";
if(dp_problem(arr,5,6))
cout<<"yes";
else
cout<<"No";

    return 0;
}
