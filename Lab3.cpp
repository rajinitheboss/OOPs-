#include<bits/stdc++.h>
using namespace std;
template<typename k>
class node
{
    public:
        k var;
        node* next;
        node* before;
    node(k var)
    {
        this->var=var;
        this->next=NULL;
        this->before=NULL;
    }
};
template<typename k>
class doublylinkedlist
{
    node<k> *head;
    node<k> *tail;
    int len;
    public:
        doublylinkedlist()
        {
            head=NULL;
            tail=NULL;
            len=0;
        }
        void push_front(k val)
        {
                node<k>* newptr=new node<k>(val);
                if(head==NULL&& tail==NULL)
                {
                    head=newptr;
                    tail=newptr;
                }
                else 
                {
                    newptr->next=head;
                    head->before=newptr;
                    head=newptr;
                }
                len++;
        }
        void push_back(k val)
        {
            node<k> *newptr=new node<k>(val);
            if(head==NULL&& tail==NULL)
            {
                head=newptr;
                tail=newptr;
            }
            else
            {
                tail->next=newptr;
                newptr->before=tail;
                tail=newptr;

            }
            len++;
        }
        k pop_front()
        {
            node<k> *ptr=head;
            head=head->next;
            if(head!=NULL)
                head->before=NULL;
            len--;
            if(len==0)
                tail=NULL;
            k ret=ptr->var;
            free(ptr);
            return ret;
        }
        k pop_back()
        {
            node<k> * ptr=tail;
            tail=tail->before;
            if(tail!=NULL)
                tail->next=NULL;
            len--;
            if(len==0)
                head=NULL;
            k ret=ptr->var;
            free(ptr);
            return ret;
        }
        int dllsize()
        {
            return len;
        }
        
};
template<typename k>
class mystack
{
    doublylinkedlist<k> l;
    public:
        void push(k val)
        {
            l.push_front(val);
        }
        k pop()
        {
            return l.pop_front();
        }
        k top()
        {
            k val=l.pop_front();
            l.push_front(val);
            return val;
        }
        int mystacksize()
        {
            return l.dllsize();
        }
        bool compare(k n)
        {
            if(n>top())
                return true;
            else 
                return false;
        }
        bool isempty()
        {
            if(l.dllsize()==0)
                return true;
            else 
                return false;
        }
};

int main()
{
    int n;
    char i;
    cin>>n;
    cin>>i;
    if(i=='C')
    {       
            mystack<char> s;
            while(n--)
            {
                char c;
                cin>>c;
                if(s.isempty()==1)
                {
                    s.push(c);
                }
                else 
                {
                    if(s.compare(c))
                    {
                        s.push(c);
                    }
                    else if(!s.compare(c))
                    {
                        while(s.isempty()!=1)
                        {
                           if(s.compare(c))
                                break;
                            cout<<s.pop();
                        }
                        s.push(c);
                    }
                }
            }
            while(s.isempty()==false)
            {
                cout<<s.pop();
            }
    }
    else if(i=='I')
    {
            mystack<int> s;
            while(n--)
            {
                int c;
                cin>>c;
                if(s.isempty()==1)
                {
                    s.push(c);
                }
                else 
                {
                    if(s.compare(c))
                    {
                        s.push(c);
                    }
                    else if(!s.compare(c))
                    {
                        while(s.isempty()!=1)
                        {
                           if(s.compare(c))
                                break;
                            cout<<s.pop();
                        }
                        s.push(c);
                    }
                }
            }
            while(s.isempty()==false)
            {
                cout<<s.pop();
            }
    }
    else if(i=='F')
    {
            mystack<float> s;
            while(n--)
            {
                float c;
                cin>>c;
                if(s.isempty()==1)
                {
                    s.push(c);
                }
                else 
                {
                    if(s.compare(c))
                    {
                        s.push(c);
                    }
                    else if(!s.compare(c))
                    {
                        while(s.isempty()!=1)
                        {
                           if(s.compare(c))
                                break;
                            cout<<s.pop();
                        }
                        s.push(c);
                    }
                }
            }
            while(s.isempty()==false)
            {
                cout<<s.pop();
            }
    }
    return 0;
    
}