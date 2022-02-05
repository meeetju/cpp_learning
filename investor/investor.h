#include "stock_market.h"
#include <string>
#include <vector>

#ifndef INVESTOR_H_
#define INVESTOR_H_

namespace Investor
{
	using namespace Market;

	// Wallet may consist of more or less volatile stocks
	enum class wallet_type { STANDARD, DEFENSIVE };

	// Wallet gathers stocks
	class Wallet
	{
	private:
		std::string type;
		std::vector<Stock*> stocks;
		double available_funds;
		static const int MIN_EXPECTED_STOCKS = 20;
		bool is_stock_in_wallet(Stock* stock);
		bool is_enough_funds(Stock* stock, int number_of_shares) const;
	public:
		void deposit_funds(double deposit);
		void withdraw_funds(double withdraw);
		void buy_stock(Stock* stock, int number_of_shares);
		void sell_stock(Stock* stock, int number_of_shares);
		void get_ballance() const;
		Wallet(wallet_type in_type);
		~Wallet() {};
	};

	class Investments
	{
	private:
		std::vector<Wallet> wallets;
	public:
		void add_wallet(Wallet);
		void get_ballance() const;
	};

}



#endif