#define CATCH_CONFIG_MAIN
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <catch2/catch.hpp>

TEST_CASE("boost::property_tree::ptree stores tree data") {
  using namespace boost::property_tree;
  ptree p;
  p.put("name", "finfisher");
  p.put("year", 2014);
  p.put("features.process", "LSASS");
  p.put("features.driver", "mssounddx.sys");
  p.put("features.arch", 32);

  REQUIRE(p.get_child("year").get_value<int>() == 2014);

  const auto file_name = "my_config.json";
  write_json(file_name, p);

  ptree p_copy;
  read_json(file_name, p_copy);
  REQUIRE(p_copy == p);
}
