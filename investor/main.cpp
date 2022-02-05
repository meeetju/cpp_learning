#include "stock_market.h"
#include "investor.h"
#include <iostream>

using namespace Market;
using namespace Investor;

int main()
{
    Stock intel("Intel");
    Stock tesla("Tesla");
    Stock netflix("Netflix");


    intel.set_price(50.0);
    tesla.set_price(700.0); 
    netflix.set_price(600.0);

    Wallet standard(wallet_type::STANDARD);

    standard.buy_stock(&intel, 10);
    standard.buy_stock(&intel, 20);
    standard.buy_stock(&netflix, 6);

    standard.get_ballance();

    standard.sell_stock(&tesla, 6);

    standard.sell_stock(&intel, 5);
    standard.get_ballance();

    standard.sell_stock(&intel, 20);
    standard.get_ballance();

    standard.sell_stock(&intel, 5);
    standard.get_ballance();

}

