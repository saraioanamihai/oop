#include <iostream>

using namespace std;

// abstract class
class Taxable {
	// pure virtual method
	virtual float computePriceAfterTax() = 0;
};