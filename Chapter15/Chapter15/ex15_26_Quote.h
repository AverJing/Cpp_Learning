#pragma once
#ifndef EX15_26_QUOTE_H
#define EX15_26_QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
	Quote() {
		std::cout << "Quote Constructor" << std::endl;
	}
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) {
		std::cout << "Quote Constructor takint two parameters" << std::endl;
	}
	Quote(const Quote& rhs) {
		std::cout << "Quote Copy assignment operator" << std::endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
	}
	Quote(Quote&& rhs) noexcept: bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)){
		std::cout << "Quote Move assignment operator" << std::endl;
	}
	Quote& operator=(const Quote& rhs) {
		std::cout << "Quote Copy assignment operator" << std::endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote& operator=(Quote&& rhs) noexcept {
		std::cout << "Quote Move assignment operator" << std::endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	std::string isbn() const { return bookNo; }
	//returns the total sales price for the specified number of items
	//derived classes will override and apply different discount algorithms
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() { std::cout << "Quote Destructor" << std::endl; }	//dynamic binding for the destructor
	virtual void debug() const { std::cout << "bookNo: " << bookNo << " price: " << price << std::endl; }
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

#endif // !EX15_26_QUOTE_H