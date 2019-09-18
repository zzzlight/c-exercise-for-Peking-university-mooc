#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int preorder[100];
int postorder[100];
bool flag=true;
vector<int> result;
struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
};

Node* create(int prel,int prer,int postl,int postr)
{
	//if(prel>prer) return NULL; �����ڵ��ڵ��ͽ������ж� �˴��Ͳ���Ҫ   ��������ڵ����ӽڵ㲻���ڵ���һ��ʱ���ٷ����õ�  ǰ�� ���� д���õĴ˷��� 
	Node* node=new Node;
	node->data=preorder[prel];
	node->leftchild=NULL;
	node->rightchild=NULL;
	if(prel==prer) 	return node;
	 //���ڽڵ㵽��ĩ��(����ĩ��)ʱ����ж� 
	int k=0;
	for(k=prel+1;k<=prer;k++)
	{
		if(preorder[k]==postorder[postr-1]) break;  //�����и���ǰһ�����ҽڵ�  ���������ҵ��õ�λ��  ÿ�ζ��ǵݹ��Ҹõ� 
	}
	if(k-prel>1) 
	{                    //postl+k-prel-2��postl+��k-1-��prel+1���� 
		node->leftchild=create(prel+1,k-1,postl,postl+k-prel-2);  //�ҵ��õ�� �õ�ǰ�沿��Ϊ������  �õ㼰���ұ�Ϊ������  �����ǽ������һ���ͺ������һ���߳������ҵ���������ڵ㣩 
		node->rightchild=create(k,prer,postl+k-prel-1,postr-1);
	}
	else
	{
		flag=false;    //���ڵ�ʱ�����ѡһ�� 
		node->rightchild=create(k,prer,postl+k-prel-1,postr-1);  
	}
	return node;
 } 
 void inorder(Node* root)
 {
 	if(root==NULL) return;
    inorder(root->leftchild);
 	result.push_back(root->data);
 	inorder(root->rightchild);
 	return ;
 	
 }
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&preorder[i]);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&postorder[i]);
	}

	Node* root=create(0,num-1,0,num-1);
	inorder(root);
	
	if(flag==true) printf("Yes\n");
	else
	{
		printf("No\n");
	}
	for(int i=0;i<result.size();i++)
	{
		printf("%d",result[i]);
		if(i!=result.size()-1) printf(" ");
	}
	printf("\n"); //������������ȫ��Ҫ���һ������ �����ʽ���� 
}


