#include "define.h"
#include "search.h"
void search(FILE *fp, ll num_arr[])
{
	int tmp = -1;
	ll i = 0;

	if (fp != NULL)
	{
		while(feof(fp) == 0)
		{
			fscanf(fp, "%1d", &tmp);
		//	printf("tmp : %d\n", tmp);
			if(tmp != -1)
				num_arr[tmp]++;
		}
//		num_arr[tmp]--;
	}
	return;
}
