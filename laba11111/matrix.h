#pragma once
#include <iostream>

class matrix
{
private:
	int _n;
	int _m;
	double** _data;
public:
	matrix();
	matrix(const int m, const int n);
	matrix(const matrix& c);
	~matrix();
	int get_n() const;
	int get_m() const;
	

	double& operator () (const int m, const int n);
	const double& operator () (const int m, const int n) const;
	void operator = (const matrix& c);
	matrix operator + (const matrix& c);
	matrix operator - (const matrix& c);
	matrix operator * (const matrix& c);
	matrix operator * (const double a);
	matrix operator / (const double a);
	bool operator == (const matrix& c);
	bool operator != (const matrix& c);
	double finding_a_trace() const;

	friend std::ostream& operator<<(std::ostream& out, const matrix& a);
	friend std::istream& operator>>(std::istream& in, matrix& a);
};

