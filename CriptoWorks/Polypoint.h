#pragma once

#include <iostream>
//#include <cmath>
#include "CriptoFunctions.h"

class Point {
private:
	int x, y;
public:

	Point();
	Point(int a ,int b);

	int getX(void) { return x; }
	int getY(void) { return y; }

	void show(void) {
		std::cout << "(" << x << " , " << y << " )" << std::endl;
	}
};

class Polynomial {
private:
	int* coeffs;
	int degree;
public:
	Polynomial();

	Polynomial(int deg);

	Polynomial(int* cfs, int deg);
	
	Polynomial operator* (const Polynomial q);
	Polynomial operator+ (const Polynomial q);

	Polynomial modmul(const Polynomial q, int modp);

	static Polynomial Linearpoly(int x, int c) {
		int* arr = new int[2];
		arr[0] = c;
		arr[1] = x;
		return Polynomial(arr, 1);
	}

	int operator() (const int x, const int modp);

	void mul (const int c);
	void mod(const int mod);
	void show(void);
};




/// <summary>
/// Receives an array of points of size n and returns 
/// a n-1 degree polynomial that goes through every point.
/// Using lagrange interpolation
/// </summary>
/// <param name="points">The array of points</param>
/// <param name="size">The size of the array</param>
/// <returns>The polynomial</returns>
Polynomial LagrangeInterpolation(Point* points, int size,int modp);
