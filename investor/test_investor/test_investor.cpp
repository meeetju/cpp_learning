#include "pch.h"
#include "CppUnitTest.h"
#include "..\stock_market.h"
#include "..\stock_market.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace testinvestor
{
	using namespace Market;

	TEST_CLASS(testinvestor)
	{
	public:
		
		TEST_METHOD(TestStockReportsProperPrice)
		{
			Stock intel("Intel");
			intel.set_price(49.1);
			Assert::AreEqual(49.1, intel.get_current_price());
		}

		TEST_METHOD(TestStockReportsProperName)
		{
			Stock intel("Intel");
			Assert::AreEqual(std::string("Intel"), intel.get_name());
		}

	};
}
