//分数运算
#include <stdio.h>
typedef struct fenshu FS;
struct fenshu{
	int fz;
	int fm;
};
void show(FS s)
{
	if (s.fm == 1)printf("  %d  ", s.fz);
	else
	printf(" %d/%d ",s.fz,s.fm);
}

void yuefen(int*a, int*b)
{
	int min, i;
	int flag1 =1;
	int flag2 =1;
	if ((*a)<0){ *a = 0 - *a;flag1 = -1;}
	if ((*b)<0){ *b = 0 - *b;flag2 = -1;	}
	min = (*a >* b) ?* b :* a;
	for (i = min; i > 1; i--)
	{
		if (*a%i == 0 && *b%i == 0)
		{
		*a /= i;
		*b /= i;
		break;
		}
	}
	*a = (*a)* flag1*flag2;
}



FS plus(FS a, FS b)
{
	FS s;
	s.fm = a.fm*b.fm;
	a.fz *= b.fm;
	b.fz *= a.fm;
	s.fz = a.fz + b.fz;
	yuefen(&s.fz,&s.fm);
	return s;
}
FS minus(FS a, FS b)
{
	FS s;
	s.fm = a.fm*b.fm;
	a.fz *= b.fm;
	b.fz *= a.fm;
	s.fz = a.fz - b.fz;
	yuefen(&s.fz, &s.fm);
	return s;

}

FS multi(FS a, FS b)
{
	FS s;
	s.fm = a.fm*b.fm;
	s.fz = a.fz * b.fz;
	yuefen(&s.fz, &s.fm);
	return s;
}

	FS divide(FS a, FS b)
	{
		FS s;
		s.fm = a.fm*b.fz;
		s.fz = a.fz * b.fm;
		yuefen(&s.fz, &s.fm);
		return s;
	}
