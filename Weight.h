// CSS342 
// Gordon Malan - 4 Oct 2018
// Lab 1 - This program creates a class for weight objects

#ifndef WEIGHT_H
#define WEIGHT_H

#include <iostream>

using namespace std;

class Weight
{
private:
	int lbs;
	int ozs;

public:
	Weight();
	Weight(int lbs); // Assumed that only one number initialization means pounds
	Weight(int lbs, int ozs);
	int getPounds() const;
	int getOunces() const;
	int convertToOunces() const;
	Weight convertToObject(int ounces) const;
	Weight add(const Weight& w2) const;
	Weight subtract(const Weight& w2) const;
	Weight multiply(const double& x) const;
	double divide(const Weight& w2) const;
	Weight divide(const double& x) const;
	int compareTo(const Weight& w2) const;

	// Define function operators for augmented operators
	Weight& operator+=(const Weight& w2);
	Weight& operator-=(const Weight& w2);
	Weight& operator*=(const double& x);
	Weight& operator/=(const double& x);
	Weight& operator/=(const Weight& w2);

	// Define function operator for unary negation
	Weight operator-();

	// Define the << and >> operators
	friend ostream& operator<<(ostream& out, const Weight& w);
	friend istream& operator>>(istream& in, Weight& w);
};

// Define nonmember function operators for comparison operators
bool operator<(const Weight& w1, const Weight& w2);
bool operator<=(const Weight& w1, const Weight& w2);
bool operator>(const Weight& w1, const Weight& w2);
bool operator>=(const Weight& w1, const Weight& w2);
bool operator==(const Weight& w1, const Weight& w2);
bool operator!=(const Weight& w1, const Weight& w2);

// Define nonmember function operators for arithmetic operators
Weight operator+(const Weight& w1, const Weight& w2);
Weight operator-(const Weight& w1, const Weight& w2);
Weight operator*(const Weight& w1, const double& x);
double operator/(const Weight& w1, const Weight& w2);
Weight operator/(const Weight& w1, const double& x);

#endif // WEIGHT_H