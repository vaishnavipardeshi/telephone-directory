#include<iostream>

using namespace std;

#define MAX 100
#define INFINITY 9999
class Graph
{
	public : int A[MAX][MAX],n;
			 char city[MAX];

	public  : Graph()
			  {
					for(int i=0;i<MAX;i++)
						for(int j=0;j<MAX;j++)
							A[i][j] = 0;
			  }
			  void createAdjnondir();
			  void displayAdj();
};
void Graph :: createAdjnondir()
{

		cout << "\n Enter how many  vertex: ";
		cin >> n;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
					cin >> A[i][j];
			}
		}
}
void Graph :: displayAdj()
{
	cout << "\n Adj MATRIX is \n ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << " " << A[i][j];
		}
		cout << "\n ";
	}
}


class Spanning
{
	private : Graph adj,sp;
	public  :
			  void menu();
			  void totalcost();
			  void prims(int start);
};

void Spanning :: prims(int start)
{
	int step,distance[MAX],visited[MAX],from[MAX],min,k;

	for(int i=0;i<adj.n;i++)
	{
		distance[i] = INFINITY;
		visited[i]  = 0;
		from[i]     = -1;
	}


	for(int step=1;step<adj.n;step++)
	{
		visited[start] = 1;
		min = INFINITY;
		k = 0;

		for(int j=0;j<adj.n;j++)
		{
			if( adj.A[start][j] > 0)
			{
				if( visited[j]==0 	&&  distance[j] > adj.A[start][j])
				{
					distance[j] = adj.A[start][j];
					from[j] = start;
				}
			}

			if( visited[j]==0 && min > distance[j] )
			{
				min = distance[j];
				k = j;
			}
		}

		start = k;
		sp.A[from[k]][k] = sp.A[k][from[k]] = distance[k];
	}

	sp.n = adj.n;
}

void Spanning :: totalcost()
{
	int total=0;

	for(int i=0;i<sp.n;i++)
		for(int j=i+1;j<sp.n;j++)
			total  = total + sp.A[i][j];

	cout << "\n Total Cost : "<<total;
}
void Spanning :: menu()
{
	int start;

	adj.createAdjnondir();
	cout << "\n Enter the start vertex for prims : ";
	cin >> start;

	sp.n = adj.n;
	prims(start);

	cout << "\n Adj Matrix \n";
	adj.displayAdj();
	cout << "\n Spanning Matrix \n";
	sp.displayAdj();
	cout << "\n Cost of Spanning Tree ";
	totalcost();
}
int main()
{
	Spanning obj;
	obj.menu();
}
