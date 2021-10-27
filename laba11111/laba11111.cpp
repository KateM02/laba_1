
#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include<conio.h>

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

void input_values(matrix& c,int& n ,int& m )
{
	do
	{
		std::cout << "Input N:";
		std::cin >> n;
	} while (n <= 0);
	do
	{
		std::cout << "Input M:";
		std::cin >> m;
	} while (m <= 0);
	std::cout << "Input values:\n";
	matrix a(n, m);
	std::cin >> a;
	c = a;
	std::cout << c;
}

int menu()
{
	while (true)
	{
		std::cout << "\n1.Input matrix" << std::endl << "2.Perform math operations" << std::endl << "3.Exit\n";
		int key = get_key();
		if (key >= '1' && key <= '3')
			return key;
	}
}
int menu_matematical_operation()
{
	while (true)
	{
		std::cout << "\n1.matrix addition\n" << "2.subtraction of matrices\n" << "3.matrix multiplication\n" << "4.multiplication by a number\n" << "5.division by number\n" << "6.comparison of matrices\n" << "7.index appeal\n" << "8.finding the trace of a matrix\n";
		int key = get_key();
		if (key >= '1' && key <= '8')
			return key;
	}
}

void matematical_operation(matrix a)
{
	try
	{
		int n=0, m=0;
		matrix b;
		input_values(b, n, m);
		std::cout << "\n1 matrix: "<< std::endl << a ;
		std::cout << "\n2 matrix: "<< std::endl << b ;
		int choose = menu_matematical_operation();
		switch (choose)
		{
		case '1':
		{
			std::cout << "Result:" << std::endl << a + b;
		}
		break;
		case '2':
		{
			std::cout << "Result:" << std::endl << a - b;
		}
		break;
		case '3':
		{
			std::cout << "Result:" << std::endl << a * b;
		}
		break;
		case '4':
		{
			double c;
			int l = 0;
			std::cout << "Do you want to work with 1 or 2 matrix?" << std::endl;
			std::cin >> l;
			std::cout << "Input the number:";
			std::cin >> c;
			if (l == 1)
			{
				std::cout << "Result:" << std::endl << a * c << std::endl;
			}
			if (l == 2)
			{
				std::cout << "Result:" << std::endl << b * c << std::endl;
			}
		}
		break;
		case '5':
		{
			double c;
			int l = 0;
			std::cout << "Do you want to work with 1 or 2 matrix?" << std::endl;
			std::cin >> l;
			std::cout << "Input the number:";
			std::cin >> c;
			if (l == 1)
			{
				std::cout << "Result:" << std::endl << a / c << std::endl;
			}
			if (l == 2)
			{
				std::cout << "Result:" << std::endl << b / c << std::endl;
			}
		}
		break;
		case '6':
		{
			if (a == b)
			{

				std::cout << "Matrices are equal" << std::endl;
			}
			if (a != b)
			{
				std::cout << "Matrices are not equal" << std::endl;
			}
		}
		break;
		case '7':
		{
			std::cout << "Do you want to work with 1 or 2 matrix?" << std::endl;
			int l = 0;
			std::cin >> l;
			std::cout << "Enter which element of the matrix you want to find\n";
			int x, y;
			if (l == 1)
			{
				std::cout << "Input x";
				std::cin >> x;
				std::cout << "Input y";
				std::cin >> y;
				std::cout << "Result:" << a(x, y) << std::endl;
			}
			if (l == 2)
			{
				std::cout << "Input x";
				std::cin >> x;
				std::cout << "Input y";
				std::cin >> y;
				std::cout << "Result:" << b(x, y) << std::endl;
			}

		}
		break;
		case '8':
		{
			std::cout << "Do you want to work with 1 or 2 matrix? " << std::endl;
			double c;
			int l = 0;
			std::cin >> l;
			if (l == 1)
			{
				c = a.finding_a_trace();
				std::cout << "Result:" << c << std::endl;
			}
			if (l == 2)
			{
				c = b.finding_a_trace();
				std::cout << "Result:" << c << std::endl;
			}
		}
		break;
		default:
			break;
		}
	}
	catch (std::exception err)
	{
		std::cerr << "error: " << err.what() << std::endl;
	}
}

int main()
{
	int n = 0, m = 0;
	matrix a;
	bool f = true;
	while (f)
	{
		int choose = menu();
		switch (choose)
		{
		case '1':
		{
			input_values(a, n, m);
		}
		break;
		case '2':
		{
			matematical_operation(a);
		}
		break;
		case '3':
		{
			f = false;
		}
		default:
			break;
		}
	}
	return 0;
}
