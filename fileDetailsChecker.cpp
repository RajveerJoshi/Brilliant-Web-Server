#include<iostream>
#include<sys/stat.h>
using namespace std;
int main()
{
FILE *f;
long fileSize;
f=fopen("/broServer/bro.cpp","rb");
fseek(f,0,SEEK_END);    //move 0 positions from end (SEEK_END)
fileSize=ftell(f);      //ftell() tells the current position of marker
fclose(f);
cout<<"File Size of bro.cpp : "<<fileSize<<endl;
f=fopen("/broServer/bro.exe","rb");
fseek(f,0,SEEK_END);    //move 0 positions from end(SEEK_END)
fileSize=ftell(f);      //ftell() tells the current position of marker
fclose(f);
cout<<"File Size of bro.exe : "<<fileSize<<endl;
return 0;
}