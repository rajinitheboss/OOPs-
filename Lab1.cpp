#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Matrix
{
    private:
        int rows;
        int columns;
        vector<vector<int> > mat;
    public:
    Matrix()
    {
        rows=0;
        columns=0;
    }
    Matrix(int x,int y)
    {
        rows=x;
        columns=y;
        mat.resize(rows);
        for(int i=0;i<rows;i++)
            mat[i].resize(columns);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
                mat[i][j]=0;
        }
    }
    Matrix(int x,int y,vector<vector<int> > m)
    {
        rows=x;
        columns=y;
        mat=m;
    }
        void setValue(int x,int y,int val)
        {
            mat[x-1][y-1]=val;
        }
        int getValue(int x,int y)
        {
            return mat[x-1][y-1];
        }
        int getNoRows()
        {
            return rows;
        }
        int getNoColumns()
        {
            return columns;
        }
        int trace()
        {
            if(rows!=columns)
                return -1;
            else
            {
                int sum=0;
                for(int i=0;i<rows;i++)
                {
                    sum=sum+mat[i][i];
                }
                return sum;
            }
            return 0;
        }
        bool isSpecialMatrix()
        {
            int sum=0;
            for(int i=0;i<columns;i++)
            {
                sum=sum+mat[0][i];
            }
            for(int i=1;i<rows;i++)
            {
                int parsum=0;
                for(int j=0;j<columns;j++)
                {
                    parsum=parsum+mat[i][j];
                }
                if(parsum!=sum)
                    return false;
            }
            for(int j=0;j<columns;j++)
            {
                int parsum=0;
                for(int i=0;i<rows;i++)
                {
                    parsum=parsum+mat[i][j];
                }
                if(parsum!=sum)
                    return false;
            }
            return true;
        }
        bool checkTriangular()
        {
            if(rows!=columns)
                return false;
            else 
            {
            int flag1=0;
            for(int i=0;i<rows;i++)
            {
                for(int j=i+1;j<columns;j++)
                {
                    if(mat[i][j]!=0)
                        flag1++;
                }
            }
            int flag2=0;
            for(int i=0;i<rows;i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(mat[i][j]!=0)
                        flag2++;
                }
            }
            if(flag1==0 || flag2==0)
                return true;
            else 
                return false;
            }
            return false;
        }
        void printSpiral()
        {
            int r1=0,r2=rows;
            int c1=0,c2=columns;
            while(r1<=r2 && c1<=c2)
            {
                if(r2-r1==1)
                {
                    for(int i=c1;i<c2;i++)
                        cout<<mat[r1][i]<<" ";
                    
                    r1++;
                    c1++;
                    r2--;
                    c2--;  
                }
                else if(c2-c1==1)
                {
                    for(int i=r1;i<r2;i++)
                        cout<<mat[i][c1]<<" ";
                    r1++;
                    c1++;
                    r2--;
                    c2--;
                }
                else
                {
                for(int i=c1;i<c2;i++)
                {
                    cout<<mat[r1][i]<<" ";
                }
                for(int i=r1+1;i<r2;i++)
                {
                    cout<<mat[i][c2-1]<<" ";
                }
                for(int i=c2-2;i>=c1;i--)
                {
                    cout<<mat[r2-1][i]<<" ";
                }
                for(int i=r2-2;i>=r1+1;i--)
                {
                    cout<<mat[i][c1]<<" ";
                }
                r1++;
                c1++;
                r2--;
                c2--;
                }
            }
            cout<<endl;
        }
    
};

int main()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int> > matrix(N,vector<int>(M));

    for(int i=0;i < N;i++)
    {
        for(int j=0;j<M;j++)
            cin>>matrix[i][j];
    }
    Matrix k(N,M,matrix);
    int q;
    cin>>q;
    while(q--)
    {
        int opcode;
        cin>>opcode;
        switch(opcode)
        {
            case 1:
                k.printSpiral();
                break;
            case 2:
                cout<<k.trace()<<endl;
                break;
            case 3:
                if(k.checkTriangular())
                    cout<<"true"<<endl;
                else    
                    cout<<"false"<<endl;
                break;
            case 4:
                if(k.isSpecialMatrix())
                    cout<<"true"<<endl;
                else 
                    cout<<"false"<<endl;
                break;
        }
    }
    return 0;
}

