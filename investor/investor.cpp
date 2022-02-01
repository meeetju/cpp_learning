#include "investor.h"
#include <iostream>
#include <stdexcept>

namespace Investor
{

	Wallet::Wallet(wallet_type in_type)
	{
		switch (in_type)
		{
		case wallet_type::STANDARD:
			type = "Standard wallet";
			break;
		case wallet_type::DEFENSIVE:
			type = "Defensive wallet";
			break;
		default:
			throw std::runtime_error("Wrong type provided");
		}
		available_funds = 0.0;
		stocks.reserve(MIN_EXPECTED_STOCKS);
	}

	void Wallet::add_stock(Stock new_stock)
	{
		stocks.push_back(new_stock);
	}

	void Wallet::remove_stock(Stock stock)
	{
		//std::remove(stocks.begin(), stocks.end(), stock);
		//stocks.erase(std::remove(stocks.begin(), stocks.end(), stock), stocks.end());

		int position = 0;

		for (int i = 0; i < stocks.size(); i++)
		{
			if (stocks[i] == stock)
			{
				position = i;
			}
		}

		stocks.erase(stocks.begin() + position);
	}

	void Wallet::get_ballance() const
	{
		std::cout << "\n********** Content of the " << type << " **********" << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < int(stocks.size()); i++)
		{
			stocks[i].get_ballance();
		}
	}
}

