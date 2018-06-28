#pragma once
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Quote.h"


class Bulk_quote : public Quote {//Bulc_quote inherits from Quote
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	//overrides the base version in order to implement the bulk purchase discount policy
	double net_price(std::size_t) const override;
	void debug() const override{
		Quote::debug();
		std::cout << "min_qty: " << min_qty << " discount: " << discount << std::endl;
	}
	Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
	Bulk_quote* clone() && override {return new Bulk_quote(std::move(*this)); }
private:
	std::size_t min_qty = 0;	//minimum purchase for the discount to apply
	double discount = 0.0;		//fractional discount to apply
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
	: Quote(book, p), min_qty(qty), discount(disc){}

inline double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= min_qty)
		return n * (1 - discount) * price;
	else
		return n * price;
}

/*
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {//Bulc_quote inherits from Disc_quote
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price, std::size_t qty, double discount)
		:Disc_quote(book, price, qty, discount) {}
	//overrides the base version in order to implement the bulk purchase discount policy
	double net_price(std::size_t) const override;
	/*
	void debug() const override {
		Quote::debug();
		std::cout << "quantity: " << quantity << " discount: " << discount << std::endl;
	}*/
};

double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= quantity)
		return n * (1 - discount) * price;
	else
		return n * price;
}*/

#endif // !BULK_QUOTE_H
