/*Wallace Haviland
CS 1510 Section B
Due 2/13/15*/

#include <iostream>

using namespace std;

int main()
{
	
	int T,W,H;
cin>>T;

for(int k=0;k<T;k++)
{
	
	cin>>W;
	cin>>H;
	int doneH=3, doneW=3;
	int sum=0;
	int bestsum;
	int bestx, besty;
	
	int**p;
	p=new int*[H];
	
	for(int j=0;j<H;j++)
	{
		p[j]=new int [W];
	
	}	
	
	for(int m=0;m<H;m++)
	{
		for(int n=0;n<W;n++)
		{
			cin>>p[m][n];
		}
	}
	
	
	for(int y=0;y<=(H-3);y++)
	{
		for(int x=0;x<=(W-3);x++)
		{
			for(int u=y;u<doneH;u++)
			{
				for(int v=x;v<doneW;v++)
				{
					sum=sum+p[u][v];
				}
			}
			if(y==0&&x==0)
			{
				bestsum=sum;
				bestx=x;
				besty=y;
			}
			else if(sum<bestsum)
			{
				bestsum=sum;
				bestx=x;
				besty=y;
			}
			
		sum=0;

		doneW++;
				
		}
		doneW=3;
		doneH++;
	}
	
	cout<<"#"<<k<<": ("<<bestx<<", "<<besty<<") "<<bestsum<<endl;
	
	

	for(int d=0;d<H;d++)
		{
			delete [ ] p[d];
		}
	delete [] p;	
}

}

