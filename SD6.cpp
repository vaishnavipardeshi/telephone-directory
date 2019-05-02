#include<iostream>
#define MAX 100

using namespace std;

class Heap
{
	private : int a[MAX],n;

	public  : Heap()
			  {
					cout << "\n Enter marks obtained by student : ";
					cin >> n;
					for(int i=1;i<=n;i++)
					{
						cin >> a[i];
					}
			  }
			  void display();
			  void max_heap(int i,int tn);
			  void heapsort();
			  void buildheaptree();
};
void Heap :: display()
{
	cout << "\n SORTED ARRAY \n";
	for(int i=1;i<=n;i++)
	{
		cout << " " << a[i];
	}
	cout << "\n Max number : "<<a[n];
	cout << "\n Min number : "<<a[1];
}
void Heap :: heapsort()
{
	int temp;
    for (int i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heap(1, i - 1);
    }
}
void Heap :: buildheaptree()
{
	for(int i=n/2;i>=1;i--)
	{
		max_heap(i,n);
	}
}

void Heap :: max_heap(int i,int tn)
{
	int j=0,temp;

	temp = a[i];
	j = i*2;

	while(j<=tn)
	{
		if( j<tn  && a[j+1] > a[j]) // for odd nos
		{
			j = j+1;
		}

		if( temp > a[j] )
			break;
		else
			if( temp < a[j] )
			{
				a[j/2] = a[j];
				j = j * 2;
			}
	}

	a[j/2] = temp;
}

int main()
{
	Heap obj;
	obj.buildheaptree();
	obj.heapsort();
	obj.display();

}
