#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <deque>
#include <iterator>

TEST_CASE("std::back_inserter supports writing forward") {
  std::deque<int> dq;
  auto back_instr = std::back_inserter(dq);
  *back_instr = 2; // 2
  ++back_instr;
  *back_instr = 4; // 2 4
  ++back_instr;

  auto front_instr = std::front_inserter(dq);
  *front_instr = 1; // 1 2 4
  ++front_instr;

  auto instr = std::inserter(dq, dq.begin() + 2);
  *instr = 3; // 1 2 3 4
  instr++;

  REQUIRE(dq[0] == 1);
  REQUIRE(dq[1] == 2);
  REQUIRE(dq[2] == 3);
  REQUIRE(dq[3] == 4);
}

#include <forward_list>

TEST_CASE("std::forward_list begin and end provide input iterators") {
  const std::forward_list<int> easy_as{ 1, 2, 3 };
  auto itr = easy_as.begin();
  REQUIRE(*itr == 1);
  itr++;
  REQUIRE(*itr == 2);
  itr++;
  REQUIRE(*itr == 3);
  itr++;
  REQUIRE(itr == easy_as.cend());
}

TEST_CASE("std::forward_list begin and end provide forward iterators") {
  const std::forward_list<int> easy_as{ 1, 2, 3 };
  auto itr1 = easy_as.begin();
  auto itr2{ itr1 };
  int double_sum{};
  while(itr1 != easy_as.cend())
    double_sum += *(itr1++);
  while(itr2 != easy_as.cend())
    double_sum += *(itr2++);
  REQUIRE(double_sum == 12);
}

#include <list>

TEST_CASE("std::list begin and end provide bidirectional iterators") {
  const std::list<int> easy_as{ 1, 2, 3 };
  auto itr = easy_as.begin();
  REQUIRE(*itr == 1);
  itr++;
  REQUIRE(*itr == 2);
  itr--;
  REQUIRE(*itr == 1);
  REQUIRE(itr == easy_as.cbegin());
}

#include <vector>

TEST_CASE("std::vector begin and end provide random-access iterators") {
  const std::vector<int> easy_as{ 1, 2, 3 };
  auto itr = easy_as.begin();
  REQUIRE(itr[0] == 1);
  itr++;
  REQUIRE(*(easy_as.cbegin() + 2) == 3);
  REQUIRE(easy_as.cend() - itr == 2);
}

#include <iterator>

TEST_CASE("advance modifies input iterators") {
  std::vector<unsigned char> mission{ 0x9e, 0xc4, 0xc1, 0x29, 0x49, 0xa4, 0xf3, 0x14,
                                      0x74, 0xf2, 0x99, 0x05, 0x8c, 0xe2, 0xb2, 0x2a };
  auto itr = mission.begin();
  std::advance(itr, 4);
  REQUIRE(*itr == 0x49);
  std::advance(itr, 4);
  REQUIRE(*itr == 0x74);
  std::advance(itr, -8);
  REQUIRE(*itr == 0x09e);
}

#include <iterator>

TEST_CASE("next returns iterators at given offsets") {
  std::vector<unsigned char> mission{ 0x9e, 0xc4, 0xc1, 0x29, 0x49, 0xa4, 0xf3, 0x14,
                                      0x74, 0xf2, 0x99, 0x05, 0x8c, 0xe2, 0xb2, 0x2a };
  auto itr1 = mission.begin();
  std::advance(itr1, 4);
  REQUIRE(*itr1 == 0x49);

  auto itr2 = std::next(itr1);
  REQUIRE(*itr2 == 0xa4);

  auto itr3 = std::next(itr1, 4);
  REQUIRE(*itr3 == 0x74);

  REQUIRE(*itr1 == 0x49);
}

#include <iterator>

TEST_CASE("distance returns the number of elements between iterators") {
  std::vector<unsigned char> mission{ 0x9e, 0xc4, 0xc1, 0x29, 0x49, 0xa4, 0xf3, 0x14,
                                      0x74, 0xf2, 0x99, 0x05, 0x8c, 0xe2, 0xb2, 0x2a };
  auto eighth = std::next(mission.begin(), 8);
  auto fourth = std::prev(eighth, 4);
  REQUIRE(std::distance(fourth, eighth) == 4);
}

#include <iterator>

TEST_CASE("iter_swap swaps pointed-to elements") {
  std::vector<long> easy_as{ 3, 2, 1 };
  std::iter_swap(easy_as.begin(), std::next(easy_as.begin(), 2));
  REQUIRE(easy_as[0] == 1);
  REQUIRE(easy_as[1] == 2);
  REQUIRE(easy_as[2] == 3);
}

#include <iterator>

struct Movable {
  Movable(int id)
      : id{ id } {}
  Movable(Movable&& m) {
    id = m.id;
    m.id = -1;
  }
  int id;
};

TEST_CASE("move iterators convert accesses into move operations") {
  std::vector<Movable> donor;
  donor.emplace_back(1);
  donor.emplace_back(2);
  donor.emplace_back(3);
  std::vector<Movable> recipient{
    std::make_move_iterator(donor.begin()),
    std::make_move_iterator(donor.end()),
  };
  REQUIRE(donor[0].id == -1);
  REQUIRE(donor[1].id == -1);
  REQUIRE(donor[2].id == -1);
  REQUIRE(recipient[0].id == 1);
  REQUIRE(recipient[1].id == 2);
  REQUIRE(recipient[2].id == 3);
}

TEST_CASE("reverse iterators can initialize containers") {
  std::list<int> original{ 3, 2, 1 };
  std::vector<int> easy_as{ original.crbegin(), original.crend() };

  REQUIRE(easy_as[0] == 1);
  REQUIRE(easy_as[1] == 2);
  REQUIRE(easy_as[2] == 3);
}

TEST_CASE("make_reverse_iterator converts a normal iterator") {
  std::list<int> original{ 3, 2, 1 };
  auto begin = std::make_reverse_iterator(original.cend());
  auto end = std::make_reverse_iterator(original.cbegin());
  std::vector<int> easy_as{ begin, end };
  REQUIRE(easy_as[0] == 1);
  REQUIRE(easy_as[1] == 2);
  REQUIRE(easy_as[2] == 3);
}
