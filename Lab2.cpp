#include<bits/stdc++.h>

using namespace std;

class book
{
    string title;
    string author;
    int year;
    int price;
    public:

        book* next;
        book(string title,string author,int year,int price)
        {
            this->title=title;
            this->author=author;
            this->year=year;
            this->price=price;
            this->next=NULL;
        }
        void print()
        {
            cout<<this->title<<","<<this->author<<","<<this->year<<","<<this->price<<endl;
        }
        int getprice()
        {
            return price;
        }
        bool operator==(book &b)
        {
            if(this->title!=b.title)
                return false;
            if(this->author!=b.author)
                return false;
            if(this->year!=b.year)
                return false;
            if(this->price!=b.price)
                return false;
            return true;
        }
        string getauthor()
        {
            return author;
        }
        string gettitle()
        {
            return title;
        }
        int getyear()
        {
            return year;
        }
};
class bookshelf
{
    protected:
        book *head;
    public:
        bool checkEmpty()
        {
            if(head==NULL)
                return 1;
            else 
                return 0;
        }
        bookshelf()
        {
            head=NULL;
        }
        virtual void addBook(string,string,int,int)=0;
        virtual void removeBook()=0;
        virtual void list()=0;
        virtual void findCheap()=0;
        virtual void reverseUnique()=0;
};
class verticalshelf: public bookshelf
{
    public:
        void addBook(string,string,int,int);
        void removeBook();
        void list();
        void findCheap();
        void reverseUnique();
        void remduplicates();
};
class horizontalshelf: public bookshelf
{
    public:
        void addBook(string,string,int,int);
        void removeBook();
        void list();
        void findCheap();
        void reverseUnique();
        void remduplicates();
};

void verticalshelf::addBook(string t,string a,int y,int p)
{
    book *newbook=new book(t,a,y,p);
    if(head==NULL)
    {
        head=newbook;
    }
    else 
    {
        newbook->next=head;
        head=newbook;
    }
}
void  verticalshelf::removeBook()
{
    if(head==NULL)
    {
        cout<<"e"<<endl;
    }
    else 
    {
        book *ptr=head;
        head=head->next;
        free(ptr);
    }
}
void verticalshelf::list()
{
    if(head==NULL)
    {
        cout<<"e"<<endl;
    }
    else 
    {
        book *ptr=head;
        while(ptr)
        {
            ptr->print();
            ptr=ptr->next;
        }
    }
}
void verticalshelf::findCheap()
{
    int cheap;
    if(head==NULL)
    {
        cout<<"e"<<endl;
        return ;
    }
    else 
    {
        book *ptr=head;
        cheap=head->getprice();
        cout<<"-1";
        ptr=head->next;
        while(ptr)
        {
            if(cheap<ptr->getprice())
                cout<<","<<cheap;
            else
            {
                cout<<","<<"-1";
                cheap=ptr->getprice();
            }
            ptr=ptr->next;
        }
        cout<<endl;
    }
    return ;
}
void horizontalshelf::findCheap()
{
    int cheap;
    if(head==NULL)
    {
        cout<<"e"<<endl;
        return ;
    }
    else 
    {
        book *ptr=head;
        cheap=head->getprice();
        cout<<"-1";
        ptr=head->next;
        while(ptr)
        {
            if(cheap<ptr->getprice())
                cout<<","<<cheap;
            else
            {
                cout<<","<<"-1";
                cheap=ptr->getprice();
            }
            ptr=ptr->next;
        }
        cout<<endl;
    }
    return;
}

void horizontalshelf::addBook(string t, string a, int y,int p )
{
    book *newptr=new book(t,a,y,p);
    if(head==NULL)
    {
        head=newptr;
    }
    else 
    {
        book *ptr=head;
        while(ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->next=newptr;
    }
}
void horizontalshelf:: removeBook()
{
    if(head==NULL)
        cout<<"e"<<endl;
    else 
    {
        book*ptr=head;
        head=head->next;
        free(ptr);
    }
}
void horizontalshelf::list()
{
    if(head==NULL)
    {
        cout<<"e"<<endl;
    }
    else 
    {
        book *ptr=head;
        while(ptr)
        {
            ptr->print();
            ptr=ptr->next;
        }
    }
}
void verticalshelf::reverseUnique()
{
    remduplicates();
}
void verticalshelf::remduplicates()
{
    book* newhead=NULL;
    book* ptr1=head;
    if(head==NULL)
        return ;
    while(ptr1)
    {
        int flag=0;
        book *ptr2=newhead;
        while(ptr2)
        {
            if(*(ptr2) == *(ptr1))
            {
                flag++;
            }
            ptr2=ptr2->next;
        }
        if(flag==0)
        {
            book *newptr=new book(ptr1->gettitle(),ptr1->getauthor(),ptr1->getyear(),ptr1->getprice());
            if(newhead==NULL)
                newhead=newptr;
            else
            {
            newptr->next=newhead;
            newhead=newptr;
            }
        }
        ptr1=ptr1->next;
    }
    head=newhead;
}
void horizontalshelf::reverseUnique()
{
    remduplicates();
}
void horizontalshelf::remduplicates()
{
    book* newhead=NULL;
    book* ptr1=head;
    if(head==NULL)
        return ;
    while(ptr1)
    {
        int flag=0;
        book *ptr2=newhead;
        while(ptr2)
        {
            if(*(ptr2) == *(ptr1))
            {
                flag++;
            }
            ptr2=ptr2->next;
        }
        if(flag==0)
        {
            book *newptr=new book(ptr1->gettitle(),ptr1->getauthor(),ptr1->getyear(),ptr1->getprice());
            if(newhead==NULL)
                newhead=newptr;
            else
            {
            newptr->next=newhead;
            newhead=newptr;
            }
        }
        ptr1=ptr1->next;
    }
    head=newhead;
}

int main()
{
    int q;
    verticalshelf v;
    horizontalshelf h;
    cin>>q;
    //cout<<q<<endl;
    while(q--)
    {
        string s,t1,a1;
        cin>>s;
        char c;
        int y1,p1,n;
        if(s=="ADD")
        {
            cin>>c;
            cin>>t1;
            cin>>a1;
            cin>>y1>>p1;
            if(c=='h')
            h.addBook(t1,a1,y1,p1);
            else 
                v.addBook(t1,a1,y1,p1);
        }
        else if(s=="REMOVE")
        {   
            cin>>n;
            cin>>c;
            if(c=='h')
            {
                while(n--)
                {
                    h.removeBook();
                }
            }
            else 
            {
                while(n--)
                    v.removeBook();
            }
        }
        else if(s=="LIST")
        {
            cin>>c;
            //cout<<c<<endl;
            if(c=='h')
                h.list();
            else 
                v.list();
        }
        else if(s=="FINDC")
        {
            cin>>c;
            if(c=='h')
                h.findCheap();
            else 
                v.findCheap();
        }
        else if(s=="REVUNI")
        {
            cin>>c;
            if(c=='h')
                h.reverseUnique();
            else 
                v.reverseUnique();
        }
    }
    return 0;
}