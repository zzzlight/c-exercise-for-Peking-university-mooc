#include<stdio.h>
#include<algorithm>

using namespace std;


struct Station
{
	double price;
	double distance;
}station[505];
bool flag;   //final������±�Ҳ�Ƿ�Χ��  start�ǵ�ǰλ�� 
int findminprice(int start,int final) //�ҳ���һ����������ڵ�ǰ�� λ�ü��۸� ����ȫ����ʱ���ҳ��ڶ�С��վλ�úͼ۸� 
{												 
	int ansid=0;
	int i;
	for(i=start+1;i<=final;i++)
	{
		if(station[i].price<station[start].price) 
		{
			return i;
		}
	}
	double secondmin=99999999;
	if(i==final+1)
	{
		for(int j=start+1;j<=final;j++)
		{
			if(station[j].price<secondmin) 
			{
				secondmin=station[j].price;
				ansid=j;
			}
		}
	 } 
	return ansid;
}
bool cmp(Station a,Station b)
{
	return a.distance<b.distance;
}
int main()
{
	bool mark=false; 
	double capacity;
	double distance;
	double price;
	int num;
	double nowcapacity=0;
	double nowdistance=0;
	double maxdistance;
	double cost=0;
	scanf("%lf %lf %lf %d",&capacity,&distance,&price,&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lf",&station[i].price);
		scanf("%lf",&station[i].distance);
	}
	station[num].distance=distance;
	station[num].price=0;
	sort(station,station+num+1,cmp);
	num=num+1;
	if(station[0].distance!=0) 
	{
		printf("The maximum travel distance = 0.00");  
		mark=true;  //ע��˴������Ҫ�ֿ� ������0.000.00�� 
	}
	else
	{
		nowcapacity=0; 
		int nowstation=0;
		int maxreach=-1;
		while(1)
		{
			if(station[nowstation].distance==distance) break;
			int count=0;
			for(int x=nowstation+1;x<num;x++)
			{
				if(station[x].distance<=station[nowstation].distance+capacity*price) count++;
			}
			maxreach=nowstation+count;
			if(count==0) 
			{
				flag=true;
				maxdistance=station[nowstation].distance+capacity*price; 
				break;
			}
			int temp=findminprice(nowstation,maxreach);
			if(station[temp].price<station[nowstation].price)  //�ҵõ����ڵ�ǰ�� 
			{
				
				if(station[temp].distance<distance)   //�ж��Ƿ������� 
				{
					if(nowcapacity>(station[temp].distance-station[nowstation].distance)/price)
					{
						nowcapacity-=(station[temp].distance-station[nowstation].distance)/price;
						cost+=0;                
					}
					else
					{
						cost+=(station[temp].distance-nowcapacity*price-station[nowstation].distance)/price*station[nowstation].price;
						nowcapacity=0;          //cost�Ǵ�nowstation�㵽��һ����Ļ��� ע�⣺����nowcapacity�ǵ���һ���㴦ʱ������� 
					}
				
					nowdistance=station[temp].distance;
					nowstation=temp;
				}
				else 
				{
					cost+=(station[temp].distance-nowcapacity*price-station[nowstation].distance)/price*station[nowstation].price;
					nowstation=temp;                            //�����ĵ��� ���㵽�յ�Ļ��Ѻ� �´���ֱ����break 
				}
				
			}
			else //�Ҳ������ڵ�ǰ�� 
			{
				if(station[temp].distance<distance) 
				{
					if(nowcapacity>(station[temp].distance-station[nowstation].distance)/price)
					{
						cost+=(capacity-nowcapacity)*station[nowstation].price;
						nowcapacity=capacity-(station[temp].distance-station[nowstation].distance)/price;
					}
					else
					{
						cost+=(capacity-nowcapacity)*station[nowstation].price;
						nowcapacity=capacity-(station[temp].distance-station[nowstation].distance)/price;
					}
					
					nowstation=temp;
					nowdistance=station[temp].distance;	
				}
			
			
			}
			
		}
	}
	if(mark==false)
	{
			if(flag==true) printf("The maximum travel distance = %0.2lf",maxdistance);
		else
		{
			printf("%0.2lf",cost);
		}
	}

 } 
