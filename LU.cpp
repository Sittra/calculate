//LU分解法算矩阵，解线性方程组精确解（分数形式，int型没考虑溢出啊...初值在程序里输入...配合jiajiachengchu.cpp使用）
#define N 3//n+1阶矩阵，n+1元n+1次方程组
#include<stdio.h>
#include"jiajianchengchu.cpp"


void matrixshow(FS s[N][N+1])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N+1 ; j++)
			show(s[i][j]);
	putchar('\n');
	}
	putchar('\n');
}
void xshow(FS x[N])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("x[%d]=",i+1);
		show(x[i]);
		putchar('\n');
	}
	putchar('\n');
}

void gauss(FS a[N][N+1],FS x[]){
	int i ,j,k,l;
	FS t,tt,u[N][N+1];
	tt={0,1};
	for(j=0;j<=N;j++)
	u[0][j]=(a[0][j]);
	for(i=1;i<N;i++)
	u[i][0]=divide(a[i][0],a[0][0]);
	for(i=1;i<N;i++)
{
	for(j=i;j<N+1;j++){
	t={0,1};
	for(k=1;i-k>=0;k++)	
	{tt=multi(u[i-k][j], u[i][i-k]);
	t=plus(t,tt);}
	u[i][j]=minus(a[i][j],t);
	}

for(k=i+1;k<N;k++){
		t={0,1};
		for(l=1;i-l>=0;l++){
			tt=multi(u[k][i-l],u[i-l][i]);
		t=plus(t,tt);	
		}
	u[k][i]=minus(a[k][i],t);
	u[k][i]=divide(u[k][i],u[i][i]);
	   }
}

matrixshow(u);


x[N - 1] = divide(u[N-1][N],u[N - 1][N - 1]);
for (i = N - 2; i >= 0; i--)
{
	t = u[i][N];
	for (j = N-1; j > i; j--)
	{
		tt = multi(u[i][j], x[j]);
		t  = minus(t,tt);
	}
	x[i] = divide(t,u[i][i]);
}


xshow(x);


	}

	
	int main()
	{
	//	FS sss;
	FS a[N][N + 1] = { { { 3, 1 }, { 2, 1 }, { 5, 1 }, { 6, 1 } }, { {-1,1}, {4,1}, {3,1}, {5,1} }, { {1,1}, {-1,1}, {3,1}, {1,1} } };//在这里输入初始矩阵，形式酱紫：{分子，分母}
	FS  x[N];
	matrixshow(a);
	gauss(a, x);
	//sss = {-1,3};
	//show(sss);
	//yuefen(&sss.fz, &sss.fm);
	//show(sss);
	return 0;
};
