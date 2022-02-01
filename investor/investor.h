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
		std::vector<Stock> stocks;
		double available_funds;
	public:
		void deposit_funds(double deposit);
		void withdraw_funds(double withdraw);
		void add_stock(Stock stock);
		void remove_stock(Stock stock);
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