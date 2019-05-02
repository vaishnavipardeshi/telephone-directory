/*
    Department maintains a student information. The file contains roll number , name ,
    division and address allow user to add,delete information of student.
    Display info of particular student.
    If record of student doest exist appropriate message is displayed if it is
    and system display the student

*/
#include<iostream>
#include<fstream> // for ofstream and ifstream classes
#include<string.h>
using namespace std;

class Student
{

    public : int rollno;
             char name[10],add[10],div[10];

             void getstud()
             {
                 cout << "\n Enter the rollno ";
                 cin >> rollno;
                 cout << "\n Enter the name ";
                 cin >> name;
                 cout << "\n Enter the address ";
                 cin >> add;
                 cout << "\n Enter the division ";
                 cin >> div;
             }
             void putstud()
             {
                 cout << "\n " << rollno << " "  << name << " " << add << " " << div;
             }
};
class Database
{
    private : char fname[50];

    public  : Database()
              {
                    cout << "\n Enter the name of file ";
                    cin >> fname;
              }
              void menu();
              void addrec();
              void displayrec();
              void searchrec(int);
              void delrec(int);
};

void Database :: delrec(int srno)
{
    int flag=0;
    ifstream fin;
    ofstream fout;
    Student s;

    fin.open(fname,ios::binary);  // open file in read mode
    fout.open("temp.txt",ios::binary); // open file in write mode


    if( fin.fail() || fout.fail() )
            cout << "\n Error opening file ";
    else
    {
        while( fin.read((char*)&s,sizeof(s)) ) // Read a record from file to object
        {
            if( s.rollno == srno )
            {
                flag=1;
            }
            else
            {
                fout.write((char*)&s,sizeof(s));
            }

        }
        if(flag==1)
        {
            cout << "\n Search record deleted ...";
            remove(fname);
            rename("temp.txt",fname);
        }
        else
        {
            cout << "\n Search record not found ....";
        }

    }
    fin.close();
    fout.close();
}
void Database :: searchrec(int srno)
{
    int flag=0;
    ifstream fin;
    Student s;

    fin.open(fname,ios::binary);
    if(fin.fail())
            cout << "\n Error opening file ";
    else
    {
        cout << "\n Student Details \n";

        // It returns 1 if record are found else return 0
        while( fin.read((char*)&s,sizeof(s)) ) // Read a record from file to object
        {
            if( s.rollno == srno )
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
        {
            cout << "\n Search record found ...";
            s.putstud();
        }
        else
        {
            cout << "\n Search record not found ....";
        }

    }
    fin.close();
}
void Database :: displayrec()
{
    ifstream fin;
    Student s;

    fin.open(fname,ios::binary);
    if(fin.fail())
            cout << "\n Error opening file ";
    else
    {
        cout << "\n Student Details \n";

        // It returns 1 if record are found else return 0
        while( fin.read((char*)&s,sizeof(s)) ) // Read a record from file to object
        {
            s.putstud();
        }

    }
    fin.close();
}
void Database :: addrec()
{
    ofstream fout;
    Student s;
    int n;

    fout.open(fname,ios::binary);
    if(fout.fail())
        cout << "\n Error opening file ";
    else
    {
        cout << "\n Enter how many records : ";
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            s.getstud();
            fout.write((char*)&s,sizeof(s));  // This function is used to write a rec from an object to the file
        }
    }
    fout.close();
}
void Database :: menu()
{
    int ch,srno;

    do
    {
        cout << "\n 1 : Add rec \n 2 : display rec \n 3 : Search by rollno \n 4 : Delete rec by rollno \n 5 : Exit ";
        cout << "\n Enter u choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1 : addrec();break;
            case 2 : displayrec();break;
            case 3 : cout << "\n Enter the roll no to search : ";
                     cin >> srno;
                     searchrec(srno);
                     break;
            case 4 : cout << "\n Enter the roll no to delete : ";
                     cin >> srno;
                     delrec(srno);
        }

    }while(ch!=5);
}


int main()
{
    Database obj;
    obj.menu();

}
