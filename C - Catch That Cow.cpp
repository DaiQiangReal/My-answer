/*https://vjudge.net/contest/210279#problem/C*/
#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
int n,k;
bool moved[1000001];
int min_step;
struct status{
	int now_position;
	int sum_step;
};
queue<status> all;

void bfs()
{
	while(!all.empty())
	{
		struct status temp;
		temp.now_position=all.front().now_position;
		temp.sum_step=all.front().sum_step;
		all.pop();
		if(temp.now_position==k)
		{
			min_step=temp.sum_step;
			return;
		}
			
		if(temp.now_position<k&&!moved[temp.now_position*2])
		{
			struct status in;
			in.now_position=temp.now_position*2;
			in.sum_step=temp.sum_step+1;
			all.push(in);
			moved[in.now_position]=true;
		}
		
		if(temp.now_position<k&&!moved[temp.now_position+1])
		{
			struct status in;
			in.now_position=temp.now_position+1;
			in.sum_step=temp.sum_step+1;
			all.push(in);
			moved[in.now_position]=true;
		}
		
		if(temp.now_position>=1&&!moved[temp.now_position-1])
		{
			struct status in;
			in.now_position=temp.now_position-1;
			in.sum_step=temp.sum_step+1;
			all.push(in);
			moved[in.now_position]=true;
		}
	}
}
int main ()
{
	memset(moved,false,sizeof(bool)*1000001);
	cin>>n>>k;
	struct status initial;
	initial.now_position=n;initial.sum_step=0;
	all.push(initial);
	bfs();
	cout<<min_step;
	return 0;
	
}
