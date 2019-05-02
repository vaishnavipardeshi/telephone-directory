#include<iostream>

using namespace std;

class edgenode
{
    public : char data;
             int wt;
             edgenode *enext;
};

class vertexnode
{
    public : char data;
             edgenode *enext;
             vertexnode *vnext;

};

class Graph
{
    private : vertexnode *start;
              int n;


    public  : Graph()
              {
                 start = NULL;
              }
              edgenode * getedgenode(char);
              void createedgelist();
              vertexnode * getvertexnode();
              void createlist();
              void displaylist();
};
edgenode * Graph :: getedgenode(char data)
{
    edgenode *etemp=NULL;
    etemp = new edgenode;
    if(etemp==NULL)
        cout << "\n Memory allocation error";
    else
    {
        etemp->data = data;
        cout << "\n Enter the amt of fuel required : ";
        cin>>etemp->wt;
        etemp->enext = NULL;
    }
    return etemp;
}
void Graph :: createedgelist()
{
    int data;
    vertexnode *vend=NULL,*vstart=NULL,*vtemp=NULL,*vlast=NULL;
    edgenode *estart=NULL,*etemp=NULL,*elast=NULL;

    if(start==NULL)
        cout << "\n Graph is empty";
    else
    {
        vstart = start;

        while(vstart!=NULL)
        {
            vend = start;

            estart = NULL;

            while(vend!= NULL)
            {

                if(vstart->data != vend->data)
                {
                    cout << "\n Is there an edge between ("<<vstart->data <<"," << vend->data << " ) -> ";
                    cin >> data;
                    if(data == 1 )
                    {

                        etemp = getedgenode(vend->data);
                        if(estart == NULL)
                            estart = etemp;
                        else
                        {
                            elast = estart;
                            while(elast->enext != NULL)
                                 elast = elast->enext;
                            elast ->enext = etemp;
                        }
                    }

                }
                vend = vend ->vnext;
            }

            vstart->enext = estart;

            vstart = vstart->vnext;
        }


    }
}
vertexnode * Graph :: getvertexnode()
{
    vertexnode *temp=NULL;

    temp = new vertexnode;
    if(temp==NULL)
    {
        cout << "\n ";
    }
    else
    {
        temp->enext = NULL;
        temp->vnext = NULL;
        cout << "\n Enter flight name  :  ";
        cin >> temp->data;
    }
    return temp;
}



void Graph :: createlist()
{
        vertexnode *vtemp=NULL,*vlast=NULL;


        cout << "\n Enter no of flights : ";
        cin >> n;

        for(int i=1;i<=n;i++)
        {

            vtemp = getvertexnode();

            if(start==NULL)
            {
                start = vtemp;
            }
            else
            {
                vlast = start;
                while(vlast->vnext!=NULL)
                    vlast = vlast->vnext;

                vlast->vnext = vtemp;
            }

        }
}

void Graph :: displaylist()
{
        vertexnode *vlast=NULL;
        edgenode *elast=NULL;
        if(start==NULL)
        {
            cout << "\n List is empty";
        }
        else
        {
            vlast=start;
            while(vlast!=NULL)
            {
                cout << "\n " << vlast->data;

                elast = vlast->enext;

                while(elast!=NULL)
                {
                    cout << " => "<< elast->data << " " << elast->wt;
                    elast = elast->enext;

                }

                vlast = vlast->vnext;

            }
        }
}


int main()
{
    Graph obj;
    obj.createlist();
    obj.createedgelist();
    obj.displaylist();

}
