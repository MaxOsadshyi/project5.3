#include <iostream>
#include <cmath>
using namespace std;
double f(const double x);
int main()
{
	double yp, yk, z;
	int n;
	cout << "yp = "; cin >> yp;
	cout << "yk = "; cin >> yk;
	cout << "n = "; cin >> n;
	double dy = (yk - yp) / n;
	double y = yp;
	while (y <= yk)
	{
		z = f(1+y*y)+f(f(1)+f(y*y)*f(y*y))* f(f(1) + f(y * y) * f(y * y));
		cout << y << " " << z << endl;
		y += dy;
	}
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return cos(x/2)/(1+sin(x)*sin(x));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = pow(x,3*i)/tgamma(2*i);
			a *= R;
			S += a;
		} while (i<6);
		return S;
	}
}