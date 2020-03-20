#include <iostream>
#include<set> 
#include<map>
#include<string>
using namespace std;

set<int> myset;
map<int,int> mymap;
map<int,int> record;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string temp;
		cin>>temp;
		int number;
		cin>>number;
		if(temp=="add")
		{
			myset.insert(number);
			mymap[number]++;
			record[number]++;
			cout<<mymap[number]<<endl;
		}
		else if(temp=="ask")
		{
			if(record[number]>0)
			{
				cout<<"1 ";
				cout<<mymap[number]<<endl;
			}
			else
			{
				cout<<"0 0"<<endl;
			}
		}
		else if(temp=="del")
		{
			myset.erase(number);
			cout<<mymap[number]<<endl;
			mymap[number]=0;
			
		}
	}
	return 0;
}
