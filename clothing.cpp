#include <sstream>
#include <iomanip>
#include <iostream>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
	Product(category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

Clothing::~Clothing()
{

}


set<string> Clothing::keywords() const{

	set<string> title;
	set<string> brand;
	set<string> complete; 

	title = parseStringToWords(name_);
	brand = parseStringToWords(brand_);
	complete = setUnion(title, brand);

	return complete;
}

string Clothing::displayString() const{
	return "Clothing's info: Name: " + name_ + "; Brand: " + brand_ + "; Size: " + size_;
}

void Clothing::dump(ostream& os){
	os << displayString();
}

