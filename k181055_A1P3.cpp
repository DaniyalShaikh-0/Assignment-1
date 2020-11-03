#include<iostream>
#include<fstream>
using namespace std;
fstream In_file,Out_file;
char *store=new char[80];
int len=0,i,j,J;
void mutate_string() //to modify the string and put '-'
{
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(store[i]==' ') //to warn the program not to count spaces as same character
			{i++;}
			else
		{
			if(j==i)
			{
				j++;
			}
			if(store[i]==store[j])
			{
				store[j]='-';
			}
		}
		}
	}
	for(J=0;J<len-1;J++)
	{
		Out_file<<store[J]; //outputting modified string to file
	}
}
int main()
{
	In_file.open("FileQue3.txt",ios::in); 
	Out_file.open("FileAns3.txt",ios::out);
	while(In_file) //used as end of file marker
	{
		In_file.get(store[len]); //storing whole of the text from file including spaces (char by char)
		len++;
	}
	cout<<len;
	mutate_string();	//call to function
	In_file.close();
	Out_file.close();
}
