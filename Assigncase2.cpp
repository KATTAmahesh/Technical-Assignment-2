#include<iostream>
#include<string.h>
using namespace std;
int x=0; //globally intialize the x value
void Matrixfun(int m,int n,char **arr,int ch,int diagnol) //function intialization using Matrixfun
{
    int a_index[n],i,j,r,c,r1,c1,rows;
    if(diagnol == 2)
        rows=2;
    else
        rows=m;
    for (i = 0; i < rows; i++) //for loop using row values
    {
        for (j = 0; j < n; j++)
	    {
	        a_index[j] = j;
	    }
	    for (j = 0; j < n - 1; j++)
	    {
	        if(ch==0) 
	        {
	            r = i;
	            c = a_index[j];     //assigning values
	            r1 = i;
	            c1 = a_index[j + 1];
	        }
	        else{
	              c = i;
	            r = a_index[j];
	            c1 = i;
	            r1 = a_index[j + 1];
	        }
	        if (arr[r][c] == arr[r1][c1])
	    	{
		        a_index[j + 1] = j;
		    }
	    }

        int p = 0;
        for (j = 0; j < n; j++)
	    {
	        if (a_index[j] == j)
	       {
	           if(ch==0)
	                arr[i][p] = arr[i][j];
	           else
	                arr[p][i] = arr[j][i];
	            p++;
	       }
	    }
        while (p != n)
	    {
	        x=1;
	        if(ch==0)
	            arr[i][p] = '*';
	       else
	        arr[p][i] = '*';
	        p++;
	    }
    }
}


void display(char **arr,int m,int n) //this function display the values rows and columns
{
    int i,j;
    for (i = 0; i < m; i++)
	{
	  for (j = 0; j < n; j++)
	    {
	      cout << arr[i][j] <<" ";
	    }
	    cout << "\n";
	}
}

int main (int argc,char **argv)
{
       if (argc == 2 && strcmp(argv[1], "-h") == 0) //using help command

    {
        cout<<"Given  matrix of size M*N with only 0s and 1s"<<endl;
    }
    else if (argc == 2 && strcmp(argv[1], "-h") != 0) //using help command

    {
        cout << "to Given Wrong Help command (-h) for display the description of program" << endl;
	        }
	 else
    {
    int n,m,ch;
    cout<<"Enter the no.of rows:"<<endl;
    cin >> m;
    cout<<"Enter the no.of columns"<<endl;
    cin>>n;
    cout<<"Enter your choice "<<endl<<"0.Row wise\n1.Column wise\n2.Diagonal wise"<<endl;
    cin >> ch;// 0 for row,1 for column, 2 for diagnol
    if(ch>=0&&ch<=2)
    {
        if((ch==0 && n>1) || (ch==1 && m>1) || (ch==2 && (m==n))){
    char **arr;//pointer to pointer character array
    int i, j;
    arr = new char *[n];//allocate n objects of type char
    for (i = 0; i < m; i++) //Enter the input values
    {
        arr[i] = new char[n];
        for(j=0;j<n;j++)
        {
         cout << "Enter " << i << j << " element:\n";
            cin >> arr[i][j];
        }
    }
      cout << "Input is \n";
    display(arr,m,n);//call this function to display input values
    if(ch== 2)
    {
        char *b[2];
        b[0] = new char[n];
        b[1] = new char[n];
        int p0=0,p1=0;
        for (i = 0; i < m; i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    b[0][p0++] = arr[i][j];
                if((i + j) == (n - 1))
                    b[1][p1++] = arr[i][j];
            }
        }
        Matrixfun(m,n,b,0,2);//to pass the function arguments
        p0=0;p1=0;
        for (i = 0; i < m; i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                     arr[i][j] = b[0][p0++];
                if((i + j) == (n - 1))
                    arr[i][j] = b[1][p1++];
            }
        }
    }
    else
        Matrixfun(m,n,arr,ch,1);
    cout << "\nthe given Output is \n";
    if(x==0){
        cout<<" consecutive numbers are not present.";
    }
    else{
        display(arr,m,n);
    }
    }
    else
    {
        cout<<"Invalid option"; //
    }
    }
    else
    {
    cout<<"Invalid option";
    }
}
  return 0;
}