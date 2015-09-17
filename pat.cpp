#include <iostream>  
#include <set>  
#include <vector>  
#include <map>  
#include <queue>  
#include <stack>  
#include <string>  
#include <string.h>  
#include <algorithm>  
#include <ctype.h>
#include <cmath>
using namespace std;

//1067
//返回到0时的次数！=count，+1，else ;
/*
int in[100000];
int main(int argc, char const *argv[])
{
	long n,tmp,count=0,flag;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf(" %ld",&tmp);
		in[i] = tmp;
		if(tmp!=i&&tmp!=0)
			count++;
		else if(tmp==0)
			flag = i;
		cout<<i<<" "<<tmp<<" "<<count<<endl;
	}
	while(){
		
	}
	cout<<count;
	return 0;
}
*/
//6-07
/*const int INF = 999999999;
int main(int argc, char const *argv[])
{
	int v[101][101];
	int n,m;
	memset(v,INF,sizeof(v));
	cin>>n>>m;
	int a,b,len;
	for(int i=0;i<m;i++){
		cin>>a>>b>>len;
		v[a][b] = len;
		v[b][a] = len;
	}
	

	return 0;
}*/

//5-06//yet not deal with the conflict problem,the java version hashmap is timeout
/*
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131313; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    //return (hash & 0x7FFFF);
    return hash%100003;
}
int main(int argc, char const *argv[])
{
	long n,k,len;
	char tmp[19];
	cin>>n>>k;
	//vector<int> v;
	int *v = new int[100003];
	memset(v,0,sizeof(v));
	for(int i=0;i<n;i++){
		scanf("%s %ld",tmp,&len);
		if(len<k)
			len = k;
		v[BKDRHash(tmp)] += len; 
	}
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",tmp);
		if(v[BKDRHash(tmp)]!=0)
			printf("%d\n",v[BKDRHash(tmp)]);
		else
			printf("No Info\n");
	}
	return 0;
}*/
//1039
/*
int main(int argc, char const *argv[])
{
	int n, k, id, num;
	char name[5];
	map<int, vector<int> > mymap;
	map<int, int> mynummap;
	map<int, vector<int> >::iterator it;
	vector<int>::iterator iit;

	cin >> n >> k;
	for (int i = 0; i<k; i++){
		scanf("%d %d", &id, &num);
		for (int j = 0; j<num; j++){
			scanf("%s ", name);
			int index = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
			mymap[index].push_back(id);
			mynummap[index]++;
		}
	}
	for (int i = 0; i<n; i++){
		scanf("%s ", name);
		printf("%s", name);
		int index = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
		it = mymap.find(index);
		if (it != mymap.end()){
			printf(" %d", mynummap[index]);
			sort(it->second.begin(), it->second.end());
			for (iit = it->second.begin(); iit != it->second.end(); iit++){
				printf(" %d", *iit);
			}
			printf("\n");
		}
		else
			printf(" 0\n");
	}
	getchar();
	getchar();
	return 0;
}*/
//1046
/*
long path[100000],pathsum[100001];
int main(int argc, char const *argv[])
{
	int n;
	long sum = 0, tsum = 0,total=0;
	scanf("%d",&n);
	
	pathsum[0]=0;
	for (int i = 0; i<n; i++){
		scanf("%ld ",&path[i]);
		total+=path[i];
		if(i==0)
			pathsum[i+1]=path[i];
		else
			pathsum[i+1]=pathsum[i]+path[i];
	}
	int m, a, b;
	scanf("%d",&m);
	for (int i = 0; i<m; i++){
		scanf("%d %d",&a,&b);
		if (a>b){
			int temp = a;
			a = b;
			b = temp;
		}
		sum = pathsum[b-1]-pathsum[a-1];
		tsum=total-sum;
		tsum>sum ? printf("%ld\n",sum):printf("%ld\n",tsum);
	}
	return 0;
}*/
//1037
/*
int imp(const void *a,const void *b)
{
	return *(long *)b-*(long *)a;
}
int dmp(const void *a,const void *b)
{
	return *(long *)a-*(long *)b;
}
int main(int argc, char const *argv[])
{
	long np,nc;
	long long sum=0;
	cin>>nc;
	long *coupon = new long[nc];
	for(long i=0;i<nc;i++){
		cin>>coupon[i];
	}
	cin>>np;
	long *price = new long[np];
	for(long i=0;i<np;i++){
		cin>>price[i];
	}
	qsort(coupon,nc,sizeof(coupon[0]),imp);
	qsort(price,np,sizeof(price[0]),imp);
	long i=0;
	while(i<nc&&i<np){
		if(coupon[i]>0&&price[i]>0){
			sum+=coupon[i]*price[i];
			i++;
		}
		else
			break;
	}
	qsort(coupon,nc,sizeof(coupon[0]),dmp);
	qsort(price,np,sizeof(price[0]),dmp);
	i=0;
	while(i<nc&&i<np){
		if(coupon[i]<0&&price[i]<0){
			sum+=coupon[i]*price[i];
			i++;
		}
		else
			break;
	}
	cout<<sum;
	return 0;
}*/
//1033
/*
int dcmp(const void *a, const void *b)
{
	double *c = (double *)a;
	double *d = (double *)b;
	if (*(c + 1) <= *(d + 1))
		return -1;
	else return 1;
}
int pcmp(const void *a, const void *b)
{
	double *c = (double *)a;
	double *d = (double *)b;
	if (*c <= *d)
		return -1;
	else return 1;
}
int main(int argc, char const *argv[])
{
	int c, d, davg, n, cur = 0, flag = 0,ff=0;
	double price[500][2], dis[500][2], sum = 0, dmax, curprice = 0, curdis = 0, usegas = 0, curgas = 0;
	cin >> c >> d >> davg >> n;
	dmax = c*davg;
	int i;
	for (i = 0; i<n; i++){
		cin >> price[i][0] >> price[i][1];
	}
	price[i][0] = 0;
	price[i][1] = d;
	qsort(price, n, sizeof(price[0]), dcmp);

	if (price[0][1] != 0)
		printf("The maximum travel distance = 0.00");
	else{
		curprice = price[0][0];
		int i = 0;
		while (true){
			flag = 0;
			int j = 0;
			for (; price[i][1] <= dmax + curdis&&i<n;){
				dis[j][0] = price[i][0];
				dis[j++][1] = price[i][1];
				if (price[i][0] <= curprice){
					sum += ((price[i][1] - curdis) / davg - curgas)*curprice;
					curprice = price[i][0];
					curdis = price[i][1];
					curgas = 0;
					flag = 1;
					i++;
					break;
				}
				i++;
			}
			if (d - curdis <= dmax){
				sum += ((d - curdis) / davg - curgas)*curprice;
				break;
			}
			if (flag == 0){
				qsort(dis, j, sizeof(dis[0]), pcmp);
				sum += (c-curgas)*curprice;
				curprice = dis[0][0];
				usegas = (dis[0][1] - curdis) / davg;
				curgas = c - usegas;
				curdis = dis[0][1];
			}
			else
				memset(dis, 0, sizeof(dis));
			if (i == n||price[i][1]-curdis>dmax){
				ff = 1;
				break;
			}
		}
		if (ff == 0)
			printf("%.2lf", sum);
		else
			printf("The maximum travel distance = %.2lf", curdis+dmax);
	}
	system("pause");
	return 0;
}*/
//1050
/*
int main(int argc, char const *argv[])
{
	int a[128][2] = { -1 }, b[10001], count = 0;
	char s1[10001], tmp;
	int i = 0;
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	memset(s1, 0, sizeof(s1));
	while (scanf("%c", &tmp) && tmp != '\n'){
		count++;
		s1[i] = tmp;
		if (a[tmp][0] == -1){
			a[tmp][0] = i;
			a[tmp][1] = i;
		}
		else{
			b[a[tmp][1]] = i;
			a[tmp][1] = i;
		}
		i++;
	}
	while (scanf("%c", &tmp) && tmp != '\n'){
		if (a[tmp][0] != -1){
			i = a[tmp][0];
			s1[a[tmp][1]] = 0;
			while (true){
				s1[i] = 0;
				i = b[i];
				if (i == -1)
					break;
			}
		}
	}
	for (i = 0; i < count; i++)
	if (s1[i] != 0)
		printf("%c", s1[i]);
	system("pause");
	return 0;
}*/
//1028
/*
class Stu
{
public:
	char name[9];
	char id[7];
	char grade[4];
};

int nname(const void * a, const void * b)
{
	Stu *c = (class Stu *)a;
	Stu *d = (class Stu *)b;
	if (strcmp(c->name, d->name) == 0)
		return strcmp(c->id, d->id)>0;
	else
		return strcmp(c->name, d->name)>0;

}
int iid(const void * a, const void * b)
{
	Stu *c = (class Stu *)a;
	Stu *d = (class Stu *)b;
	return strcmp(c->id, d->id)>0;
}
int ggrade(const void * a, const void * b)
{
	Stu *c = (class Stu *)a;
	Stu *d = (class Stu *)b;
	if (strcmp(c->grade, d->grade)!=0)
		return strcmp(c->grade, d->grade)>0;
	else
		return strcmp(c->id, d->id)>0;
}
int main(int argc, char const *argv[])
{
	long n, c;
	string id, name, grade;
	cin >> n >> c;
	Stu *student = new Stu[n];
	for (int i = 0; i<n; i++){
		scanf("%s %s %s", &(student[i].id[0]), &(student[i].name[0]), &(student[i].grade[0]));
	}
	if (1 == c)
		qsort(student, n, sizeof(student[0]), iid);
	else if (2 == c)
		qsort(student, n, sizeof(student[0]), nname);
	else if (3 == c)
		qsort(student, n, sizeof(student[0]), ggrade);

	for (int i = 0; i<n; i++){
		//cout << student[i].id << " " << student[i].name << " " << student[i].grade << endl;
		printf("%s %s %s\n", student[i].id, student[i].name, student[i].grade);
	}
	system("pause");
	return 0;
}*/
//1022
/*
int main(int argc, char const *argv[])
{
	int n;
	string id, title, author, keyword, publisher, year;
	char tmp[60];
	char *temp;
	vector<string> v;
	vector<string>::iterator sit;
	map<string, vector<string> > t, a, k, p, y;
	map<string, vector<string> >::iterator it;
	//map<string,vector<string> > k;
	cin >> n;
	for (int i = 0; i<n; i++){
		//cin >> id;
		getchar();
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		//getline(cin,tmp);
		gets(tmp);
		getline(cin, publisher);
		cin >> year;
		t[title].push_back(id);
		a[author].push_back(id);
		p[publisher].push_back(id);
		y[year].push_back(id);

		temp = strtok(tmp, " ");
		keyword = temp;
		while (true){
			k[keyword].push_back(id);
			temp = strtok(NULL, " ");
			if (temp != NULL)
				keyword = temp;
			else
				break;
		}
	}
	int m;
	string kk;
	cin >> m;
	for (int i = 0; i<m; i++){
		cin >> keyword;
		getchar();
		getline(cin, kk);
		cout << keyword << " " << kk<<endl;
		if (keyword == "1:"){
			it = t.find(kk);
			if (it != t.end()){
				sort(it->second.begin(), it->second.end());
				for (sit = it->second.begin(); sit != it->second.end(); sit++)
					cout << *sit << endl;
			}
			else
				cout << "Not Found"<<endl;
		}
		else if (keyword == "2:"){
			it = a.find(kk);
			if (it != a.end()){
				sort(it->second.begin(), it->second.end());
				for (sit = it->second.begin(); sit != it->second.end(); sit++)
					cout << *sit << endl;
			}
			else
				cout << "Not Found" << endl;
		}
		else if (keyword == "3:"){
			it = k.find(kk);
			if (it != k.end()){
				sort(it->second.begin(), it->second.end());
				for (sit = it->second.begin(); sit != it->second.end(); sit++)
					cout << *sit << endl;
			}
			else
				cout << "Not Found" << endl;
		}
		else if (keyword == "4:"){
			it = p.find(kk);
			if (it != p.end()){
				sort(it->second.begin(), it->second.end());
				for (sit = it->second.begin(); sit != it->second.end(); sit++)
					cout << *sit << endl;
			}
			else
				cout << "Not Found" << endl;
		}
		else if (keyword == "5:"){
			it = y.find(kk);
			if (it != y.end()){
				sort(it->second.begin(), it->second.end());
				for (sit = it->second.begin(); sit != it->second.end(); sit++)
					cout << *sit << endl;
			}
			else
				cout << "Not Found" << endl;
		}
	}
	system("pause");
	return 0;
}*/
//2-07
/*
int main(int argc, char const *argv[])
{
	long n,count,flag=0,f=0;
	while(cin>>n){
		flag=0;
		f=0;
		printf("%ld=",n);
		for(long i=2;i<=sqrt(double(n));i++){
			if(n%i==0){
				f=1;
				if(flag++!=0)
					printf("*");
				printf("%ld",i);
				n/=i;
				count = 1;
				while(n%i==0){
					count++;
					n/=i;
				}
				if(count>1)
					printf("^%ld",count);
			}			
		}
		if(f==1){
			if(n!=1)
				printf("*%ld\n",n);
			else
				printf("\n");
		}
		else
			printf("%ld\n",n);
	}
	return 0;
}*/

//2-10
/*
int main(int argc, char const *argv[])
{
	int d,p,tmp;
	while(cin>>d>>p){
		if(p>3){
			cout<<d-(p/2+1)<<endl;
		}
		else
			cout<<d-1<<endl;
	}

	return 0;
}*/
//1023
/*
int main(int argc, char const *argv[])
{
	char c,in[20]={0},out[21]={0};
	int count[10]={0},i=0,carry=0,tmp,t;
	while(scanf("%c",&c)&&c!='\n'){
		count[c-'0']++;
		in[i++] = c;
	}
	t=i;
	if(in[0]<'5'){
		for(i-=1;i>=0;i--){
			tmp = in[i];
			out[i] = (in[i]-'0')*2%10+carry+'0';
			count[out[i]-'0']--;
			carry = (tmp-'0')*2/10;
		}
	}
	else{
		for(i-=1;i>=0;i--){
			tmp = in[i];
			out[i+1] = (in[i]-'0')*2%10+carry+'0';
			count[out[i+1]-'0']--;
			carry = (tmp-'0')*2/10;
		}
		out[0]=carry+'0';
		
	}

	int flag=0;
	for(int i=0;i<10;i++){
		if(count[i]!=0)
			flag=1;
	}
	if(flag==1)
		printf("No\n");
	else
		printf("Yes\n");
		puts(out);

	return 0;
}*/
//1029
/*
int main(int argc, char const *argv[])
{

	int n = 0, m = 0, count = 0, i = 0, j = 0;
	long flag;
	int ii = 0;
	scanf("%d", &n);

	long *s1 = new long[n];
	for (ii = 0; ii < n; ii++)
		scanf("%ld", &s1[ii]);
	scanf("%d", &m);

	long *s2 = new long[m];
	for (ii = 0; ii < m; ii++)
		scanf("%ld", &s2[ii]);
	if (n&&m){
		while (1){
			if (i < n&&j < m){
				if (s2[j] >= s1[i]){
					count++;
					i++;
					flag = 1;
				}
				else{
					count++;
					j++;
					flag = 0;
				}
				if (count == (n + m + 1) / 2){
					if (flag == 1)
						printf("%ld", s1[i - 1]);
					else
						printf("%ld", s2[j - 1]);
					break;
				}
			}
			else{
				if (i == n)
					printf("%ld", s2[j + (n + m + 1) / 2 - count - 1]);
				else
					printf("%ld", s1[i + (n + m + 1) / 2 - count - 1]);
				break;
			}
		}
		delete[] s1;
		delete[] s2;
	}
	else{
		if (n)
			printf("%ld", s1[n / 2]);
		else if (m)
			printf("%ld", s2[m / 2]);

	}
	return 0;
}*/

//1015
/*
void ten2n(char num[], int n)
{
	long tmp = atoi(num);
	memset(num, 0, sizeof(num));
	int i = 0;
	while (tmp){
		num[i++] = tmp%n + '0';
		tmp /= n;
	}
}
long n2ten(char num[], int n)
{
	long res = 0;
	char tmp[20];
	memset(tmp, 0, sizeof(tmp));
	memcpy(tmp, num, 20);
	memset(num, 0, sizeof(num));
	for (int i = 0; tmp[i]; i++){
		res = res*n + tmp[i] - '0';
	}
	return res;
}

bool isPrime(long tmp)
{
	if (tmp == 0 || tmp == 1)
		return 1;
	int flag = 0;
	for (int i = 2; i <= sqrt(double(tmp)); i++){
		if (tmp%i == 0){
			flag = 1;
			break;
		}
	}
	return flag;
	//if(flag)
	//	cout<<"No"<<endl;
	//else
	//	cout<<"Yes"<<endl;
}

int main(int argc, char const *argv[])
{
	int tmp, radix, f1, f2;
	char num[20];
	while (cin >> num&&atoi(num) >= 0){
		cin >> radix;
		f1 = isPrime(atoi(num));
		ten2n(num, radix);
		f2 = isPrime(n2ten(num, radix));
		if (f1 || f2)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		memset(num, 0, sizeof(num));
	}
	system("pause");
	return 0;
}*/
//1009
/*
int main(int argc, char const *argv[])
{
	int n, mm, count = 0;
	long exp, texp;
	double coeff, tcoeff;
	map<long, double> m, res;
	map<long, double>::iterator it, iit;
	map<long, double>::reverse_iterator rit;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> exp >> coeff;
		m.insert(pair<long, double>(exp, coeff));
	}
	cin >> mm;
	for (int i = 0; i<mm; i++){
		cin >> exp >> coeff;
		for (it = m.begin(); it != m.end(); it++){
			tcoeff = it->second * coeff;
			texp = it->first + exp;
			iit = res.find(texp);
			if (iit != res.end()){
				tcoeff += iit->second;
				if (fabs(tcoeff)>1e-15){
					iit->second = tcoeff;
				}
				else{
					res.erase(iit);
					count--;
				}
			}
			else{
				res.insert(pair<long, double>(texp, tcoeff));
				count++;
			}
		}
	}
	cout << count;
	for (rit = res.rbegin(); rit != res.rend(); rit++)
		printf(" %ld %.1lf", rit->first, rit->second);
	return 0;
}*/
//1007
/*
int main(int argc, char const *argv[])
{
	long in[10000], res[10000], sum[10000], cur = 0, max = -1, begin, end;
	int n, flag = 0;
	memset(sum, -1, sizeof(sum));
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%ld", &in[i]);
	}
	int j = 0;
	long sumtmp = 0;
	for (int i = 0; i < n; i++){
		if (in[i] >= 0)
			flag = 1;
		if (sumtmp + in[i] >= 0){
			sumtmp += in[i];//all
			if (sumtmp >= sum[j]){
				sum[j] = sumtmp;
				res[cur++] = in[i];
			}
			else
				continue;
		}
		else{
			j++;
			res[cur++] = -1;
			sumtmp = 0;
		}
		if (sum[j] > max){
			max = sum[j];
			end = cur - 1;
		}
	}
	if (flag){
		int i;
		for (i = end; i >= 0 && res[i] != -1; i--)
			;
		cout << max << " " << res[i + 1] << " " << res[end];
	}
	else{
		cout << "0";
		cout << " " << in[0] << " " << in[n - 1];
	}
	return 0;
}*/
//1035
/*
int main(int argc, char const *argv[])
{
	int n, count = 0, flag = 0, j = 0;
	string name, pw;
	string::iterator it;

	cin >> n;
	int *f = new int[n];
	vector< vector<string> > v(n, vector<string>(0));
	for (int i = 0; i < n; i++){
		cin >> name >> pw;
		for (it = pw.begin(); it != pw.end(); it++){
			if (*it == '1' || *it == '0' || *it == 'l' || *it == 'O'){
				if (*it == '1')
					*it = '@';
				else if (*it == '0')
					*it = '%';
				else if (*it == 'l')
					*it = 'L';
				else if (*it == 'O')
					*it = 'o';
				flag = 1;

			}
		}
		if (flag == 1){
			count++;
			v[j].push_back(name);
			v[j].push_back(pw);
			j++;
			flag = 0;
		}
	}
	if (count > 0){
		cout << count << endl;
		for (int i = 0; i < count; i++){
			cout << v[i][0] << " " << v[i][1] << endl;
		}
	}
	else{
		if (n != 1)
			cout << "There are " << n << " accounts and no account is modified";
		else
			cout << "There is 1 account and no account is modified";
	}
	delete[] f;
	system("pause");

	return 0;
}*/
//1031
/*
int main(int argc, char const *argv[])
{
	string s;
	string::iterator itb, ite;
	int size, tmp;
	cin >> s;
	size = s.size();
	tmp = size;
	size = (size + 2) / 3;
	itb = s.begin();
	ite = s.end() - 1;
	for (int j = 0; j < size - 1; j++){
		cout << *itb;
		for (int i = 0; i < tmp - 2 * size; i++)
			cout << " ";
		cout << *ite << endl;
		itb++;
		ite--;
	}
	while (itb != ite + 1){
		cout << *itb;
		itb++;
	}


	return 0;
}*/

//1027
/*
char res[2] = { '0' };
void ten213(int n)
{
	int i = 0;
	if (n >= 13){
		while (n){
			int tmp = n % 13;
			if (tmp <= 9){
				res[i++] = tmp + '0';
			}
			else{
				switch (tmp){
				case 10:res[i++] = 'A'; break;
				case 11:res[i++] = 'B'; break;
				case 12:res[i++] = 'C'; break;
				}
			}
			n /= 13;
		}
	}
	else{
		res[1] = '0';
		if (n <= 9)
			res[0] = n % 13 + '0';
		else{
			switch (n % 13){
			case 10:res[0] = 'A'; break;
			case 11:res[0] = 'B'; break;
			case 12:res[0] = 'C'; break;
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int in[3];
	string::iterator it;
	cin >> in[0] >> in[1] >> in[2];
	cout << "#";
	for (int i = 0; i < 3; i++){
		ten213(in[i]);
		cout << res[1] << res[0];
	}
	return 0;
}*/

//1007
/*
int main(int argc, char const *argv[])
{
	int n, t, flag = 0, res[3] = { 0 };
	vector<int> v;
	vector<int>::iterator it;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> t;
		if (t<0)
			v.push_back(t);
		else{
			flag = 1;
		}
		if (res[0] + t>res[0]){
			res[0] = res[0] + t;
		}
	}
	if (flag == 0){
		cout << "0";
		for (it = v.begin(); it != v.end(); it++){
			cout << " " << *it;
		}
	}
	else{
		;
	}
	return 0;
}*/
//1005
/*
int main(int argc, char const *argv[])
{
	string name, in, out;
	int n;
	map<string, string> unlock, lock;
	map<string, string>::iterator it;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> name >> in >> out;
		unlock.insert(pair<string, string>(in, name));
		lock.insert(pair<string, string>(out, name));
	}
	it = unlock.begin();
	cout << it->second << " ";
	it = lock.end();
	it--;
	cout << it->second;
}


typedef struct Node
{
	int curAdress, key, nextAdress;
	bool exist;
	Node(){ exist = false; }
	bool operator < (const Node& orh) const
	{
		return key < orh.key;
	}
}Node;
#define MAX 1000000
int main()
{
	int n, root;
	scanf("%d%d", &n, &root);
	vector<Node> nodeMap(MAX);
	for (int i = 0; i < n; ++i)
	{
		Node tmp;
		scanf("%d%d%d", &tmp.curAdress, &tmp.key, &tmp.nextAdress);
		tmp.exist = true;
		if (tmp.curAdress >= 0 && tmp.curAdress < MAX)
			nodeMap[tmp.curAdress] = tmp;
	}
	//process
	vector<Node> nodeList;
	int curID = root;
	while (curID >= 0 && curID < MAX && nodeMap[curID].exist)
	{
		nodeList.push_back(nodeMap[curID]);
		curID = nodeMap[curID].nextAdress;
	}
	//output
	if (nodeList.empty())
	{
		if (root == -1)
			printf("0 -1\n");
		else printf("0 %05d\n", root);
	}
	else
	{
		sort(nodeList.begin(), nodeList.end());
		printf("%d %05d\n", nodeList.size(), nodeList[0].curAdress);
		for (int i = 0; i < nodeList.size(); ++i)
		{
			if (i != nodeList.size() - 1)
				printf("%05d %d %05d\n", nodeList[i].curAdress, nodeList[i].key, nodeList[i + 1].curAdress);
			else printf("%05d %d -1\n", nodeList[i].curAdress, nodeList[i].key);
		}
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	unordered_map<string, long> mmap;
	unordered_map<string, long>::iterator it;
	int n, len;
	//string id;
	long l;
	char id[19];
	//cin >> n >> len;
	scanf("%d %d", &n, &len);
	for (int i = 0; i < n; i++){
		//cin >> id >> l;
		scanf("%s %ld", id, &l);
		if (l < len)
			l = len;
		it = mmap.find(id);
		if (it == mmap.end())
			mmap.insert(pair<string, long>(id, l));
		else{
			it->second += l;
		}
	}
	//cin >> n;
	scanf("%d", &n);
	char(*res)[]
		for (int i = 0; i < n; i++){
			//cin >> id;
			scanf("%s", id);
			it = mmap.find(id);
			if (it != mmap.end())
				//cout << it->second << endl;
				printf("%ld\n", it->second);
			else
				//cout << "No Info" << endl;
				printf("No Info\n");
		}
		return 0;
}*/

//3-07 boring scanf
/*
int main(int argc, char const *argv[])
{
	int in;
	vector<int> v;
	vector<int>::iterator it;
	while (scanf("%d", &in) && in >= 0){
		v.push_back(in);
	}
	it = v.end();
	if (v.size() - 1 >= v[0])
		cout << *(it - v[0]);
	else
		cout << "NULL";
	return 0;
}

int main(int argc, char const *argv[])
{
	vector<string> in;
	vector<string>::iterator it;
	string tmp;
	int i = 0, cur = 0;
	int flag = 0;
	int add = 1, sub = 1, mul = 1, div = 1;
	double res[30] = { 0 };
	while (cin >> tmp)
		in.push_back(tmp);

	for (it = in.end() - 1; it >= in.begin(); it--){
		char *tmp = (char *)(*it).c_str();
		add = *it == "+" ? 0 : 1;//equal = 0
		sub = *it == "-" ? 0 : 1;
		mul = *it == "*" ? 0 : 1;
		div = *it == "/" ? 0 : 1;
		if (add&&sub&&mul&&div){//number
			stringstream ss(tmp);
			ss >> res[cur++];
		}
		else{
			if (cur < 2){
				flag = 1;
				break;
			}
			if (!add){
				res[cur - 2] = res[cur - 1] + res[cur - 2];
				cur -= 1;
				add = 0;
			}
			else if (!sub){
				res[cur - 2] = res[cur - 1] - res[cur - 2];
				cur -= 1;
				sub = 0;
			}
			else if (!mul){
				res[cur - 2] = res[cur - 1] * res[cur - 2];
				cur -= 1;
				mul = 0;
			}
			else if (!div){
				if (fabs(res[cur - 2]) <= 1e-15){
					flag = 1;
					break;
				}
				res[cur - 2] = res[cur - 1] / res[cur - 2];

				cur -= 1;
				div = 0;
			}
		}
	}
	if (!flag)
		printf("%.1lf", res[0]);
	else
		cout << "ERROR";
	return 0;
}*/
//2-09
/*
int main(int argc, char const *argv[])
{
	int n, size, pos = 0, offset = 0, count = 0;
	cin >> n;
	//int *box = new int[n+1];
	int box[1000] = { 100 };
	for (int i = 0; i < 1000; i++)
		box[i] = 100;
	for (int i = 0; i<n; i++){
		cin >> size;
		for (int j = pos;;){
			if (box[j] >= size){
				box[j] -= size;
				printf("%d %d\n", size, j + 1);
				if (j + 1>count)
					count = j + 1;
				if (box[pos] == 0)
					pos++;
				break;
			}
			else{
				j++;
			}
		}
	}
	printf("%d\n", count);
	//delete[] box;

	return 0;
}*/
//2-12
/*
int main(int argc, char const *argv[])
{
	vector<int> v1, v2;
	vector<int>::iterator it1, it2;
	int tmp;
	while (scanf("%d", &tmp) && tmp != -1)
		v1.push_back(tmp);
	while (scanf("%d", &tmp) && tmp != -1)
		v2.push_back(tmp);
	if (v1.size() == 0 || v2.size() == 0)
		printf("NULL");
	else{
		int i = 0;
		int flag = 0;
		for (it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end(), it2 != v2.end();){
			if (*it1 == *it2){
				if (i != 0)
					printf(" ");
				printf("%d", *it1);
				it1++;
				it2++;
				flag = 1;
				i++;
			}
			else if (*it1 > *it2)
				it2++;
			else
				it1++;

		}
		if (flag == 0)
			printf("NULL");
	}
	return 0;
}*/
//2-11
/*
int main(int argc, char const *argv[])
{
	vector<int> v;
	int tmp;
	while (scanf("%d", &tmp) && tmp != -1){
		v.push_back(tmp);
	}
	while (scanf("%d", &tmp) && tmp != -1){
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	if (v.size()){
		int i = 0;
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++){
			if (i != 0)
				//cout<<" ";
				printf(" ");
			//cout<<*it;
			printf("%d", *it);
			i++;
		}
	}
	else
		cout << "NULL";

	return 0;
}*/
//2-13
/*
//long s1[100000],s2[100000];
int main(int argc, char const *argv[])
{

	int n, count = 0, i = 0, j = 0;
	long flag;
	int ii = 0;
	scanf("%d", &n);
	long *s1 = new long[n];
	long *s2 = new long[n];
	for (ii = 0; ii < n; ii++)
		scanf("%ld", &s1[ii]);
	for (ii = 0; ii < n; ii++)
		scanf("%ld", &s2[ii]);

	while (1){
		if (s2[j] >= s1[i]){
			count++;
			i++;
			flag = 1;
		}
		else{
			count++;
			j++;
			flag = 0;
		}
		if (count == n){
			if (flag == 1)
				printf("%ld", s1[i - 1]);
			else
				printf("%ld", s2[j - 1]);
			break;
		}
	}
	delete[] s1;
	delete[] s2;
	return 0;
}*/
//1036
/*
class Stu
{
public:
	string name;
	string gender;
	string subject;
	int score;
};
int main(int argc, char const *argv[])
{
	int n;
	string nname, ggender, ssubject;
	int mscore = 101, fscore = -1, sscore;
	Stu male, female;
	int cm = 0, cf = 0;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> nname >> ggender >> ssubject >> sscore;
		if (strcmp(ggender.c_str(), "F") == 0){
			cf++;
			if (sscore>fscore){
				fscore = sscore;
				female.name = nname;
				female.gender = ggender;
				female.subject = ssubject;
				female.score = sscore;
			}
		}
		else if (strcmp(ggender.c_str(), "M") == 0){
			cm++;
			if (sscore < mscore){
				mscore = sscore;
				male.name = nname;
				male.gender = ggender;
				male.subject = ssubject;
				male.score = sscore;
			}
		}
	}
	if (cm >= 1 && cf >= 1){
		cout << female.name << " " << female.subject << endl;
		cout << male.name << " " << male.subject << endl;
		cout << female.score - male.score;
	}
	else if (cm >= 1){

		cout << "Absent" << endl;
		cout << male.name << " " << male.subject << endl;
		cout << "NA";
	}
	else if (cf >= 1){

		cout << female.name << " " << female.subject << endl;
		cout << "Absent" << endl;
		cout << "NA";
	}
	else
		cout << "Absent" << endl << "Absent" << endl << "NA";
	return 0;
}*/
//2-05
/*
int main(int argc, char const *argv[])
{
	int n;
	double sum = 0, avg = 0, in[10000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> in[i];
		sum += in[i];
	}
	avg = sum / n;
	sum = 0;
	for (int i = 0; i < n; i++){
		sum += pow((in[i] - avg), 2);
	}
	printf("%.5f", sqrt(sum / n));
	return 0;
}*/
//1003
/*
int main(int argc, char const *argv[])
{
	int n, a = 0, b = 0, c = 0;
	string s;
	string::iterator it;
	int flag = 0, count1 = 0, count2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		a = b = c = flag = count1 = count2 = 0;
		for (it = s.begin(); it != s.end(); it++){
			if (*it != 'P' && *it != 'A' && *it != 'T'){
				cout << "NO" << endl;
				flag = 1;
				break;
			}
			if (*it == 'P')
				count1++;
			else if (*it == 'T')
				count2++;
			if (count1 > 1 || count2 > 1){
				cout << "NO" << endl;
				flag = 1;
				break;
			}
			else{
				if ('A' == *it && (int)(it - s.begin())<(int)s.find("P"))
					a++;
				else if ('A' == *it && (int)(it - s.begin())>(int)s.find("P") && (int)(it - s.begin())<(int)s.find("T"))
					b++;
				else if ('A' == *it && (int)(it - s.begin())>(int)s.find("T"))
					c++;
			}
		}
		if (flag == 0){
			if (a*b != c || b == 0)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}

	}
	system("pause");
	return 0;
}*/
//1014
/*
int main(int argc, char const *argv[])
{
	string s1, s2, s3, s4;
	string::iterator it1, it2;
	cin >> s1 >> s2 >> s3 >> s4;
	for (it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end(), it2 != s2.end(); it1++, it2++){
		if (*it1 == *it2&&'A' <= (*it1) && (*it1) <= 'G'){
			switch (*it1){
			case 'A':cout << "MON "; break;
			case 'B':cout << "TUE "; break;
			case 'C':cout << "WED "; break;
			case 'D':cout << "THU "; break;
			case 'E':cout << "FRI "; break;
			case 'F':cout << "SAT "; break;
			case 'G':cout << "SUN "; break;
			}
			for (it1++, it2++; it1 != s1.end(), it2 != s2.end(); it1++, it2++)
			if (*it1 == *it2 && ('A' <= (*it1) && (*it1) <= 'N' || '0' <= (*it1) && (*it1) <= '9')){
				//'A'<=(*it1)&&(*it1)<='G'?cout<<9+(*it)-'A'+1:cout<<*it-'0';
				'A' <= (*it1) && (*it1) <= 'N' ? printf("%02d:", 9 + (*it1) - 'A' + 1) : printf("%02d:", *it1 - '0');
				break;
			}
			break;
		}
	}
	for (it1 = s3.begin(), it2 = s4.begin(); it1 != s3.end(), it2 != s4.end(); it1++, it2++){
		if (*it1 == *it2 && (('A' <= (*it1) && (*it1) <= 'Z') || ('a' <= (*it1) && (*it1) <= 'z'))){
			printf("%02d", it1 - s3.begin());
			break;
		}
	}

	return 0;
}*/
//1025
/*
long l[100000][3], li[100000][3];

int main(int argc, char const *argv[])
{
	long add, n, d;
	cin >> add >> n >> d;
	long t1, t2, t3;
	for (int iii = 0; iii < n; iii++){
		scanf("%ld %ld %ld", &t1, &t2, &t3);
		l[t1][0] = t1;
		l[t1][1] = t2;
		l[t1][2] = t3;
	}
	int c = 0;
	for (int ii = 0;; ii++){
		li[ii][0] = l[add][0];
		li[ii][1] = l[add][1];
		li[ii][2] = l[add][2];
		add = l[add][2];
		c++;
		if (add == -1)
			break;
	}
	int j = n / d, i = 1, count = 0;
	n = c;
	while (n > 0){
		if (n >= d){
			for (int k = 1; k <= d; k++){
				if (count != 0){
					printf("%05ld\n", li[d*i - k][0]);
				}
				printf("%05ld %ld ", li[d*i - k][0], li[d*i - k][1]);
				count++;
			}
			i++;
		}
		else{
			i--;
			for (int k = 0; k < n; k++){
				printf("%05ld\n%05ld %ld ", li[d*i + k][0], li[d*i + k][0], li[d*i + k][1]);
			}

		}
		n -= d;
	}
	printf("-1");
	system("pause");
	return 0;
}*/
//1010
/*
int main(int argc, char const *argv[])
{
	int a, b, count = 0;
	while (cin >> a >> b){
		if (b != 0){
			if (count++ != 0)
				cout << " ";
			cout << a*b << " " << b - 1;
		}
	}
	if (count == 0)
		cout << "0 0";
	return 0;
}*/
//1024
/*
int main(int argc, char const *argv[])
{
	string s;
	string::size_type p;
	string::iterator it;
	int ex = 0, count = 0;
	bool r = false, e = false;
	cin >> s;
	it = s.begin();
	p = s.find("E");
	if (*(it + p + 1) == '+')
		e = true;
	if (*it == '+')
		r = true;
	if (r == false)
		printf("-");
	for (it = s.begin() + p + 2; it != s.end(); it++){
		ex = 10 * ex + (*it - '0');
	}
	//cout << ex << endl;
	//cout << endl << ex << endl;
	if (e){
		if (ex == 0)
		for (it = s.begin() + 1; it < s.begin() + p; it++){
			cout << *it;
			//count++;
		}
		else{
			for (it = s.begin() + 1; it < s.begin() + p; it++){

				if (((int)p - 3)>ex){//length>exp

					if (*it == '.')
						continue;
					//else
					cout << *it;
					if (count == ex)
						cout << ".";
					count++;

				}
				else{
					if (*it == '.'&&ex != 0)
						continue;
					cout << *it;
					count++;
				}
			}


			for (int i = count; i <= ex; i++){
				printf("0");
			}
		}
	}
	else{
		if (ex == 0)
		for (it = s.begin() + 1; it < s.begin() + p; it++){
			cout << *it;
			//count++;
		}
		else{
			printf("0.");
			for (int i = 0; i < ex - 1; i++){
				printf("0");
			}
			for (it = s.begin() + 1; it < s.begin() + p; it++){
				if (*it == '.'&&ex != 0)
					continue;
				cout << *it;
				//count++;
			}
		}
	}
	system("pause");
	return 0;
}*/
//1015
/*
int imp(const void *a, const void *b)
{
	long *c = (long *)a;
	long *d = (long *)b;
	if (*(c + 1) + *(c + 2) != *(d + 1) + *(d + 2)){
		return *(d + 1) + *(d + 2) - (*(c + 1) + *(c + 2));//big2small
	}
	else{
		if (*(c + 1) != *(d + 1))
			return *(d + 1) - *(c + 1);//big2small
		else
			return *c - *d;//small2big
	}

}

long grade1[100000][3], grade2[100000][3], grade3[100000][3], grade4[100000][3];
int main(int argc, char const *argv[])
{

	long a, d, c;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int n, l, h, count = 0;
	//cin >> n >> l >> h;
	scanf("%d %d %d", &n, &l, &h);
	for (int i = 0; i < n; i++){
		//cin >> a >> d >> c;
		scanf("%ld %ld %ld", &a, &d, &c);
		if (d >= l&&c >= l){
			count++;
			if (d >= h&&c >= h){
				grade1[c1][0] = a;
				grade1[c1][1] = d;
				grade1[c1][2] = c;
				c1++;
			}
			else if (c < h&&d >= h){

				grade2[c2][0] = a;
				grade2[c2][1] = d;
				grade2[c2][2] = c;
				c2++;
			}
			else if (c < h&&d < h&&d >= c){

				grade3[c3][0] = a;
				grade3[c3][1] = d;
				grade3[c3][2] = c;
				c3++;
			}
			else {

				grade4[c4][0] = a;
				grade4[c4][1] = d;
				grade4[c4][2] = c;
				c4++;
			}
		}

	}
	//cout << count << endl;
	printf("%d\n", count);
	qsort(grade1, c1, sizeof(grade1[0]), imp);
	qsort(grade2, c2, sizeof(grade2[0]), imp);
	qsort(grade3, c3, sizeof(grade3[0]), imp);
	qsort(grade4, c4, sizeof(grade4[0]), imp);
	for (int i = 0; i < c1; i++){
		printf("%ld %ld %ld\n", grade1[i][0], grade1[i][1], grade1[i][2]);
		//cout << grade1[i][0] << " " << grade1[i][1] << " " << grade1[i][2] << endl;
	}
	for (int i = 0; i < c2; i++){
		//cout << grade2[i][0] << " " << grade2[i][1] << " " << grade2[i][2] << endl;
		printf("%ld %ld %ld\n", grade2[i][0], grade2[i][1], grade2[i][2]);
	}
	for (int i = 0; i < c3; i++){
		//cout << grade3[i][0] << " " << grade3[i][1] << " " << grade3[i][2] << endl;
		printf("%ld %ld %ld\n", grade3[i][0], grade3[i][1], grade3[i][2]);
	}
	for (int i = 0; i < c4; i++){
		//cout << grade4[i][0] << " " << grade4[i][1] << " " << grade4[i][2] << endl;
		printf("%ld %ld %ld\n", grade4[i][0], grade4[i][1], grade4[i][2]);
	}
	system("pause");
	return 0;
}*/


//1018
/*
int main()
{
	int n;
	cin >> n;

	int awin = 0;
	int bwin = 0;
	int draw = 0;

	// 'BCJ' <--> times[012]
	int timesa[3] = { 0 };
	int timesb[3] = { 0 };

	for (int i = 0; i < n; ++i){
		char a, b;
		cin >> a >> b;
		if (a == b){
			++draw;
		}
		else if (a == 'C' && b == 'J'){
			++timesa[1];
			++awin;
		}
		else if (a == 'J' && b == 'B'){
			++timesa[2];
			++awin;
		}
		else if (a == 'B' && b == 'C'){
			++timesa[0];
			++awin;
		}
		else if (a == 'C' && b == 'B'){
			++timesb[0];
			++bwin;
		}
		else if (a == 'J' && b == 'C'){
			++timesb[1];
			++bwin;
		}
		else if (a == 'B' && b == 'J'){
			++timesb[2];
			++bwin;
		}
	}

	char maxa, maxb;
	int maxta, maxtb;

	maxa = timesa[0] >= timesa[1] ? 'B' : 'C';
	maxta = timesa[0] >= timesa[1] ? timesa[0] : timesa[1];
	maxa = maxta >= timesa[2] ? maxa : 'J';

	maxb = timesb[0] >= timesb[1] ? 'B' : 'C';
	maxtb = timesb[0] >= timesb[1] ? timesb[0] : timesb[1];
	maxb = maxtb >= timesb[2] ? maxb : 'J';

	cout << awin << " " << draw << " " << bwin << endl;
	cout << bwin << " " << draw << " " << awin << endl;
	cout << maxa << " " << maxb << endl;

	system("pause");

	return 0;
}*/


//1013
/*
int  p[1000000];
inline bool prime(int num)
{
	for (int i = 2; i <= sqrt((double)num); i++){
		if (0 == num%i)
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int n, m, count = 1;
	cin >> m >> n;

	int j = 0, cur = 1;
	while (j <= 10000){
		if (prime(cur))
			p[j++] = cur;
		cur++;
	}
	p[0] = 0;
	for (int i = m; i <= n; i++){
		cout << p[i];
		if (count != n - m + 1)
		if (count % 10)
			cout << " ";
		else{
			//cout<<"f";
			cout << endl;
		}
		count++;
	}
	//cout<<"f";
	return 0;
}*/


//1012
/*
int main(int argc, char const *argv[])
{
	int n, i = 1, x;
	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
	float a4 = 0, sum = 0;
	cin >> x;
	for (int k = 0; k < x; k++){
		cin >> n;
		if (0 == n % 5){
			if (0 == n % 2){
				a1 += n;
				f1 = 1;
			}
		}
		if (1 == n % 5){
			if (i % 2){//ji
				a2 += n;
				i++;
				f2 = 1;
			}
			else{
				a2 -= n;
				i++;
				f2 = 1;
			}
		}
		if (2 == n % 5){
			a3++;
			f3 = 1;
		}
		if (3 == n % 5){
			sum += n;
			a4++;
			f4 = 1;
		}
		if (4 == n % 5 && n > a5){
			a5 = n;
			f5 = 1;
		}
	}
	f1 == 0 ? printf("N ") : printf("%d ", a1);
	f2 == 0 ? printf("N ") : printf("%d ", a2);
	f3 == 0 ? printf("N ") : printf("%d ", a3);
	f4 == 0 ? printf("N ") : printf("%.1f ", sum / a4);
	f5 == 0 ? printf("N") : printf("%d", a5);
	return 0;
}*/


//1019 tmd
/*
int imp(const void *a, const void *b)
{
	char *c = (char *)a;
	char *d = (char *)b;
	return *c - *d;//small
}

int dmp(const void *a, const void *b)
{
	char *c = (char *)a;
	char *d = (char *)b;
	return *d - *c;//large
}

void itob(int i, char *a, int *len)
{
	int j = *len - 1;
	*len = 0;
	while (i){
		*(a + j) = i % 10 + 48;
		i /= 10;
		j--;
		(*len)++;
	}
}

void itob(char *a, int in)
{
	for (int i = 3; i >= 0; i--){
		a[i] = in % 10 + '0';
		in /= 10;
	}
}

int main(int argc, char const *argv[])
{
	char a[5] = { 0 }, b[5] = { 0 };
	int aa, bb, len, in;
	cin >> in;
	itob(a, in);
	if (!strncmp(a, "6174", 4)){
		cout << "7641 - 1467 = 6174";
	}
	else if (a[0] == a[1] && a[0] == a[2] && a[0] == a[3]){
		printf("%04d - %04d = %04d\n", in, in, 0);
	}
	else
	while (strncmp(a, "6174", 4)){
		strcpy(b, a);
		qsort(a, 4, sizeof(a[0]), imp);//min
		qsort(b, 4, sizeof(b[0]), dmp);//max
		aa = atoi(a);
		bb = atoi(b);
		printf("%04d - %04d = %04d\n", bb, aa, -aa + bb);
		itob(a, -aa + bb);
	}
	return 0;
}*/

//1022
/*
int main(int argc, char const *argv[])
{
	long long a, b;
	int radix, res[30];
	cin >> a >> b >> radix;
	a += b;
	int i = 0;
	while (a >= 0){
		res[i++] = a%radix;
		a /= radix;
		if (a == 0)
			break;
	}
	for (i = i - 1; i >= 0; i--)
		cout << res[i];
	return 0;
}*/


//1020
/*
int cmp(const void *a, const void *b)
{
	double *c = (double *)a;
	double *d = (double *)b;
	if (*c != *d)
		return (*c > *d) ? -1 : 1;//large
	else
		return (*(c + 1) > *(d + 1)) ? -1 : 1;
}

int main(int argc, char const *argv[])
{
	int n, d;
	double stock[1000], price[1000], rate[1000][2], sum = 0;
	cin >> n >> d;
	for (int i = 0; i < n; i++){
		cin >> stock[i];
	}
	for (int i = 0; i < n; i++){
		cin >> price[i];
		rate[i][0] = price[i] / stock[i];
		rate[i][1] = i;
	}
	qsort(rate, n, sizeof(rate[0]), cmp);
	int tmp;
	for (int i = 0; i < n; i++){
		//tmp =
		if (stock[(int)rate[i][1]] <= d){
			sum += price[(int)rate[i][1]];
			d -= stock[(int)rate[i][1]];
		}
		else{
			sum += d*price[(int)rate[i][1]] / stock[(int)rate[i][1]];
			d = 0;
		}
		if (d == 0)
			break;
	}
	printf("%.2lf", sum);
	return 0;
}
*/
//1026
/*
int main()
{
	int m,n;
	cin>>m>>n;

	int a = (int)((n-m)/100.0+0.5);
	int b = a/60;
	int c = b/60;
	int d = a%60;
	printf("%02d:%02d:%02d\n",c,b%60,d);
	return 0;
}*/
//1028
/*
bool compare1(int preYear, int Year, int preMonth, int Month, int preDay, int Day)
{
	if(Year > preYear)
		return true;
	else if(Year == preYear){
		if(Month > preMonth)
			return true;
		else if(Month == preMonth)
			if(Day > preDay)
				return true;
	}
	return false;
}

bool compare2(int preYear, int Year, int preMonth, int Month, int preDay, int Day)
{
	if(Year < preYear)
		return true;
	else if(Year == preYear){
		if(Month < preMonth)
			return true;
		else if(Month == preMonth)
			if(Day < preDay)
				return true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	int maxYear = 2014, minYear = 1814;
	int maxMonth = 9, minMonth = 9;
	int maxDay = 7, minDay = 5;
	string maxName = "", minName = "";
	int validCount = 0;
	while(n--){
		string name;
		cin>>name;
		int year = 0,month = 0,day = 0;
		scanf("%d/%d/%d",&year,&month,&day);
		if(compare2(2014, year, 9, month, 7, day) && compare1(1814,year,9,month,5,day)){
			validCount++;
			if(compare2(maxYear,year,maxMonth,month,maxDay,day)){
				maxYear = year;
				maxMonth = month;
				maxDay = day;
				maxName = name;
			}
			if(compare1(minYear,year,minMonth,month,minDay,day)){
				minYear = year;
				minMonth = month;
				minDay = day;
				minName = name;
			}
		}
	}
	cout<<validCount;
	if(maxName!="")
		cout<<" "<<maxName;
	if(minName!="")
		cout<<" "<<minName<<endl;
	return 0;
}
*/

//1029
/*
int main()
{
	string str1;
	string str2;
	string::const_iterator it1, it2;
	cin >> str1;
	cin >> str2;
	set<char> s;
	for(it1 = str1.begin(),it2 = str2.begin(); it1 != str1.end() ; ++it1){
		if(*it1 != *it2){
			char c1 = toupper(*it1);
			if(s.find(c1) == s.end()){
				s.insert(c1);
				cout<<c1;
			}
		}
		else
			it2++;
	}
	cout<<endl;
	return 0;
}
*/

//1031
/*
int main()
{
	int n;
	cin >> n;
	int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char mCode[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	string::const_iterator it;
	bool flag = true;
	while(n--){
		string str;
		cin>>str;
		int sum = 0;
		int i = 0;
		for(it = str.begin(); it != str.end()-1; ++it){
			int d = *it - '0';
			sum += d*weight[i++];
		}
		if(mCode[sum%11] != (*it)){
			cout<<str<<endl;
			flag = false;
		}
	}
	if(flag)
		cout<<"All passed"<<endl;
	
	return 0;
}
*/
