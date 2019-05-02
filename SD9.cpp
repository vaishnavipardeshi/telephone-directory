#include<iostream>
#include<fstream> // for ofstream and ifstream classes
#include<string.h>
using namespace std;

class Index
{
    public : int key,offset;
             void putindex()
             {
                    cout << "\n " << key << " \t " << offset;
             }
};

class Employee
{

    public : int id,salary;
             char name[10],desg[10];

             void getemp()
             {
                 cout << "\n Enter the id ";
                 cin >> id;
                 cout << "\n Enter the name ";
                 cin >> name;
                 cout << "\n Enter the desg ";
                 cin >> desg;
                 cout << "\n Enter the salary ";
                 cin >> salary;
             }
             void putemp()
             {
                 cout << "\n " << id << " "  << name << " " << desg << " " << salary;
             }
};
class Database
{
    private : char fname[50];
              int n;

    public  : Database()
              {
                    n = 0;
                    cout << "\n Enter the name of file ";
                    cin >> fname;
              }
              void menu();
              void sorting();
              void addrec();
              void displayrec();
              void searchrec(int);
              void delrec(int);
};

void Database :: delrec(int srno)
{
    int flag=0;
    ifstream fin1,fin2;
    ofstream fout;
    Employee s;
    Index obj;

    fin1.open(fname,ios::binary);  // open file in read mode
    fin2.open("index.txt",ios::binary);

    fout.open("temp.txt",ios::binary); // open file in write mode


    if( fin2.fail() || fin1.fail() || fout.fail() )
            cout << "\n Error opening file ";
    else
    {
        while( fin1.read((char*)&s,sizeof(s)) ) // Read a record from file to object
        {
            if( s.id == srno )
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
            cout << "\n Search record deleted from master...";
            remove(fname);
            rename("temp.txt",fname);
        }
        else
        {
            cout << "\n Search record not found ....";
        }

        fout.seekp(0,ios::beg);

        while( fin2.read((char*)&obj,sizeof(obj)) ) // Read a record from file to object
        {
            if( obj.key == srno )
            {
                flag=1;
            }
            else
            {
                fout.write((char*)&obj,sizeof(obj));
            }

        }
        if(flag==1)
        {
            cout << "\n Search record deleted from index file...";
            remove("index.txt");
            rename("temp.txt","index.txt");
        }
        else
        {
            cout << "\n Search record not found ....";
        }

    }
    fin1.close();
    fin2.close();

    fout.close();
}
void Database :: searchrec(int srno)
{
    int flag=0;
    ifstream fin1,fin2;
    Employee s;
    Index obj;

    fin1.open(fname,ios::binary);
    fin2.open("index.txt",ios::binary);

    if(fin1.fail() && fin2.fail() )
            cout << "\n Error opening file ";
    else
    {

        while( fin2.read((char*)&obj,sizeof(obj)) ) // Read a record from file to object
        {
            if( obj.key == srno )
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
        {
            cout << "\n Search record found ...";
            fin1.seekg(obj.offset * sizeof(s),ios::beg);
            fin1.read((char*)&s,sizeof(s));
            s.putemp();
        }
        else
        {
            cout << "\n Search record not found ....";
        }

    }
    fin1.close();
    fin2.close();
}
void Database :: displayrec()
{
    ifstream fin1,fin2;
    Employee s;
    Index obj;

    fin1.open(fname,ios::binary);
    fin2.open("index.txt",ios::binary);

    if(fin1.fail() || fin2.fail())
            cout << "\n Error opening file ";
    else
    {
        cout << "\n Employee Details \n";
        while( fin1.read((char*)&s,sizeof(s)) ) // Read a record from file to object
        {
            s.putemp();
        }
        cout << "\n\n\n Index Details \n";
        while ( fin2.read((char*)&obj,sizeof(obj)))
        {
            obj.putindex();
        }


    }
    fin1.close();
    fin2.close();
}
void Database :: sorting()
{
    Index obj1,obj2;
    int i,j;
    fstream f;
    f.open("index.txt", ios::in | ios::out | ios::binary );
    if(f.fail())
        cout << "\n Error opening file ";
    else
    {
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                f.seekg(i*sizeof(obj1),ios::beg);
                f.read((char*)&obj1,sizeof(obj1));

                f.seekg(j*sizeof(obj2),ios::beg);
                f.read((char*)&obj2,sizeof(obj2));

                cout << "\n" << obj1.key << " " << obj2.key;

                if( obj1.key > obj2.key)
                {
                        f.seekp(i*sizeof(obj2),ios::beg);
                        f.write((char*)&obj2,sizeof(obj2));

                        f.seekp(j*sizeof(obj1),ios::beg);
                        f.write((char*)&obj1,sizeof(obj1));
                }
            }
        }


    }
    f.close();

}
void Database :: addrec()
{
    ofstream fout1,fout2;
    Employee s;
    Index obj;
    char ch;
    fout1.open(fname,ios::binary);
    fout2.open("index.txt",ios::binary);

    if(fout1.fail() && fout2.fail() )
        cout << "\n Error opening file ";
    else
    {
        do
        {
            s.getemp();
            fout1.write((char*)&s,sizeof(s));  // This function is used to write a rec from an object to the file

            obj.key     = s.id;
            obj.offset  = n;
            fout2.write((char*)&obj,sizeof(obj));  // This function is used to write a rec from an object to the file

            cout << "\n Do u want to add more rec y.n -> ";
            cin >> ch;

            n++;

        }while(ch!='n');


    }
    fout1.close();
    fout2.close();
    sorting();
}
void Database :: menu()
{
    int ch,srno;

    do
    {
        cout << "\n 1 : Add rec \n 2 : display rec \n 3 : Search by id \n 4 : Delete rec by id \n 5 : Exit ";
        cout << "\n Enter u choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1 : addrec();break;

            case 2 : displayrec();break;

            case 3 : cout << "\n Enter the id  to search : ";
                     cin >> srno;
                     searchrec(srno);
                     break;

            case 4 : cout << "\n Enter the id  to delete : ";
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
