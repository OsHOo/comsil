#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
void search(FILE *fp, ll num_arr[]);
void print_array(ll num_arr[]);
void recur_num(ll num, ll num_arr[]);
int main()
{
	ll num;
	ll *tmp;
	ll num_arr[10] = { 0, };
	int test, i, j=0;
	scanf("%d", &test);
	tmp = (ll *)malloc(sizeof(ll)*test);
	for (i = 0; i < test; i++)
	{
		scanf("%lld", &tmp[i]);
	}
	while (test != 0)
	{
		num = tmp[j];
		for (i = 0; i < 10; i++)
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
void recur_num(ll num, ll num_arr[])
{
	int i;
	FILE *fp;
	if (num / 10 != 0)
	{
		recur_num(num / 10 - 1, num_arr);
		for (i = 0; i < 10; i++)
		{
			num_arr[i] *= 10;
		}
	}

	fp = fopen("num.txt", "w+");
	while (num % 10 != 0)
	{
		fprintf(fp, "%lld", num);
		num--;
	}
	if (num != 0)
		fprintf(fp, "%lld", num);
	fclose(fp);
	fp = fopen("num.txt", "r");
	search(fp, num_arr);
	fclose(fp);
//	remove("num.txt");
	if (num / 10 != 0)
	{
		for (i = 0; i < 10; i++)
		{
			if (i == 0)
				num_arr[i] += (num / 10 - 1);
			else
				num_arr[i] += num / 10;
		}
	}
}
void print_array(ll num_arr[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%lld ", num_arr[i]);
	}
	printf("\n");
	return;
}
void search(FILE *fp, ll num_arr[])
{
	int tmp = -1;
	ll i = 0;

	if (fp != NULL)
	{
		while (feof(fp) == 0)
		{
			fscanf(fp, "%1d", &tmp);
			printf("tmp : %d\n", tmp);
			if(tmp != -1)
				num_arr[tmp]++;
		}
	//	num_arr[tmp]--;
	}
	return;
}
