#pragma once
#ifndef EX15_26_DISC_QUOTE_H
#define EX15_26_DISC_QUOTE_H

#include "ex15_26_Quote.h"
//Sorry, Disc_quote should be Bulk_quote
class Disc_quote : public Quote {
public:
	Disc_quote() {
		std::cout << "Disc_quote Constructor" << std::endl;
	}
	Disc_quote(const std::string& book, double p, std::size_t qty, double disc)
		:Quote(book, p), quantity(qty), discount(disc) {
		std::cout << "Disc_quote Constructor takint four parameters" << std::endl;
	}
	Disc_quote(const Disc_quote& rhs) :Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
		std::cout << "Disc_quote Copy Constrctor" << std::endl;
	}
	Disc_quote(const Disc_quote&& rhs) noexcept : Quote(std::move(rhs)), quantity(std::move(rhs.quantity))
		, discount(std::move(rhs.discount)) {
		std::cout << "Disc_quote Move Constructor" << std::endl;
	}
	Disc_quote& operator=(const Disc_quote& rhs) {
		std::cout << "Disc_quote copy assignment operator" << std::endl;
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		return *this;
	}
	Disc_quote& operator=(const Disc_quote&& rhs) noexcept {
		std::cout << "Disc_quote move assignment operator" << std::endl;
		Quote::operator=(rhs);
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
		return *this;
	}
	~Disc_quote() { std::cout << "Disc_quote destructor" << std::endl; }

	virtual double net_price(size_t cnt) const override {
		if (cnt >= quantity) return cnt * (1 - discount) * price;
		else return cnt * price;
	}
protected:
	std::size_t quantity = 0;	//purchase size for the discount to apply
	double discount = 0.0;		//fractional discount to apply

};

#endif // !EX15_26_DISC_QUOTE_H