#define CATCH_CONFIG_MAIN
#include <array>
#include <catch2/catch.hpp>

std::array<int, 10> static_array;

TEST_CASE("std::array") {
  REQUIRE(static_array[0] == 0);

  SECTION("uninitialized without braced initializers") {
    std::array<int, 10> local_array;
    REQUIRE(local_array[0] != 0);
  }

  SECTION("initialized with braced initializers") {
    std::array<int, 10> local_array{ 1, 1, 2, 3 };
    REQUIRE(local_array[0] == 1);
    REQUIRE(local_array[1] == 1);
    REQUIRE(local_array[2] == 2);
    REQUIRE(local_array[3] == 3);
    REQUIRE(local_array[4] == 0);
  }
}

TEST_CASE("std::array access") {
  std::array<int, 4> fib{ 1, 1, 0, 3 };

  SECTION("operator[] can get and set elements") {
    fib[2] = 2;
    REQUIRE(fib[2] == 2);
  }

  SECTION("at() can get and set elements") {
    fib.at(2) = 2;
    REQUIRE(fib.at(2) == 2);
    REQUIRE_THROWS_AS(fib.at(4), std::out_of_range);
  }

  SECTION("get can get and set elements") {
    std::get<2>(fib) = 2;
    REQUIRE(std::get<2>(fib) == 2);
    // std::get<5>(fib);
  }
}

TEST_CASE("std::array has convenience methods") {
  std::array<int, 4> fib{ 0, 1, 2, 0 };

  SECTION("front") {
    fib.front() = 1;
    REQUIRE(fib.front() == 1);
    REQUIRE(fib.front() == fib[0]);
  }

  SECTION("back") {
    fib.back() = 3;
    REQUIRE(fib.back() == 3);
    REQUIRE(fib.back() == fib[3]);
  }
}

TEST_CASE("We can obtain a pointer to the first element using") {
  std::array<char, 9> color{ 'o', 'c', 't', 'a', 'r', 'i', 'n', 'e' };
  const auto* color_ptr = color.data();

  SECTION("data") {
    REQUIRE(*color_ptr == 'o');
  }

  SECTION("address-of front") {
    REQUIRE(&color.front() == color_ptr);
  }

  SECTION("address-of at(0)") {
    REQUIRE(&color.at(0) == color_ptr);
  }

  SECTION("address-of [0]") {
    REQUIRE(&color[0] == color_ptr);
  }
}

TEST_CASE("std::array begin/end form a half-open range") {
  std::array<int, 0> fib{};
  REQUIRE(fib.begin() == fib.end());
}

TEST_CASE("std::array iterators are pointer-like") {
  std::array<int, 3> easy_as{ 1, 2, 3 };
  auto iter = easy_as.begin();
  REQUIRE(*iter == 1);
  ++iter;
  REQUIRE(*iter == 2);
  ++iter;
  REQUIRE(*iter == 3);
  ++iter;
  REQUIRE(iter == easy_as.end());
}

TEST_CASE("std::array can be used in a range expression") {
  std::array<int, 5> fib{ 1, 1, 2, 3, 5 };
  int sum{};
  for(auto element : fib) {
    sum += element;
  }
  REQUIRE(sum == 12);
}

TEST_CASE("std::vector supports default construction") {
  std::vector<const char*> codebreakers;
  REQUIRE(codebreakers.empty());
}

TEST_CASE("std::vector supports") {
  SECTION("braced initialization") {
    std::vector<int> fib{ 1, 1, 2, 3, 5 };
    REQUIRE(fib[0] == 1);
  }
  SECTION("fill constructor") {
    std::vector<int> nines(5, 9);
    REQUIRE(nines[0] == 9);
    REQUIRE(nines[4] == 9);
  }
}

TEST_CASE("std::vector supports construction from iterators") {
  std::array<int, 5> fib_arr{ 1, 1, 2, 3, 5 };
  std::vector<int> fib_vec(fib_arr.begin(), fib_arr.end());
  REQUIRE(fib_vec[4] == 5);
  REQUIRE(fib_vec.size() == fib_arr.size());
}

TEST_CASE("std::vector assign replaces ") {
  std::vector<int> message{ 13, 80, 110, 114, 102, 110, 101 };
  REQUIRE(message.size() == 7);
  message.assign({ 67, 97, 101, 115, 97, 114 });
  REQUIRE(message[5] == 114);
  REQUIRE(message.size() == 6);
}

TEST_CASE("std::vector insert places new elements") {
  std::vector<int> zeros(3, 0);
  auto second_element = zeros.begin() + 2;
  zeros.insert(second_element, 10);
  REQUIRE(zeros[2] == 10);
  REQUIRE(zeros.size() == 4);
}

TEST_CASE("std::vector push_back places new elements") {
  std::vector<int> zeros(3, 0);
  zeros.push_back(10);
  REQUIRE(zeros[3] == 10);
}

#include <utility>

TEST_CASE("std::vector emplace methods forward arguments") {
  std::vector<std::pair<int, int>> factors;
  factors.emplace_back(2, 30);
  factors.emplace_back(3, 20);
  factors.emplace_back(4, 15);
  factors.emplace(factors.begin(), 1, 60);
  REQUIRE(factors[0].first == 1);
  REQUIRE(factors[0].second == 60);
}

// size capacity shrink_to_fit resize reserve max_size clear

TEST_CASE("std::vector exposes size management methods") {
  std::vector<std::array<char, 1024>> kb_store;
  REQUIRE(kb_store.empty());
  REQUIRE(kb_store.max_size() > 0);

  size_t elements{ 1024 };
  kb_store.reserve(elements);
  REQUIRE(kb_store.empty());
  REQUIRE(kb_store.capacity() == elements);

  kb_store.emplace_back();
  kb_store.emplace_back();
  kb_store.emplace_back();
  REQUIRE(kb_store.size() == 3);

  kb_store.shrink_to_fit();
  REQUIRE(kb_store.capacity() == 3);

  kb_store.clear();
  REQUIRE(kb_store.empty());
  REQUIRE(kb_store.size() == 0);
  REQUIRE(kb_store.capacity() == 3);
}

#include <deque>

TEST_CASE("std::deque supports front insertion") {
  std::deque<char> deckard;
  deckard.push_front('a'); //  a
  deckard.push_back('i'); //  ai
  deckard.push_front('c'); // cai
  deckard.push_back('n'); // cain
  REQUIRE(deckard[0] == 'c');
  REQUIRE(deckard[1] == 'a');
  REQUIRE(deckard[2] == 'i');
  REQUIRE(deckard[3] == 'n');
}

#include <list>

TEST_CASE("std::list supports front insertion") {
  std::list<int> odds{ 11, 22, 33, 44, 55 };
  odds.remove_if([](int x) { return x % 2 == 0; });
  auto odds_iter = odds.begin();
  REQUIRE(*odds_iter == 11);
  ++odds_iter;
  REQUIRE(*odds_iter == 33);
  ++odds_iter;
  REQUIRE(*odds_iter == 55);
  ++odds_iter;
  REQUIRE(odds_iter == odds.end());
}

#include <stack>

TEST_CASE("std::stack supports push/pop") {
  std::vector<int> vec{ 1, 3 };
  std::stack<int, decltype(vec)> easy_as(vec);

  REQUIRE(easy_as.top() == 3);
  easy_as.pop();
  easy_as.push(2);
  REQUIRE(easy_as.top() == 2);
  easy_as.pop();
  REQUIRE(easy_as.top() == 1);
  easy_as.pop();
  REQUIRE(easy_as.empty());
}

#include <queue>

TEST_CASE("std::queue supports push/pop") {
  std::deque<int> deq{ 1, 2 };
  std::queue<int> easy_as(deq); // 1 2

  REQUIRE(easy_as.front() == 1);
  REQUIRE(easy_as.back() == 2);
  easy_as.pop(); // 2
  easy_as.push(3); // 2 3
  REQUIRE(easy_as.front() == 2);
  REQUIRE(easy_as.back() == 3);
  easy_as.pop(); // 3
  REQUIRE(easy_as.front() == 3);
  easy_as.pop(); //
  REQUIRE(easy_as.empty());
}

#include <queue>

TEST_CASE("std::priority_queue supports push/pop") {
  std::priority_queue<double> prique;
  prique.push(1.0); // 1.0
  prique.push(2.0); // 2.0 1.0
  prique.push(1.5); // 2.0 1.5 1.0

  REQUIRE(prique.top() == Approx(2.0));
  prique.pop(); // 1.5 1.0
  prique.push(1.0); // 1.5 1.0 1.0
  REQUIRE(prique.top() == Approx(1.5));
  prique.pop(); // 1.0 1.0
  REQUIRE(prique.top() == Approx(1.0));
  prique.pop(); // 1.0
  REQUIRE(prique.top() == Approx(1.0));
  prique.pop(); //
  REQUIRE(prique.empty());
}

#include <bitset>

TEST_CASE("std::bitset supports integer initialization") {
  std::bitset<4> bs(0b0101);
  REQUIRE(bs[0] == true);
  REQUIRE(bs[1] == false);
  REQUIRE(bs[2] == true);
  REQUIRE(bs[3] == false);
}

TEST_CASE("std::bitset supports string initialization") {
  std::bitset<4> bs1(0b0101);
  std::bitset<4> bs2("0101");
  REQUIRE(bs1 == bs2);
}

#include <initializer_list>

TEST_CASE("std::initializer_list supports") {
  auto fib = { 1, 1, 2, 3, 5 };
  SECTION("size") {
    REQUIRE(fib.size() == 5);
  }
  SECTION("begin and end") {
    int sum{};
    for(auto val : fib)
      sum += val;
    REQUIRE(sum == 12);
  }
}

#include <cmath>

size_t square_root(size_t x) {
  auto result = static_cast<size_t>(sqrt(x));
  if(result * result != x)
    throw std::logic_error{ "Not a perfect square." };
  return result;
}

template <typename T>
struct SquareMatrix {
  constexpr SquareMatrix(std::initializer_list<T> val)
      : dim{ square_root(val.size()) }
      , data(dim, std::vector<T>{}) {
    auto itr = val.begin();
    for(size_t row{}; row < dim; row++) {
      data[row].assign(itr, itr + dim);
      itr += dim;
    }
  }
  T& get(size_t row, size_t col) {
    if(row >= dim || col >= dim)
      throw std::out_of_range{ "Index out of range." };
    return data[row][col];
  }
  const size_t dim;

  private:
  std::vector<std::vector<T>> data;
};

TEST_CASE("SquareMatrix and std::initializer_list") {
  SquareMatrix<int> mat{ 1, 2, 3, 4, 5, 0, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  REQUIRE(mat.dim == 4);
  mat.get(1, 1) = 6;
  REQUIRE(mat.get(1, 1) == 6);
  REQUIRE(mat.get(0, 2) == 3);
}
