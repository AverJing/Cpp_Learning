#ifndef SALES_DATA
#define SALES_DATA
#include <string>

using namespace std;

struct Sales_data
{
	friend ostream & operator<<(ostream &os, const Sales_data &val) {
		os << val.bookNo << ' ' << val.units_sold << ' '
			<< val.aver_price << ' ' << val.revenue << endl;
		return os;
	}
	friend istream & operator >>(istream &in, Sales_data &val) {
		in >> val.bookNo >> val.units_sold >> val.aver_price;
		val.revenue = val.units_sold * val.aver_price;
		return in;
	}
private:
	string bookNo;
	double revenue = 0.0;
	unsigned units_sold = 0;
	double aver_price = 0.0;
public:
	Sales_data() {}
	Sales_data(const string book, const unsigned num, const double price) :bookNo(book),
		units_sold(num), revenue(price * num),aver_price(price) {}
	string ISBN() {
		return bookNo;
	}
	Sales_data & operator +=(const Sales_data& val_data) {
		revenue += val_data.revenue;
		units_sold += val_data.units_sold;
		aver_price = revenue / units_sold;
		return *this;
	}
};


#endif // !SALES_DATA
