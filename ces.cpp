#include<iostream>
#include<vector>
#include<memory>
#include<thread>
using namespace std;
int ces = 10;
void Merge(vector<int>&, int , int , int);
void swap(int &x, int & y) {
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}
void bubbleSort(vector<int> arr) {
	int n = arr.size();
	for(int i = n - 1; i >= 1; --i) {
		for(int j = 0; j < i; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	cout<<"after bubblesort:";
	for(auto& s : arr) {
		cout<<s<<" ";
	}
}
void selectSort(vector<int> arr) {
	int n = arr.size();
	for(int i = 0; i < n - 1; i++) {
		int temp = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[temp]) {
				temp = j;
			}
		}
		if(temp != i) {
			swap(arr[temp], arr[i]);
		}
	}
	cout<<"after selectsort:";
	for(auto& s : arr) {
		cout<<s<<" ";
	}
}
void insertSort(vector<int> arr) {
	
	
	int n = arr.size();
	for(int i = 1; i < n; i++) {
		int temp = arr[i];
		int j = i - 1;
		while(j >= 0) {
			if(arr[j] > temp) {
				arr[j + 1] = arr[j];
				j--;
			}else {
				
				break;
			}
		}
		arr[j + 1] = temp;
	}
	cout<<"after insertsort:";
	for(auto& s : arr) {
		cout<<s<<" ";
	}
	
}
void quickSort(vector<int>& arr, int left, int right) {
	if(left >= right) return;
	int pivot = arr[left],start = left ,end = right;
	while(left < right) {
		while(arr[right] >= pivot && left < right) {
			right--;
		}
		if(left < right) {
			arr[left] = arr[right];
			left++;
		}
		while(arr[left] <= pivot && left < right) {
			left++;
		}
		if(left < right) {
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = pivot;
	quickSort(arr, start, left - 1);
	quickSort(arr, left + 1, end);
}
void mergeSort(vector<int>& arr, int left, int right) {
	if(left == right) return;
	int mid = left + (right - left) / 2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}
void Merge(vector<int>& arr, int left, int mid, int right) {
	int start2 = mid + 1, start1 = left;
	vector<int> temp;
	while(left <= mid || start2 <= right) {
		if(left > mid) {
			temp.push_back(arr[start2]);
			start2++;
		}else if(start2 > right){
			temp.push_back(arr[left]);
			left++;
		}else {
			int val = arr[left] <= arr[start2] ? arr[left++] : arr[start2++];
			temp.push_back(val);
		}
	}
	
	for(int i = 0; i<temp.size(); i++) {
		arr[i+start1] = temp[i];
	}

}

int main() {
	vector<int> Input = {10,4,7,9,10,11,5,8,15,20,8,2,14,1,6};
	cout<<"before sort:";
	for(auto& s : Input) {
		cout<<s<<" ";
	}
	cout<<endl;
	bubbleSort(Input);
	cout<<endl;
	selectSort(Input);
	cout<<endl;
	insertSort(Input);
	cout<<endl;
	quickSort(Input, 0, 14);
	cout<<"after quicksort:";
	for(auto& s : Input) {
		cout<<s<<" ";
	}
	cout<<endl;
	vector<int> Input2 = {10,4,7,9,10,11,5,8,15,20,8,2,14,1,6};
	cout<<"before sort:";
	for(auto& s : Input2) {
		cout<<s<<" ";
	}
	cout<<endl;
	cout<<"after mergesort:";
	mergeSort(Input2, 0, 14);
	for(auto& s : Input2) {
		cout<<s<<" ";
	}
	
	
}
	/*std::unique_ptr<int> ptr(new int(5));
	std:: shared_ptr<int> ptr1(new int (6));
	int * a  =new int(10);
	{
	std::shared_ptr<int> ptr3 = ptr1;
	std::cout<<ptr1.use_count();
	}
	std::cout<<ptr1.use_count();*/




//大根堆 
/*void swap(int& x, int& y) {
	x = x ^ y;
	y = x ^ y;
	x = x ^ y; 
}
void maxHeapify(std::vector<int>& heap, int n, int parent) {
	int largest = parent;
	int leftChild = 2 * parent + 1;
	int rightChild = 2 * parent + 2;
	if(leftChild < n && heap[leftChild] > heap[largest]) {
		largest = leftChild;
	} 
	if(rightChild < n && heap[rightChild] > heap[largest]) {
		largest = rightChild;
	}
	if(largest != parent) {
		std::cout<<"调整过两个点"<<heap[parent]<<"和"<<heap[largest]<<"交换"<<std::endl; 
		swap(heap[parent],heap[largest]);
		
		maxHeapify(heap, n, largest);
	} 
}
void heapSort(std::vector<int>& heap, int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		std::cout<<"开始"<<i<<std::endl; 
		maxHeapify(heap, n, i);
	}
	for(int i = n - 1; i > 0; --i){
		std::cout<<"最后调整"<<i<<std::endl; 
		swap(heap[0], heap[i]);
		maxHeapify(heap, i, 0);
	} 
}
int main() {
	int n;
	std::cin>>n;
	std::vector<int> heap(n);
	for(int i = 0; i < n; i++) {
		std::cin>>heap[i];
	}
	heapSort(heap, 10);
	for(auto& h : heap)
		std::cout<<h<<" ";
	
}*/
