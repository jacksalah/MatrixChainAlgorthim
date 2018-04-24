// GROUP:   X
// ID:      XXXXXXXX
// Assign:  10
// Assign:  MatChain
// UVA:     348
// Name:    XX STUDENT FULL NAME
// UVA Username: UVA username of student

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include<limits>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int p[11]; // the dimensions of matrices

int t[11][11]; // T[a][b]=the optimal number of multiplication of p[a]...p[b]
int D[11][11]; // D[a][b]=the decision (value of k) that gets T[a][b]

// Top down version
int MatChain(int a, int b) // Recursive, cost of multiplying the b-a matrices with indexes: a...b-1
{
    if ((a+1)==b)
    {
        t[a][b]= 0;
        return 0;
    }
    if (t[a][b]>=0    && t[a][b] !=numeric_limits<int>::max())
    {
        return  t[a][b];
    }

    for (int k=a+1; k<b; k++)
    {
        int  min2=MatChain(a,k)+MatChain(k,b)+(p[a]*p[k]*p[b]);
        if ( min2<t[a][b] )
        {
            t[a][b]= min2;
            D[a][b]=k;
        }
    }
    return  t[a][b];
}

void MatChainTopDown(int n) // Initialize T then call MatChain(0,n)
{

    for (int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {
            t[i][j]= numeric_limits<int>::max();
        }
    }
MatChain( 0,n);
//MatChainSol(0,n);

}
void MatChainSol(int a, int b)
{
    if ((a+1)==b)
    {
        cout<<"A"<<b;
        return;
    }
    int k=D[a][b];
    cout<<"(";
    MatChainSol(a,k);
    cout<<" x ";
    MatChainSol(k,b);
    cout<<")";


}
// BottomUp version
void MatChainBottomUp(int n)
{
    for (int s = 1; s <= n; ++s)
    {
        for (int i = 0; i+s <= n; ++i)
        {
            int j = i+s;
            MatChain(i , j);
        }
    }
}

// Recursive to output the solution for both versions


void Compute()
{
int no;
int temp=1;
while(true){
 cin>>no;
 if (no==0)     {
      break;
 }
  int left,right;
 for(int i=0;i<no;i++)
     {
      cin>>left>>right;
      p[i]=left;
     }
     p[no]=right;
         MatChainTopDown(no);
        cout << "Case " <<temp << ": " ;
        temp++;
        MatChainSol(0, no);
        cout<<endl;
}
return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //freopen("input_assign10_00348.txt", "r", stdin);
    Compute();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
