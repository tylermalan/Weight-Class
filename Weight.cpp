// CSS342 
// Gordon Malan - 4 Oct 2018
// Lab 1 - This program creates a class for weight objects

#include "Weight.h"

Weight::Weight() {
	lbs = 0;
	ozs = 0;
}

Weight::Weight(int lbs) {
	// Assumed that only one number means pounds
	this->lbs = lbs;
	ozs = 0;
}

Weight::Weight(int lbs, int ozs) {
	this->lbs = lbs + (ozs / 16);
	this->ozs = ozs % 16;
	if (this->lbs < 0 && this->ozs > 0) {
		this->lbs += 1;
		this->ozs -= 16;
	}
	else if (this->lbs > 0 && this->ozs < 0) {
		this->lbs -= 1;
		this->ozs = 16 + this->ozs;
	}
}

int Weight::getPounds() const {
	return lbs;
}

int Weight::getOunces() const {
	return ozs;
}

// Two helper functions defined
int Weight::convertToOunces() const {
	return ozs + (lbs * 16);
}

Weight Weight::convertToObject(int ounces) const {
	int p = ounces / 16;
	int o = ounces % 16;
	Weight w(p, o);
	return w;
}

// Functions to aid in operator overloading
Weight Weight::add(const Weight& w2) const {
	int first = this->convertToOunces();
	int second = w2.convertToOunces();
	int sum = first + second;
	return convertToObject(sum);
}

Weight Weight::subtract(const Weight& w2) const {
	int first = this->convertToOunces();
	int second = w2.convertToOunces();
	int sum = first - second;
	return convertToObject(sum);
}

Weight Weight::multiply(const double& x) const {
	int ounces = this->convertToOunces();
	ounces *= x;
	return convertToObject(ounces);
}

double Weight::divide(const Weight& w2) const {
	int first = this->convertToOunces();
	int second = w2.convertToOunces();
	if (second == 0) {
		cout << "Error! You cannot divide by zero! ... ";
	}
	return static_cast<double>(first) / static_cast<double>(second);
}

Weight Weight::divide(const double& x) const {
	if (x == 0) {
		cout << "Error! You cannot divide by zero! ... ";
	}
	int first = this->convertToOunces();
	double y = first / x;
	return convertToObject(static_cast<int>(y));
}

int Weight::compareTo(const Weight& w2) const {
	int first = this->convertToOunces();
	int second = w2.convertToOunces();
	if (first < second) {
		return -1;
	}
	else if (first == second) {
		return 0;
	}
	else {
		return 1;
	}
}

// Define function operators for augmented operators
Weight& Weight::operator+=(const Weight& w2) {
	*this = add(w2);
	return *this;
}

Weight& Weight::operator-=(const Weight& w2) {
	*this = subtract(w2);
	return *this;
}

Weight& Weight::operator*=(const double& x) {
	*this = multiply(x);
	return *this;
}

Weight& Weight::operator/=(const double& x) {
	*this = divide(x);
	return *this;
}

Weight& Weight::operator/=(const Weight& w2) {
	*this = divide(w2);
	return *this;
}

// Define function operator for unary negation
Weight Weight::operator-() {
	return Weight(-lbs, -ozs);
}

// Define function operators for output and input
ostream& operator<<(ostream& out, const Weight& w) {
	int x = w.getPounds();
	int y = w.getOunces();
	if (x == 0 && y == 0) {
		out << "0 ozs";
	}
	else if (x == 0) {
		out << y << " ozs";
	}
	else if (y == 0) {
		out << x << " lbs";
	}
	else {
		out << x << " lbs " << y << " ozs";
	}
	return out;
}

istream& operator>>(istream& in, Weight& w) {
	cout << "Enter pounds: ";
	in >> w.lbs;
	cout << "Enter ounces: ";
	in >> w.ozs;
	return in;
}

//Define nonmember function operators for comparison operators
bool operator<(const Weight& w1, const Weight& w2) {
	return w1.compareTo(w2) < 0;
}

bool operator<=(const Weight& w1, const Weight& w2) {
	return w1.compareTo(w2) <= 0;
}

bool operator>(const Weight& w1, const Weight& w2) {
	return w1.compareTo(w2) > 0;
}

bool operator>=(const Weight& w1, const Weight& w2) {
	return w1.compareTo(w2) >= 0;
}

bool operator==(const Weight& w1, const Weight& w2) {
	return w1.compareTo(w2) == 0;
}

bool operator!=(const Weight& w1, const Weight& w2) {
	return w1.compareTo(w2) != 0;
}

// Define nonmember function operators for arithmetic operators
Weight operator+(const Weight& w1, const Weight& w2) {
	return w1.add(w2);
}

Weight operator-(const Weight& w1, const Weight& w2) {
	return w1.subtract(w2);
}

Weight operator*(const Weight& w1, const double& x) {
	return w1.multiply(x);
}

double operator/(const Weight& w1, const Weight& w2) {
	return w1.divide(w2);
}

Weight operator/(const Weight& w1, const double& x) {
	return w1.divide(x);
}
