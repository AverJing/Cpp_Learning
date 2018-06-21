#include "Sales_data.h"

inline Sales_data::Sales_data(std::istream & is)
{
	//is >> bookNo >> units_sold >> revenue;
	is >> *this;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs)
{
	if (bookNo == rhs.bookNo) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}
	return *this;
}

Sales_data & Sales_data::operator=(const std::string & isbn)
{
	*this = Sales_data(isbn);
	return *this;
}

std::istream & operator>>(std::istream &in, Sales_data &rhs)
{
	double price = 0.0;
	in >> rhs.bookNo >> rhs.units_sold >> price;
	if (in)
		rhs.revenue = rhs.units_sold * price;
	else
		rhs = Sales_data();
	return in;
}

std::ostream & operator<<(std::ostream &os, const Sales_data &rhs)
{
	os << rhs.bookNo << ' ' << rhs.units_sold << ' ' << rhs.revenue
		<< ' ' << rhs.avg_price();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}
