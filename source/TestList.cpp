#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"


TEST_CASE("describe_list", "[list_a1]"){

	List<int> l1;

	REQUIRE(l1.size() == 0);
	REQUIRE(l1.empty());
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
