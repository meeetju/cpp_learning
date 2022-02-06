#include "pch.h"
#include "..\stock_market.h"
#include "..\stock_market.cpp"
#include <string>

using namespace Market;

TEST(TestStock, TestStockReportsProperPrice) {

	Stock intel("Intel");
	intel.set_price(49.1);
  
	EXPECT_EQ(49.1, intel.get_current_price());
}

TEST(TestStock, TestStockReportsProperName) {

	Stock intel("Intel");

	EXPECT_EQ("Intel", intel.get_name());
}