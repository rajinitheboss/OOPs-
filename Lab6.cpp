#include<bits/stdc++.h>

using namespace std;

class node
{
    bool isend;
    vector<node *> next;
    friend class trie;
    public:
    node()
    {
        isend=false;
        for(int i=0;i<26;i++)
        {
            next.push_back(NULL);
        }
    }
};
class trie
{
    node *root;
    public:
    trie()
    {
        root=new node;
    }
    void addprefix(string s)
    {
        node * ptr=root;
        for(int i=0;i<s.length();i++)
        {
            if(!(ptr->next)[s[i]-'a'])
            {
                (ptr->next)[s[i]-'a'] = new node;
                ptr=(ptr->next)[s[i]-'a'];
            }
            else
            {
                ptr=(ptr->next)[s[i]-'a'];    
            }
        }
        ptr->isend=true;
    }
    string crtstring(string s)
    {
        string maxstring="";
        string currentstring="";
        node* ptr=root;
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if((ptr->next)[s[i]-'a'])
            {
                if(ptr->isend==true)
                {
                    flag=1;
                    maxstring=currentstring;
                }
                currentstring=currentstring+s[i];
                ptr=(ptr->next)[s[i]-'a'];
            }
            else
            {
                if(ptr->isend==true)
                {
                    return currentstring;
                }
                else
                {
                    break;
                }
            }
        }
        if(flag)
            return maxstring;
        else if(ptr->isend==1)
            return currentstring;
        else 
            return s;
    }
};

int main()
{
    int n;
    cin>>n;
    trie t;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        t.addprefix(s);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        cout<<t.crtstring(s)<<" ";
    }
    return 0;
}