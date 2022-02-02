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

    intel.buy(10);

    intel.set_price(50.0);
    tesla.set_price(700.0); 
    netflix.set_price(600.0);

    intel.buy(10);
    tesla.buy(5);
    netflix.buy(10);
    intel.buy(20);


    Wallet standard(wallet_type::STANDARD);

    standard.add_stock(intel);
    standard.add_stock(tesla);
    standard.add_stock(netflix);
    standard.add_stock(tesla);

    standard.get_ballance();

    standard.remove_stock(tesla);

    standard.get_ballance();
}

