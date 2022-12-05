#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int com(char *a,char*b)
{
	if(strlen(a)==strlen(b))
		return strcmp(a,b);
	else
		return strlen(a)-strlen(b);
}
int main(void)
{
	int n,add1=0,add2=0;
	char x[100][11],y[100][19],z[100][4],max[4],min[4];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&x[i]);
		scanf("%s",&y[i]);
		scanf("%s",&z[i]);
		if(strcmp(z[i],"n/a")==0)
		{
			i--;
			n--;
		}
	}
	strcpy(max,z[0]);
	strcpy(min,z[0]);
	for(int i=1;i<n;i++)
	{
		if(com(z[i],max)>0)
		{
			strcpy(max,z[i]);
			add1=i;
		}
		if(com(z[i],min)<0)
		{
			strcpy(min,z[i]);
			add2=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(com(max,z[i])==0)
		{
			if(strcmp(x[add1],x[i])>0)
			add1=i;
		}
		if(com(min,z[i])==0)
		{
			if(strcmp(x[add2],x[i])<0)
			add2=i;
		}
	}
	printf("%s %s\n",x[add1],y[add1]);
	printf("%s %s\n",x[add2],y[add2]);
	return 0;
}
