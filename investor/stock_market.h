#ifndef STOCK_MARKET_H_
#define STOCK_MARKET_H_
#include <string>
#include <vector>

namespace Market
{

	// Strucure representing a stock position
	struct Position
	{
	int number_of_shares;
	double buy_price;
	Position(int number, double price);
	~Position() {};
	};

	// Stock representation
	class Stock
	{
	private:
		std::string company_name;
		double current_price;
		std::vector<Position> positions;
	public:
		std::string get_name() const;
		void set_price(double price) ;
		void buy(int number_of_shares);
		void sell(int number_of_shares);
		void get_ballance() const;
		Stock(const std::string& in_name);
		~Stock() {};
		bool operator==(const Stock& stock) const;
	};

}
#endif