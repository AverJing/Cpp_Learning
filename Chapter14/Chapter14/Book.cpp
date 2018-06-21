#include "Book.h"

std::istream & operator>>(std::istream &is, Book &rhs)
{
	is >> rhs.no_ >> rhs.name_ >> rhs.author_ >> rhs.pubdate_;
	if (!is) rhs = Book();
	return is;
}

std::ostream & operator<<(std::ostream &os, const Book &rhs)
{
	os << rhs.no_ << ' ' << rhs.name_ << ' ' << rhs.author_ << ' '
		<< rhs.pubdate_;
	return os;
}

bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs==rhs);
}

bool operator<(const Book &lhs, const Book &rhs)
{
	return (lhs.no_< rhs.no_);
}

bool operator>(const Book &lhs, const Book &rhs)
{
	return (lhs.no_ > rhs.no_);
}

Book operator+(const Book &lhs, const Book &rhs)
{
	Book temp = lhs;
	temp += rhs;
	return temp;
}

Book & Book::operator+=(const Book &rhs)
{
	if (*this == rhs) {
		this->num_ += rhs.num_;
	}
	return *this;
}
