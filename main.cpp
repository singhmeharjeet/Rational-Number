	//
	//  main.cpp
	//  Rational Number Full Class
	//
	//  Created by Meharjeet Singh on 27/05/21.
	//

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

/*////////////////////////////////////////////////////////////////////////////////////////*/

class RationalNumber {
private:
	int a, b;
	static int count;
public:
		// Constructors-------------------------------
	RationalNumber ();
	RationalNumber (const int &, const int &);
	RationalNumber (const double &);

		// Setters--------------------------------------
	void setNumerator (const int &);
	void setDenominator (const int &);

		// Getters--------------------------------------
	int getNumerator () const;
	int getDenominator () const;

		// Other Member Functions-----------------------
	void standardize ();
	void reduce ();
	double toDecimal () const;

		// Static Member Functions----------------------
	static int getCount ();

		// Friend Functions Apart from Operators--------
	friend ostream & operator<<(ostream &, RationalNumber &);
	friend istream & operator>>(istream &, RationalNumber &);
	friend RationalNumber getRandomRationalNumber();

		// Operator Functions
		// Binary Operators
		// Addition------------------------------------------
	RationalNumber operator+(const RationalNumber &) const;
	RationalNumber operator+(const int &) const;
	RationalNumber operator+(const double &) const;
	RationalNumber operator+(const float &) const;
	friend RationalNumber operator+(const int &, const RationalNumber &);
	friend RationalNumber operator+(const double &, const RationalNumber &);
	friend RationalNumber operator+(const float &, const RationalNumber &);
		// Subtract------------------------------------------
	RationalNumber operator-(const RationalNumber &) const;
	RationalNumber operator-(const int &) const;
	RationalNumber operator-(const double &) const;
	RationalNumber operator-(const float &) const;
	friend RationalNumber operator-(const int &, const RationalNumber &);
	friend RationalNumber operator-(const double &, const RationalNumber &);
	friend RationalNumber operator-(const float &, const RationalNumber &);
		// Multiply------------------------------------------
	RationalNumber operator*(const RationalNumber &) const;
	RationalNumber operator*(const int &) const;
	RationalNumber operator*(const double &) const;
	RationalNumber operator*(const float &) const;
	friend RationalNumber operator*(const int &, const RationalNumber &);
	friend RationalNumber operator*(const double &, const RationalNumber &);
	friend RationalNumber operator*(const float &, const RationalNumber &);
		// Divide------------------------------------------
	RationalNumber operator/(const RationalNumber &) const;
	RationalNumber operator/(const int &) const;
	RationalNumber operator/(const double &) const;
	RationalNumber operator/(const float &) const;
	friend RationalNumber operator/(const int &,  const RationalNumber &);
	friend RationalNumber operator/(const double &, const RationalNumber &);
	friend RationalNumber operator/(const float &, const RationalNumber &);
		// Post Increment and Decrement----------------------
	RationalNumber operator++(const int DUMMY);
	RationalNumber operator--(const int DUMMY);

		// Unary Operators
		// Negation-------------------------------------------
	RationalNumber operator-();

		// Pre Increment and Decrement------------------------
	RationalNumber operator++();
	RationalNumber operator--();

		// Comparitive Operators----------------------------------------
			// Equals
	bool operator==(const RationalNumber&) const;
	bool operator==(const int&) const;
	bool operator==(const double&) const;
	bool operator==(const float&) const;
	friend bool operator==(const int&, const RationalNumber&);
	friend bool operator==(const double&, const RationalNumber&);
	friend bool operator==(const float&, const RationalNumber&);
			// Not Equals
	bool operator!=(const RationalNumber&) const;
	bool operator!=(const int&) const;
	bool operator!=(const double&) const;
	bool operator!=(const float&) const;
	friend bool operator!=(const int&, const RationalNumber&);
	friend bool operator!=(const double&, const RationalNumber&);
	friend bool operator!=(const float&, const RationalNumber&);
			// Less than equals
	bool operator<=(const RationalNumber&) const;
	bool operator<=(const int&) const;
	bool operator<=(const double&) const;
	bool operator<=(const float&) const;
	friend bool operator<=(const int&, const RationalNumber&);
	friend bool operator<=(const double&, const RationalNumber&);
	friend bool operator<=(const float&, const RationalNumber&);
			// Greater than equals
	bool operator>=(const RationalNumber&) const;
	bool operator>=(const int&) const;
	bool operator>=(const double&) const;
	bool operator>=(const float&) const;
	friend bool operator>=(const int&, const RationalNumber&);
	friend bool operator>=(const double&, const RationalNumber&);
	friend bool operator>=(const float&, const RationalNumber&);
			// Less than
	bool operator<(const RationalNumber&) const;
	bool operator<(const int&) const;
	bool operator<(const double&) const;
	bool operator<(const float&) const;
	friend bool operator<(const int&, const RationalNumber&);
	friend bool operator<(const double&, const RationalNumber&);
	friend bool operator<(const float&, const RationalNumber&);
			// Greater than
	bool operator>(const RationalNumber&) const;
	bool operator>(const int&) const;
	bool operator>(const double&) const;
	bool operator>(const float&) const;
	friend bool operator>(const int&, const RationalNumber&);
	friend bool operator>(const double&, const RationalNumber&);
	friend bool operator>(const float&, const RationalNumber&);
};
	//-------------------------------------------------
int RationalNumber::count = 0;

	// Constructors-------------------------------
RationalNumber::RationalNumber () : a(0), b(1){
	count++;
}
RationalNumber::RationalNumber (const int &a, const int &b){
	this->a = a;
	this->b = b;
	standardize(); 	// Changes the values of the object to change it to standard form
	reduce(); 		// Changes the Rational Number to irreducible fraction
	count++;
}
RationalNumber::RationalNumber (const double &x){
	double temp = abs(x);

	int numerator = temp;
	int denominator = 1;
	double fraction = temp - numerator;

	while (fraction > 0) {
		temp *= 10; // Moves the decimal to the right
		numerator = temp; // Updates the Rational Number
		denominator *= 10;
		fraction = temp - numerator; // Updates the fraction
	}
	if (x < 0)
		numerator = -numerator;

	this->a = numerator; // Assigns the Calculatded values
	this->b = denominator;

	standardize(); // Changes the values of the object to change it to standard form
	reduce(); // Changes the Rational Number to irreducible fraction
	count++; // Update Count objects
}

	// Setters--------------------------------------
void RationalNumber::setNumerator (const int &a){
	this->a = a;
}
void RationalNumber::setDenominator (const int &b){
	if (b != 0) {
		this->b = b;
	}
	else
		this->b = 1;
}

	// Getters--------------------------------------
int RationalNumber::getNumerator () const {
	return a;
}
int RationalNumber::getDenominator () const {
	return b;
}

	// Other Member Functions-----------------------
void RationalNumber::standardize (){
	if (b < 0){
		a = -a;
		b = -b;
	}
	return;
}
void RationalNumber::reduce (){
	if (a == 0) {
		b = 1;
		return;
	}
	else {
			//Remeber that the denominator is NEVER zero by design
			//Therefore here both numerator and denominator are non-zero.
		int m = abs(a);
		int n = abs(b);
		int gcd = m < n ? m : n;
		while (gcd > 0) {
			if (m % gcd == 0 && n % gcd == 0)
				break;
			gcd--;
		}
		a /= gcd;
		b /= gcd;
	}
}
double RationalNumber::toDecimal () const {
	double result = static_cast<double>(a)/b;
	return result;
}

	// Static Member Functions----------------------
int RationalNumber::getCount (){
	return count;
}

	// Friend Functions Apart from Operators--------
ostream& operator<<(ostream &aliasCout, RationalNumber &r) {
	r.standardize();
	r.reduce();
	aliasCout << "(" << r.a << "/" << r.b << ")";
	return aliasCout;
}
istream& operator>>(istream& aliasCin, RationalNumber& r) {
	cout << endl << "Numerator : ";
	int temp;
	aliasCin >> temp;
	r.a = temp;
	cout << "Denominator : " ;
	aliasCin >> temp;
	r.b = temp;

	return aliasCin;
}
RationalNumber getRandomRationalNumber() {
	return RationalNumber (rand()% 501 - 250,rand() % 500 - 250);
}

	// Operator Functions
	// Binary Operators
	// Addition------------------------------------------
RationalNumber RationalNumber::operator+(const RationalNumber &r) const {
	RationalNumber A;
	int a1 = this->a;
	int b1 = this->b;

	int a2 = r.a;
	int b2 = r.b;
// a1/b1 + a2/b2    = > a1*b2 + a2*b1 / b1*b2;
	A.a = a1*b2 + a2*b1;
	A.b = b1*b2;
	return A;
}
RationalNumber RationalNumber::operator+(const int &integer) const {
	RationalNumber A;
	A.a = integer;
	A.b = 1;
	return *this + A;
}
RationalNumber RationalNumber::operator+(const double &decimal) const {
	RationalNumber A(decimal);
	return *this + A;
}
RationalNumber RationalNumber::operator+(const float &decimal) const {
	RationalNumber A(static_cast<double>(decimal));
	return *this + A;
}
RationalNumber operator+(const int &integer, const RationalNumber &r) {
	return r + integer;
}
RationalNumber operator+(const double& decimal, const RationalNumber& r) {
	return r + decimal;
}
RationalNumber operator+(const float& decimal, const RationalNumber& r) {
	return r + decimal;
}
	// Subtract------------------------------------------
RationalNumber RationalNumber::operator-(const RationalNumber& r) const {
	RationalNumber A;
	int a1 = this->a;
	int b1 = this->b;

	int a2 = r.a;
	int b2 = r.a;

	A.a = a1*b2 - a2*b1;
	A.b = b1*b2;
	return A;
}
RationalNumber RationalNumber::operator-(const int& integer) const {
	RationalNumber A;
	A.a = integer;
	A.b = 1;
	return *this - A;
}
RationalNumber RationalNumber::operator-(const double& decimal) const {
	RationalNumber A(decimal);
	return *this - A;
}
RationalNumber RationalNumber::operator-(const float& decimal) const{
	RationalNumber A(static_cast<double>(decimal));
	return *this - A;

}
RationalNumber operator-(const int& integer, const RationalNumber& r) {
	RationalNumber A (integer,1);
	return A - r;
}
RationalNumber operator-(const double& decimal, const RationalNumber& r) {
	RationalNumber A (decimal);
	return A - r;
}
RationalNumber operator-(const float& decimal, const RationalNumber& r) {
	RationalNumber A (static_cast<double>(decimal));
	return A - r;
}
	// Multiply------------------------------------------
RationalNumber RationalNumber::operator*(const RationalNumber& r) const {
	return RationalNumber (this->a * r.a, this->b * r.b);
}
RationalNumber RationalNumber::operator*(const int& integer) const {
	return RationalNumber(integer,1) * (*this);
}
RationalNumber RationalNumber::operator*(const double& decimal) const {
	return RationalNumber(decimal) * (*this);
}
RationalNumber RationalNumber::operator*(const float& decimal) const {
	return RationalNumber (static_cast<double>(decimal)) * (*this);
}
RationalNumber operator*(const int& integer, const RationalNumber& r) {
	return RationalNumber (integer,1) * r;
}
RationalNumber operator*(const double& decimal, const RationalNumber& r) {
	return RationalNumber (decimal) * r;
}
RationalNumber operator*(const float& decimal, const RationalNumber& r) {
	return RationalNumber (static_cast<double>(decimal)) * r;
}
	// Divide------------------------------------------
RationalNumber RationalNumber::operator/(const RationalNumber& r) const {
	return RationalNumber(this->b, this->a) * r;
}
RationalNumber RationalNumber::operator/(const int& integer) const {
	return RationalNumber(1, integer) * (*this);
}
RationalNumber RationalNumber::operator/(const double& decimal) const {
	return RationalNumber (1/decimal) * (*this);
}
RationalNumber RationalNumber::operator/(const float& decimal) const {
	return RationalNumber (static_cast<double>(1)/decimal) * (*this);
}
RationalNumber operator/(const int& integer,  const RationalNumber& r) {
	return RationalNumber (integer,1) * RationalNumber(r.b, r.a);
}
RationalNumber operator/(const double& decimal, const RationalNumber& r) {
	return RationalNumber (decimal) * RationalNumber(r.b, r.a);
}
RationalNumber operator/(const float& decimal, const RationalNumber& r) {
	return RationalNumber (static_cast<double>(decimal)) * RationalNumber(r.b, r.a);
}
	// Post Increment and Decrement----------------------
RationalNumber RationalNumber::operator++ (const int DUMMY) {
	*this = (*this) + 1;
	return *this -1;
}
RationalNumber RationalNumber::operator--(const int DUMMY) {
	*this = *this - 1;
	return *this + 1;
}

	// Unary Operators
	// Negation-------------------------------------------
RationalNumber RationalNumber::operator-() {
	return -1*(*this);
}

	// Pre Increment and Decrement------------------------
RationalNumber RationalNumber::operator++() {
	*this = *this + 1;
	return *this;
}
RationalNumber RationalNumber::operator--() {
	*this = *this -1 ;
	return *this;
}

	// Comparitive Operators----------------------------------------
	// Equals
bool RationalNumber::operator==(const RationalNumber& r) const {
	if ( this->getNumerator() == r.getNumerator() && this->getDenominator() == r.getDenominator()) {
		return true;
	}
	else
		return false;
}
bool RationalNumber::operator==(const int& integer) const {
	RationalNumber A(integer,1);
	if (A == *this)
		return true;
	else
		return false;
}
bool RationalNumber::operator==(const double& decimal) const {
	RationalNumber A(decimal);
	if (A == *this)
		return true;
	else
		return false;
}
bool RationalNumber::operator==(const float& decimal) const {
	RationalNumber A(static_cast<double>(decimal));
	if (A == *this)
		return true;
	else
		return false;

}
bool operator==(const int& integer, const RationalNumber& r) {
	return r == integer;
}
bool operator==(const double& decimal, const RationalNumber& r) {
	return r == decimal;
}
bool operator==(const float& decimal, const RationalNumber& r) {
	return r == decimal;
}
	// Not Equals
bool RationalNumber::operator!=(const RationalNumber& r) const {
	if (this->toDecimal() != r.toDecimal())
		return true;
	else
		return false;

}
bool RationalNumber::operator!=(const int& integer) const {
	RationalNumber A(integer,1);
	return A != *this;
}
bool RationalNumber::operator!=(const double& decimal) const {
	RationalNumber A(decimal);
	return A != *this;
}
bool RationalNumber::operator!=(const float& decimal) const {
	RationalNumber A (static_cast<double>(decimal));
	return A != *this;
}
bool operator!=(const int& integer, const RationalNumber& r) {
	return r!= integer;
}
bool operator!=(const double& decimal, const RationalNumber& r) {
	return r != decimal;
}
bool operator!=(const float& decimal, const RationalNumber& r) {
	return r != decimal;
}
	// Less than equals
bool RationalNumber::operator<=(const RationalNumber& r) const {
	if (this->toDecimal() <= r.toDecimal())
		return true;
	else return false;
}
bool RationalNumber::operator<=(const int& integer) const {
	RationalNumber A (integer, 1);
	return *this <= A;
}
bool RationalNumber::operator<=(const double& decimal) const {
	RationalNumber A (decimal);
	return *this <= A;
}
bool RationalNumber::operator<=(const float& decimal) const {
	RationalNumber A (static_cast<double>(decimal));
	return *this <= A;
}
bool operator<=(const int& integer, const RationalNumber& r) {
	RationalNumber A (integer,1);
	if (A.toDecimal() <= r.toDecimal())
		return true;
	else return false;
}
bool operator<=(const double& decimal, const RationalNumber& r) {
	RationalNumber A (decimal);
	if (A.toDecimal() <= r.toDecimal())
		return true;
	else return false;
}
bool operator<=(const float& decimal, const RationalNumber& r) {
	RationalNumber A (static_cast<double>(decimal));
	if (A.toDecimal() <= r.toDecimal())
		return true;
	else return false;
}
	// Greater than equals
bool RationalNumber::operator>=(const RationalNumber& r) const {
	if (this->toDecimal() >= r.toDecimal())
		return true;
	else return false;
}
bool RationalNumber::operator>=(const int& integer) const {
	RationalNumber A (integer,1);
	return *this >= A;
}
bool RationalNumber::operator>=(const double& decimal) const {
	RationalNumber A (decimal);
	return *this >= A;
}
bool RationalNumber::operator>=(const float& decimal) const {
	RationalNumber A (static_cast<double>(decimal));
	return *this >= A;
}
bool operator>=(const int& integer, const RationalNumber& r) {
	return r <= integer;
}
bool operator>=(const double& decimal, const RationalNumber& r) {
	return r <= decimal;
}
bool operator>=(const float& decimal, const RationalNumber& r) {
	return r <= decimal;
}
	// Less than
bool RationalNumber::operator<(const RationalNumber& r) const {
	if (this->toDecimal() < r.toDecimal())
		return true;
	else return false;
}
bool RationalNumber::operator<(const int& integer) const {
	RationalNumber A (integer,1);
	return *this < A;
}
bool RationalNumber::operator<(const double& decimal) const {
	RationalNumber A (decimal);
	return *this < A;
}
bool RationalNumber::operator<(const float& decimal) const {
	RationalNumber A (static_cast<double>(decimal));
	return *this < A;
}
bool operator<(const int& integer, const RationalNumber& r) {
	RationalNumber A (integer,1);
	return A < r;
}
bool operator<(const double& decimal, const RationalNumber& r) {
	RationalNumber A (decimal);
	return A < r;
}
bool operator<(const float& decimal, const RationalNumber& r) {
	RationalNumber A (static_cast<double>(decimal));
	return A < r;
}
	// Greater than
bool RationalNumber::operator>(const RationalNumber& r) const {
	return !(*this < r);
}
bool RationalNumber::operator>(const int& integer) const {
	return !(*this < integer);
}
bool RationalNumber::operator>(const double& decimal) const {
	return !(*this < decimal);
}
bool RationalNumber::operator>(const float& decimal) const {
	return !(*this < decimal);
}
bool operator>(const int& integer, const RationalNumber& r) {
	return r < integer;
}
bool operator>(const double& decimal, const RationalNumber& r) {
	return r < decimal;
}
bool operator>(const float& decimal, const RationalNumber& r) {
	return r < decimal;
}



/*////////////////////////////////////////////////////////////////////////////////////////*/

void  math_plus (){
	RationalNumber a1 (1,2);
	RationalNumber sum = (a1 + a1);
	cout << a1 << "\t+\t" << a1 << "\t=\t" << sum << endl;

	int random = rand() % 10;
	sum = (a1 + random);
	cout << a1 << "\t+\t" << random << "\t=\t" <<  sum << endl;
	cout << random << "\t+\t" << a1 << "\t=\t" <<  sum << endl;

	double random2 = (rand() % 101) / 10;
	sum = (a1 + random2);
	cout << a1 << "\t+\t"<< random2 << "\t=\t" << sum << endl;
	cout << random << "\t+\t" << a1 << "\t=\t" <<  sum << endl;

	float random3 = (rand() % 101) / 10;
	sum = (a1 + random3);
	cout << a1 << "\t+\t" << random3 << "\t=\t" << sum << endl;
	cout << random << "\t+\t" << a1 << "\t=\t" <<  sum << endl;
}
int main() {
	srand(static_cast<unsigned int>(time(0)));
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << ":::::::::::::  Testing Constructors  ::::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	RationalNumber a1;
	cout << "Default RationalNumber = " << a1 << " = " << a1.toDecimal() << endl;
	RationalNumber a2(-5,2);
	cout << "Non-Default RationalNumber(-5,2) = " << a2 << " = " << a1.toDecimal() << endl;
	RationalNumber a3(-2.5);
	cout << "Non-Default RationalNumber(-2.5) = " << a3 << " = " << a3.toDecimal() << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << "::::::::::::::  Getters and Setters  ::::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "The Numerator of\t\t: " << a1 << " is " << a1.getNumerator() << endl;
	cout << "The Denominator of\t: " << a1 << " is " << a1.getDenominator() << endl;
	int numerator = rand() % 50 - 25;
	a1.setNumerator(numerator);
	cout << "a1.setNumerator(" << numerator << ")\t: New numerator is " << a1.getNumerator() << endl;
	int denominator = rand() % 50 - 25;
	a1.setDenominator(denominator);
	cout << "a1.setDenominator(" << denominator << ")\t: New denominator is " << a1.getDenominator() << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << "::::::::::::  Other Member Functions  :::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << " After Standardising \t(15/-30)" ;
	a1.setDenominator(-30);
	a1.setNumerator(15);
	cout << " becomes : ";
	a1.standardize();
	cout << a1 << endl;

	cout << " After Reducing \t\t(-15/30)" ;
	cout << " becomes : ";
	a1.reduce();
	cout << a1 << endl;

	cout << " Changing to Decimal \t(-1/2) " ;
	cout << "  becomes : " << a1.toDecimal() << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << "::::::::::::  Static Member Functions  ::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "The Total objects are: " << RationalNumber::getCount() << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << ":::::::::::  I/O Operator Overloading  ::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Using RationalNumber with 'cin' " << endl;
	//cout << "Enter a Rational Number";
	//cin >> a1;
	cout << "Printing objects with : cout << a1\t: " << a1 << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << "::::::::::::  Random Number Function  :::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	a1 = getRandomRationalNumber();
	cout << "A Random Rational Number is\t\t: " << a1 << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------
	cout << "::::::::::::  Arithmetic Operators  :::::::::::::::" << endl;
	cout << "-----------------------------------------------------" << endl;
	math_plus();
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
		//----------------------------------------------------------------------------------------------------



	return 0;
}


