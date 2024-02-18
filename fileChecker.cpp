#include<stdio.h>
#include<sys/stat.h>
using namespace std;
int main()
{
int x;
struct stat s;
//stat returns 0 if the path exists
//stat return -1 if the path doesn't exists
x=stat("/bro/apps/app1/static",&s); 
//if returns +ve then its a folder else its a file
printf("%d\n",x);
printf("%d\n",s.st_mode & S_IFDIR);
return 0;
}