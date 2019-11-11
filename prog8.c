#include<stdio.h>
#define max 10
struct dist_vect
{
	int dist[max];
	int from[max];
};

int main()
{
	int adj[max][max],i,j,k,n,count,hop[10][10]={{10}};
	struct dist_vect arr[10];
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&adj[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			arr[i].dist[j]=adj[i][j];
			arr[i].from[j]=j;
		}
	count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(arr[i].dist[j]>adj[i][k]+arr[k].dist[j])
				{
					arr[i].dist[j]=adj[j][k]+arr[k].dist[j];
					arr[i].from[j]=k;
					count++;
					if(count==0)
						hop[i][j]=1;
					else
						hop[i][j]=count+hop[k][j];
				}
			}
			count=0;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("State value of router %d\n",i+1);
		printf("\nnode\tvia node\tdistance\tno. of hop\n");
		for(j=0;j<n;j++)
		{
			if(i==j)
				printf("\n%d\t%d\t%d\n",j+1,arr[i].from[j+1],arr[i].dist[j]);
			else
				printf("\n%d\t%d\t%d\t%d\n",j+1,arr[i].from[j]+1,arr[i].dist[j],hop[i][j]+1);
		}
	}
}
