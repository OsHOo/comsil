#include "define.h"
#include "recursive.h"
#include "search.h"
void recur_num(ll num, ll num_arr[])
{
	int i;
	FILE *fp;
	if(num/10 != 0)
	{
		recur_num(num / 10 - 1, num_arr);
		for(i=0;i<10;i++)
		{
			num_arr[i] *= 10;
		}
	}

	fp = fopen("num.txt","w+");
	while (num % 10 != 0)
	{
		fprintf(fp,"%lld",num);
		num--;
	}
	
	if(num != 0)
		fprintf(fp, "%lld", num);
	fclose(fp);
	fp = fopen("num.txt","r");
	search(fp, num_arr);
	fclose(fp);
	remove("num.txt");
	if(num / 10 != 0)
	{
		for (i = 0 ; i < 10; i++)
		{
			if(i==0)
				num_arr[i] += (num / 10 - 1);
			else
				num_arr[i] += num / 10;
		}
	}
}
