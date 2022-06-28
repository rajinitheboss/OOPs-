#include<bits/stdc++.h>
using namespace std;

class Dictionary
{
    private:
        map<int,set<string> > m;
    public:
    void biuldDict(vector<string> words)
    {
        for(int i=0;i<(int)words.size();i++)
        {
            m[words[i].length()].insert(words[i]);
        }
        return;
    }
    void addWord(string s)
    {
        m[s.length()].insert(s);
    }
    bool search(string target)
    {
        set<string > ::iterator it;
        it=m[target.length()].find(target);
        if(it!=m[target.length()].end())
            return true;
        else 
            return false;
    }
    set<string> getWordsAfterReplace(string target)
    {
        set<string> s;
        set<string> :: iterator it;
        for(it=m[target.length()].begin();it!=m[target.length()].end();it++)
        {
            int flag=0;
            for(int j=0;j<(int)target.length();j++)
            {
                if(target[j]!=(*it)[j])
                {
                    flag++;
                    if(flag==2)
                    {
                        break;
                    }
                }
            }
            if(flag<=1)
                s.insert(*(it));
        }
        return s;
    }
    set<string> getWordsAfterSwap(string target)
    {
        set<string> s;
        set<string> s1=m[target.length()];
        for(int i=0;i<target.length()-1;i++)
        {
            string se=target;
            se[i]=target[i+1];
            se[i+1]=target[i];
            if(s1.find(se)!=s1.end())
                s.insert(se);
        }
        return s;
    }
    int maxChangeableWord()
    {
        int max=0;
        map<int,set<string> > ::iterator it;
        for(it=m.begin() ; it!=m.end();it++)
        {
            set<string> :: iterator it1;
            set<string> s=it->second;
            for(it1=s.begin();it1!=s.end();it1++)
            {
                int k=getWordsAfterReplace(*it1).size();
                if(k>max)
                    max=k;
            }
        }
        if(max==0)
            return max;
        else 
            return max-1;
    }
    int maxSwappableWord() 
    {
        int max=0;
        map<int,set<string> > ::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            set<string> :: iterator it1;
            set<string> s=it->second;
            for(it1=s.begin();it1!=s.end();it1++)
            {
                int k=getWordsAfterSwap(*it1).size();
                if(k>max)
                    max=k;
            }
        }
        return max;
    }
};

int main()
{
    int n;
    cin>>n;
    Dictionary d;
    vector<string> s;
    for(int i=0;i<n;i++)
    {
        string p;
        cin>>p;
        s.push_back(p);
    }
    d.biuldDict(s);
    int q;
    cin>>q;
    int x;
    for(int i=0;i<q;i++)
    {
        cin>>x;
        if(x==1)
        {
            string s;
            cin>>s;
            d.addWord(s);
        }
        else if(x==2)
        {
            string s;
            cin>>s;
            bool k=d.search(s);
            if(k)
                cout<<"true"<<endl;
            else 
                cout<<"false"<<endl;
        }
        else if(x==3)
        {
            string s;
            cin>>s;
            set<string> :: iterator it;
            set<string> se=d.getWordsAfterReplace(s);
            /*if(d.search(s)==1)
                se.insert(s);*/
            if(se.size()==0)
                cout<<"-1"<<endl;
            else 
            {
            for(it=se.begin();it!=se.end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
            }
        }
        else if(x==4)
        {
            string s;
            cin>>s;
            set<string> :: iterator it;
            set<string> se=d.getWordsAfterSwap(s);
            if(se.size()==0)
                cout<<"-1"<<endl;
            else 
            {
            for(it=se.begin();it!=se.end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
            }
        }
        else if(x==5)
        {
            cout<<d.maxChangeableWord()<<endl;
        }
        else if(x==6)
        {
            cout<<d.maxSwappableWord()<<endl;
        }
    }
    return 0;
}