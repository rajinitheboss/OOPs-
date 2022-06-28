#include<bits/stdc++.h>
using namespace std;

int ironman(vector<int>&stones)
{
    int maxp=0; int index=0; int temp=0;
    for(int i=0;i<stones.size();i++)
    {
      if(stones.size()!=1)
      {    
        if(i==0){temp=stones[i]*stones[i+1];}
        else if(i==stones.size()-1){temp=stones[i]*stones[i-1];}
        else{temp=stones[i]*stones[i+1]*stones[i-1];}
      }
      else
      {
        temp=stones[0]; 
      }
      
      if(temp>maxp){maxp=temp; index=i;}
      else if(temp==maxp)
      {
        if(stones[i]<stones[index]){index=i;}
      }
    }
    vector<int> ::iterator it=stones.begin()+index;
    stones.erase(it);
    return maxp;
}

int main()
{
  int n; cin>>n; int sum=0;
  vector<int>stones(n);
  for(int i=0;i<n;i++){cin>>stones[i];}
  int thanos; cin>>thanos;
  while(n--)
  {
      int ma=ironman(stones);
    sum=sum+ma;
  }
  cout<<sum<<endl;
  if(sum>thanos){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;} 
  return 0;
}