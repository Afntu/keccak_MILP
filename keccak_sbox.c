#include<stdio.h>
#include<math.h>
int jth_bit(int a,int j) //This function return the ith bit of a nonnegative integer a. 
{
       int b = (a >> j) & 1;    //b is i th bit of a
       return b;
}

int main()
{
	int a[5],b[5],s[32],n,i;
	
	for(int k = 0; k < 32; k++ )
	{
		for(int j = 0; j < 5; j++)
		{
			a[4-j] = jth_bit(k,j);
		}
		int d = 0;
		for(i = 0; i < 5; i++ ) 
	        {
	                b[i] = a[i] ^ (~a[(i+1)%5] & a[(i+2)%5]) ;
		        d = d + b[i]*pow(2,4-i);
	        }
	        s[k] = d;
	        printf("s[%d] = %d\n",k,d);
        }
        printf("s[32] = {%d,",s[0]);
        for(int k = 1; k < 31; k++ )
        {
        	printf("%d,",s[k]);		
	}
	printf("%d}\n",s[31]);
}
