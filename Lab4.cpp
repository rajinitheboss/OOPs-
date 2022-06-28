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
class Queue
{
    private:
        doublylinkedlist<k> l;
    public:
    void enqueue(k p)
    {
        l.push_back(p);
    }
    k dequeue()
    {
        return l.pop_front();
    }
    int size()
    {
        return l.dllsize();
    }
    bool isEmpty()
    {
        if(size()>0)
            return 0;
        else 
            return 1;
    }
};
template<typename k>
class Printer
{
    private:
        Queue < k > q;
        int capacity;
        int ink;
    public:
        Printer(int capacity,int ink)
        {
            this->capacity=capacity;
            this->ink = ink;
        }
        void addDocument(k p)
        {
            if(q.size()==capacity)
                throw PrinterBusy("PRINTER_BUSY");
            q.enqueue(p);
        }
        k printdocument()
        {
            if(q.size()==0)
                throw NoDocument("NO_DOCUMENT");
            else if(ink==0)
                throw InsufficientInk("INSUFFICIENT_INK");
            else 
            {
                k doc=q.dequeue();
                ink--;
                return doc;
            }
        }
        void fillink(int ink)
        {
            
            this->ink=ink;
        }
        class InsufficientInk
        {   
            
            public:
            string c;
            InsufficientInk(string s)
            {
                c=s;
            }
        };
        class PrinterBusy 
        {
           
            public:
            string c;
            PrinterBusy(string s)
            {
                c=s;
            }
        };
        class NoDocument 
        {
            
            public:
            string c;
            NoDocument(string s)
            {
                c=s;
            }
        };
};
template<typename k>
void func(int m,int n)
{
    Printer <k> p(m,n);
    int q;
    cin>>q;
    while(q--)
    {
        int opcode;
        cin>>opcode;
        try
        {
            if(opcode==1)
            {
                k doc;
                cin>>doc;
                p.addDocument(doc);
            }
            else if(opcode==2)
            {
                cout<<p.printdocument()<<endl;
            } 
            else 
            {
                int in;
                cin>>in;
                p.fillink(in);
            }
        }
        catch(typename Printer<k>::PrinterBusy x)
        {
                cout<<x.c<<endl;
        }
        catch(typename Printer<k>::NoDocument x)
        {
            cout<<x.c<<endl;
        }
        catch(typename Printer<k>::InsufficientInk x)
        {
            cout<<x.c<<endl;
        }
    }
    return ;
}

int main()
{
    int m,n;
    char t;
    cin>>m>>n;
    cin>>t;
    if(t=='I')
    func<int>(m,n);
    else if(t=='C')
    func<char>(m,n);
    else 
    func<float>(m,n);
    return 0;
}