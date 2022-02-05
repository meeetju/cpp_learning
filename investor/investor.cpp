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

	void Wallet::buy_stock(Stock* stock, int number_of_shares)
	{
		std::cout << "Buying " << number_of_shares << " of " << stock->get_name() << std::endl;

		if (is_enough_funds(stock, number_of_shares))
		{
			if (!is_stock_in_wallet(stock))
			{
				stocks.push_back(stock);
				std::cout << "Adding " << stock->get_name() << " with address: " << stock << " to stocks" << std::endl;
			}
			stock->add_shares(number_of_shares);
		}
		else
		{
			std::cout << "The are not enough funds in the wallet!\n";
		}
	}

	void Wallet::sell_stock(Stock* stock, int number_of_shares)
	{
		std::cout << "Sell " << number_of_shares << " of " << stock->get_name() << std::endl;

		if (is_stock_in_wallet(stock))
		{
			stock->remove_shares(number_of_shares);
			std::cout << "Sold " << stock->get_name() << " shares for " << stock->get_current_price() << " each" << std::endl;
		}
		else
		{
			std::cout << "There is no " << stock->get_name() << " in the wallet!\n";
		}
	}

	bool Wallet::is_stock_in_wallet(Stock* stock)
	{
		return find(stocks.begin(), stocks.end(), stock) != stocks.end();
	}

	bool Wallet::is_enough_funds(Stock* stock, int number_of_shares) const
	{
		return bool (available_funds >= (stock->get_current_price() * number_of_shares));
	}

	void Wallet::get_ballance() const
	{
		std::cout << "\n\n================== WALLET START ====================\n";
		std::cout << "Content of the " << type << std::endl;
		std::cout << "Available funds: " << available_funds << std::endl;

		for (int i = 0; i < int(stocks.size()); i++)
		{
			stocks[i]->get_ballance();
		}

		std::cout << "=================== WALLET END =====================\n\n\n";
	}
}

