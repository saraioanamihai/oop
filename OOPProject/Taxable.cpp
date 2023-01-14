#include <iostream>

using namespace std;

// abstract class
class Taxable {
public:
	// pure virtual method
	virtual float computePriceAfterTax() = 0;
};