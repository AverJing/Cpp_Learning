#pragma once
#ifndef EX_15_20_BASE_H
#define EX_15_20_BASE_H

class Base {
protected:
	int prot_mem;
private:
	char priv_mem;
};

class Pub_Derv : public Base {
	void memfcn(Base &b) { b = *this; }
	int f() { return prot_mem; }
};

class Priv_Derv : private Base {
	void memfcn(Base &b) { b = *this; }
	int f1() const { return prot_mem; }
};

class Prot_Derv : protected Base {
	void memfcn(Base &b) { b = *this; }
	int f2() { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
	void memfcn(Base &b) { b = *this; }
	int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
	// void memfcn(Base &b) { b = *this; } // error: 'Base' not accessible because 'Priv_Derv' uses 'private' to inherit from 'Base'
};

struct Derived_from_Protected : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }
};

#endif // !EX_15_20_BASE_H
