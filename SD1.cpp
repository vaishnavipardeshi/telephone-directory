#include<iostream>
using namespace std;

class Set
{
    public : int a[100],n;
             Set()
             {
                n = 0;
             }
             void display()
             {
                 cout << "\n { ";
                 for(int i=0;i<n;i++)
                    cout << " " << a[i] << " ";
                 cout << " } ";
             }
             void addelement(int data)
             {
                 a[n] = data;
                 n++;
             }
             int contains(int data)
             {
                 int flag=0;

                 for(int i=0;i<n;i++)
                 {
                     if(a[i] == data)
                     {
                         flag = 1;
                         break;
                     }
                 }

                 return flag;

             }
             void setsize()
             {
                 cout << "\n Size of Set " << n;
             }
             void removeelement(int data)
             {
                 int i,j,flag=0;

                 for(i=0;i<n;i++)
                 {
                     if(a[i] == data)
                     {
                         flag = 1;
                         break;
                     }
                 }
                 if(flag==1)
                 {
                     cout << "\n Element Removed "<< a[i];

                     for(j=i;j<n-1;j++)
                     {
                         a[j] = a[j+1];
                     }
                     n--;
                 }
                 else
                    cout << "\n Element not found ....";
             }
};

class MySet
{
    private : Set obj1,obj2,obj3;
    public  : void menu();
              void union1();
              void intersection();
              void diff();
              int subset();
};
void MySet :: diff()
{
    int flag=0,i=0,j=0,k=0;

    for(i=0;i<obj1.n;i++)
    {
        flag=0;

        for(j=0;j<obj2.n;j++)
        {
                if(obj1.a[i] == obj2.a[j])
                {
                    flag=1;
                    break;
                }
        }
        if(flag==0)
        {
            obj3.a[k++] = obj1.a[i];
        }
    }

    obj3.n = k;

}
void MySet :: union1()
{
    int flag=0,i=0,j=0,k=0;

    // Copy set 2 to Set 3
    for(j=0;j<obj2.n;j++)
    {
        obj3.a[k++] = obj2.a[j];
    }

    // chcck common element and discard it from set 1
    for(i=0;i<obj1.n;i++)
    {
        flag=0;

        for(j=0;j<obj2.n;j++)
        {
                if(obj1.a[i] == obj2.a[j])
                {
                    flag=1;
                    break;
                }
        }
        if(flag==0)
        {
            obj3.a[k++] = obj1.a[i];
        }
    }

    obj3.n = k;
}
int MySet :: subset()
{
    int flag=0,i=0,j=0,k=0;

    if(obj1.n == obj2.n)
    {


    // chcck common element and discard it from set 1
    for(j=0;j<obj2.n;j++)
    {
        flag=0;

        for(i=0;i<obj1.n;i++)
        {
                if(obj1.a[i] == obj2.a[j])
                {
                    flag=1;
                    break;
                }
        }
        if(flag==0)
        {
           break;
        }
    }

    }
    return flag;
}

void MySet :: intersection()
{
    int flag=0,i=0,j=0,k=0;


    // chcck common element and discard it from set 1
    for(i=0;i<obj1.n;i++)
    {
        flag=0;

        for(j=0;j<obj2.n;j++)
        {
                if(obj1.a[i] == obj2.a[j])
                {
                    flag=1;
                    break;
                }
        }
        if(flag==1)
        {
            obj3.a[k++] = obj1.a[i];
        }
    }

    obj3.n = k;
}

void MySet :: menu()
{
  int ch,data,x;

  do
  {


    cout << "\n 1 : Add Set A";
    cout << "\n 2 : Remove Set A ";
    cout << "\n 3 : Size of Set A ";
    cout << "\n 4 : Contains element in Set A ";
    cout << "\n 5 : display Set A ";
    cout << "\n 6 : Union A + B ";
    cout << "\n 7 : Intersection ";
    cout << "\n 8 : Diff A-B";
    cout << "\n 9 : Subset";
    cout << "\n 10 : Exit ";
    cout << "\n Enter u choice : ";
    cin >> ch;
    switch(ch)
    {
        case 1 : cout << "\n Enter how many element in set A ";
                 cin >> x;
                 for(int i=0;i<x;i++)
                 {

                    cout << "\n Enter element in Set A ";
                    cin >> data;
                    obj1.addelement(data);

                 }
                 break;
        case 2 : cout << "\n Enter element to remove from Set A ";
                 cin >> data;
                 obj1.removeelement(data);
                 break;
        case 3 : obj1.setsize();
                 break;
        case 4 : cout << "\n Enter element to search in set A ";
                 cin >> data;
                 if( obj1.contains(data) )
                 {
                     cout << "\n Element found in Set ";
                 }
                 else
                 {
                     cout << "\n Element not found in Set ";
                 }
                 break;
        case 5 : cout << "\n SET A \n";
                 obj1.display();
        case 6 : obj2.n = 0;
                 cout << "\n Enter how many element in set B ";
                 cin >> x;
                 for(int i=0;i<x;i++)
                 {

                    cout << "\n Enter element in Set B ";
                    cin >> data;
                    obj2.addelement(data);

                 }
                 union1();
                 cout << "\n Display Set A  \n";
                 obj1.display();
                 cout << "\n Display Set B \n";
                 obj2.display();
                 cout << "\n Display Set C  UNION \n";
                 obj3.display();
                 break;
        case 7 : obj2.n = 0;
                 cout << "\n Enter how many element in set B ";
                 cin >> x;
                 for(int i=0;i<x;i++)
                 {

                    cout << "\n Enter element in Set B ";
                    cin >> data;
                    obj2.addelement(data);

                 }
                 intersection();
                 cout << "\n Display Set A  \n";
                 obj1.display();
                 cout << "\n Display Set B \n";
                 obj2.display();
                 cout << "\n Display Set C  INTERSECTION \n";
                 obj3.display();
                 break;
        case 8 : obj2.n = 0;
                 cout << "\n Enter how many element in set B ";
                 cin >> x;
                 for(int i=0;i<x;i++)
                 {

                    cout << "\n Enter element in Set B ";
                    cin >> data;
                    obj2.addelement(data);

                 }
                 diff();
                 cout << "\n Display Set A  \n";
                 obj1.display();
                 cout << "\n Display Set B \n";
                 obj2.display();
                 cout << "\n Display Set C  DIFF A-B = C \n";
                 obj3.display();
                 break;
        case 9 : obj2.n = 0;
                 cout << "\n Enter how many element in set B ";
                 cin >> x;
                 for(int i=0;i<x;i++)
                 {

                    cout << "\n Enter element in Set B ";
                    cin >> data;
                    obj2.addelement(data);

                 }
                 cout << "\n Display Set A  \n";
                 obj1.display();
                 cout << "\n Display Set B \n";
                 obj2.display();
                 if(subset())
                    cout << "\n Set B is a subset of A ";
                 else
                    cout << "\n Set B is not a subset of A";
                 break;


    }
  }while(ch!=10);
}

int main()
{
    MySet obj;
    obj.menu();
}
