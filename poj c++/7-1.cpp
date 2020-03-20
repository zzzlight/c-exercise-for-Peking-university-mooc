#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* n1,T* n2)
{
	T sum;
	for(T* temp=n1;temp!=n2;temp++)
	{
		sum+=*temp;
	}
	return sum;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //ÌáÊ¾£º1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}
