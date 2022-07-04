#include<stdio.h>
#include<math.h>

int main()
{
	int i,j,r,k,n,l,w;
	int rho_val[5][5] = { 0, 36, 3, 105, 210, 
			       1, 300, 10, 45, 66,
			      190, 6, 171, 15, 253,
			      28, 55, 153, 21, 120,
			      91, 276, 231, 136, 78 };
	printf("Enter the number of rounds\n"); //Number of Rounds is denoted by n.
	scanf("%d",&n);
	printf("Enter the number of lane\n"); //Number of lane denoted by l and l is in {0,1,2,3,4,5,6} and w = 2^l.
	scanf("%d",&l);
	w = pow(2,l);
	
	// after rho operation   Rho(y_i_j_((k + rho_val[i][j])%w)) =  z_i_j_k
	
	for(k = 0;k < w;k++)
	{
		for(j = 0;j < 5 ;j++)
		{
			for(i = 0;i < 5;i++)
			{
				//printf("Rho(y_%d_%d_%d) = z_%d_%d_%d \n",i,j,((k + rho_val[i][j])%w),i,j,k);
				printf("Rho(y_%d_%d_%d) = y_%d_%d_%d \n",i,j,k,i,j,((k + rho_val[i][j] +62*w)%w)); 
			}	
		}
	}
}	
