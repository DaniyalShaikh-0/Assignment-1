#include<iostream>
#include<fstream>
using namespace std;
int n,m,i,j,count=0,k;		//global variable
int rec_count(char **array,int i,int j); //recursive function's parameter
int main()
{
	fstream in_file;
	in_file.open("FileQue2.txt",ios::in);
	in_file>>n;
	in_file>>m;
	char **array=new char*[n]; // dynamic array to store 0's & 1's
	int tl;
	for(tl=0;tl<n;tl++)
	{
		array[tl]=new char[m];
	}
	int t_r=0,t_c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			in_file>>array[i][j]; //storing whole path from input file
		}
	}
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<array[i][j];
		}
		cout<<'\n';
	}
	cout<<rec_count(array,0,0); // call
	
}
int rec_count(char **array,int i,int j)
{
	if(i>n-1 || j>m-1 || i<0 || j<0 || array[i][j]=='1') //safe conditions or base case
	{
		return count;
	}
	if(array[i][j]=='0')
	{
		if(i==n-1 && j==m-1)
		{
			count++;
			return count;
		}
	rec_count(array,i+1,j); // recursive call 2	
	rec_count(array,i,j+1); // recursive call 1
	}
}
