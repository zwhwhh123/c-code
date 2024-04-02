#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sum=0;
        
     for(int i=0;i<grid.size();i++)
     {
         for(int j=0;j<grid.size();j++)
         {
             if(grid[i][j]==1)
             {queue<pair<int,int>> a;
             a.emplace(i,j);
                  sum++;
                while(!a.empty())
                {     int left,right;
                left=a.front().first,right=a.front().second;
                grid[left][right]=0;                
                if(left<0||left>=grid.size()||right<0||right>=grid[0].size()||grid[left][right]==0)
                    a.pop();
                else if(left-1>=0&&grid[left-1][right]==1)
                    a.emplace(left-1,right);                    
                else if(left+1<grid.size()&&grid[left+1][right]==1)
                a.emplace(left+1,right);
                else if(right-1>=0&&grid[left][right-1]==1)
                a.emplace(left,right-1);
                else if(right+1<grid[0].size()&&grid[left][right+1]==1)
                a.emplace(left,right+1);
                
         }
     }
         }}
    return sum;
    }
    int main()
    {
    vector<vector<int>> grid(8,vector<int>(13));
    for(int i=0;i<8;i++)
    for(int j=0;j<13;j++)
    cin>>grid[i][j];
    cout<<maxAreaOfIsland(grid);
    return 0;
    
	}
