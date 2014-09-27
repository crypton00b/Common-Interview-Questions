#include<string.h>
#include<iostream>
#include<limits.h>
using namespace std;
int dpproblem(int *arr,int val,int m)
{
    int table[val+1];
    memset(table,INT_MAX,sizeof(table));
    table[0]=0;
    for(int i=0;i<=val;i++){
    cout<<"\n"<<table[i];
    }

    for(int i=1; i<=val; i++) //in lis problem the first case
    {

        for( int j=0; j<m; j++) //just like the lis problem
        {

            if(arr[j]<=i&&table[i-arr[j]]+1<table[i])
            {
                cout<<"test";
                table[i]=table[i-arr[j]]+1;
                cout<<"\n"<<table[i];

            }
        }

    }
 return table[val];


}

int main()
{
    int arr[3]= {1,3,5};
    cout<<dpproblem(arr,11,3);

    return 0;
}
