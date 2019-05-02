#include<iostream>
using namespace std;
#define MAX 100

class TBTnode
{
		public : int data,lflag,rflag;
		TBTnode *lchild,*rchild;
};
class TBT
{
	private : TBTnode *root,*header;
	public  : TBT()
			  {
				root = NULL;
				header = NULL;
			  }
			  void menu();
			  TBTnode * getnode();
			  TBTnode * getnode1();
			  void createTBTtree();
			  void inorder();
};

void TBT :: menu()
{
	int ch,x;

	do
	{
		cout << "\n 1 : Create TBT ";
		cout << "\n 2 : Inorder  ";
		cout << "\n 3 : Exit";
		cout << "\n Enter u choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1 : header=getnode1();
					 createTBTtree();
					 break;
			case 2 : cout << "\n Inorder display \n";
					 inorder();
					 break;
        }
	}while(ch!=3);
}

TBTnode * TBT :: getnode()
{
	TBTnode *newnode=NULL;

	newnode = new TBTnode;
	if ( newnode == NULL)
	{
		cout << "\n Memory allocation error ";
	}
	else
	{
		newnode->lflag=0;
		newnode->rflag=0;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		cout << "\n Enter the data : ";
		cin >> newnode->data;
	}

	return newnode;
}

TBTnode * TBT :: getnode1()
{
	TBTnode *newnode=NULL;

	newnode = new TBTnode;
	if ( newnode == NULL)
	{
		cout << "\n Memory allocation error ";
	}
	else
	{
		newnode->lflag=0;
		newnode->rflag=0;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
	}

	return newnode;
}

void TBT :: createTBTtree()
{
		TBTnode *newnode=NULL,*oldnode=NULL;
		int n;

		cout << "\n Enter no of nodes in tree : ";
		cin >> n;

		for(int i=0;i<n;i++)
		{
				newnode=getnode();

				if ( root == NULL )
				{
					root = newnode;
					root->lchild=header;
					root->rchild=header;
					root->lflag=1;
					root->rflag=1;
				}
				else
				{
					oldnode = root;
					while(1)
					{
						if( newnode->data < oldnode->data)
						{
							if(oldnode->lflag==1)
							{
								newnode->lchild=oldnode->lchild;
								oldnode->lchild = newnode;
								oldnode->lflag=0;
								newnode->lflag=1;
								newnode->rchild=oldnode;
								newnode->rflag=1;
								break;
							}
							else
							{
								oldnode = oldnode->lchild;
							}
						}
						else
						{
							if ( newnode->data > oldnode->data)
							{
								if(oldnode->rflag==1)
								{
									newnode->rchild=oldnode->rchild;
									oldnode->rchild = newnode;
									oldnode->rflag=0;
									newnode->rflag=1;
									newnode->lchild=oldnode;
									newnode->lflag=1;
									break;
								}
								else
								{
									oldnode = oldnode->rchild;
								}
							}
							else
							{
								cout << "\n Dulicate Not allowed ";
								break;
							}
						}
					}
				}
		}
}


void TBT :: inorder()
{
	int flag=0;
	TBTnode *pt=NULL;

	if(root == NULL)
	{
		cout << "\n Tree is empty";
	}
	else
	{
		pt = root;

		while(pt!=header)
		{
				while(pt->lflag==0 && flag==0)
				{
					pt=pt->lchild;
				}
				cout << " " << pt->data;

				if(pt->rflag==0)
				{
					flag=0;
					pt = pt->rchild;
				}
				else
				{
					flag=1;
					pt = pt->rchild;
				}
		}
	}
}

int main()
{
	TBT obj;
	obj.menu();
}
