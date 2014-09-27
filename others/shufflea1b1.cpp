 #include<iostream>
 #include<stdio.h>
using namespace std;
void shufflearray(int *,int,int);
void swapcase(int *a,int *b)
{
    //cout<<"test2";
    printf("%d\n",*a);
    printf("%d\n",*b);

    int temp;
    temp = *a;

    *a = *b;

    *b = temp;


}
void shuffle(int *array){
shufflearray(array,0,7);
 for(int i=0;i<8;i++){
    cout<<array[i]<<"\n";
    }

}
void shufflearray(int *ori_arr,int low,int high)
{

    if(low+1<high)
    {
        //cout<<"test";
    int mid_i=(low+high)/2;
    int mid_j=mid_i+1;
    swapcase(ori_arr+mid_i,ori_arr+(mid_j+1));
    swapcase(ori_arr+mid_i-1,ori_arr+mid_j);
    shufflearray(ori_arr,low,mid_i);;
    shufflearray(ori_arr,mid_j,high);


    }
    return;


}

void ev_change(int a[], int n){
    if(n > 2){
        //length of first part
        int new_length1 = (n + 1)/2;
        //length of second par
        int new_length2 = n - new_length1;
        //number of elements from first part, which need to be swap in this round
        int num = new_length1 / 2;
        int index1 = new_length1 - num;
        int index2 = new_length1;
        int temp;
        for( ; index1 < new_length1; index1++, index2++){
            temp = a[index1];
            a[index1] = a[index2];
            a[index2] = temp;
        }
        /* if the length of first part is odd, */
        /* then the first element of second part should come from B */
        /* for example for n = 6 the second part is [A3, B5, B6] */
        /* they should be sorted as [B5, B6, A3] */
        if( new_length1 % 2 == 1){
            int b1 = a[index2];
            for( int i = 0, i1 = index2 - 1, i2 = n - 1; i<num; i++, i1--, i2--){
                temp = a[i1];
                a[i1 + 1] = a[i2];
                a[i2] = temp;
            }
        a[new_length1] = b1;
        }
        //recursive call
        ev_change(a, new_length1);
        ev_change(a + new_length1, new_length2);
    }
    return;
}

//We can show the time complexity is O(n*log(n)) using master theorem
//T(n) = 2T(n/2) + O(n)
//==> T(n) = O(n*log(n))


int main()
{

int array[8]={1,3,5,7,2,4,6,8};
ev_change(array,7);
//shuffle(array);
 for(int i=0;i<8;i++){
    cout<<array[i]<<"\n";
    }
return 0;
}
