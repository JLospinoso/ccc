#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>
#include <set>

TEST_CASE("std::set supports") {
  std::set<int> emp;
  std::set<int> fib{ 1, 1, 2, 3, 5 };
  SECTION("default construction") {
    REQUIRE(emp.empty());
  }
  SECTION("braced initialization") {
    REQUIRE(fib.size() == 4);
  }
  SECTION("copy construction") {
    auto fib_copy(fib);
    REQUIRE(fib.size() == 4);
    REQUIRE(fib_copy.size() == 4);
  }
  SECTION("move construction") {
    auto fib_moved(std::move(fib));
    REQUIRE(fib.empty());
    REQUIRE(fib_moved.size() == 4);
  }
  SECTION("range construction") {
    std::array<int, 5> fib_array{ 1, 1, 2, 3, 5 };
    std::set<int> fib_set(fib_array.cbegin(), fib_array.cend());
    REQUIRE(fib_set.size() == 4);
  }
}

TEST_CASE("std::set allows access") {
  std::set<int> fib{ 1, 1, 2, 3, 5 };
  SECTION("with find") {
    REQUIRE(*fib.find(3) == 3);
    REQUIRE(fib.find(100) == fib.end());
  }
  SECTION("with count") {
    REQUIRE(fib.count(3) == 1);
    REQUIRE(fib.count(100) == 0);
  }
  SECTION("with equal_range") {
    auto pair_itr = fib.equal_range(3);
    REQUIRE(*pair_itr.first == 3);
    REQUIRE(*pair_itr.second == 5);
  }
  SECTION("with lower_bound") {
    auto itr = fib.lower_bound(3);
    REQUIRE(*itr == 3);
  }
  SECTION("with upper_bound") {
    auto itr = fib.upper_bound(3);
    REQUIRE(*itr == 5);
  }
}

TEST_CASE("std::set allows insertion") {
  std::set<int> fib{ 1, 1, 2, 3, 5 };
  SECTION("with insert") {
    fib.insert(8);
    REQUIRE(fib.find(8) != fib.end());
  }
  SECTION("with emplace") {
    fib.emplace(8);
    REQUIRE(fib.find(8) != fib.end());
  }
  SECTION("with emplace_hint") {
    fib.emplace_hint(fib.end(), 8);
    REQUIRE(fib.find(8) != fib.end());
  }
}

TEST_CASE("std::set allows removal") {
  std::set<int> fib{ 1, 1, 2, 3, 5 };
  SECTION("with erase") {
    fib.erase(3);
    REQUIRE(fib.find(3) == fib.end());
  }
  SECTION("with clear") {
    fib.clear();
    REQUIRE(fib.empty());
  }
}

TEST_CASE("std::multiset handles non-unique elements") {
  std::multiset<int> fib{ 1, 1, 2, 3, 5 };
  SECTION("and count returns values greater than 1") {
    REQUIRE(fib.count(1) == 2);
  }
  SECTION("and equal_range returns non-trivial ranges") {
    auto [begin, end] = fib.equal_range(1);
    REQUIRE(*begin == 1);
    ++begin;
    REQUIRE(*begin == 1);
    ++begin;
    REQUIRE(begin == end);
  }
}

#include <functional>

TEST_CASE("std::hash<long> returns") {
  std::hash<long> hasher;
  auto hash_code_42 = hasher(42);
  SECTION("equal hash codes for equal keys") {
    REQUIRE(hash_code_42 == hasher(42));
  }
  SECTION("unequal hash codes for unequal keys") {
    REQUIRE(hash_code_42 != hasher(43));
  }
}

TEST_CASE("std::equal_to<long> returns") {
  std::equal_to<long> long_equal_to;
  SECTION("true when arguments equal") {
    REQUIRE(long_equal_to(42, 42));
  }
  SECTION("false when arguments unequal") {
    REQUIRE_FALSE(long_equal_to(42, 43));
  }
}

#include <unordered_set>

TEST_CASE("std::unordered_set") {
  std::unordered_set<unsigned long> sheep(100);
  SECTION("allows bucket count specification on construction") {
    REQUIRE(sheep.bucket_count() >= 100);
    REQUIRE(sheep.bucket_count() <= sheep.max_bucket_count());
    REQUIRE(sheep.max_load_factor() == Approx(1.0));
  }
  SECTION("allows reservation") {
    sheep.reserve(100'000);
    sheep.insert(0);
    REQUIRE(sheep.load_factor() <= 0.00001);

    while(sheep.size() < 100'000)
      sheep.insert(sheep.size());
    REQUIRE(sheep.load_factor() <= 1.0);
  }
}

#include <map>

auto colour_of_magic = "Colour of Magic";
auto the_light_fantastic = "The Light Fantastic";
auto equal_rites = "Equal Rites";
auto mort = "Mort";

TEST_CASE("std::map supports") {
  SECTION("default construction") {
    std::map<const char*, int> emp;
    REQUIRE(emp.empty());
  }
  SECTION("braced initialization") {
    std::map<const char*, int> pub_year{
      { colour_of_magic, 1983 },
      { the_light_fantastic, 1986 },
      { equal_rites, 1987 },
      { mort, 1987 },
    };
    REQUIRE(pub_year.size() == 4);
  }
}

TEST_CASE("std::map is an associative array with") {
  std::map<const char*, int> pub_year{
    { colour_of_magic, 1983 },
    { the_light_fantastic, 1986 },
  };

  SECTION("operator[]") {
    REQUIRE(pub_year[colour_of_magic] == 1983);

    pub_year[equal_rites] = 1987;
    REQUIRE(pub_year[equal_rites] == 1987);

    REQUIRE(pub_year[mort] == 0);
  }

  SECTION("an at method") {
    REQUIRE(pub_year.at(colour_of_magic) == 1983);

    REQUIRE_THROWS_AS(pub_year.at(equal_rites), std::out_of_range);
  }
}

TEST_CASE("std::map supports insert") {
  std::map<const char*, int> pub_year;
  pub_year.insert({ colour_of_magic, 1983 });
  REQUIRE(pub_year.size() == 1);

  std::pair<const char*, int> tlfp{ the_light_fantastic, 1986 };
  pub_year.insert(tlfp);
  REQUIRE(pub_year.size() == 2);

  auto [itr, success] = pub_year.insert({ the_light_fantastic, 9999 });
  REQUIRE(itr->first == the_light_fantastic);
  REQUIRE(itr->second == 1986);
  REQUIRE_FALSE(success);
  REQUIRE(pub_year.size() == 2);
}

TEST_CASE("std::map supports insert_or_assign") {
  std::map<const char*, int> pub_year{ { the_light_fantastic, 9999 } };
  auto [itr, inserted] = pub_year.insert_or_assign(the_light_fantastic, 1986);
  REQUIRE(itr->second == 1986);
  REQUIRE_FALSE(inserted);
}

TEST_CASE("We can remove std::map elements using") {
  std::map<const char*, int> pub_year{
    { colour_of_magic, 1983 },
    { the_light_fantastic, 1986 },
    { equal_rites, 1987 },
    { mort, 1987 },
  };
  SECTION("erase") {
    pub_year.erase(mort);
    REQUIRE(pub_year.find(mort) == pub_year.end());
  }
  SECTION("clear") {
    pub_year.clear();
    REQUIRE(pub_year.empty());
  }
}

TEST_CASE("std::multimap supports non-unique keys") {
  std::array<char, 64> far_out{ "Far out in the uncharted backwaters of the unfashionable end..." };
  std::multimap<char, size_t> indices;
  for(size_t index{}; index < far_out.size(); index++)
    indices.emplace(far_out[index], index);

  REQUIRE(indices.count('a') == 6);

  auto [itr, end] = indices.equal_range('d');
  REQUIRE(itr->second == 23);
  itr++;
  REQUIRE(itr->second == 59);
  itr++;
  REQUIRE(itr == end);
}
