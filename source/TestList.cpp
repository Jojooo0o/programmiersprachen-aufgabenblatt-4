#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"
#include <vector>
#include <algorithm>

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

//A5
	TEST_CASE("should be an empty range after default construction", "[iterators]"){
		List<int> list;
		auto b = list.begin();
		auto e = list.end();

		REQUIRE(b == e);
	}

	TEST_CASE("provide access to the first element with begin", "[iterators]"){
		List<int> list;
		list.push_front(42);
		REQUIRE(*list.begin() == 42);
	}
//A7
	TEST_CASE("copy constructor", "[constructor]"){
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		List<int> list2{list};
		REQUIRE(list == list2);
	}
//A8
	TEST_CASE("insert", "[insert]"){
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);

		auto it = list.begin();
		++it;
		list.insert(it, 5);

		for(auto iterator = list.begin(); iterator != list.end(); ++iterator){
			std::cout << *iterator << std::endl;
		}
	}
//A9
	TEST_CASE("reverse", "[reverse]"){
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);

		List<int> list2 {list};
		list2.reverse();

		//auto list2 = reverse(list);
		auto list3 = reverse(list2);

		REQUIRE(list == list3);
	}

//A10
/*	TEST_CASE("copy list to vector", "[copy vector]"){
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);

		std::vector<int> v1;

		std::copy(list.begin(), list.end(), v1.begin());
	}
*/
//A12
	TEST_CASE("move constructor", "[constructor]"){
		List<int> list;
		list.push_front(1);
		list.push_front(1);
		list.push_front(1);
		list.push_front(1);

		List<int> list2(std::move(list));

		REQUIRE(0 == list.size());
		REQUIRE(list.empty());
		REQUIRE(4 == list2.size());
	}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
