#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void printPrimes(int n)
{

	int size = 100;
	if (n > 0)
		size = n;

	//initialize array
	bool * primes = new bool[size];
	for (int i = 0; i < size; i++)
		primes[i] = 1;

	//0 and 1 are not primes
	primes[0] = primes[1] = 0;

	//cross out every x numbers
	int sroot = (int) sqrt((double) size);
	cout << "only crossing out up to multiples of " << sroot << endl << endl;
	for (int i = 0; i < size; i++)
	{
		if (primes[i] == 1)
		{
			for (int j = i + i; j < size; j += i)
				primes[j] = 0;
		}
	}

	//print
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (primes[i] == 1)
		{
			cout << i << "\t";
			count++;
			if (count % 10 == 0)
				cout << endl;
		}
	}

	cout << endl;
	delete[] primes;

}

int gcd(int a, int b)
{

	int mx = max(a, b);
	int mn = min(a, b);

	while (mx != mn)
	{

		cout << mx << " " << mn << endl;
		int diff = mx - mn;
		cout << "diff = " << diff << endl;
		mx = max(diff, mn);
		mn = min(diff, mn);
		cout << mx << " " << mn << endl << endl;

	}
	return mx;
}

void swap(unsigned int &a, unsigned int &b)
{
	int t = a;
	a = b;
	b = t;
}

void euclidsAlgorithm(unsigned int a, unsigned int b)
{
	/*
	 if (a == 0 || b == 0 || a == b)
	 return max(a, b);
	 */
	//make a>=b
	if (a < b)
		swap(a, b);

	//quotient, remainder

	if (b == 0)
	{
		cout << "division by zero";
		return;
	}

	vector<int> aList;
	vector<int> bList;
	vector<int> qList;
	vector<int> rList;

	int q = a / b;
	int r = a - q * b;

	aList.push_back(a);
	bList.push_back(b);
	qList.push_back(q);
	rList.push_back(r);

	while (r != 0)
	{
		a = b;
		b = r;
		q = a / b;
		r = a - q * b;
		aList.push_back(a);
		bList.push_back(b);
		qList.push_back(q);
		rList.push_back(r);
	}


	int size = aList.size();

	for(int i=0;i<size;i++)
		cout << aList[i] << " = " << bList[i] << " * (" << qList[i] << ") + " << rList[i] << endl;

	cout << endl << endl;



	/*
	 a  = b*(q)+ r
	 28 = 4*(6)+ 2
	 a<-b
	 b<-r
	 */

}

int main(int argc, char * argv[])
{
	euclidsAlgorithm(17*30,17*26);
}
