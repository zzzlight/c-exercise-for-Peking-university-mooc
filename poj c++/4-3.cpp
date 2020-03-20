#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
	friend ostream& operator <<(ostream & o,const Point &s)
	{
		o<<s.x<<","<<s.y;
		return o;
	}
	friend istream& operator >>(istream & o, Point &s)
	{
		o>>s.x>>s.y;
		return o;
	}
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
