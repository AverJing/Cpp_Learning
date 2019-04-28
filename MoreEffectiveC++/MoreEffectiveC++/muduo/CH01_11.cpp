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
#include <thread>
#include <string>
#include <memory>
#include <mutex>
#include <map>
#include <functional>
#include <cassert>
#include <chrono>

int count = 0;

class Stock {
public:
	Stock(const std::string& n) :name(n) {}
	std::string& getKey() {
		return name;
	}
	bool operator==(const Stock& lhs) {
		return name == lhs.name;
	}
private:
	std::string name;
};

class StockFactory :public std::enable_shared_from_this<StockFactory> {
public:
	StockFactory() = default;
	StockFactory(const StockFactory&) = delete;
	StockFactory& operator=(const StockFactory&) = delete;
	std::shared_ptr<Stock> get(const std::string& name) {
		std::shared_ptr<Stock> pStock;
		std::unique_lock<std::mutex> lock{ m_ };//lock
		++count;
		auto& wkStock = stocks_[name];//注意是引用
		pStock = wkStock.lock();
		if (!pStock) {
			pStock.reset(new Stock(name), 
				std::bind(&StockFactory::weakDeleteCallback, std::weak_ptr<StockFactory>(shared_from_this()), std::placeholders::_1));
			wkStock = pStock;
		}
		return pStock;
	}
private:
	mutable std::mutex m_;
	std::map<std::string, std::weak_ptr<Stock>> stocks_;
	void removeStock(Stock* s) {
		if (s) {
			std::unique_lock<std::mutex> lock{ m_ };//lock
			stocks_.erase(s->getKey());
		}
	}
	static void weakDeleteCallback(const std::weak_ptr<StockFactory>& wkStockFac, Stock* s) {
		auto factory = wkStockFac.lock();
		if (factory) {
			factory->removeStock(s);
		}
		delete s;
	}
};

void testLongLifeFactory() {
	std::shared_ptr<StockFactory> factory(new StockFactory());
	{
		auto stock = factory->get("IBM");
		auto stock2 = factory->get("IBM");
		assert(stock == stock2);
		//stock destrcuts here
	}
	//factory destructs here
}

void testShortLifeFactory() {
	std::shared_ptr<Stock> stock;
	{
		std::shared_ptr<StockFactory> factory(new StockFactory());
		stock = factory->get("IBM");
		auto stock2 = factory->get("IBM");
		assert(stock == stock2);
		//factory destrcuts here
	}
	//stock destructs here
}

int main(){
	auto prev = std::chrono::steady_clock::now();
	for (int i = 0; i < 1000; ++i) {
		std::thread t(testLongLifeFactory);
		t.join();
		std::thread t2(testShortLifeFactory);
		t2.join();
	}
	auto now = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::duration<double>>(now - prev).count() << std::endl;
	std::cout << count << std::endl;
	return 0;
}