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
	//printf("Enter the number of rounds\n"); //Number of Rounds is denoted by n.
	//scanf("%d",&n);
	printf("Enter the number of lane\n"); //Number of lane denoted by l and l is in {0,1,2,3,4,5,6} and w = 2^l.
	scanf("%d",&l);
	w = pow(2,l);
	
	// after rho operation Pi_Rho(y_i_j_k) =  y_((3*j - 4*i)%5)_i_((k - rho_val[i][j])%w) 
	
	for(j = 0;j < 5 ;j++)
	{
		for(k = 0;k < w;k++)
		{
			for(i = 0;i < 5;i++)
			{
				printf("Pi_Pho(y_%d_%d_%d) = y_%d_%d_%d \n",i,j,k,((i + 3*j)%5),i,((k - rho_val[((i + 3*j)%5)][i] + 300*w )%w));// here 300w is just to adjust the negative value in (mod w) 
			}	
		}
	}
}	
