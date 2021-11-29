#include "Polypoint.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int a, int b)
{
	x = a; y = b;
}

Polynomial::Polynomial()
{
	degree = 0;
	coeffs = nullptr;
}

Polynomial::Polynomial(int deg)
{
	degree = deg;
	int* temp = new int[deg + 1];
	for (int i = 0; i <= deg; i++) {
		temp[i] = 1;
	}
	coeffs = temp;
}

Polynomial::Polynomial(int* cfs, int deg)
{
	degree = deg;
	coeffs = cfs;
}

Polynomial Polynomial::operator*(const Polynomial q)
{
	int new_deg = degree + q.degree;
	int* coeff_result = new int[new_deg  + 1];

	int sum;
	int a_j;
	int b_i_j;
	for (int i = 0; i <= new_deg; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			

			if (i - j > q.degree ) { b_i_j = 0; }
			else { b_i_j = q.coeffs[i - j]; }

			if (j > degree ) { a_j = 0; }
			else { a_j = coeffs[j]; }


			
			/*std::cout << "i: " << i << std::endl;
			std::cout << "i-j: " << i - j << std::endl;
			std::cout << "j: " << j << std::endl;

			std::cout << "a_j: "<< a_j << std::endl;
			std::cout << "b_i_j: " << b_i_j << std::endl;
			std::cout << "\n\n\n" << std::endl;*/

			sum += a_j * b_i_j;
		}
		/*std::cout << "d_i: " << sum << std::endl;*/
		coeff_result[i] = sum;
	}

	return Polynomial(coeff_result,new_deg);
}

Polynomial Polynomial::operator+(const Polynomial q)
{
	int max_deg;
	if (degree < q.degree) {
		max_deg = q.degree;
	}
	else {
		max_deg = degree;
	}

	int a_i, b_i;
	int* coeff_result = new int[max_deg + 1];
	for (int i = 0; i <= max_deg; i++) {
		if (i > degree) { a_i = 0; }
		else { a_i = coeffs[i]; }

		if (i > q.degree) { b_i = 0; }
		else { b_i = q.coeffs[i]; }

		coeff_result[i] = a_i + b_i;
	}

	return Polynomial(coeff_result, max_deg);
}

Polynomial Polynomial::modmul(const Polynomial q, int modp)
{
	Polynomial p = *this * q;
	p.mod(modp);
	return p;
}

int Polynomial::operator()(const int x, const int modp)
{
	int sum = 0;
	for (int i = 0; i <= degree; i++) {
		if (i == 0) {
			sum += coeffs[i];
		}
		else {
			sum += (squareandmultiply(x, i, modp) * coeffs[i]) % modp;
		}
	}

	sum %= modp;
	if (sum < 0) { sum += modp; }
	return sum;
}

void Polynomial::mul(const int c)
{
	for (int i = 0; i <= degree; i++) {
		coeffs[i] *= c;
	}
		
}

void Polynomial::mod(const int mod)
{
	for (int i = 0; i <= degree; i++) {
		coeffs[i] %= mod;
		if (coeffs[i] < 0) { coeffs[i] += mod; }
	}
}

void Polynomial::show(void)
{
	for (int i = 0; i <= degree; i++) {
		if (i == degree) {
			std::cout << coeffs[degree - i] << " + ";
		}
		else if (i == degree - 1) {
			std::cout << coeffs[degree - i] << "x" << " + ";
		}
		else {
			std::cout << coeffs[degree - i] << "x^" << degree - i << " + ";
		}
	}
}

Polynomial LagrangeInterpolation(Point* points, int size, int modp)
{
	int x_i, y_i;
	int cte;

	Polynomial temp;
	Polynomial* productos = new Polynomial[size];
	for (int i = 0; i < size; i++) {
		
		y_i = points[i].getY();
		x_i = points[i].getX();

		cte = y_i;
		for (int j = 0; j < size; j++) {
			if (j != i) {
				cte *= inverse_mod(x_i - points[j].getX(), modp);
				cte %= modp;
			}
		}

		cte %= modp;
		temp = Polynomial::Linearpoly(0, 1);
		for (int j = 0; j < size; j++) {
			if (j != i) {
				temp = temp * Polynomial::Linearpoly(1, -points[j].getX());
				temp.mod(modp);
			}
		}

		temp.mul(cte);
		productos[i] = temp;

	}

	Polynomial sum = Polynomial::Linearpoly(0,0);
	for (int i = 0; i < size; i++) {
		sum = sum + productos[i];
	}
	sum.mod(modp);
	return sum;
}