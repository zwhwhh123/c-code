#include<iostream>
#include<vector>
#include<ctime>
#include<mutex>
#include<thread>
#include<deque>
#include"test.cpp"
#define function1(a) a
using namespace std;
int k = 20;
inline void function(int i) {
	std::cout<<"这是第"<<i<<"个内联函数"; 
} 
class nihao {
public:
	 virtual int getV() {
		return this->val;
	}
virtual	~nihao() {
		cout<<"my val is "<<this->getV()<<"decon"<<endl;
	}
	nihao(int x = 1): val(x){
	cout<<"my val is "<<val<<"con"<<endl;}
private:
	int val;
	

};
class son  {
	public:
	 son():num(new int(0)) {
		cout<<"I am son's con   "<<++con<<endl;
	}
	son(const son &s): num(new int(*s.num)){
		cout<<"I am copy con of son: "<<++copy<<endl;
	}
	~son() {
		delete num;
		cout<<"I am son's decon: "<<++de<<endl;
	}
	int getV() {
		cout<<"son's getV()"<<endl;
		return 111;
	}
	int *num;
	static int con;
	static int copy;
	static int de; 
}; 
int son::con = 0;
int son::copy = 0;
int son::de = 0;

const int Num = 10;
std::deque<char> dq;
static std::mutex mtx;

void producer() {
	for(int i = 1; i < Num; i++) {
		mtx.lock();
		dq.push_front(i +'a');
		std::cout<<"当前放入产品:"<<dq.front()<<std::endl; 
		mtx.unlock();
	} 
}
void consumer() {
	while(true) {
		if(dq.empty()) {
			continue;
		}
	
		mtx.lock();
		char data = dq.back();
		dq.pop_back();
		std::cout<<"当前拿到产品:"<<data<<std::endl; 
		mtx.unlock();
	} 
}
son GET() {
	son b;
	return b;
}
int f(int *k, int & m) {
	*k = 10;
	m = 5;
	cout<<*k<<m;
}
void fun(){
	int a;
	cout<<a; 
} 
int quanju = 5;
void f1(int a, int b){
	cout<<a+b;
}
void f1(int a, double b){
	cout<<a - b;
}
 int main(){
	/*std::thread t1(producer);
	std::thread t2(consumer);
	t1.join();
	t2.join();*/

}
