 #include <iostream>
using namespace std;
int get_sum(int ara[],int idx) // find cummulative sum of index=idx from bit tree = ara
{
   int sum = 0;
   while( idx >0)
   {
        sum += ara[idx];
        idx-=idx & (-idx);
   }
 return sum;
}

void update( int ara[] , int n, int x, int idx) // update value = x, at index = idx, of ara[] size = n
{
    idx++;
    while( idx <= n )
    {
        ara[idx] += x;

        idx += idx & (-idx);
        }
}

//constructor
int* init_bt(int aray[],int n ) //initiate bit tree of ara[] size = n
{
     int *bit_tr = new int[n+1];
     for( int i = 0; i < n; i++)
     {
       bit_tr[i] = 0;
     }
     for( int i = 0; i < n; i++)
     {
       update( bit_tr, n, aray[i], i );
     }
     return bit_tr;
}
//driver
int main()
{
    int arra[] = { 2,4,5,6,7,8,10,11,12};
    int n = sizeof(arra)/sizeof(int);
    int *bit_tree = init_bt(arra, n );
    cout<< get_sum(bit_tree,3)<<"\n";
}
