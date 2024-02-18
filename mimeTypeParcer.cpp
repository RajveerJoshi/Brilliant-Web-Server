#include<iostream>
#include<map>
using namespace std;
void doParsing()
{
FILE *file;
file=fopen("C:/bro/bro-data/mime.types","r");
if(file==NULL)
{
cout<<"Unable to open file"<<endl;
return;
}
fseek(file,0,SEEK_END);
long fileSize=ftell(file);
rewind(file);
cout<<"Size of the file is : "<<fileSize<<endl;
cout<<"----------------------"<<endl;
char lines[100];
char mimeType[100];
char extension[20];
int i,j;
map<string,string> mimeTypes;
while(true)
{
fgets(lines,1000,file);
if(lines[0]=='#') continue;
for(i=0;i<100 && lines[i]!=9;i++) mimeType[i]=lines[i];
mimeType[i]='\0';
for(;lines[i]==' ' || lines[i]==9;i++);
for(j=0;i<100 && (lines[i]!='\r' || lines[i]!='\n');i++,j++)
{
extension[j]=lines[i];
}
extension[j]='\0';
if(feof(file)) break;
string x=string(extension);
string y=string(mimeType);
mimeTypes.insert(make_pair(x,y));
}
cout<<"Size of Map : "<<mimeTypes.size()<<endl;
map<string,string>::iterator it=mimeTypes.begin();
while(it!=mimeTypes.end())
{
cout<<it->first<<" , "<<it->second<<endl;
++it;
}
}
int main()
{
doParsing();
return 0;
}