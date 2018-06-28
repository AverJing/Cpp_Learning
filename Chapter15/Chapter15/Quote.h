#pragma once
#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	//returns the total sales price for the specified number of items
	//derived classes will override and apply different discount algorithms
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;	//dynamic binding for the destructor
	virtual void debug() const{ std::cout << "bookNo: " << bookNo << " price: " << price << std::endl; }
	std::string isbn() { return bookNo; }
	//virtual function to return a dynamically allocated copy of itself
	//these members use reference qualifiers
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }
private:
	std::string bookNo;	//ISBN number of this item
protected:
	double price = 0.0;	//normal, undiscounted price
};

double print_total(std::ostream& os, Quote const& item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due " << ret << std::endl;
	return ret;
}

#endif // !QUOTE_H
