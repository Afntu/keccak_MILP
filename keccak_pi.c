#include<stdio.h>
#include<math.h>

int main()
{
	int i,j,r,k,n,l,w;
	printf("Enter the number of rounds\n"); //Number of Rounds is denoted by n.
	scanf("%d",&n);
	printf("Enter the number of lane\n"); //Number of lane denoted by l and l is in {0,1,2,3,4,5,6} and w = 2^l.
	scanf("%d",&l);
	w = pow(2,l);
	
	// after pi operation pi(z_i_j_k) = t_j_((2*i + 3*j)%5)_k
	
	for(i = 0;i < 5;i++)
	{
		for(j = 0;j < 5 ;j++)
		{
			for(k = 0;k < w;k++)
			{
				//printf("Pi(z_%d_%d) = z_%d_%d \n",i,j,j,((2*i + 3*j)%5)); 
				printf("Pi(z_%d_%d_%d) = z_%d_%d_%d \n",i,j,k,((3*j + i)%5),i,k);
			}	
		}
	}
}	
