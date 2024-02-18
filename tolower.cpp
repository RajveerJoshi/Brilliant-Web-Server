#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isEven(int data)
{
return data%2==0;
}
int main()
{
int x[5]={50,23,542,73,93};
int y[5];
transform(x,x+5,y,isEven); //to convert to lower Case
int j;
for(j=0;j<=4;j++) cout<<y[j]<<endl;
return 0;
}