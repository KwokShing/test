#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <ctype.h>

using namespace std;


typedef long int lld;//long int
#define rot(v) (((v)>>3)|(((v)&7)<<9))

const int MAX=110000;
const int MOD=100003;
const int INF=1000000000;

struct Node
{
    int a,b;
    char x;
    int mile,next;
}node[MAX];

int head[MOD],E;
char buf[22];
int chg(char x)
{
    if(x=='x')return 10;
    return x-'0';
}

int fun(char s[],int &a,int &b,char &x)

{
    int ret=0,i;
    int tmp;
    a=b=0;
    for(i=0;i<9;i++){
        tmp=s[i]-'0';
        a=a*10+tmp;//记录没取余数的数值
        ret=ret*10+tmp;
    }
    ret%=MOD;
    for(;i<17;i++){
        tmp=s[i]-'0';
        b=b*10+tmp;//记录后面没取余数的数值
        ret=(ret*10+tmp)%MOD;
    }
    x=s[i];//记录最后一位
    return (ret*100+chg(s[i]))%MOD;//返回取余数的数值
}

void ins(char s[],int mile)
{
    int a,b;
    char x;
    int h=fun(s,a,b,x);
    int i;
    //发生冲突时的处理 

    for(i=head[h];i!=-1;i=node[i].next)//head 全局变量
    {

        if(node[i].x==x&&node[i].a==a&&node[i].b==b){
            node[i].mile+=mile;
            return ;
        }
    }
    node[E].a=a;
    node[E].b=b;
    node[E].x=x;
    node[E].mile=mile;
    node[E].next=head[h];
    head[h]=E++;
}

int query(char s[])
{
    int a,b;
    char x;
    int h=fun(s,a,b,x);
    int i;
    for(i=head[h];i!=-1;i=node[i].next){
        if(node[i].x==x&&node[i].a==a&&node[i].b==b)return node[i].mile;
    }
    return -1;
}
void out(int n)
{
    if(n)
    {
        out(n/10);
        putchar('0'+n%10);
    }
}
int main()

{
    int n,m;
    int k,i;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(head,-1,sizeof(head));
        E=0;
        int mile=0;
        while(n--)
        {
            scanf("%s%d",buf,&mile);
            if(mile<k)mile=k;
            ins(buf,mile);
        }
        scanf("%d",&m);
        getchar();
        while(m--)
        {
            gets(buf);
            mile=query(buf);
            if(mile==-1)puts("No Info");
            else
            {
                out(mile);
               putchar('\n');

            }
        }
    }
    return 0;
}
//RC4
/*
typedef unsigned long ULONG;

//³õÊ¼»¯º¯Êý  
void rc4_init(unsigned char *s, unsigned char *key, unsigned long Len)
{
	int i = 0, j = 0;
	char k[256] = { 0 };
	unsigned char tmp = 0;
	for (i = 0; i < 256; i++)
	{
		s[i] = i;
		k[i] = key[i % Len];
	}
	for (i = 0; i < 256; i++)
	{
		j = (j + s[i] + k[i]) % 256;
		tmp = s[i];
		s[i] = s[j]; //½»»»s[i]ºÍs[j]
		s[j] = tmp;
	}
}

//¼Ó½âÃÜ  
void rc4_crypt(unsigned char *s, unsigned char *Data, unsigned long Len)
{
	int i = 0, j = 0, t = 0;
	unsigned long k = 0;
	unsigned char tmp;
	for (k = 0; k < Len; k++)
	{
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;
		tmp = s[i];
		s[i] = s[j]; //½»»»s[x]ºÍs[y]
		s[j] = tmp;
		t = (s[i] + s[j]) % 256;
		Data[k] ^= s[t];
	}
}

int main()
{
	unsigned char s[256] = { 0 }, s2[256] = { 0 }; //S-box
	char key[256] = { "jus" };
	char pData[512] = "ÕâÊÇÒ»¸öÓÃÀ´¼ÓÃÜµÄÊý¾ÝData";
	ULONG len = strlen(pData);
	int i;

	printf("pData = %s\n", pData);
	printf("key = %s, length = %d\n\n", key, strlen(key));
	rc4_init(s, (unsigned char *)key, strlen(key)); //ÒÑ¾­Íê³ÉÁË³õÊ¼»¯
	printf("Íê³É¶ÔS[i]µÄ³õÊ¼»¯£¬ÈçÏÂ£º\n\n");
	for (i = 0; i < 256; i++)
	{
		printf("%02X ", s[i]);
		if (i && (i + 1) % 16 == 0) putchar('\n');
	}
	printf("\n\n");
	for (i = 0; i < 256; i++) //ÓÃs2[i]ÔÝÊ±±£Áô¾­¹ý³õÊ¼»¯µÄs[i]£¬ºÜÖØÒªµÄ£¡£¡£¡
	{
		s2[i] = s[i];
	}
	printf("ÒÑ¾­³õÊ¼»¯£¬ÏÖÔÚ¼ÓÃÜ:\n\n");
	rc4_crypt(s, (unsigned char *)pData, len); //¼ÓÃÜ
	printf("pData = %s\n\n", pData);
	printf("ÒÑ¾­¼ÓÃÜ£¬ÏÖÔÚ½âÃÜ:\n\n");
	//rc4_init(s, (unsigned char *)key, strlen(key)); //³õÊ¼»¯ÃÜÔ¿
	rc4_crypt(s2, (unsigned char *)pData, len); //½âÃÜ
	printf("pData = %s\n\n", pData);
	return 0;
}*/

//qsort
/*
int cmp(const void *a, const void *b)
{
	int *c = (int *)a;
	int *d = (int *)b;
	if (*c != *d)
		return -(*c - *d);
	return -(*(c + 1) - *(d + 1));
}

int main()
{
	int i, j;
	int a[6][2] = { { 1, 6 }, { 1, 5 }, { 3, 9 }, { 3, 8 }, { 4, 10 }, { 4, 12 } };
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	qsort(a, 6, sizeof(a[0]), cmp);

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	FILE *fp;
	int direct[100], x[100], y[100];
	char a[3], b[3], c[3];
	memset(direct, 0, sizeof(direct));
	memset(direct, 0, sizeof(x));
	memset(direct, 0, sizeof(y));
	if ((fp = fopen("out.txt", "r")) == NULL)
		exit(1);
	int i = 0;
	while (true)
	{
		if (feof(fp)) break;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		fscanf(fp, "%s %s %s\n", a, b, c);
		direct[i] = atoi(a);
		x[i] = atoi(b);
		y[i] = atoi(c);
		i++;

	}
	int j = i;
	for (; i > 0; i--)
	{
		printf("%d %d %d\n", direct[j - i], x[j - i], y[j - i]);
	}

	fclose(fp);
	getchar();
	system("pause");
	return 0;
}*/

/*
int main(int argc, char const *argv[])
{
	int it = 0;
	char box[5];
	int boxSize[5] = { 1, 2, 3, 4, 5 };
	memset(box, '0', sizeof(box));
	FILE *fp;
	fp = fopen("test.txt", "at+");
	if (fp == NULL)
		exit(1);

	while (1)
	{
		unsigned char data;
		data = getchar();
		box[data - '1']++;

		if (it++ == 10) break;
	}


	for (int i = 0; i < 5; i++)
	{
		fprintf(fp, "%d. %d, %d, %d, %c\n", i + 1, boxSize[i], boxSize[i], boxSize[i], box[i]);
	}


	fclose(fp);
	return 0;
}
*/

/*
int main(int argc, char const *argv[])
{
	int res[120], r[120], n, num, count = 0;
	for (int i = 0; i < 120; i++)
	{
		res[i] = 0;
		r[i] = 0;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (res[num] == 0)
		{
			res[num] = -1;
			count++;
			while (num != 1)
			{
				if (num % 2 == 1)
					num = (3 * num + 1) / 2;
				else
					num = num / 2;
				if (res[num] == -1)
				{
					res[num] = 1;
					count--;
					break;
				}
				else
					res[num] = 1;
			}
		}
	}
	for (int i = 100; i >= 0; i--)
	{
		if (res[i] == -1)
		{

			if (count != 1)
				printf("%d ", i);
			else
				printf("%d", i);
			count--;
		}

	}
	//puts("fuck");
	//cout<<"fuck";
	return 0;
}


class global{
private:
	int x;
public:
	void add(int x)
	{
		cout << x + 1;
		cout << "\n";

	}
	global()
	{
		cout << "Initialize\n";
	}
	~global()
	{
		cout << "Clean up\n";
	}
}an;
*/

/*
int main()
{
	cout << "Hello,world!\n";
	global a;
	a.add(2);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i, n, sum = 0;
	double x, y;
	printf("ÃŠÃ¤ÃˆÃ«ÂµÃ£ÂµÃ„ÃŠÃ½ÃÂ¿Â£Âº");
	scanf("%d", &n); //ÃŠÃ¤ÃˆÃ«Â²ÃºÃ‰ÃºÃ‹Ã¦Â»ÃºÂµÃ£ÂµÃ„ÃŠÃ½ÃÂ¿
	srand(time(NULL)); //Â³ÃµÃŠÂ¼Â»Â¯Ã‹Ã¦Â»ÃºÃŠÃ½Ã‰ÃºÂ³Ã‰Ã†Ã·
	for (i = 1; i < n; i++)
	{
		x = (double)rand() / RAND_MAX; //Â²ÃºÃ‰Ãº0-1ÂµÃ„Ã’Â»Â¸Ã¶Ã‹Ã¦Â»ÃºÃŠÃ½x
		y = (double)rand() / RAND_MAX; //Â²ÃºÃ‰Ãº0-1ÂµÃ„Ã’Â»Â¸Ã¶Ã‹Ã¦Â»ÃºÃŠÃ½y
		if ((x*x + y*y) <= 1) //ÃˆÃ´Ã”ÃšÃ’ÃµÃ“Â°Ã‡Ã¸
			sum++; //Â¼Ã†ÃŠÃ½
	}
	printf("PI=%f\n", (double)4 * sum / n);
	getchar();
	return 0;
}*/


/*
void zxc(int* a)
{
	*a = 2;

}
int main()
{
	int x, y = 2;
	//x=&y;
	int a[3] = { 1, 2, 3 };
	//printf("%d\n",x);
	zxc(&x);
	printf("%d\n", x);
	//printf("%d",a[*x]);


}*/

/*
void qwe(int* a, int* b)
{
	*a = 1;
	*b = 2;
}

int main()
{
	int *x, *y;
	int z = 0, q = 1;
	x = &z;
	y = &q;
	qwe(x, y);

	printf("%d %d", *x, *y);


}*/

/*
int zx = 10;
int main()
{
	int *x = (int *)malloc(5 * sizeof(int));
	int y = 10;
	char *knots = (char*)malloc(5 * sizeof(char));
	x[1] = 2;
	char *t = "asdfsdf";
	scanf("%d", x + 1);
	scanf("%s", &knots[1]);
	*(x + 3) = 3;
	//for(int i=0;i<5;i++)
	//printf("%d ",x[i]);
	printf("%d %d", x[1], *(x + 1));
	printf("%s", &knots[1]);
	//printf("%s",t);
	printf("%d", zx);
}*/

/*
struct zxc
{
	char name[10];
	int num;
}z[3];
int main()
{
	strcpy(z[0].name, "abc");
	strcpy(z[1].name, "zxc");
	strcpy(z[2].name, "qwe");
	for (int i = 0; i <= 2; i++)
		puts(z[i].name);

}*/
/*
int main()
{
	int x = 5, y = 0, z = 0, t;
	t = (x || (y = 5), x&&z || (y = 1), x + y + z);
	printf("%d", t);

}
void hanzi(int x)
{
	if (x == 1) printf("yi");
	else if (x == 2) printf("er");
	else if (x == 3) printf("san");
	else if (x == 4) printf("si");
	else if (x == 5) printf("wu");
	else if (x == 6) printf("liu");
	else if (x == 7) printf("qi");
	else if (x == 8) printf("ba");
	else if (x == 9) printf("jiu");
	else if (x == 0) printf("ling");

}*/

/*
int main()
{
	char num[101];
	int sum = 0;

	gets(num);
	int i = 0;
	while (num[i] != 0)
	{
		sum += num[i++] - 48;
	}
	//printf("%d",sum);

	int shuzu[5];
	int j = 0;

	while (sum != 0)
	{
		shuzu[j++] = sum % 10;
		sum /= 10;
	}
	j -= 1;
	while (j != -1)
	{
		hanzi(shuzu[j--]);
		if (j != -1)
			printf(" ");
	}

}*/

/*
int main(int argc, char const *argv[])
{
	int i, j, n, count = 0;
	int flag1 = 0, flag2 = 0;

	scanf("%d", &n);
	if (1 <= n && n < 3)
		printf("0");
	else if (n >= 3 && n < 100000)
	{
		for (i = 3; i < n; i += 2)
		{
			for (j = 2; j <= sqrt(i*1.0); j++)
			if (i%j == 0)
			{
				flag1 = 1;
				break;
			}
			if (i + 2 <= n){
				for (j = 2; j <= sqrt((i + 2)*1.0); j++)
				if ((i + 2) % j == 0)
				{
					flag2 = 1;
					break;
				}
				if (flag1 == 0 && flag2 == 0)
					count++;
				flag1 = 0; flag2 = 0;
			}
		}
		printf("%d\n", count);

	}

	return 0;
}*/

/*
int main(int argc, char const *argv[])
{
	int i, j;
	char num[1000];
	int count[10];
	for (int i = 0; i < 10; i++)
		count[i] = 0;

	//freopen("1.txt","r",stdin);
	gets(num);

	for (i = 0;; i++)
	{
		count[num[i] - 48]++;
		if (num[i] == 0)
			break;

	}
	for (int i = 0; i < 10; i++)
	if (count[i] != 0)
		printf("%d:%d\n", i, count[i]);
	//fclose(stdin);
	return 0;
}*/

/*
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int num[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}

	if (num[0] != 0){
		for (int i = 1; i < 10; i++)
		{
			if (num[i] != 0)
			{
				printf("%d", i);
				num[i]--;
				break;
			}
		}

	}

	for (int i = 0; i < 10; i++)
	{
		while (num[i]--)
			printf("%d", i);
	}


	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	char n[1000], m[1000], b;



	return 0;
}
*/