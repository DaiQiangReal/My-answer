/*https://vjudge.net/contest/210279#problem/E*/
#include <stdio.h>  
int input;
bool flag = false;
void dfs(long long a, int step)
{
	if (flag||step == 19)
	{
		return;
	}
	if (a%input == 0)
	{
		printf("%lld\n", a);
		flag = true;
		return;
	}
	else
	{
		dfs(a * 10, step + 1);
		dfs(a * 10 + 1, step + 1);
	}
	return;
}
int main()
{

	while (scanf("%d", &input)&&input!=0)
	{
		dfs(1, 0);
		flag = false;
	}
	return 0;
}
