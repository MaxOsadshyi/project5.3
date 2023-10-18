#include <iostream>
#include <cmath>
using namespace std;
double f(const double x);
int main()
{
	double tp, tk, z;
	int n;
	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> n;
	double dt = (tk - tp) / n;
	double t = tp;
	while (t <= tk)
	{
		z = f(1+2*t)+f(f(1)+2*f(2*t))* f(f(1) + 2 * f(2 * t));
		cout << t << " " << z << endl;
		t += dt;
	}
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return (sin(x)*sin(x)+sin(x*x))/(1+cos(x)*cos(x));
	else
	{
		double S = 0;
		int n = 0;
		double a = 1;
		S = a;
		int c = (1 / (1 + x * x));
		do
		{
			n++;
			double R = pow(x,4*n+1)/tgamma(4*n+1);
			a *= R;
			S += a;
		} while (n<6);
		return S*c;
	}
}