#include<iostream>
#include<string>
using namespace std;
class solution{
		public:	char zwh;
			int qwe(int a)
			{
				val=a;
				return val;
			}
			void zzz(string w)
			{if(w.length()>2)
				zwh=w[w.length()-1];
			   else zwh='n';
			}
			
			private:
				int val;
			
		
};
int main()
{
	solution q;
	int e;
	cin>>e;
	cout<<q.qwe(e);
	cout<<endl;
	string z;
	cin>>z;
	q.zzz(z);
	cout<<q.zwh;
	return 0;
	
}

