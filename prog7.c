#include<stdio.h>
#include<string.h>
void main()
{
	int count,src_router,i,j,v,w,min;
	int cost_matrix[100][100],dist[100],last[100],flag[100];
	printf("Enter the number of nodes\n");
	scanf("%d",&count);
	printf("Enter the cost matrix\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			printf("\n%d--->%d ",i,j);
			scanf("%d",&cost_matrix[i][j]);
			if(cost_matrix[i][j]<0)
				cost_matrix[i][j]=999;
		}
	}
	printf("Enter the source node\n");
	scanf("%d",&src_router);
	for(v=0;v<count;v++)
	{
		flag[v]=0;
		last[v]=src_router;
		dist[v]=cost_matrix[src_router][v];
	}
	flag[src_router]=1;
	for(i=0;i<count;i++)
	{
		min=999;
		for(w=0;w<count;w++)
		{
			if(!flag[w])
				if(dist[w]<min)
				{
					v=w;
					min=dist[w];
				}
		}
		flag[v]=1;
		for(w=0;w<count;w++)
		{
			if(!flag[w])
				if(min+cost_matrix[v][w]<dist[w])
				{
					dist[w]=min+cost_matrix[v][w];
					last[w]=v;
				}
		}
	}
	for(i=0;i<count;i++)
	{
		printf("\n%d--->%d",src_router,i);
		w=i;
		printf("\nShortest path cost = %d\n",dist[i]);
	}
}
