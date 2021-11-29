#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

/// <summary>
/// Performs Euclides Algorithm to find the gcd between two integers
/// </summary>
/// <param name="a">Integer 1</param>
/// <param name="b">Integer 2</param>
/// <param name="display">If display to console nicely the gcd </param>
///<returns>The gcd between a and b< / returns>
long long gcd(long long a, long long b, bool display = false);


/// <summary>
/// Performs Extended Euclides Algorithm, receives a and b, returns gcd(a,b) 
/// and if gcd(a,b) = 1, returns s and t such that a*s + b*t = 1
/// Otherwise, returns -1 on both s and t.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="gcd_result"></param>
/// <param name="s_result"></param>
/// <param name="t_result"></param>
void extended_euclides(long long a, long long b, long long& gcd_result, long long& s_result, long long& t_result);
void extended_euclides(int a, int b, int& gcd_result, int& s_result, int& t_result);

/// <summary>
/// Calculates the multiplicative inverse of a given integer in the given modulo
/// </summary>
/// <param name="n">The integer inverse to be calculated</param>
/// <param name="modulus">The modulo to calculate the inverse</param>
/// <returns>Multiplicative inverse of n</returns>
long long inverse_mod(long long n, long long modulus);
int inverse_mod(int n, int modulus);

/// <summary>
/// Encodes text using shift-cipher codification
/// NOTE: Only works with UPPERCASE SENTENCES and using 26letters english alphabet, no spaces, no accentuations etc
/// </summary>
/// <param name="plaintext"> The text to be encoded </param>
/// <param name="key">The key to encode the text with</param>
/// <returns>The encoded string</returns>
std::string shift_cipher_encode(const std::string plaintext, const int key);

/// <summary>
/// Decodes text using shift-cipher codification
/// NOTE: Only works with UPPERCASE SENTENCES and using 26letters english alphabet, no spaces, no accentuations etc
/// </summary>
/// <param name="ciphertext">The string to be decoded</param>
/// <param name="key">The key to decode the text with</param>
/// <returns>The decoded String</returns>
std::string shift_cipher_decode(const std::string ciphertext, const int key);


/// <summary>
/// Maps the integers from 0-26 to the letters A-Z
/// NOTE: Only works with uppercase and integers between 0 and 26
/// </summary>
/// <param name="n">The integer to be mapped</param>
/// <returns>The equivalent Letter</returns>
char inttoletter(int n);

/// <summary>
/// Maps the chars from A-Z to the integers 0-26
/// NOTE: Only works with uppercase chars 
/// </summary>
/// <param name="x">The char to be mapped</param>
/// <returns>The equivalent int</returns>
int lettertoint(char x);


/// <summary>
/// Encodes text using affine-cipher codification
/// NOTE: Only works with UPPERCASE SENTENCES and using 26letters english alphabet, no spaces, no accentuations etc
/// </summary>
/// <param name="plaintext">The string to be encoded</param>
/// <param name="key_a">The key a to encode the text with</param>
/// <param name = "key_b">The key b to encode the text with </param>
/// <returns>The encoded String</returns>
std::string affine_cipher_encode(const std::string plaintext, const int key_a, const int key_b);


/// <summary>
/// Decodes text using affine-cipher codification
/// NOTE: Only works with UPPERCASE SENTENCES and using 26letters english alphabet, no spaces, no accentuations etc
/// </summary>
/// <param name="ciphertext">The string to be decoded</param>
/// <param name="key_a">The key a to decode the text with</param>
/// <param name = "key_b">The key b to decode the text with </param>
/// <returns>The decoded String</returns>
std::string affine_cipher_decode(const std::string ciphertext, const int key_a, const int key_b);


/// <summary>
/// Encodes text using vigenere-cipher codification
/// NOTE: Only works with UPPERCASE SENTENCES and using 26letters english alphabet, no spaces, no accentuations etc
/// </summary>
/// <param name="plaintext">The string to be encoded</param>
/// <param name="key">The key a to encode the text with</param>
/// <returns>The encoded String</returns>
std::string vigenere_cipher_encode(const std::string plaintext, const std::string key);

/// <summary>
/// Decodes text using vigenere-cipher codification
/// NOTE: Only works with UPPERCASE SENTENCES and using 26letters english alphabet, no spaces, no accentuations etc
/// </summary>
/// <param name="ciphertext">The string to be decoded</param>
/// <param name="key">The key a to decode the text with</param>
/// <returns>The decoded String</returns>
std::string vigenere_cipher_decode(const std::string ciphertext, const std::string key);



/// <summary>
/// Receives an english alphabet character and returns it's relative frequency in english language (0-1)
/// </summary>
/// <param name="c">The character</param>
/// <returns>The frequency of the given character</returns>
double char_frequency(const char c);


const double ENGLISH_COINCIDENCE = 0.065;

/// <summary>
/// Receives a vector of characters in the english alphabet (26 characters) and returns it's coincidence index
/// those vectors similar to an english text their coincidence index should be about 0.065
/// </summary>
/// <param name="vector">The given vector</param>
/// <param name="length">The length of the vector</param>
/// <returns>The coincidence index of the given vector </returns>
double coincidence_index(std::string str);

/// <summary>
/// Splits string into matrix of j rows
/// </summary>
/// <param name="str">the string to split</param>
/// <param name="j_split">The number of rows to split the string</param>
/// <returns>Pointer to generated char matrix</returns>
char** SplitStringMatrix(std::string str, int j_split);

/// <summary>
/// Displays coincidence index by each row supposing J as a period, checks up to max_j value
/// </summary>
/// <param name="ciphertext">The text to be splitted</param>
/// <param name="max_j">The maximum j to consider</param>
void vigenere_cipher_j_find(const std::string ciphertext, int max_j);

/// <summary>
/// Removes '-' (script - character) from string, returns new one without it
/// </summary>
/// <param name="str">the string to remove the script from</param>
/// <returns>the string without scripts</returns>
std::string remove_special_guion(std::string str);

/// <summary>
/// Receives a char vector and returns equivalent string as an std::string object
/// </summary>
/// <param name="vector">the vector to fetch the string from</param>
/// <param name="length">the length of the given vector</param>
/// <returns>the equivalent string</returns>
std::string charvector_tostr(char* vector, int length);

/// <summary>
/// Returns the distance of the row to the natural frequencies of the english language
/// </summary>
/// <param name="str"> the string to be considered</param>
/// <returns>The distance of the given row</returns>
double row_englishdistance(std::string str);

/// <summary>
/// Attemps to attack a vigenere cipher, given the encrypted text, and a supposed period j,
/// and (possibly) returns the encryption key
/// </summary>
/// <param name="ciphertext">The ciphered text </param>
/// <param name="supposed_j">The supposed period (length of key)</param>
/// <returns>The encryption key</returns>
std::string vigenere_cipher_attack(const std::string ciphertext, int supposed_j);


/// <summary>
/// Supposes t0 as cubic root of c, uses sequences that converges to cubic root of given c,
/// returns an approximation of the cubic root, NOTE: usable for whole numbers
/// </summary>
/// <param name="t0">The supposition of the cubic root</param>
/// <param name="c">The number whose cubic root to be found</param>
/// <param name="N">The number of iterations</param>
/// <returns>An approximation of the cubic root of the whole number</returns>
double wholeCubicRoot(int t0, int c, int N);


/// <summary>
/// Square and multiply algorithm, calculates (base^power) mod (mod)
/// in polynomial time
/// </summary>
/// <param name="base">base of number</param>
/// <param name="power">power to be calculated</param>
/// <param name="mod">the modulus to be used in calculations</param>
/// <returns>The result of base^power mod (mod)</returns>
long long squareandmultiply(long long base, long long power, long long mod);


/// <summary>
/// Returns an array of bool, the binary representation of n
/// </summary>
/// <param name="n"> An integer in its decimal representation</param>
/// <param name="size">A reference int, which stores the size (bits) of the binary array</param>
/// <returns>A binary array that represents n in binary</returns>
bool* decimaltobinary(long long n, int& size);


/// <summary>
/// Checks if the given number is prime, using trial division.
/// checks linearly if each number lower than n divides it.
/// Deterministic algorithm.
/// </summary>
/// <param name="n">The number to determine the primality</param>
/// <returns>The primality of n</returns>
bool trialDivisionIsPrime(int n);

/// <summary>
/// Receives m whole odd number and determines (probably) is primality
/// </summary>
/// <param name="m"> The number to determine the primality</param>
/// <param name="b"> The b value to use during the algorithm</param>
/// <returns>The primality of m (probably)</returns>
bool RabinMillerIsPrime(int m, int b = -1);

/// <summary>
/// Generates a random integer number between start and end, including endpoints
/// </summary>
/// <param name="start">Start of interval</param>
/// <param name="end">End of interval</param>
/// <returns>A number between start and end</returns>
int randint(int start, int end);


/// <summary>
/// Generates a random LONG LONG number between start and end, including endpoints
/// </summary>
/// <param name="start">Start of interval</param>
/// <param name="end">End of interval</param>
/// <returns>A number between start and end</returns>
long long randint_longlong(long long start, long long end);

/// <summary>
/// Trivial 10^m mod n, hash function
/// </summary>
/// <param name="m">m</param>
/// <param name="n">n</param>
/// <returns></returns>
long long HashFunction(long long m, long long n);


