#include<iostream>
#include<map>
#include<string.h>
using namespace std;
class Friendpage //friend page application using class
{
private:    //declaration of variables
    string sname;
    string semail_id;
    string sfriend;
    multimap<string,string>mp,s;  //using Associative container declaration
    multimap<string,string>::iterator itr; //iterator using multimap
public:
    Friendpage() //constructor function 
    {
        cout<<" Baseclass constructor is involked "<<endl;
    }
    void choose() //accessing user details using choose function
    {
        int ich;
         cout<<"1.AddUser"<<"\n"<<"2.DeleteUser"<<"\n"<<"3.EditUser"<<"\n"<<"4.SearchUser"<<"\n"<<"5.DisplayUser"
         <<"\n"<<"6.AddFriend"<<"\n"<<"7.Exit"<<endl;    //display the list of options select one
       cout << "enter your choice";
       cin >> ich;
       switch (ich) //calling functions using switch case
        {
        case 1:
                addUser(); //declaration of adduser function
                break;
        case 2:
                deleteUser();//declaration of eraiseuser function
                break;
        case 3:
                editUser(); //declaration of modifyuser function
                break;
        case 4:
                searchUser();   //declaration of searchuser function
                break;
        case 5:
                displayUser();  //declaration of display the user details using function
                break;
        case 6:
                addFriend();    //declaration of addfriend details using this function
                break;
        case 7:
          exit (0);

        }
    }

    void addUser() //definition of adding a userdetails
    {

     int inum;
     cout<<" enter the  number of user details :- "<<endl;
     cin>>inum;
     for(int i=1;i<=inum;i++)
     {
         cout<<" Enter the name :- "<<endl;
         cin>>sname;
         cout<<" Enter the emailid :- "<<endl;
         cin>>semail_id;
         mp.insert(make_pair(sname,semail_id));
     }
        choose();
    }

    
    void displayUser() //definition of displaying the all user records
  {
    cout << "Display user datails";
    for (itr = mp.begin(); itr != mp.end(); itr++)
      {
    cout <<"Name:"<< itr->first;
    cout <<"Email id:" <<itr->second;
      }

 }
     
    void deleteUser()//definition of delete  user records
    {
        string str;
        cout<<" enter the name to delete :- "<<endl;
        cin>>str;
        mp.erase(str);//this is multimap function
        choose();
    }
    void editUser()  //definition of modifying the user records
    {
         string sNewname;
         cout<<" name to edit details "<<endl;
         cin>>sname;
         cout<<" Propose a new name "<<endl;
         cin>>sNewname;
         cout<<" new email "<<endl;
         cin>>semail_id;
         mp.erase(sname); //this is multimap functon 
         mp.insert(make_pair(sNewname,semail_id));//this is multimap functon 

        choose();
    }
     void searchUser()  //search user details function definition   
  {
    cout << "Enter the username to search";
    cin >> sname;
    for (itr = mp.begin (); itr != mp.end (); itr++)
      {
    if (itr->first==sname)
      cout << "data existed" << endl;
    else
      cout << "user not exist" << endl;
          
      }
    }
    void addFriend ()  //addfriend function definition
  {
    cout << "Enter the name to add friend";
    cin >> sname;
    cout << "enter email id";
    cin >> semail_id;
    s.insert (pair < string, string > (sname, semail_id));  //this is multimap functon insert data
    cout << "Enter name of the person to addfriend";
    cin >> sname;
    for (itr = mp.begin (); itr != mp.end (); itr++)
      {
       if (itr->first == sfriend)
       {
         s.insert (pair < string, string > (itr->first, itr->second)); //this is multimap functon insert a records
       }
      }
      cout<<"Friends list"<<endl;
        for (itr = s.begin (); itr != s.end (); itr++)
        {
        cout << itr->first << itr->second;
        }
  }
    ~Friendpage()  //destructor of friendpage class
    {
        cout<<" Base class destructor is involked "<<endl;
    }
};

int main(int argc,char *argv[])  
{

    if(argc>1)
	{
		cout<<"\n Usage of file --> \n"
		"\t filename.exe and enter"<<endl<<
		"			or"<<endl<<
		"\t ./filename.out and enter"<<endl;
	}
	else
	{
    Friendpage obj; //object creation
    obj.choose(); //function calling
	}
return 0;
}