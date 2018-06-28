#pragma once
#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double p, std::size_t qty, double disc)
		:Quote(book, p), quantity(qty), discount(disc) {}
	virtual double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;	//purchase size for the discount to apply
	double discount = 0.0;		//fractional discount to apply

};

#endif // !DISC_QUOTE_H
