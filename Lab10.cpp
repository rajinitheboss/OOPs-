#include<bits/stdc++.h>
using namespace std;

class base{
    private:
    public:
        int bagweight;
        int n;
        vector<int> revenue;
        vector<int> weights;
        base()
        {
            cin>>bagweight;
            cin>>n;
            revenue.resize(n);
            weights.resize(n);
            for(int i=0;i<n;i++)
            {
                cin>>revenue[i];
            }
            for(int i=0;i<n;i++)
            {
                cin>>weights[i];
            }
        }
        virtual int optimumvalues()
        {return 0;}
};
class inherited:public base{
    public:
        int optimumvalues()
        {
            return optimumvalues(bagweight,n,revenue,weights);
        }
        int optimumvalues(int bagweight,int n,vector<int> &revenue,vector<int> &weights)
        {
            vector<int> opt;
            for(int i=0;i<bagweight+1;i++)
            {
                if((i)<*(min_element(weights.begin(),weights.end())))
                    opt.push_back(0);
                else 
                {
                    int ans=INT_MIN;
                    for(int j=0;j<n;j++)
                    {
                        if(weights[j]<=i)
                        {
                            if(ans<revenue[j]+opt[i-weights[j]])
                                ans=revenue[j]+opt[i-weights[j]];
                        }
                    }
                    opt.push_back(ans);
                }
            }
            return opt[bagweight];
        }

};
int main()
{
    inherited h;
    cout<<h.optimumvalues()<<endl;
    return 0;
}