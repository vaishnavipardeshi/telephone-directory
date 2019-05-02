#include<iostream>

using namespace std;

#define MAX 100
#define INFINITY 9999
class Graph
{
	public : int A[MAX][MAX],n;
	
	public  : Graph()
			  {
					for(int i=0;i<MAX;i++)
						for(int j=0;j<MAX;j++)
							A[i][j] = 0;
			  }
			  void createAdjnondir();
			  void displayAdj();
			  void diskstr(int src,int dest);
};
void Graph :: diskstr(int src,int dest)
{
	int path[MAX],j=0,i=0,curr=0,currdist=0,min=0,k=0,newcst=0;
	int  visited[MAX],distance[MAX],from[MAX];

  for(i=0;i<n;i++)
  {
    visited[i]  =0;
    distance[i] =INFINITY;
    from[i]     =INFINITY;
  }
  
  visited[src]=1;
  curr=src;
  distance[src]=0;

  while(curr!=dest)
  {
	 
	 currdist=distance[curr];
	 
	 
	 min=INFINITY;
	 for(i=0;i<n;i++)
	 {
		if(visited[i]==0 && A[curr][i] > 0)
		{
			newcst=currdist+A[curr][i];
			if(newcst<distance[i])
			{
				distance[i]=newcst;
				from[i]=curr;
			}
			if(distance[i]<min)
			{
				min=distance[i];
				k=i;
			}
		}
	 }
	curr=k;
	visited[curr]=1;
  }

  //find path
  
  cout << "\n total min cost " << distance[dest];
  
  j=0;
  path[j++] = dest;
  while(src!=dest)
  {
	  path[j++] = from[dest];
	  dest = from[dest];
  }
  j--;
  cout << "\n Path is : ";
  while(j>=0)
  {
	  cout << " - "<< path[j];
	  j--;
  }
}


void Graph :: createAdjnondir()
{
		
		cout << "\n Enter how many vertex : ";
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


int main()
{
	int src ,dest;
	Graph obj;
	obj.createAdjnondir();
	obj.displayAdj();
	cout<<"Enter the source "<<endl;
	cin>>src;
	cout<<"Enter the destination"<<endl;
	cin>>dest;
	obj.diskstr(src,dest);
}