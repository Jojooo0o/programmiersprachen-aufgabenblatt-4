#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"

//A1
	TEST_CASE("describe_list", "[list_a1]"){

		List<int> l1;

		REQUIRE(l1.size() == 0);
		REQUIRE(l1.empty());
	}
//A2
	TEST_CASE("describe_list_pushfront", "[list pushfront]"){
		List<int> list;
		list.push_front(42);
		REQUIRE(list.front() == 42);
	}

	TEST_CASE("describe_list_pushback", "[list pushback]"){
		List<int> list;
		list.push_back(4);
		REQUIRE(list.back() == 4);
	}

	TEST_CASE("describe_list_popfront", "[list popfront]"){
		List<int> list;
		list.push_front(42);
		list.push_front(12);
		list.pop_front();
		REQUIRE(list.front() == 42);
	}

	TEST_CASE("describe_list_popback", "[list popback]"){
		List<int> list;
		list.push_back(4);
		list.push_back(42);
		list.pop_back();
		REQUIRE(list.back() == 4);
	}
//A3
	TEST_CASE("describe_list_clear", "[list clear]"){
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		list.clear();

		REQUIRE(list.empty());
	}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
