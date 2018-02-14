/*https://vjudge.net/contest/210279#problem/A*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
bool place_col[100];
char map[100][100];
int placed=0;
int input_n,input_k,ans=0;
void dfs(int line)
{
	if(placed==input_k)
		{
			ans++;
			return;
		}
	else
	{
		if(line>input_n)
			return;
		for(int i=0;i<input_n;i++)
		{
			if(map[line][i]=='#'&&!place_col[i])
			{
				place_col[i]=true;
				placed++;
				dfs(line+1);
				place_col[i]=false;
				placed--;
			}
		}
		dfs(line+1);
		return;
	}
	
}
int main ()
{
	bool out_flag=false;
	
	while(scanf("%d %d",&input_n,&input_k)&&input_n!=-1)
	{
		ans=0;
		memset(place_col,false,sizeof(bool)*100*100);
		for(int i=0;i<input_n;i++)
			scanf("%s",map[i]);
		dfs(0);
		if(out_flag)
			cout<<endl;
		cout<<ans;
		out_flag=true;
		
	}
	return 0;
}
