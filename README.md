# MyWebServer
An HTTP Web Server in C++ that supports traditional features used across.HTTP uses a client-server model, where the client (usually a web browser)
initiates requests, and the server responds to those requests. HTTP operates on top of TCP/IP, which ensures reliable delivery of data across the 
internet.My Web Server is compatible with windows & linux platforms. The backbone of My web server is socket programming / network programming 
available in built-in libraries.

# Features of HTTP Web Server
1) Built-in encoding.
2) Supports GET type requests.
3) HTTP/1.1 (version 1.1) support.
4) parser for Query Strings in requests.

# The main key of HTTP Web Server
1) HTTP Methods.
2) URI(Uniform Resource Identifier).
3) HTTP Status Codes.
4) HTTP Headers.
5) Web Server Software.
# Testcase1
* Reference : /appOne 
//Bobby [The user]  
//Assume that the below code is being written by the server user
int main()
{
try
{
Bro bro;    //Creating Object of bro class
bro.setStaticResourcesFolder("whatever"); //whatever folder will containt all necessary files to be used
bro.get("/save_test1_data",[](Request &request,Response &response) void {
const char *html=R""""(
<!DOCTYPE HTML>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>Bro Test Cases</title>
</head>
<body>
<h1>Test Case 1-GET with Query string</h1>
<h3>Response From Server side</h3>
<b>Data Saved</b>
<br/><br/>
<a href='/index.html'>Home</a>
</body>
</html>
)"""";
response.setContentType("text/html");
response<<html;
});
bro.post("/save_test2_data",[](Request &request,Response &response) void {
const char *html=R""""(
<!DOCTYPE HTML>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>Bro Test Cases</title>
</head>
<body>
<h1>Test Case 2-POST with Form Data</h1>
<h3>Response From Server side</h3>
<b>Data Saved</b>
<br/><br/>
<a href='/index.html'>Home</a>
</body>
</html>
)"""";
response.setContentType("text/html");
response<<html;
});
bro.listen(6060,[](Error & error)void {
if(error.hasError())
{
cout<<"error.getError()";
return;
}
cout<<"Bro HTTP server is ready to accept request on port no. 6060"<<endl;
});
}catch(string exception)
{
//In case if something is not going as per the rule
cout<<exception<<endl;
}
return 0;
}

# TestCase2
* Reference : /appTwo
//A Web-Application is Perform CRUD Operation
int main()
{
typedef struct _student
{
int rollNumber;
char name[21];
char gender;
}Student;
try
{
Bro bro;    //Creating Object of bro class
bro.setStaticResourcesFolder("static"); //static folder will contain all the necessary files to be used
bro.get("/",[](Request &request,Response &response) void {

response<<R""""(
<!DOCTYPE HTML>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>Thinking Machines</title>
</head>
<body>
<h1>List of Students</h1>
<table border='1'>
<thead>
<tr>
<th>S.no.</th><th>Roll Number</th><th>Name</th><th>Gender</th>
<th>Edit</th><th>Delete</th>
</tr>
</thead>
<tbody>
)"""";
FILE *file;
file=fopen("student.dat","rb");
int sno=0;
if(file!=NULL)
{
Student stud;
char str[11];
while(1)
{
fread(&stud,sizeof(Student),1,file);
if(feof(file)) break;
sno++;
response<<"<tr>";
itoa(sno,str,10);
response<<"<td>"<<str<<"</td>";
itoa(stud.rollNumber,str,10);
response<<"<td>"<<str<<"</td>";
response<<"<td>"<<stud.name<<"</td>";
if(stud.gender=='M')
{
response<<"<td><img src='images/male.png'/></td>";
}
else
{
response<<"<td><img src='images/female.png'/></td>";
}
response<<"<td><a href='/editStudent?rollNumber="<<str<<"'>Edit</a></td>";
response<<"<td><a href='/deleteStudent?rollNumber="<<str<<"'>Delete</a></td>";
response<<"</tr>";
}
fclose(file);
}
if(sno==0)
{
response<<"<tr><td colspan='6' align='center'>No students</td></tr>";
}
response<<R""""(
</tbody>
</table>
<br/>
<a href='StudentAddForm.html'>Add Student</a>
</body>
</html>
)"""";
});
bro.get("/addStudent",[](Request &request,Response &response){
string rollNumber=request["rollNumber"];
string name=request["name"];
string gender=request["gender"];
Student stud;
stud.rollNumber=atoi(rollNumber.c_str());
strcpy(stud.name,name.c_str());
stud.gender=gender[0];
//we should check id roll Number supplied , already exists
FILE *file=fopen("student.dat","ab");
fwrite(&stud,sizeof(Student),1,file);
fclose(file);
response<<R""""(
<!DOCTYPE HTML>
<html lang='en'>
<head>
<meta charset='utf-8'>
<title>Thinking Machines</title>
</head>
<body>
<h1>Student (add Module)</h1>
<br/>
<br/>
<h3>Student Added</h3>
<form action='/'>
<button type='submit'>Ok</button>
</form>
<br/>
<a href='/'>Home</a><br/>
</body>
</html>
)"""";
});
bro.listen(6060,[](Error & error)void {
if(error.hasError())
{
cout<<"error.getError()";
return;
}
cout<<"Bro HTTP server is ready to accept request on port no. 6060"<<endl;
});
}catch(string exception)
{
//In case if something is not going as per the rule
cout<<exception<<endl;
}
return 0;
}
