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
		stocks.reserve(MIN_EXPECTED_STOCKS);
		available_funds = 0.0;
		
	}

	void Wallet::deposit_funds(double deposit)
	{
		if (deposit > 0.0)
		{
			available_funds += deposit;
		}
		else
		{
			std::cout << "Deposit must be greather than 0.0!\n";
		}
		
	}

	void Wallet::withdraw_funds(double withdraw)
	{
		if (withdraw <= available_funds)
		{
			available_funds -= withdraw;
		}
		else
		{
			std::cout << "Insufficient funds!\n";
		}
		
	}

	void Wallet::add_stock(Stock new_stock)
	{
		if (find(stocks.begin(), stocks.end(), new_stock) == stocks.end())
		{
			stocks.push_back(new_stock);
		}
		else
		{
			std::cout << "Stock already exists!\n";
		}
	}

	void Wallet::remove_stock(Stock stock)
	{
		stocks.erase(std::remove(stocks.begin(), stocks.end(), stock), stocks.end());
	}

	void Wallet::get_ballance() const
	{
		std::cout << "\n********** Content of the " << type << " **********" << std::endl;
		std::cout << "Available funds: " << available_funds << std::endl;

		for (int i = 0; i < int(stocks.size()); i++)
		{
			stocks[i].get_ballance();
		}
	}
}

