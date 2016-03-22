#include <iostream>
using namespace std;

double** CreateMatrix(int);
void IsDataValidSize(int&);
void IsDataValidEpsilon(double&);
void DisplayMatrix(double**, int);
void FillingLibraryMatrix(double**, int);
void FillingMyMatrix(double **, int, double);
double MySin(double, double);
void FillingDeferenceMatrix(double**, double**, double**, int);
double MaxElementInMatrix(double**, int);

int main(){
	int n = 0;
	double eps = 0;
	IsDataValidSize(n);
	system("cls");
	IsDataValidEpsilon(eps);
	system("cls");
	double** a = CreateMatrix(n);
	cout << "Library Matrix:" << endl << endl;
	FillingLibraryMatrix(a, n);
	DisplayMatrix(a, n);
	cout << "-----------------------------------------------------------" << endl;
	double** b = CreateMatrix(n);
	cout << "My Matrix:" << endl << endl;
	FillingMyMatrix(b, n, eps);
	DisplayMatrix(b, n);
	cout << "-----------------------------------------------------------" << endl;
	double** c = CreateMatrix(n);
	cout << "Difference Matrix" << endl << endl;
	FillingDeferenceMatrix(a, b, c, n);
	DisplayMatrix(c, n);
	cout << "\t\t\t\t\t\t\t" << "Max Element: " << MaxElementInMatrix(c, n) << endl;
	cout << "-----------------------------------------------------------" << endl;
	system("pause");
	return 0;
}

void IsDataValidSize(int &n)
{
	while (true)
	{
		system("cls");
		cout << "Enter Size of square matrix(Size > 0):";
		cin >> n;
		if (n > 0) break;
	}
}

void IsDataValidEpsilon(double &eps)
{
	while (true)
	{
		system("cls");
		cout << "Enter precision of calculations(1 > Epsilon > 0): ";
		cin >> eps;
		if (eps > 0 && eps < 1) break;
	}
}

double** CreateMatrix(int n)
{
	double **a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	return a;
}

void DisplayMatrix(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
			if (j < n - 1)
				cout.width(12);
		}
		cout << endl;
	}
}

double MySin(double x, double eps)
{
	double n = x;
	double sum = 0.0;
	int i = 1;

	while (fabs(n) > eps)
	{
		sum += n;
		n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
		i++;
	}
	return sum;
}

void FillingLibraryMatrix(double **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 2 * j)
				a[i][j] = sin(2 * i*j) + sin(i) / (pow((i - j - 4), 3) + pow((i + j), 2));
			else
			{
				a[i][j] = i;
			}
		}
	}
}

void FillingMyMatrix(double **b, int n, double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 2 * j)
				b[i][j] = MySin((2 * i*j), eps) + MySin(i, eps) / (pow((i - j - 4), 3) + pow((i + j), 2));
			else
			{
				b[i][j] = i;
			}
		}
	}
}

void FillingDeferenceMatrix(double**a, double** b, double** c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = fabs(a[i][j] - b[i][j]);
		}
	}
}

double MaxElementInMatrix(double** c, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (c[i][j] > max)
				max = c[i][j];
		}
	}
	return max;
}