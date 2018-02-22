#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);

private:
	vector<Screen> screens;
};

class Screen {
public:
	friend void Window_mgr::clear(ScreenIndex);
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c = ' '):height(ht),width(wd),contents(ht * wd, c){}
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const { return contents[ht * width + wd]; };
	Screen &move(pos r, pos c) {
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
	inline Screen &set(char c) {
		contents[cursor] = c;
		return *this;
	}
	inline Screen &set(pos r, pos col, char ch) {
		contents[r*width + col] = ch;
		return *this;
	}
	Screen &display(ostream &os) { do_display(os); return *this; }
	const Screen &display(ostream &os) const { do_display(os); return *this; }
	//pos size() const { return height * width; }
	inline pos size();
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream &os) const { os << contents; }
};

Screen::pos Screen::size() {
	return height * width;
}

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

#endif // !SCREEN_H
