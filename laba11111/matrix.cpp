#include "matrix.h"
#include <iostream>

matrix::matrix()
{
	_m = 0;
	_n = 0;
	_data = NULL;
}
matrix::matrix(const int N, const int M)
{
	_m = M;
	_n = N;
	_data = new double* [_n];
	for (int i = 0; i < _n; i++)
	{
		_data[i] = new double[_m]();
	}
}
matrix::matrix(const matrix& c)
{
	_n = c._n;
	_m = c._m;
	_data = new double* [_n];
	for (int i = 0; i < _n; i++)
	{
		_data[i] = new double[_m];
	}
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			_data[i][j] = c._data[i][j];
		}
	}
}
matrix::~matrix()
{
	for (int i = 0; i < _n; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}
int matrix::get_n() const
{
	return _n;
}
int matrix::get_m() const
{
	return _m;
}

double& matrix :: operator() (const int n, const int m)
{
	if (m >= _m || n >= _n || m < 0 || n < 0)
	{
		throw std::logic_error("no such index exists");
	}
	return _data[n][m];
}
const double& matrix::operator()(const int n, const int m) const
{
	if (m >= _m || n >= _n || m < 0 || n < 0)
	{
		throw std::logic_error("no such index exists");
	}
	return _data[n][m];
}
void matrix:: operator = (const matrix& c)
{
	for (int i = 0; i < _n; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
	_n = c._n;
	_m = c._m;
	_data = new double* [_n];
	for (int i = 0; i < _n; i++)
	{
		_data[i] = new double[_m];
	}
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			_data[i][j] = c._data[i][j];
		}
	}
}
matrix matrix :: operator +  (const matrix& c)
{
	if (_m != c._m || _n != c._n)
	{
		throw std::logic_error("matrices of different sizes cannot be stacked");
	}

	matrix res(_n, _m);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			res._data[i][j] = _data[i][j] + c._data[i][j];
		}
	}
	return res;
}
matrix matrix :: operator -  (const matrix& c)
{
	if (c._m != _m || c._n != _n)
	{
		throw std::logic_error("matrices of different sizes cannot be subtracted");
	}

	matrix res(_n, _m);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			res._data[i][j] = _data[i][j] - c._data[i][j];
		}
	}
	return res;
}
matrix matrix :: operator * (const matrix& c)
{
	if (_m != c._n)
	{
		throw std::logic_error("the number of rows of the first matrix is not equal to the number of columns of the second");
	}

	matrix res(_n, c._m);

	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < c._m; j++)
		{
			res._data[i][j] = 0;
			for (int k = 0; k < _m; k++)
			{
				res._data[i][j] += _data[i][k] * c._data[k][j];
			}
		}
	}
	return res;
}
matrix matrix :: operator * (const double a)
{
	matrix res(_n, _m);
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			res._data[i][j] = _data[i][j] * a;
		}
	}
	return res;
}
matrix matrix :: operator / (const double a)
{
	if (a == 0)
	{
		throw std::logic_error("you cannot divide by zero");
	}
	matrix res(_n, _m);
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			res._data[i][j] = _data[i][j] / a;
		}
	}
	return res;
}

bool matrix :: operator == (const matrix& c)
{
	if (_n == c._n && _m == c._m)
	{
		for (int i = 0; i < _n; i++)
		{
			for (int j = 0; j < _m; j++)
			{
				if (_data[i][j] != c._data[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}

bool matrix :: operator != (const matrix& c)
{
	if (_n == c._n && _m == c._m)
	{
		for (int i = 0; i < _n; i++)
		{
			for (int j = 0; j < _m; j++)
			{
				if (_data[i][j] != c._data[i][j])
					return true;
			}
		}
		return false;
	}
	return true;
}

double matrix::finding_a_trace() const
{
	if (_n != _m)
	{
		throw std::logic_error("matrix is not square");
	}
	double a = 0;
	for (int i = 0; i < _m; i++)
	{
		a += _data[i][i];
	}
	return a;
}
std::ostream& operator<<(std::ostream& out, const matrix& a)
{
	for (int i = 0; i < a.get_n(); i++)
	{
		for (int j = 0; j < a.get_m(); j++)
		{
			out << a._data[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}
std::istream& operator>>(std::istream& in, matrix& a)
{
	for (int i = 0; i < a.get_n(); i++)
	{
		for (int j = 0; j < a.get_m(); j++)
		{
			std::cout << "[" << i << "][" << j << "] : ";
			in >> a._data[i][j];
		}
	}
	return in;
}
