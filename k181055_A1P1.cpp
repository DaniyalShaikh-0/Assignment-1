#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class file1{ 			//CLASS THAT INCLUDES INPUT,OUTPUT FILES AND ALL ARRAYS
	private:
	int n,m;
	int search;
	char ** arr; // To store the fruit puzzle
	int **out_arr; 
	fstream q1,Out_file;	//INPUT FILE : q1    ,    OUTPUT FILE : Out_file
	string *search_arr; //To store fruits name
	public:
	file1(){	//Initializing Constructor
		n=0;
		m=0;
		arr=NULL;
		out_arr=NULL;
		search=0;
		search_arr=NULL;
	}
	void in_data() //to open files and input data from files
	{
		q1.open("FileQue1.txt",ios::in);
		Out_file.open("FileAns1.txt",ios::out);
		q1>>n;
		q1>>m;
		int i,j,k;
		arr=new char* [n];
		for(i=0;i<n;i++)
		{
			arr[i]=new char[m];
			for(j=0;j<m;j++)
			{
				q1>>arr[i][j];
			}
		}
		q1>>search;
		search_arr=new string[search];
		for(k=0;k<search;k++)
		{
			q1>>search_arr[k];
		}
		out_arr=new int*[search];
		for(k=0;k<search;k++)
		{
			out_arr[k]=new int[2];
		}
	}
	void disp()	//for displaying useful values
	{	
	int i,j,k;
		cout<<" N = "<<n;
		cout<<endl<<" M = "<<m;
		cout<<endl<<" array \n\n";
			for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n"<<search<<endl;
		for(k=0;k<search;k++)
		{
			cout<<search_arr[k];
			cout<<endl;
		}
	}
	void solve() //finding word's first position up,down,left,right
	{
		int arr_cmp[search];
		int i,j,k=0,l=0;
		int rcnt,count=0,newi,finalcount=0;
		int c1,c2,flg=0,pcount;
		int temp_pos_r=0,temp_pos_c=0;
		for(i=0;i<search;i++)
		{
			arr_cmp[i]=search_arr[i].size();
		}
		for(i=0;i<search;i++)
		{
			count=0;
		for(pcount=0;pcount<(n*m);pcount++)
			{
			if(flg==0&&count==0)
			{
				k=0;l=0;
			while((search_arr[i][0]!=arr[k][l]))
			{
				if((k==n-1)&&(l==m-1))
				{
					break;
				}
				l++;
				if(l==m)
				{
					k++;
					l=0;
			 	}
			}
				if(search_arr[i][0]==arr[k][l])
				{
					count=1;
					temp_pos_r=k;
					temp_pos_c=l;
				}
			}
			
				c1=temp_pos_r;
				c2=temp_pos_c;	
				if(((c1+1)<n)&&(search_arr[i][1]==arr[c1+1][c2]))// DOWN
				{
					count=2;
					for(j=2;j<arr_cmp[i];j++)
					{
						if((c1+j)>(n-1))
						{
							break;
						}
						else
						{
						if(search_arr[i][j]==arr[c1+j][c2])
						{
							count++;	
						}
						else
						{
							break;
						}
						}
					}	
				if(count==arr_cmp[i])
				{
					finalcount=count;
					Out_file<<temp_pos_r;
					Out_file<<',';
					Out_file<<temp_pos_c<<endl;
					break;
				}
				}
    			if(((c2+1)<m)&&(search_arr[i][1]==arr[c1][c2+1])) //RIGHT
				{
					count=2;
					for(j=2;j<arr_cmp[i];j++)
					{
						if((c2+j)>m-1)
						{
							break;
						}
						else
						{
						
							if(search_arr[i][j]!=arr[c1][c2+j])
							{
								break;
							}
							else
							{
								count++;
							}
						}
					}
						if(count==arr_cmp[i])
				{
					finalcount=count;
					Out_file<<temp_pos_r;
					Out_file<<',';
					Out_file<<temp_pos_c<<endl;
					break;
				}
				}
				if((((c1-1)<n)&&((c1-1)>0))&&(search_arr[i][1]==arr[c1-1][c2]))// UP
				{
					count=2;
					for(j=2;j<arr_cmp[i];j++)
					{
						if((c1-j)>(n-1)&&((c1-j)<0))
						{
							break;
						}
						else
						{
						if(search_arr[i][j]==arr[c1-j][c2])
						{
							count++;	
						}
						else
						{
							break;
						}
						}
					}	
				if(count==arr_cmp[i])
				{
					finalcount=count;
					Out_file<<temp_pos_r;
					Out_file<<',';
					Out_file<<temp_pos_c<<endl;
					break;
				}
				}
				if((((c2-1)<m)&&((c2-1)>0))&&(search_arr[i][1]==arr[c1][c2-1])) //LEFT
				{
					count=2;
					for(j=2;j<arr_cmp[i];j++)
					{
						if(((c2-j)>m-1)&&((c2-j)<0))
						{
							break;
						}
						else
						{
						
							if(search_arr[i][j]!=arr[c1][c2-j])
							{
								break;
							}
							else
							{
								count++;
							}
						}
					}
						if(count==arr_cmp[i])
				{
					finalcount=count;
					Out_file<<temp_pos_r;
					Out_file<<',';
					Out_file<<temp_pos_c<<endl;
					break;
				}
				}
				else
				{
					l=0;
					k=0;
				while(search_arr[i][0]!=arr[k][l] || (k==temp_pos_r && l== temp_pos_c))
				{
					l++;
				if(k==n-1 && l==m-1)
			 	{
			 		break;
				}
				if(l==m)
				{
					k++;
					l=0;
				}
				}
				flg=0;
				if(search_arr[i][0]==arr[k][l])
				{
					count=1;
					temp_pos_r=k;
					temp_pos_c=l;
				}
				}
			}
			if(finalcount!=arr_cmp[i])
			{
				Out_file<<'n'<<endl;
			}
		}
	}	
};
int main()
{
	file1 obj;
	obj.in_data();
	obj.disp();
	obj.solve();
}
