#include "define.h"
#include "recursive.h"
void print_array(ll num_arr[]);
int main()
{
	ll num;
	ll *tmp;
	ll num_arr[10] = {0,};
	int test, i, j = 0;
	scanf("%d",&test);
	tmp = (ll *)malloc(sizeof(ll)*test);
	for (i=0;i<test;i++)
	{
		scanf("%lld",&tmp[i]);
	}
	while(test != 0)
	{
		num = tmp[j];
		for (i=0;i<10;i++)
		{
			num_arr[i] = 0;
		}
		recur_num(num, num_arr);
		print_array(num_arr);
		test--;
		j++;
	}
	return 0;
}
void print_array(ll num_arr[])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%lld ", num_arr[i]);
	}
	printf("\n");
	return;
}

