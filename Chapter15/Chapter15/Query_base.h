#pragma once

#include "TextQueryTemplate.h"
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

class Query;

//abstract class acts as a base class for concrete query types; all members are private
class Query_base {
	friend class Query;
protected:
	using line_no = TextQueryTem::line_no;		//used in eval the functions
	virtual ~Query_base() = default;
private:
	//eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQueryTem&) const = 0;
	//rep is a string representation of the query
	virtual std::string rep() const = 0;
};

class WordQuery : public Query_base{
	friend class Query;
	WordQuery(const std::string& s):query_word(s){}
	QueryResult eval(const TextQueryTem& t) const {
		return t.query(query_word);
	}
	std::string rep() const { return query_word; }
	std::string query_word;
};

class Query {
	friend Query operator~(const Query &);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
	friend std::ostream& operator<<(std::ostream& os, const Query &query) {
		return os << query.rep();
	}
public:
	Query(const std::string & s) : q(new WordQuery(s)) {};
	QueryResult eval(const TextQueryTem &t) const {
		return q->eval(t);
	}
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query& q) : query(q) {}
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQueryTem&) const;
	Query query;
};

class BinaryQuery : public Query_base{
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s) :
		lhs(l), rhs(r), opSym(s) {}
	//abstract class: BinaryQuery doesn't define eval
	std::string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;
};

inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query&l, const Query&r) :BinaryQuery(l, r, "&") {}
	QueryResult eval(const TextQueryTem&) const;
};

inline inline Query operator&(const Query &l, const Query &r)
{
	return std::shared_ptr<Query_base>(new AndQuery(l, r));
}

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& l, const Query& r) :BinaryQuery(l, r, "|") {}
	QueryResult eval(const TextQueryTem&) const;
};

inline Query operator|(const Query &l, const Query &r)
{
	return std::shared_ptr<Query_base>(new OrQuery(l, r));
}

// return the union of its operands' result sets
QueryResult OrQuery::eval(const TextQueryTem &text) const
{
	// virtual calls through the Query members, lhs and rhs
	// the calls to eval return the QueryResult for each operand
	auto right = rhs.eval(text), left = lhs.eval(text);
	// copy the line numbers from the left-hand operand into the result set
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	// insert lines from the tight-hand operand
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

// return the intersection of its operands' result sets
QueryResult AndQuery::eval(const TextQueryTem &text) const
{
	// virtual calls through the Query operands to get results sets for the operands
	auto left = lhs.eval(text), right = rhs.eval(text);
	// set to hold the intersection of left and right
	auto ret_lines = make_shared<set<line_no>>();
	// writes the intersection of two ranges to a destination iterator 
	// destination iterator in this call adds elements to rets
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

// return the lines not in its operand's result set
QueryResult NotQuery::eval(const TextQueryTem& text) const {
	// virtual call to eval through the Query operand
	auto result = query.eval(text);
	// start out with an empty result set
	auto ret_lines = make_shared<set<line_no>>();
	// we have a iterator through the lines on which our operand appears
	auto beg = result.begin(), end = result.end();
	// for each line in the input file, if that line is not in result.
	// add that line number to ret_lines
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		// if we haven't processed all the lines in result
		// check whether this line is present
		if (beg == end || *beg != n)
			ret_lines->insert(n);	//if not in result, add this line
		else if (beg != end)
			++beg;					//otherwise get the next line number in result if there is one 
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}