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
		static const int MIN_EXPECTED_POSITIONS = 5;
		//bool is_empty_position(Position position);
		void remove_shares_from_positions(int shares_to_remove);
		void remove_empty_positions();
	public:
		std::string get_name() const;
		double get_current_price() const { return current_price; };
		void set_price(double price) ;
		void add_shares(int number_of_shares);
		void remove_shares(int number_of_shares);
		void get_ballance() const;
		Stock(const std::string& in_name);
		~Stock() {};
		bool operator==(const Stock& stock) const;
	};

}
#endif