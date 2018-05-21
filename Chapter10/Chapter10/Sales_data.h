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
	friend istream &read(istream &in, Sales_data &val) {
		in >> val.bookNo >> val.units_sold >> val.aver_price;
		val.revenue = val.units_sold * val.aver_price;
		return in;
	}
private:
	string bookNo;
	double revenue = 0.0;
	unsigned units_sold = 0;
	double aver_price = 0.0;
	inline double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0;
	}
public:
	//ex7_12 Define a constructor that takes an istream into the body of this class
	Sales_data(istream &is) : Sales_data() {
		read(is, *this);
	}
	/*Sales_data(const string book, const unsigned num, const double price) :bookNo(book),
		units_sold(num), revenue(price * num),aver_price(price) {}*/
	Sales_data(const std::string& s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(n * p)
	{
		std::cout << "Sales_data(const std::string&, unsigned, double)"
			<< std::endl;
	}

	Sales_data() : Sales_data("", 0, 0.0f)
	{
		std::cout << "Sales_data()" << std::endl;
	}

	Sales_data(const std::string& s) : Sales_data(s, 0, 0.0f)
	{
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}

	string ISBN() const{
		return bookNo;
	}
	Sales_data & operator +=(const Sales_data& val_data) {
		revenue += val_data.revenue;
		units_sold += val_data.units_sold;
		aver_price = revenue / units_sold;
		return *this;
	}
	Sales_data& combine(const Sales_data  &rhs) {
		revenue += rhs.revenue;
		units_sold += rhs.units_sold;
		return *this;
	}
};


#endif // !SALES_DATA
