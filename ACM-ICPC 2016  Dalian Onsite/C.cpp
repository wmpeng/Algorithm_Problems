#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
string str("236067977499789696409173668731276235440618359611525724270897245410520925637804899414414408378782274969508176150773783504253267724447073863586360121533452708866778173191879165811276645322639856580535761350417533785003423392414064442086432539097252592627228876299517");
string ans;
int aaa[300];

int aa[500], bb[500],mult[500];
int alen, blen, mlen;
void Mult()
{
	int i, j;
	memset(mult, 0, sizeof(mult));
	for (i = 0; i < alen; i++)
		for (j = 0; j < 250; j++)
		{
			mult[i + j] += aa[i] * aaa[j];
			mult[i + j + 1] += mult[i + j] / 10;
			mult[i + j] %= 10;
		}
	for (i = 490; i >= 100; i--)
		if (mult[i] != 0)
			break;
	mlen = i + 1;

	mult[250]++;
	for (i = 250; i <= 490; i++)
	{
		mult[i + 1] += mult[i] / 10;
		mult[i] %= 10;
	}
}

void assert()
{
	int i, j;
	for (i = 101; i >= 0; i--)
	{
		if (aa[i] < bb[i])
			return;
		if (aa[i] > bb[i])
			break;
	}
	for (i = 101; i >= 0; i--)
		aa[i] ^= bb[i] ^= aa[i] ^= bb[i];
}
void output()
{
	int i, j;
	for (i = 0, j = 250; j <= mlen - 1 || i <= blen - 1; i++, j++)
	{
		//cout << "(" << mult[j] << "," << bb[i] << ")";
		if (mult[j] != bb[i])
		{
			cout << "1" << endl;
			return;
		}
	}
	cout << "0" << endl;
	return;
}

int main()
{
	int i, j, ii, jj, t = 0;
	for (i = 0; i < 250; i++)
	{
		ans += (str[i] - '0' + t * 10) / 2 + '0';
		t = (str[i] - '0' + t * 10) % 2;
	}
	ans[0] = '6' + 10;
	for (i = 0; i < 250; i++)
		aaa[250 - i-1] = ans[i] - '0';
	/*for (i = 0; i < 250; i++)
		cout << aaa[i];
	cout << endl;*/
	string a, b;
	while(cin>>a>>b)
	{
		alen = a.length();
		blen = b.length();
		memset(aa, 0, sizeof(aa));
		memset(bb, 0, sizeof(bb));

		for (i = 0; i < alen; i++)
			aa[alen - i-1] = a[i] - '0';
		for (i = 0; i < blen; i++)
			bb[blen - i-1] = b[i] - '0';
		assert();//±£Ö¤a<b
		/*for (i = 0; i <= 10; i++)
			cout << aa[i];
		cout << endl;
		for (i = 0; i <= 10; i++)
			cout << bb[i];
		cout << endl;*/

		Mult();

		/*for (i = mlen - 1; i >= 250; i--)
			cout << mult[i];
		cout << endl;*/

		output();

	}

}