#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<char> result;
int myhash[800];
bool good[800];
string output;
int main()
{
	
	int num;
	cin>>num;
	string word;
	cin>>word;
	for(int i=0;i<word.size();)       //�����Ǵ�ǰ���� ���� �����˷��������ľ��Ǻü� 
	{
		int count=1;
		for(int j=i+1;j<word.size();j++)
		{
			if(word[j]!=word[i]) break;
			else count++;
		}
		if(count%num!=0||good[word[i]]==true) 
		{
			good[word[i]]=true;
			i++;
		}
		else 
		{
			i=i+num;    
		}
	
	}	
	for(int i=0;i<word.size();)
	{
		int count=1;
		for(int j=i+1;j<word.size();j++)
		{
			if(word[j]!=word[i]) break;
			else count++;
		}
		if(count%num!=0||good[word[i]]==true) 
		{
			good[word[i]]=true;
			output.push_back(word[i]);
			i++;
		}
		else 
		{
			output.push_back(word[i]);
			if(result.empty())result.push_back(word[i]);
			else
			{
				int flag=false;
				for(int t=0;t<result.size();t++)
				{
					if(result[t]==word[i]) flag=true;
				}
				if(flag==false&&good[word[i]]==false) result.push_back(word[i]);
			}
			i=i+num;      //���ǻ��� ÿnum������һ�� 
		}
	
	}	
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
	}
	cout<<endl;
	cout<<output;
 } 
