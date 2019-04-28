/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <vector>
#include <functional>

template<typename T>
class SignalTrivial;

template<typename RET, typename... Args>
class SignalTrivial<RET(Args...)> {
public:
	using Functor = std::function<RET(Args...)>;
	void connect(Functor&& f) {
		functors_.push_back(std::forward<Functor>(f));
	}
	void call(Args&& ... s) {
		for (const auto& e : functors_) {
			e(s...);
		}
	}
private:
	std::vector<Functor> functors_;
};

int main(){
	SignalTrivial<int(int,int)> s;
	s.connect([](int a, int b) {std::cout << a + b << std::endl;return a + b; });
	s.call(2, 10);
	return 0;
}