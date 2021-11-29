#include "CriptoFunctions.h"


long long gcd(long long a, long long b, bool display)
{
	long long helper;
	
	if (a < b) {
		helper = b;
		b = a;
		a = helper;
		
	}

	long long r_prev_prev = a;
	long long r_prev = b;
	long long r;
	long long q;
	do {
		// r_n-2 = q * r_n-1 + r_n
		q = r_prev_prev / r_prev;
		r = r_prev_prev - r_prev * q;

		if(display)
			std::cout << r_prev_prev << " = " << q << "x" << r_prev << " + " << r << std::endl;

		r_prev_prev = r_prev;
		r_prev = r;
	} while (r != 0);

	return r_prev_prev;
}


void extended_euclides(long long a, long long b, long long& gcd_result, long long& s_result, long long& t_result)
{
	
	bool swapped = false;
	if (a < b) {
		long long helper;
		helper = b;
		b = a;
		a = helper;
		swapped = true;
	}

	long long r_prev_prev = a;
	long long r_prev = b;
	long long r,q;

	long long s_prev_prev = 1; long long t_prev_prev = 0;
	long long s_prev = 0; long long t_prev = 1;
	long long s,t;
	do {
		// r_n-2 = q * r_n-1 + r_n
		q = r_prev_prev / r_prev;
		r = r_prev_prev - r_prev * q;

		s = s_prev_prev - q * s_prev;
		t = t_prev_prev - q * t_prev;

		r_prev_prev = r_prev;
		r_prev = r;

		s_prev_prev = s_prev;
		s_prev = s;

		t_prev_prev = t_prev;
		t_prev = t;
	} while (r != 0);

	// s and t such that a*s + b*t = 1

	gcd_result = r_prev_prev;

	if (swapped) {
		t = s_prev_prev;
		s = t_prev_prev;
	}
	else {
		s = s_prev_prev;
		t = t_prev_prev;
	}

	if (gcd_result != 1) {
		s_result = t_result = -1;
	}
	else {
		s_result = s;
		t_result = t;
	}

}

void extended_euclides(int a,int b, int & gcd_result, int& s_result, int& t_result)
{

	bool swapped = false;
	if (a < b) {
		int helper;
		helper = b;
		b = a;
		a = helper;
		swapped = true;
	}

	int r_prev_prev = a;
	int r_prev = b;
	int r, q;

	int s_prev_prev = 1; int t_prev_prev = 0;
	int s_prev = 0; int t_prev = 1;
	int s, t;
	do {
		// r_n-2 = q * r_n-1 + r_n
		q = r_prev_prev / r_prev;
		r = r_prev_prev - r_prev * q;

		s = s_prev_prev - q * s_prev;
		t = t_prev_prev - q * t_prev;

		r_prev_prev = r_prev;
		r_prev = r;

		s_prev_prev = s_prev;
		s_prev = s;

		t_prev_prev = t_prev;
		t_prev = t;
	} while (r != 0);

	// s and t such that a*s + b*t = 1

	gcd_result = r_prev_prev;

	if (swapped) {
		t = s_prev_prev;
		s = t_prev_prev;
	}
	else {
		s = s_prev_prev;
		t = t_prev_prev;
	}

	if (gcd_result != 1) {
		s_result = t_result = -1;
	}
	else {
		s_result = s;
		t_result = t;
	}

}

long long inverse_mod(long long n, long long modulus)
{
	long long inverse,gcd_result,t;
	n %= modulus;
	if (n < 0) {
		n += modulus;
	}
	extended_euclides(n,modulus,gcd_result,inverse,t);
	if (inverse < 0) {
		return inverse + modulus;
	}
	return inverse;
}

int inverse_mod(int n, int modulus)
{
	int inverse, gcd_result, t;
	n %= modulus;
	if (n < 0) {
		n += modulus;
	}
	extended_euclides(n, modulus, gcd_result, inverse, t);
	if (inverse < 0) {
		return inverse + modulus;
	}
	return inverse;
}

std::string shift_cipher_encode(const std::string plaintext, const int key)
{
	std::string encoded = "";

	char let;
	for (unsigned int i = 0; i < plaintext.length(); i++) {
		
		let = plaintext[i];
		let -= 65;
		let += key;
		let %= 26;
		if (let < 0) {
			let += 26;
		}
		let += 65;
		encoded += let;
	}
	return encoded;
}

std::string shift_cipher_decode(const std::string ciphertext, const int key) {
	std::string decoded = "";

	char let;
	for (unsigned int i = 0; i < ciphertext.length(); i++) {
		let = ciphertext[i];
		let -= 65;
		let -= key;
		let %= 26;
		if (let < 0) {
			let += 26;
		}
		let += 65;
		decoded += let;
	}

	return decoded;
}

char inttoletter(int n)
{
	if (n < 0) {
		n += 26;
	}

	n += 65;
	char x = char(n);
	return x;
}

int lettertoint(char x)
{
	int n = x;
	n -= 65;
	return n;
}

std::string affine_cipher_encode(const std::string plaintext, const int key_a, const int key_b) {
	std::string encoded = "";

	char let;
	int eq;
	for (unsigned int i = 0; i < plaintext.length(); i++) {

		let = plaintext[i];
		eq = lettertoint(let);

		char let_mapped = inttoletter( (key_a* eq + key_b)%26 );
		encoded += let_mapped;
	}
	return encoded;
}

std::string affine_cipher_decode(const std::string ciphertext, const int key_a, const int key_b) {
	std::string decoded = "";

	char let;
	int eq;
	int inverse = inverse_mod(key_a,26);
	for (unsigned int i = 0; i < ciphertext.length(); i++) {

		let = ciphertext[i];
		eq = lettertoint(let);
		char let_mapped = inttoletter((inverse * (eq - key_b) ) % 26);
		
		decoded += let_mapped;
	}

	return decoded;
}

std::string vigenere_cipher_encode(const std::string plaintext, const std::string key)
{
	std::string keycript = "";
	
	for (unsigned int i = 0; i < plaintext.length() / key.length(); i++)
		keycript += key;

	keycript += key.substr(0, plaintext.length() % key.length());

	std::string encoded = "";
	char c;
	int shift;
	for (unsigned int i = 0; i < plaintext.length(); i++) {
		 c = plaintext[i];
		 shift = lettertoint(keycript[i]);

		 c -= 65;
		 c += shift;
		 c %= 26;
		 if (c < 0) {
			 c += 26;
		 }
		 c += 65;
		 encoded += c;
	}

	return encoded;
}

std::string vigenere_cipher_decode(const std::string ciphertext, const std::string key)
{
	std::string keycript = "";

	for (unsigned int i = 0; i < ciphertext.length() / key.length(); i++)
		keycript += key;

	keycript += key.substr(0, ciphertext.length() % key.length());

	std::string decoded = "";
	char c;
	int shift;
	for (unsigned int i = 0; i < ciphertext.length(); i++) {
		c = ciphertext[i];
		shift = lettertoint(keycript[i]);

		c -= 65;
		c -= shift;
		c %= 26;
		if (c < 0) {
			c += 26;
		}
		c += 65;
		decoded += c;
	}

	return decoded;
}

double char_frequency(const char c)
{
	switch (c) {
		case 'A':
			return 0.082;
		case 'B':
			return 0.015;
		case 'C':
			return 0.028;
		case 'D':
			return 0.043;
		case 'E':
			return .127;
		case 'F':
			return .022;
		case 'G':
			return .020;
		case 'H':
			return .061;
		case 'I':
			return .070;
		case 'J':
			return .002;
		case 'K':
			return .008;
		case 'L':
			return .040;
		case 'M':
			return .024;
		case 'N':
			return .067;
		case 'O':
			return .075;
		case 'P':
			return .019;
		case 'Q':
			return .001;
		case 'R':
			return .060;
		case 'S':
			return .063;
		case 'T':
			return .091;
		case 'U':
			return .028;
		case 'V':
			return .010;
		case 'W':
			return .023;
		case 'X':
			return .001;
		case 'Y':
			return .020;
		case 'Z':
			return .001;
		default:
			throw "Invalid Character received";

	}
}

double coincidence_index(std::string str)
{
	//Calculate Frequency Vector, Counts letters
	double freq_vector[26];
	for (int i = 0; i < 26; i++)
		freq_vector[i] = 0;

	
	char let;
	int let_index;
	for (unsigned int i = 0; i < str.length(); i++) {
		let = str[i];
		let_index = lettertoint(let);
		freq_vector[let_index] += 1.0;
	}

	//Now calculate coincidence index
	double coincidence = 0;
	for (int i = 0; i < 26; i++)
		coincidence += ((freq_vector[i]*(freq_vector[i]-1.0))/double((str.length())*(str.length()-1))); //650 is 25*26
	
	return coincidence;
}

char** SplitStringMatrix(std::string str, int j_split)
{
	int cols = int(ceil(double(str.length()) / double(j_split)));
	int rows = j_split;

	char** matrix = new char* [rows];
	for (int i = 0; i < rows; ++i)
		matrix[i] = new char[cols];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = '-';
		}
	}
	
	for (unsigned int i = 0; i < str.length(); i++) {
		char c = str[i];
		matrix[i % j_split][i / j_split] = c;
	}
	

	return matrix;
}



void vigenere_cipher_j_find(const std::string ciphertext, int max_j)
{
	//Find J
	char** matrix;
	char* row;
	int cols;

	/*
	int j = 1;
	
	matrix = SplitStringMatrix(ciphertext, j);
	cols = ceil(double(ciphertext.length()) / double(j));
	row = matrix[0];
	std::cout << coincidence_index(row, cols) << " ";
	
	*/
	double ci;
	double average_ci;
	std::string rowstring;
	for (int j = 1; j <= max_j; j++) {
		matrix = SplitStringMatrix(ciphertext,j);
		cols = int(ceil(double(ciphertext.length()) / double(j)));
		std::cout << "J: " << j << "   ----> ";
		average_ci = 0;
		for (int i = 0; i < j; i++) {
			row = matrix[i];
			rowstring = charvector_tostr(row, cols);
			rowstring = remove_special_guion(rowstring);
			ci = coincidence_index(rowstring);
			average_ci += ci;
			std::cout << ci << " ";
		}
		average_ci /= j;
		//std::cout << "\nAverage: " << average_ci << " distance from ENGLISH CONSTANT: " << abs(ENGLISH_COINCIDENCE-average_ci);
		
		std::cout << "\n\n";

		for (int i = 0; i < j; ++i)
			delete[] matrix[i];

		delete matrix;
	}
	
	
}

double row_englishdistance(std::string str)
{
	double freq_vector[26];
	for (int i = 0; i < 26; i++)
		freq_vector[i] = 0;

	//count letters
	char let;
	int let_index;
	for (unsigned int i = 0; i < str.length(); i++) {
		let = str[i];
		let_index = lettertoint(let);
		freq_vector[let_index] += 1.0;
	}

	for (int i = 0; i < 26; i++)
		freq_vector[i] = freq_vector[i]/ str.length();


	double distance = 0;
	//find distance
	for (int i = 0; i < 26; i++)
		distance += pow(freq_vector[i] - char_frequency(inttoletter(i)), 2);
	
	return distance;
}

std::string remove_special_guion(std::string str) {
	//std::string help = vector;
	std::string newstring="";
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] != '-') {
			newstring += str[i];
		}
	}
	return newstring;
}

std::string charvector_tostr(char* vector, int length)
{
	std::string newstring = "";
	for (int i = 0; i < length; i++)
		newstring += vector[i];

	return newstring;
}

std::string vigenere_cipher_attack(const std::string ciphertext, int supposed_j)
{
	std::string key = "";

	char** matrix = SplitStringMatrix(ciphertext, supposed_j);
	int cols = int(ceil(double(ciphertext.length()) / double(supposed_j)));

	double min;
	int min_shift;
	double distance;
	std::string rowstring;

	for (int r = 0; r < supposed_j; r++){
		char* row = matrix[r];
		min = 100;
		for (int i = 0; i < 26; i++) {
			rowstring = charvector_tostr(row,cols);
			rowstring = remove_special_guion(rowstring);
			rowstring = shift_cipher_decode(rowstring, i);
			distance = row_englishdistance(rowstring);
			if (distance < min) {
				min = distance;
				min_shift = i;
			}
			//std::cout << "I: " << i << " ->" << distance << "\n";
		}
		std::cout << "Closest to english: " << inttoletter(min_shift) << std::endl;
		key += inttoletter(min_shift);
	}
	for (int i = 0; i < supposed_j; ++i)
		delete[] matrix[i];

	delete matrix;

	return key;
}

double wholeCubicRoot(int t0, int c, int N)
{
	double t_i = t0;
	for (int i = 0; i < N; i++)
		t_i = (2.0 / 3.0) * t_i + (1.0 / 3.0) * (c / pow(t_i, 2));

	return t_i;
}

long long squareandmultiply(long long base, long long power, long long mod)
{
	int size_bits;
	bool* y_k = decimaltobinary(power, size_bits);

	long long w = 1;
	for (int i = size_bits - 1; i > -1; i--) {
		w = w * w;
		w %= mod;
		
		if (y_k[i]) {
			w = w * base;
			w %= mod;
		}
	}

	if (w < 0) {
		return w + mod;
	}

	return w;
}


bool* decimaltobinary(long long n, int &size) {
	size=0;
	long long n_copy =n;
	while (true) {
		size += 1;
		n_copy = n_copy / 2;
		
		if (n_copy == 0) {
			break;
		}
	}
	
	bool* binaryrep = new bool[size];

	
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array 
		binaryrep[i] = n % 2;
		n = n / 2;
		i++;
	}
	
	return binaryrep;
}

bool trialDivisionIsPrime(int n)
{
	if (n == 1) {
		return true;
	}
	int i = 2;
	while (i != n) {
		if (n % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

bool RabinMillerIsPrime(int m, int b)
{
	int t = m - 1;
	int s = 0;
	while (true) {
		if (t % 2 == 1) {
			break;
		}
		s++;
		t /= 2;
	}

	if (b == -1) {
		while (true) {
			b = randint(2, m); //No incluir 1
			if (gcd(b, m) == 1) {
				break;
			}
		}
	}
	
	int y = squareandmultiply(b, t, m);
	if (y == 1) {
		return true;
	}
	

	for (int i = 0; i < s; i++) {
		if (y == m - 1) {
			return true;
		}
		else {
			y = y * y;
			y %= m;
		}
	}

	return false;
}

int randint(int start, int end)
{
	return (rand() % (end - start)) + start;
}

long long randint_longlong(long long start, long long end)
{
	return (rand() % (end - start)) + start;
}

long long HashFunction(long long m, long long n)
{
	return squareandmultiply(10, m, n);
}

