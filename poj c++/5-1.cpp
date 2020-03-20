#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
	char * s;
	public :
		MyString(){
			s=NULL;
		}
		MyString (const char* t)
		{
			int len=strlen(t);
			s=new char[len+1];
			for(int i=0;i<len;i++)
			{
				s[i]=t[i];	
			}	
			s[len]='\0';
		}
		MyString(const MyString& tt)
		{
			s=new char[strlen(tt.s)+1];
			strcpy(s,tt.s);
		}
	 MyString operator() (int start,int end)
	 {
	 	MyString temp;
	 	temp.s=new char[end];
	 	for(int i=0;i<end;i++)
	 	{
	 		temp.s[i]=this->s[i+start];
		 }
		 temp.s[end]='\0';
		 return temp;
	 }
	char& operator[](int i) { return s[i]; }
	friend ostream& operator<<(ostream &os,const MyString &t)
	{
		if(t.s==NULL) return os;
		else 
		{
			os<<t.s;
			return os;
		}
	}
	 
     MyString operator+(const MyString &rhs)
    {
         MyString res;
         int n = strlen(s) + strlen(rhs.s);
         res.s = new char[n];
         strcpy(res.s, s);
         strcat(res.s, rhs.s);
         return res;
     }
     MyString operator+(const char *rhs)
     {
         MyString res;
         MyString r(rhs);
         res = *this + r;  //调用前一个+ 
         return res;
     }
      MyString operator+=(const char *rhs)
     {
         MyString res;
         MyString r(rhs);
         res = *this + r;  
        *this=res;  //改变自己值 
         return res;
     }
	friend MyString operator+(const char *str,const MyString &t)
	{
		MyString temp(str);
	//	temp=temp+t;
		return temp+t;
	}
	bool operator < (const MyString & rhs) {
         int flag=strcmp(s, rhs.s);
         if (flag == -1)
            return true;
        else
        {
            return false;
        }
   }
     bool operator > (const MyString & rhs) {
         int flag = strcmp(s, rhs.s);
         if (flag == 1)
              return true;
         else
          {
             return false;
         }
    }
      bool operator ==(const MyString & rhs) {
         int flag = strcmp(s, rhs.s);
         if (flag == 0)
              return true;
          else
          {
             return false;
         }
     }
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
