#pragma once
#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include <iostream>
#include <string>
//#include "Quote.h"

/*
class limit_quote : public Quote {
public:
	limit_quote() = default;
	limit_quote(const std::string&, double, std::size_t, std::size_t, double);
	double net_price(std::size_t n) const override; 
	void debug() const override {
		Quote::debug();
		std::cout << "min_qty: " << min_qty << " max_qty: " << max_qty
			<< " discount: " << discount << std::endl;
	}
private:
	std::size_t min_qty = 0;
	std::size_t max_qty = 0;
	double discount = 0.0;
};

limit_quote::limit_quote(const std::string &book, double p, std::size_t n1, std::size_t n2, double disc)
	:Quote(book, p), min_qty(n1), max_qty(n2), discount(disc){}

inline double limit_quote::net_price(std::size_t n) const
{
	if (n > max_qty)
		return max_qty * (1 - discount)*price + (n - max_qty)*price;
	else if (n >= min_qty) //n <= max_qty && n >= min_qty
		return n * (1 - discount)*price;
	else
		return n * price;
}
*/

#include "Disc_quote.h"

class limit_quote : public Disc_quote {
public:
	limit_quote() = default;
	limit_quote(const std::string& book, double price, std::size_t n1, std::size_t n2, double disc)
		:Disc_quote(book, price, n1, discount), max_qty(n2) {}
	double net_price(std::size_t n) const override final;
	/*
	void debug() const override {
		Quote::debug();
		std::cout << "min_qty: " << quantity << " max_qty: " << max_qty
			<< " discount: " << discount << std::endl;
	}*/
private:
	std::size_t max_qty = 0;
};

double limit_quote::net_price(std::size_t n) const
{
	if (n > max_qty)
		return max_qty * (1 - discount)*price + (n - max_qty)*price;
	else if (n >= quantity) //n <= max_qty && n >= min_qty
		return n * (1 - discount)*price;
	else
		return n * price;
}

#endif // !LIMIT_QUOTE_H