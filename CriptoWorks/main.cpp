#include <iostream>
#include "CriptoFunctions.h"
#include "Polypoint.h"

using namespace std;

int main(void) {

	/*Ejercicio 3 punto 2*/

	/*
	int key_a = 15; int key_b = 20;
	std::string affine_encoded = "DUSUTCSUTKYUCEDUPCKHUNCDUYKCHYKUQDUUPKTSCTKYUDUPCKHUNCDUSUTCSUTKYUGUIEE";
	std::string decoded = affine_cipher_decode(affine_encoded,key_a,key_b);

	std::cout << "Texto Cifrado: " << affine_encoded << std::endl;
	std::cout << "Descifrado: " << decoded << std::endl;
	*/
	

	/* Ejercicio 4 Criptoataque Sistema Vigenere */

	/*
	std::string encoded = "COADMXWQMMAEPI";
	std::string key = "MUSE";
	std::string decoded = vigenere_cipher_decode(encoded, key);

	std::cout << decoded << std::endl;
	*/

	/* m1*/
	
	/*
	int n = 23359211;
	int a = 3;
	int b = 2;
	int c_a = 2257692;
	int c_b = 11922174;

	int x = squareandmultiply(c_b, b, n);

	int inv = inverse_mod(1212177, n);

	int m1 = (squareandmultiply(c_a,a,n) * inverse_mod(squareandmultiply(c_b,b,n),n))%n;

	std::cout << "m1: " << m1 + n << std::endl;
	*/
	/*
	int start = 15;
	int end = 43155;
	int counter = 0;
	for (int i = start; i <= end; i++) {
		if (trialDivisionIsPrime(i)) {
			counter += 1;
		}
	}

	std::cout << "#prime numbers between 15 and 43155: " << counter << std::endl;
	*/

	//srand(time(NULL));
	//int start = 15;
	//int end = 43155;
	//int counter = 0;

	//int k = 3;

	//bool isPrime = true;
	//for (int i = start; i <= end; i++) {
	//	isPrime = true;
	//	
	//	for (int j = 0; j < k; j++) { //Aplicar rabin-miller k-veces
	//		isPrime = RabinMillerIsPrime(i);
	//		if (!isPrime) { //Si se obtiene compuesto, se tiene certeza que no es primo.
	//			break;
	//		}
	//	}

	//	if (isPrime) {
	//		counter += 1;
	//	}
	//}

	//std::cout << "#prime numbers between 15 and 43155: " << counter << std::endl;

	//return 0;


	/* Taller 3*/

	long long p = 104723;
	srand(time(NULL));

	/*
	EJERCICIO 3
	=============
	*/
	/*
	long long alpha = -1;
	while (true) {
		alpha = randint_longlong(2, p - 1);
		if ((squareandmultiply(alpha, (p - 1) / 2, p) != 1)) {
			std::cout << alpha << std::endl;
			break;
		}
	}*/

	/*
	Hallamos a aleatorio

	long long a = randint_longlong(1, p - 2);
	std::cout << a << std::endl;
	*/
	
	
	long long alpha = 29486;
	long long a = 13084;
	long long m = 3967; // 4 ultimos números de valentina
	long long n = 3246413;
	
	long long beta = squareandmultiply(alpha, a, p);

	long long x = HashFunction(m,n);

	long long k = 2021;

	long long gamma = squareandmultiply(alpha, k, p);
	long long delta_a = (x - a * gamma) % (p - 1);
	if (delta_a < 0) { delta_a = delta_a + (p-1); }

	long long delta = (delta_a * inverse_mod(k,p-1))%(p-1);
		

	std::cout << "(gamma,delta) = (" << gamma << "," <<  delta << ")" << std::endl;


	///*Verificar firma*/
	long long calc = (squareandmultiply(beta, gamma, p) * squareandmultiply(gamma, delta, p)) % p;

	long long alpha_x = squareandmultiply(alpha, x, p);

	std::cout << calc << " == " << alpha_x << std::endl;

	
	/* Polynomios */

	//int a[] = {-1,1}; // 1 + x
	//int deg_a = 1;

	//int b[] = {3,1, 2}; // 3 + x + 2x^2
	//int deg_b = 2;

	//Polynomial A(a, deg_a);
	//Polynomial B(b, deg_b);


	/*Point points[] = { {1,9},{2,1},{3,1},{4,5} };

	int size = 4;
	int modp = 11;
	Polynomial f = LagrangeInterpolation(points, size, modp);

	f.show();
	std::cout << "f(1): " << f(1, modp) << std::endl;
	std::cout << "f(2): " << f(2, modp) << std::endl;
	std::cout << "f(3): " << f(3, modp) << std::endl;
	std::cout << "f(4): " << f(4, modp) << std::endl;
	std::cout << "f(5): " << f(5, modp) << std::endl;*/

	/*Point points[] = { {3,43},{7,50},{9,44},{11,36},{15,56},{21,40},{26,21},{32,40} };

	int size = 8;
	int modp = 61;
	Polynomial f = LagrangeInterpolation(points, size, modp);

	f.show();
	std::cout << std::endl;
	std::cout << "f(3): " << f(3, modp) << std::endl;
	std::cout << "f(7): " << f(7, modp) << std::endl;
	std::cout << "f(9): " << f(9, modp) << std::endl;
	std::cout << "f(11): " << f(11, modp) << std::endl;
	std::cout << "f(15): " << f(15, modp) << std::endl;
	std::cout << "f(21): " << f(21, modp) << std::endl;
	std::cout << "f(26): " << f(26, modp) << std::endl;
	std::cout << "f(32): " << f(32, modp) << std::endl;*/

}