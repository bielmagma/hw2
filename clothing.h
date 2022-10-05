#include "product.h"
#include "util.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Clothing: public Product{
	public:
		Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);

		~Clothing();


		virtual std::set<std::string> keywords() const;
		virtual std::string displayString() const;
		virtual void dump(std::ostream& os);
		virtual bool isMatch(std::vector<std::string>& searchTerms) const;

	private:
		std::string size_;
		std::string brand_;


};




