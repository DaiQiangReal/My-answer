/*https://vjudge.net/contest/210279#problem/L*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int s,n,m;
bool outputendl = false;
struct status{
	int now_s;
	int now_n;
	int now_m;
	int step;
};
queue<status> progress;
bool same[100][100][100];
int ansmin = 999999;
void judge(struct status temp)
{
	if((temp.now_m==temp.now_n&&temp.now_s==0)||(temp.now_m==temp.now_s&&temp.now_n==0)||(temp.now_n==temp.now_s&&temp.now_m==0))
		if (temp.step < ansmin)
			ansmin = temp.step;
	return;
}

void bfs()
{
	while(!progress.empty())
	{
		struct status temp;
		temp=progress.front();
		progress.pop(); 
		judge(temp);
			
		{//s->m;
			struct status in;
			in = temp;
			in.now_m = in.now_s + in.now_m;
			if (in.now_m > m)
			{
				in.now_s = in.now_m - m;
				in.now_m = m;
			}
			else
				in.now_s = 0;
			if (!same[in.now_s][in.now_n][in.now_m])
			{
				in.step++;
				progress.push(in);
				same[in.now_s][in.now_n][in.now_m] = true;
			}
		} 
		{//s->n;
			struct status in;
			in = temp;
			in.now_n = in.now_s + in.now_n;
			if (in.now_n > n)
			{
				in.now_s = in.now_n - n;
				in.now_n = n;
			}
			else
				in.now_s = 0;
			if (!same[in.now_s][in.now_n][in.now_m])
			{
				in.step++;
				progress.push(in);
				same[in.now_s][in.now_n][in.now_m] = true;
			}
		}
		{//m->s;
			struct status in;
			in = temp;
			in.now_s = in.now_m + in.now_s;
			in.now_m = 0;
			if (!same[in.now_s][in.now_n][in.now_m])
			{
				in.step++;
				progress.push(in);
				same[in.now_s][in.now_n][in.now_m] = true;
			}
		}
		{//m->n;
			struct status in;
			in = temp;
			in.now_n = in.now_m + in.now_n;
			if (in.now_n > n)
			{
				in.now_m = in.now_n - n;
				in.now_n = n;
			}
			else
				in.now_m = 0;
			if (!same[in.now_s][in.now_n][in.now_m])
			{
				in.step++;
				progress.push(in);
				same[in.now_s][in.now_n][in.now_m] = true;
			}
		}
		{//n->s;
			struct status in;
			in = temp;
			in.now_s = in.now_n + in.now_s;
			in.now_n = 0;
			if (!same[in.now_s][in.now_n][in.now_m])
			{
				in.step++;
				progress.push(in);
				same[in.now_s][in.now_n][in.now_m] = true;
			}
		}
		{//n->m;
			struct status in;
			in = temp;
			in.now_m = in.now_n + in.now_m;
			if (in.now_m > m)
			{
				in.now_n = in.now_m - m;
				in.now_m = m;
			}
			else
				in.now_n = 0;
			if (!same[in.now_s][in.now_n][in.now_m])
			{
				in.step++;
				progress.push(in);
				same[in.now_s][in.now_n][in.now_m] = true;
			}
		}
	}
	return;
}
int main ()
{
	while (scanf("%d%d%d", &s,&n,&m) && s != 0)
	{
		memset(same, false, sizeof(bool) * 100 * 100 * 100);
		struct status input;
		input.now_s = s;
		input.now_m = 0;
		input.now_n = 0; 
		input.step = 0;
		progress.push(input);
		bfs();
		/*if (ansmin == 999999)
		{
			if (outputendl)
				cout << endl;
			cout << "NO";
			outputendl = true;
		}
		else
		{
			if (outputendl)
				cout <<endl;
			cout <<ansmin;
			outputendl = true;
			ansmin = 999999;
		}*/
		if (ansmin == 999999)
			cout << "NO" << endl;
		else
			cout << ansmin << endl;
		ansmin = 999999;
	}
	return 0;
	
 } 
