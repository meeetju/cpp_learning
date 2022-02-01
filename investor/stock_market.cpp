#include "stock_market.h"
#include <iostream>

namespace Market
{
	Position::Position(int number, double price)
	{
		if (price <= 0.0)
			throw std::runtime_error("Incorrect price! Cannot buy!");
		else
		{
			number_of_shares = number;
			buy_price = price;
		}
	}

	Stock::Stock(const std::string& in_name)
	{
		company_name = in_name;
		current_price = 0.0;

		std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::streamsize prec = std::cout.precision(3);
	}

	std::string Stock::get_name() const
	{
		return company_name;
	}

	void Stock::set_price(double price)
	{
		current_price = price;
	}

	void Stock::buy(int number_of_shares)
	{
		try
		{
			Position position = Position(number_of_shares, current_price);
			positions.push_back(position);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what();
		}
	}

	void Stock::get_ballance() const
	{

		std::cout << "\nCurrent Summary for " << company_name << ":" << std::endl;

		if (positions.empty())
		{
			std::cout << "	  No open positions for this stock\n" << std::endl;
		}
		else
		{
			for (int i = 0; i < positions.size(); i++)
			{
				std::cout << "	* Position " << i + 1 << " : shares number: " << positions[i].number_of_shares << ", price: " << positions[i].buy_price << std::endl;
			}
		}

	}

	bool Stock::operator==(const Stock& stock) const
	{
		return (this->company_name == stock.company_name);
	}

}