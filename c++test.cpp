#include <iostream>
//#include <climits>
#include <string>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
//#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	// double res = -6.0/7*(log(6.0/7)/log(2.0))-1.0/7*(log(1.0/7)/log(2.0));
	// double res = -200.0/450*(log(200.0/450)/log(2.0))-250.0/450*(log(250.0/450)/log(2.0));
	// double res = log(double(10));
//	double res = 0.991076-(205.0/450*(-105.0/205*(log(105.0/205)/log(2.0))-100.0/205*(log(100.0/205)/log(2.0))+245.0/450*(-95.0/245*(log(95.0/245)/log(2.0))-150.0/245*(log(150.0/245)/log(2.0)));
	cout<<"111";
	
	return 0;
}
/*
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
    //return hash;
}

int main()
{
	char * s = "fasdfadsfasdd";
	cout<<BKDRHash(s)<<endl;
	printf("%p",BKDRHash(s));
}
*/
/*

#define  MAX 1000
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<bool> existed(MAX, false);
	for (int i = 0; i < b.size(); ++i){
cout<<b[i]<<endl;
		existed[b[i]] = true;
	}
	for (int i = 0; i < a.size(); ++i)
		if (!existed[a[i]]) printf("%c",a[i]);
	printf("\n");
	return 0;
}*/
/*
class test
{
public:
	string aa;
	string bb;

};
bool cmp(const test & a,const test & b)
{
	return a.bb>b.bb;
}
int main(int argc, char const *argv[])
{
	test t[3];
	t[0].aa = "1";
	t[0].bb = "3";
	t[1].aa = "2";
	t[1].bb = "2";
	t[2].aa = "3";
	t[2].bb = "1";
	sort(t,t+3,cmp);
	cout<<t[0].aa<<" "<<t[0].bb<<endl<<t[1].aa<<" "<<t[1].bb<<endl<<t[2].aa<<" "<<t[2].bb;
	return 0;
}*/
/*
void ttt(char a[])
{
	a[0] = 49;
}
int main()
{
	long *a = new long[0];

}*/
//int bb[99999999];
/*
unsigned int BKDRHash(char *str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}
int main()
{
	int a;
	scanf("%d", &a);
	cout << a;
}*/
/*
int main(int argc, char const *argv[])
{
	vector<int> v1, v2;
	vector<int>::iterator it1, it2;
	int tmp;
	while (cin >> tmp&&tmp != -1)
		v1.push_back(tmp);
	while (cin >> tmp&&tmp != -1)
		v2.push_back(tmp);
	if (v1.size() == 0 && v2.size() == 0)
		cout << "NULL";
	else{
		int i = 0;
		for (it1 = v1.begin(), it2 = v2.begin();; it1++, it2++){
			if (i != 0)
				cout << " ";
		}
	}
	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	char ttt[20] = "fsfsad";
	printf("%d", sizeof(ttt));

	itoa(x, temp, 10);
	strcat(boxsize, temp);
	strcat(boxsize, " ");

	itoa(y, temp, 10);
	strcat(boxsize, temp);
	strcat(boxsize, " ");

	itoa(z, temp, 10);
	strcat(boxsize, temp);
	strcat(boxsize, "\n");

	//itoa(size,&boxsize[5],10);
	puts(boxsize);
	puts("haha");

	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	string text;
	int alpha[26];
	memset(alpha, 0, sizeof(alpha));
	getline(cin, text);

	string::iterator it;
	for (it = text.begin(); it != text.end(); it++)
	{
		if (isalpha(*it))
			alpha[*it - 65]++;
	}

	for (int i = 0; i < 26; i++)
		printf("%c,%2d,%d\n", i + 65, i + 1, alpha[i]);

	system("pause");
	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	int res[120], r[120], n, num, count = 0;
	for (int i = 0; i < 120; i++)
	{
		res[i] = 0;
		r[i] = 0;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
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
				cout << i << " ";
			else
				cout << i;
			count--;
		}

	}
	//cout<<"fuck";
	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	//	freopen("1.txt","r",stdin);
	string a;
	char res[1100], in[1100];
	//	for(int k = 0; k<5; k++){

	for (int i = 0; i < 1100; i++)
	{
		in[i] = 0;
		res[i] = 0;
	}
	int b, flag = 0, j = 0, q = 0;
	cin >> a >> b;

	string::const_iterator it;
	for (it = a.begin(); it != a.end(); it++)
	{
		in[j++] = *it;
	}
	int i = j;
	//cout<<in[0]<<"fuck"<<endl;
	if (in[0] != '0'&&b != 0)
	{
		for (j = 0; j < i; j++)
		{
			res[j] = (q * 10 + in[j] - 48) / b + 48;
			q = (q * 10 + in[j] - 48) % b;
		}

		//cout<<res<<" "<<q;
		if (res[0] == '0')
			cout << &res[1] << " " << q;
		else
			cout << res << " " << q;
	}
	else if (in[0] == '0')
		cout << 0 << " " << 0;
	//	}
	//	fclose(stdin);
	return 0;
}*/
/*
int main(int argc, char const *argv[])
{
	string s;
	char ch[20];
	cin.get(ch, 20);
	cout << ch;
	return 0;
}

class  A
{
public:
	A() :a(0){};
	void fun2()
	{
		fun();
		cout << a << endl;
	}

private:
	int a;
	void fun()
	{
		a = 1;
	}

};
*/

/*
int main(int argc, char const *argv[])
{
	A b;
	b.fun2();
	return 0;
}*/

/*
int main(int argc, char const *argv[])
{
	std::vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	//v.clear();
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}*/

/*
struct test
{
	int i;
	float f;
};
int main(int argc, char const *argv[])
{
	struct test a;
	a.i = 10;
	a.f = 20;
	cout << a.i << a.f << endl;
	return 0;
}*/

/*
int main(int argc, char const *argv[])
{
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	vector<int>::iterator it;
	for (it = test.begin(); it != test.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (it = test.begin(); it != test.end(); it++)
	{
		if (*it == 5)
			test.erase(it);
	}

	for (it = test.begin(); it != test.end(); it++)
	{
		cout << *it << " ";
	}


	return 0;
}*/

/*
int main(int argc, char const *argv[])
{
	const string& data = "655369";
	char *endptr = NULL;
	int flag = 1;
	strtof(data.c_str(), &endptr);
	if (errno != 0 || (endptr != NULL && *endptr != '\0'))
	{
		cout << "fuck" << endl;//false
		flag = 0;
	}
	else
		cout << "you" << endl;//true float

	if (((int)atof(data.c_str())) == atof(data.c_str()) && flag)
		cout << "int" << endl;
	else
		cout << "not int";
}*/

/*
class Point//声明
{
public:
	Point(double xx, double yy) { x = xx; y = yy; }//默认构造函�?
	void Getxy();//公有成员函数
	friend double Distance(Point &a, Point &b);//友元函数
private:
	double x, y;
};

void Point::Getxy()
{
	cout << "(" << endl;
}

double Point::Distance(Point &a, Point &b)  //注意函数名前未加类声明符
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	Point p1(3.0, 4.0), p2(6.0, 8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1, p2);
	cout << "Distance is" << d << endl;
}*/

/*
int main()
{
	A a;
	map<string, int> test;
	test.insert(pair<string, int>("a", 1));

	test.insert(pair<string, int>("b", 3));
	map <string, int>::iterator iter;
	for (iter = test.begin(); iter != test.end(); iter++)
	{
		if (iter->first == "a")

			iter->second = 5;

	}
	iter = test.find("a");
	cout << iter->second << endl;
	pair<map<string, int>::iterator, bool> res;
	res = test.insert(pair<string, int>("a", 2));
	if (res.second)
		cout << "fuck" << endl;
	else
		cout << "you" << endl;

}*/
/*
int main()
{
	fstream fs("1.txt");
	string a, b;

	fs >> a;
	cout << a << endl;
	fs >> b;
	cout << b << endl;


	fs.close();
}
fs.getline(a, 256);
cout << a; //'\n'

fs >> a;
cout << a;//backspace
}*/

/*
int main()
{
	vector <int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);
	vector <int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it;
	cout << endl;


}*/

/*
int main()
{
	const char* ttt = "1.txt";
	ofstream stream;
	ifstream in;
	string s;

	char temp[1024];
	in.open("1.txt");
	in.seekg(4, ios::beg);
	in >> temp;
	cout << temp;
	system("pause");
}*/
/*
int main()
{
	int x, y;
	cout << "danwei" << endl;
	cin >> x;
	cin >> y;
	cout << x << ':' << y << endl;
	cout << sizeof(double) << endl;
	cout << SHRT_MAX;

}*/
/*
int main()
{
	int x = 20;
	string str = "zxcqwasd";
	char b[] = "zxcasd";
	cout << hex;
	cout << x << endl;
	cout.put('a');
	wcout << L"czvadf" << endl;
	cout << strlen(b) << endl;
	cout << sizeof(b) << endl;
	cout << str.size() << endl;

}*/
/*
int main()
{
	string str, str2;
	char charr[10];
	//getline(cin,str);
	//cout<<str<<endl;
	//cout<<str.size();
	//cin.get(charr,10).get();
	getline(cin, str);
	getline(cin, str2);
	cout << str << endl;
	cout << str2 << endl;
	cout << str + str2 << endl;


}*/
/*
class Baseclass
{
public:
	Baseclass(int i) :m_i(i)
	{
	}
	void f()
	{
		m_i += 8;
	}
	virtual void display()
	{
		cout << m_i << endl;
	}
private:
	int m_i;
};

class Derive :public Baseclass
{
public:
	Derive(int i, int j = 0) :m_i(i), Baseclass(j){}
	void f()
	{
		m_i += 6;
	}
	void display()
	{
		cout << m_i << endl;
	}
private:
	int m_i;

};
int main()
{
	Baseclass *p = new Derive(5);
	p->display();
	p->f();
	p->display();

	Derive *q = dynamic_cast<Derive *>(p);
	q->display();
	q->f();
	q->display();

}*/


