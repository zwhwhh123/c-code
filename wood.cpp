#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{int w,firstm,secm;
vector<int> q;
vector<int> a;

	while(cin>>w)
	{	
	if(cin.get()=='\n') break;  	
		}
	while(cin>>w)
	{
    
		a.push_back(w);
		if(cin.get()=='\n') break;
	}
	int min=0;
	while(a.size()!=1)
{
sort(a.begin(),a.end(),greater<int>());
    firstm=a.back(); a.pop_back(); 
secm=a.back();
a.pop_back();
min+=(firstm+secm);
a.push_back(firstm+secm);
}
cout<<min;
	return 0;
}
