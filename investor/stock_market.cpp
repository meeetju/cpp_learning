#include "stock_market.h"
#include <iostream>
#include <string>

namespace Market
{
	bool is_empty_position(Position position)
	{
		return position.number_of_shares == 0;
	}

	Position::Position(int number, double price)
	{
		if (price <= 0.0)
			throw std::runtime_error("Incorrect price! Cannot buy!\n");
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
		positions.reserve(MIN_EXPECTED_POSITIONS);

		std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::streamsize prec = std::cout.precision(3);

		std::cout << "Created new stock " << company_name << " on address: " << this << std::endl;
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

			std::cout << "Buying " << number_of_shares << " shares of " << this->company_name << std::endl;

		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what();
		}
	}

	void Stock::sell(int number_of_shares)
	{
		int actual_shares_number = 0;
		for (int i = 0; i<int(positions.size()); i++)
			actual_shares_number += positions[i].number_of_shares;

		std::cout << "Current total number of shares for " << company_name << " is " << actual_shares_number << std::endl;

		if (number_of_shares > actual_shares_number)
		{
			std::cout << "Not enough shares owned\n";
		}
		else
		{
			std::cout << "Selling " << number_of_shares << " shares of " << this->company_name << std::endl;

			int shares_to_sale = number_of_shares;

			for(int i = 0; i < int(positions.size()); i++)
			{
				if (positions[i].number_of_shares <= shares_to_sale)
				{
					shares_to_sale -= positions[i].number_of_shares;
					positions[i] = Position(0, positions[i].buy_price);
				}
				else
				{
					int new_shares_num = positions[i].number_of_shares - shares_to_sale;
					positions[i] = Position(new_shares_num, positions[i].buy_price);
					shares_to_sale = 0;
					break;
				}
			}
			remove_empty_positions();
		}
		
	}

	//bool Stock::is_empty_position(Position position)
	//{
	//	return position.number_of_shares == 0;
	//}

	void Stock::remove_empty_positions()
	{
		positions.erase(std::remove_if(positions.begin(), positions.end(), is_empty_position), positions.end());
	}

	void Stock::get_ballance() const
	{

		std::cout << "\nOpened positions for " << company_name << ":" << std::endl;

		if (positions.empty())
		{
			std::cout << "- No open positions for this stock\n";
		}
		else
		{
			for (int i = 0; i < int(positions.size()); i++)
			{
				std::cout << "- Position " << i + 1 << " : shares number : " << positions[i].number_of_shares << ", price : " << positions[i].buy_price << std::endl;
			}
		}
		std::cout << std::endl;
	}

	bool Stock::operator==(const Stock& stock) const
	{
		return (this->company_name == stock.company_name);
	}

}