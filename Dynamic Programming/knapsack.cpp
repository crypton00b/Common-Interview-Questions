/* knap sack problem can be explained like this.....there are n items i.....n that has n weights wt[w1...wn] and n values val[v1....vn] respectively.what would be the max value that we can get if
we take it optmally which is less than a max weight W.So we make a matrix with item numbers as  rows and weight from 1 to max weight W as columns.the corresponding value is the max  value that can
k[i][w]be attained.k[i][w] is the max value that can be attained with items under the maxweight w. so for weight 1 to W ,we consider adding items or deleting it.....
if(w-wt[i]>=0) condition checks whether adding the item will surpass the max weight or not */




#include<iostream>
#include<vector>
#include<stddef.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

int knapsack(int wt[],int v[],int weight,int n)
{
    int k[n+1][weight+1];//k[i][w]max value that can be attained if the max weight is w and selecting items from 1 ot i

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=weight; w++)
        {

            if(i==0||w==0)
            {
                k[i][w]=0;

            }
            else if(w-wt[i-1]>=0)//w is the max weight,if the weight can be put in to the bag,then we will check whether the value that we obtain is more or less after adding it
            {
                k[i][w]=max(k[i-1][w],v[i]+k[i-1][w-wt[i-1]]);
            }
            else
            {

                k[i][w]=k[i-1][w];// doesnt take the item into knapsack
            }

        }

    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=weight; j++)
        {
            cout<<k[i][j]<<"\t";

        }
        cout<<"\n";


    }
    return k[n][weight];

}


int main()
{

    int n=3;
    int weight=50;
    int value[3]= {60,100,120};
    int wt[3]= {10,20,30};
    cout<<"\n"<<knapsack(wt,value,weight,n);

    return 0;
}
