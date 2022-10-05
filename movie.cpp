#include <sstream>
#include <iomanip>
#include <iostream>
#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
	Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

Movie::~Movie()
{

}


set<string> Movie::keywords() const{

	set<string> title;

	string genre = genre_;
	genre = convToLower(genre);
	genre = trim(genre);

	title = parseStringToWords(name_);
	title.insert(genre);

	return title;
}

string Movie::displayString() const{
	return "Movie's info: Title: " + name_ + "; Genre: " + genre_ + "; Rating: " + rating_;
}

void Movie::dump(ostream& os){
	os << displayString();
}

