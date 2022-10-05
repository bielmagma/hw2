#include <sstream>
#include <iomanip>
#include <iostream>
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
	Product(category, name, price, qty)
{
	isbn_ = isbn;
	author_ = author;
}

Book::~Book()
{

}

set<string> Book::keywords(){

	set<string> title;
	set<string> author;
	set<string> complete; 

	string isbn = isbn_;
	isbn = convToLower(isbn);
	isbn = trim(isbn);

	title = parseStringToWords(name_);
	author = parseStringToWords(author_);
	complete = setUnion(title, author);
	complete.insert(isbn);

	return complete;
}

string Book::displayString(){
	return "Book's info: Title: " + name_ + "; Author: " + author_ + "; ISBN: " + isbn_;
}

void Book::dump(ostream& os){
	os << displayString();
}

