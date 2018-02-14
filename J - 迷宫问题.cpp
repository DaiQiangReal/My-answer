/*https://vjudge.net/contest/210279#problem/J*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int maze[5][5];
struct format {
	int line,column;
	char way[1000];
};
queue<format> all;
void bfs()
{
	while(!all.empty())
	{
		struct format now;
		now=all.front();
		all.pop();
		if(now.line==4&&now.column==4)
		{
			int i=0;
			while(1)
			{
				cout<<now.way[i++];
				if(now.way[i-1]==',')
					cout<<' ';
				if(now.way[i]=='(')
					cout<<endl;
				if(now.way[i]=='\0')
					return;
			}
		}
		if(now.line+1<5&&maze[now.line+1][now.column]==0)
		{
			struct format temp;
			temp=now;
			temp.line++;
			char chartemp[5];
			sprintf(chartemp,"(%d,%d)",now.line,now.column);
			strcat(temp.way,chartemp);
			all.push(temp);
		}
		if(now.line-1>=0&&maze[now.line-1][now.column]==0)
		{
			struct format temp;
			temp=now;
			temp.line--;
			char chartemp[5];
			sprintf(chartemp,"(%d,%d)",now.line,now.column);
			strcat(temp.way,chartemp);
			all.push(temp);
		}
		if(now.column+1<5&&maze[now.line][now.column+1]==0)
		{
			struct format temp;
			temp=now;
			temp.column++;
			char chartemp[5];
			sprintf(chartemp,"(%d,%d)",now.line,now.column);
			strcat(temp.way,chartemp);
			all.push(temp);
		}
		if(now.column-1>=0&&maze[now.line][now.column-1]==0)
		{
			struct format temp;
			temp=now;
			temp.column--;
			char chartemp[5];
			sprintf(chartemp,"(%d,%d)",now.line,now.column);
			strcat(temp.way,chartemp);
			all.push(temp);
		}
	}
	
}
int main ()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>maze[i][j];
	struct format temp;
	temp.column=0;
	temp.line=0;
	temp.way[0]='\0';
	all.push(temp);
	bfs();
	cout<<endl<<"(4, 4)";
	return 0;			
}
