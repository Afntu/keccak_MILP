#include<stdio.h>	

int main()
{
	int i,j,r,k,n,l,w;
	n = 1;
	l = 4;
	
	int rho_val[5][5] = { 0, 36, 3, 105, 210, 
			       1, 300, 10, 45, 66,
			      190, 6, 171, 15, 253,
			      28, 55, 153, 21, 120,
			      91, 276, 231, 136, 78 };
	
	//printf("Enter the number of rounds\n"); //Number of Rounds is denoted by n.
	//scanf("%d",&n);
	//printf("Enter the number of lane\n"); //Number of lane denoted by l and l is in {0,1,2,3,4,5,6} and w = 2^l.
	//scanf("%d",&l);
	w = (1 << l);  // w = 2^l.
	printf("Minimize\n");
	for(r = 0;r < n;r++)
	{
		for(j = 0;j < 5 ;j++)
		{
			for(k = 0;k < w;k++)
                       {   
				if( j == 4 && k == w - 1 && r == n - 1)
					printf("A_%d_%d_%d ",r,j,k);
				else
					printf("A_%d_%d_%d + ",r,j,k);	
	                }
	        }
	 }         
	printf("\n");
	printf("\nSubject To\n\n");
	
//inequalities for Computing parity bits

	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(k = 0;k < w;k++)
			{
				for(j = 0;j < 5 ;j++)
				{
					if(j == 4)
						printf("x_%d_%d_%d_%d + p_%d_%d_%d - 2d_%d_%d_%d >= 0",r,i,j,k,r,i,k,r,i,k);
					else
						printf("x_%d_%d_%d_%d + ",r,i,j,k);	
				}
				printf("\n");
				for(j = 0;j < 5 ;j++)
				{
					if(j == 4)
						printf("- x_%d_%d_%d_%d - p_%d_%d_%d + 2d_%d_%d_%d >= 0\n",r,i,j,k,r,i,k,r,i,k);
					else
						printf("- x_%d_%d_%d_%d ",r,i,j,k);	
				}
				printf("\n");
			}
		}
	}			
	printf("\n");
	for(r = 0; r < n;r++)
	{	
		for(i = 0;i < 5;i++)
		{
			for(k = 0;k < w;k++)
			{
			
				for(j = 0;j < 5;j++)
				{
					if( i == 4 && j == 4 && k == w-1)
						printf("x_%d_%d_%d_%d >= 1 ",r,i,j,k);
					else
						printf("x_%d_%d_%d_%d + ",r,i,j,k);	
				}
			}
		}
	}	
	printf("\n");
	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(k = 0;k < w;k++)
			{
				for(j = 0;j < 5 ;j++)
				{
					printf("d_%d_%d_%d - x_%d_%d_%d_%d >= 0 \n",r,i,k,r,i,j,k);
				}
				printf("d_%d_%d_%d - p_%d_%d_%d >= 0 \n",r,i,k,r,i,k);
			}
		}
	}
	printf("\n");

//parity bits inequality done, now for theta	

	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(k = 0;k < w;k++)
			{
				for(j = 0;j < 5 ;j++)
				{
					printf("x_%d_%d_%d_%d + p_%d_%d_%d + p_%d_%d_%d + y_%d_%d_%d_%d - 2e_%d_%d_%d_%d >= 0 \n",r,i,j,k,r,((i + 4)%5),k,r,((i + 1)%5),((k - 1 + w)%w),r,i,j,k,r,i,j,k);  // Here (i-1) is considered as (i -1 + w) in (mod w). and k-1 as k+4. 
					printf("- x_%d_%d_%d_%d - p_%d_%d_%d - p_%d_%d_%d - y_%d_%d_%d_%d + 2e_%d_%d_%d_%d >= 0 \n",r,i,j,k,r,((i + 4)%5),k,r,((i + 1)%5),((k -1 + w)%w),r,i,j,k,r,i,j,k);
					printf("\n");
					printf("e_%d_%d_%d_%d - x_%d_%d_%d_%d >= 0 \n",r,i,j,k,r,i,j,k);
					printf("e_%d_%d_%d_%d - p_%d_%d_%d >= 0 \n",r,i,j,k,r,((i+4)%5),k);
					printf("e_%d_%d_%d_%d - p_%d_%d_%d >= 0 \n",r,i,j,k,r,((i+1)%5),((k - 1 + w)%w));
					printf("e_%d_%d_%d_%d - y_%d_%d_%d_%d >= 0 \n",r,i,j,k,r,i,j,k);
					printf("\n");
				}	
			}
		}
	}

// Rho and after that Pi permutation is applied
	
	
// Sbox Chi Modeling
	
		
	for(r = 0;r < n;r++)
	{
		for(j = 0;j < 5;j++)
		{
			for(k = 0;k < w;k++)
			{
				for(i = 0;i < 5 ;i++)
				{
					printf("A_%d_%d_%d - y_%d_%d_%d_%d >= 0 \n",r,j,k,r,((i + 3*j)%5),i,((k - rho_val[((i + 3*j)%5)][i] + 300*w )%w));
				}	
			}
		}
	}
	printf("\n");

	for(r = 0;r < n;r++)
	{
		for(j = 0;j < 5;j++)
		{
			for(k = 0;k < w;k++)
			{
				for(i = 0;i < 5 ;i++)
				{
					if(i == 4)
						printf("y_%d_%d_%d_%d - A_%d_%d_%d >= 0 ",r,((i + 3*j)%5),i,((k - rho_val[((i + 3*j)%5)][i] + 300*w )%w),r,j,k);
					else
						printf("y_%d_%d_%d_%d + ",r,((i + 3*j)%5),i,((k - rho_val[((i + 3*j)%5)][i] + 300*w )%w));			
				}
			printf("\n");		
			}
		}
	}
printf("\n");
	for(r = 0;r < n;r++)
	{
		for(k = 0;k < w;k++)
		{
			for(j = 0;j < 5;j++) 
			{
				printf("5 z_%d_0_%d_%d + 5 z_%d_1_%d_%d + 5 z_%d_2_%d_%d + 5 z_%d_3_%d_%d + 5 z_%d_4_%d_%d - y_%d_%d_0_%d - y_%d_%d_1_%d - y_%d_%d_2_%d - y_%d_%d_3_%d - y_%d_%d_4_%d >= 0 \n",r,j,k,r,j,k,r,j,k,r,j,k,r,j,k,r,((0 + 3*j)%5),((k - rho_val[((0 + 3*j)%5)][0] + 300*w )%w),r,((1 + 3*j)%5),((k - rho_val[((1 + 3*j)%5)][1] + 300*w )%w),r,((2 + 3*j)%5),((k - rho_val[((2 + 3*j)%5)][2] + 300*w )%w),r,((3 + 3*j)%5),((k - rho_val[((3 + 3*j)%5)][3] + 300*w )%w),r,((4 + 3*j)%5),((k - rho_val[((4 + 3*j)%5)][4] + 300*w )%w));
				
				printf("5 y_%d_%d_0_%d + 5 y_%d_%d_1_%d + 5 y_%d_%d_2_%d + 5 y_%d_%d_3_%d + 5 y_%d_%d_4_%d - z_%d_0_%d_%d - z_%d_1_%d_%d - z_%d_2_%d_%d - z_%d_3_%d_%d - z_%d_4_%d_%d >= 0 \n",r,((0 + 3*j)%5),((k - rho_val[((0 + 3*j)%5)][0] + 300*w )%w),r,((1 + 3*j)%5),((k - rho_val[((1 + 3*j)%5)][1] + 300*w )%w),r,((2 + 3*j)%5),((k - rho_val[((2 + 3*j)%5)][2] + 300*w )%w),r,((3 + 3*j)%5),((k - rho_val[((3 + 3*j)%5)][3] + 300*w )%w),r,((4 + 3*j)%5),((k - rho_val[((4 + 3*j)%5)][4] + 300*w )%w),r,j,k,r,j,k,r,j,k,r,j,k,r,j,k);

			}
		}
	}	

printf("\n");
	for(r = 0;r < n;r++)
	{
		for(k = 0;k < w;k++)
		{
			for(j = 0;j < 5;j++)
			{
				printf("y_%d_%d_0_%d + y_%d_%d_1_%d + y_%d_%d_2_%d + y_%d_%d_3_%d + y_%d_%d_4_%d + z_%d_0_%d_%d + z_%d_1_%d_%d + z_%d_2_%d_%d + z_%d_3_%d_%d + z_%d_4_%d_%d - 2 f_%d_%d_%d >= 0 \n",r,((0 + 3*j)%5),((k - rho_val[((0 + 3*j)%5)][0] + 300*w )%w),r,((1 + 3*j)%5),((k - rho_val[((1 + 3*j)%5)][1] + 300*w )%w),r,((2 + 3*j)%5),((k - rho_val[((2 + 3*j)%5)][2] + 300*w )%w),r,((3 + 3*j)%5),((k - rho_val[((3 + 3*j)%5)][3] + 300*w )%w),r,((4 + 3*j)%5),((k - rho_val[((4 + 3*j)%5)][4] + 300*w )%w),r,j,k,r,j,k,r,j,k,r,j,k,r,j,k,r,j,k);
				for(i = 0;i < 5;i++)
				{
					printf("f_%d_%d_%d - z_%d_%d_%d_%d >= 0\n",r,j,k,r,i,j,k);
					printf("f_%d_%d_%d - y_%d_%d_%d_%d >= 0\n",r,j,k,r,((i + 3*j)%5),i,((k - rho_val[((i + 3*j)%5)][i] + 300*w )%w));
				}
				
			}
		}
	}	
		
	printf("\nBinary\n");
	
	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(j = 0;j < 5 ;j++)
			{
				for(k = 0;k < w;k++)
				{
					printf("x_%d_%d_%d_%d\n",r,i,j,k);	
	                       }
	                }
	         }
	 }                     
	for(r = 0;r < n;r++)
		for(i = 0;i < 5;i++)
			for(k = 0;k < w;k++)
				printf("p_%d_%d_%d\n",r,i,k);		
	
	for(r = 0;r < n;r++)
	{
		for(j = 0;j < 5 ;j++)
		{
			for(k = 0;k < w;k++)
                       {   
				printf("f_%d_%d_%d\n",r,j,k);
	                }
	        }
	 }              
	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(j = 0;j < 5 ;j++)
			{
				for(k = 0;k < w;k++)
				{
			        	printf("y_%d_%d_%d_%d\n",r,i,j,k);
			        }
			 }
		}
	}		        					
	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(j = 0;j < 5 ;j++)
			{
				for(k = 0;k < w;k++)
				{
					printf("z_%d_%d_%d_%d\n",r,i,j,k);	
				}
			}
		}		
	}
	printf("\nGeneral\n");	
	
	for(r = 0;r < n;r++)
	{
		for(i = 0;i < 5;i++)
		{
			for(j = 0;j < 5 ;j++)
			{
				for(k = 0;k < w;k++)
				{
					printf("e_%d_%d_%d_%d\n",r,i,j,k);
	                       }
	                } 
	        }
	}                     
	for(r = 0;r < n;r++)
	{	for(i = 0;i < 5;i++)
		{
			for(k = 0;k < w;k++)
			{
				printf("d_%d_%d_%d\n",r,i,k);	
			}
		}	     									        	}									
				
					
	return 0;	
}
