#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000000 

int BigFact(int m, short data[]); 

int main()
{	
	short data[SIZE] = { 0 };	//存储SIZE位数，表示SIZE位的大数，并且初始化为0        	
	long long int i, j;  	
	printf("请输入想要计算阶乘数的数值:");	
	scanf("%I64d", &i);	
	int x = BigFact(i, data);		//计算阶乘i！，返回阶乘值的位数	
	if (x)         //判断数组是否溢出，无溢出则打印阶乘值，否则打印溢出提示信息	
	{		
		printf("%d! = ", i);		
		for (j = x - 1; j >= 0; j--)		//从最高位开始打印每一位阶乘值			
		printf("%d", data[j]);		
		printf("\n");	
	}	
	else        		
		printf("数据太大，溢出!\n"); 	

	return 0;

 }
 
 
/*****************************************************************************************/
/*功能描述：本函数用于实现计算自然数的阶乘值功能，目的是计算指定数的阶乘     */
/*入口参数：参数m，表示想要计算阶乘数的数值；数组data[]，表示用于存储阶乘结果的数组*/
/*出口参数：数组data[]，表示阶乘结果                                                                 */
/*返回值：返回0或x，当返回0时表示结果溢出，当返回其他数值时表示阶乘值的位数*/
/******************************************************************************************/
int BigFact(int m, short data[])
{	
	int i, j, k; 	
	data[0] = 1;            //初始化阶乘值	
	int x = 1;      //初始化阶乘值的位数 	
	if (m)	
	{		
		for (i = 1; i <= m; i++) 	//累乘计算阶乘m！		
		{ 			
			//乘法阶段			
			for (j = 0; j < x; j++)				
				data[j] = data[j] * i; 		

			//进位阶段			
			for (k = 0; k < x; k++)			
			{			
				if (data[k] >= 10)				
				{					
					data[k + 1] = data[k + 1] + data[k] / 10;				
					data[k] = data[k] % 10; 			
	
					//如果最高位发生进位，则增加阶乘结果位数,同时判断是否溢出					
					if (k == x - 1)					
					{					
						x++;			//最高位有进位时，将位数x加1						
						if (x > SIZE)				
						return 0;		//数据溢出，结束计算并返回0							
						break;              //到最高位结束进位				
					}			
				}			
			}		
		}	
	} 
		
	return x;	

}