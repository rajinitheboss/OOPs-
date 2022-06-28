#include<bits/stdc++.h>

using namespace std;
class node
{
    public:
    int val;
    node* next;
        node(int val)
        {
            this->val=val;
            next=NULL;
        }
};
class linkedlist
{
    node *head;
    public:
        linkedlist()
        {
            head=NULL;
        }
        void insert_front(int val)
        {
            node* newnode=new node(val);
            if(head==NULL)
                head=newnode;
            else 
            {
                newnode->next=head;
                head=newnode;
            }
        }
        int remove_front()
        {
            node* ptr=head;
            int a=head->val;
            head=head->next;
            free(ptr);
            return a;
        }
        int top()
        {
            if(head!=NULL)
                return head->val;
            else 
                return -1;
        }
        bool isempty()
        {
            if(head==NULL)
                return true;
            else 
                return false;
        }
};
class Stack
{
    linkedlist l;
    public:
        void Push(int x)
        {
            l.insert_front(x);
        }
        int Pop()
        {
            if(l.isempty()==0)
                return l.remove_front();
            else 
                return -1;
        }
        int top()
        {
            return l.top();
        }
        bool isempty()
        {
            return l.isempty();
        }

};
class graph
{
    private:
        int size;
        int **a;
        bool dfs(int i,int parent,int *visited)
        {
            visited[i]=1;
            for(int j=0;j<size;j++)
            {
                if(a[i][j]==1 && j!=parent && visited[j]==1)
                    return true;
                else
                { 
                    if(a[i][j]==1 && visited[j]!=1)
                        if(dfs(j,i,visited))
                            return true;
                }    
            }
            return 0;
        }
    public:
        graph(int n)
        {
            this->size=n;
            a=new int*[n];
            for(int i=0;i<n;i++)
            {
                a[i]=new int[n];
            }

             for(int i=0;i<n;i++)
                memset(a[i],0,sizeof(a[i]));
        }
        void operator += (pair<int,int> &p)
        {
            a[p.first][p.second]=1;
            a[p.second][p.first]=1;
        }
        void operator -= (pair<int,int> &p)
        {
            a[p.first][p.second]=0;
            a[p.second][p.first]=0;
        }
        bool reach(int x,int y)
        {

            int visited[this->size]={0};
            for(int i=0;i<size;i++)
                visited[i]=0;
            Stack naistam;
            naistam.Push(x);
            while(naistam.isempty()==0)
            {
                int k=naistam.Pop();
                visited[k]=1;
                if(k==y)
                    return 1;
                else
                {
                    for(int j=0;j<size;j++)
                    {
                        if(visited[j]!=1)
                            if(a[k][j]==1)
                                naistam.Push(j);
                    }
                }
            }
            return 0;
        }
        bool detectcycle()
        {
            int visited[size]={0};

            for(int i=0;i<size;i++)
            {
                if(visited[i]!=1)
                    if(dfs(i,-1,visited)) return true;
            }
            return 0;
        }
    friend ostream& operator << (ostream& s,graph &g);
};
ostream& operator << (ostream& s,graph &g)
{

    for(int i=0;i<g.size;i++)
    {
        for(int j=0;j<g.size;j++)
            s<<g.a[i][j]<<" ";
            
        s<<endl;
    }
    return s;
}
int main()
{
    int t;
    cin>>t;
    string s;
    Stack jadi;
    while(t--)
    {
        cin>>s;
        if(s=="push")
        {
            int f;
            cin>>f;
            jadi.Push(f);
        }
        else if(s=="pop")
        {
            cout<<jadi.Pop()<<endl;
        }
        else if (s=="top")
        {
            cout<<jadi.top()<<endl;
        }
        else 
        {
            cout<<jadi.isempty()<<endl;
        }
    }
    int n;
    cin>>n;
    graph G(n);
    int m;
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        if(s=="add")
        {
            int u,v;
            cin>>u>>v;
            pair<int,int> p(u,v);
            G += p;
        }
        else if(s=="del")
        {
            int u,v;
            cin>>u>>v;
            pair<int,int> p(u,v);
            G -= p;
        }
        else if(s=="cycle")
        {
            cout<<G.detectcycle()<<endl;
        }
        else if(s=="print")
        {
            cout<<G;
        }
        else if(s=="reach")
        {
            int u,v;
            cin>>u>>v;
            cout<<G.reach(u,v)<<endl;
        }
    }
    return 0;
}