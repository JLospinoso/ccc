#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>

TEST_CASE("boost::gregorian::date default-constructs to not_a_date_time") {
  boost::gregorian::date d;
  REQUIRE(d.as_special() == boost::gregorian::not_a_date_time);
}

TEST_CASE("Can use from_string to parse date") {
  boost::gregorian::date d1{ 1986, 9, 15 };
  auto d2 = boost::gregorian::from_string("1986/9/15");
  REQUIRE(d1 == d2);
}

TEST_CASE("Invalid dates throw exceptions") {
  using boost::gregorian::bad_day_of_month;
  using boost::gregorian::date;

  REQUIRE_THROWS_AS(date(1986, 9, 32), bad_day_of_month);
}

TEST_CASE("Can obtain local date") {
  auto d_local = boost::gregorian::day_clock::local_day();
  auto d_univ = boost::gregorian::day_clock::universal_day();
}

TEST_CASE("DateTime supports basic calendar functions") {
  boost::gregorian::date d{ 1986, 9, 15 };
  REQUIRE(d.year() == 1986);
  REQUIRE(d.month() == 9);
  REQUIRE(d.day() == 15);
  REQUIRE(d.day_of_year() == 258);
  REQUIRE(d.day_of_week() == boost::date_time::Monday);
}

TEST_CASE("date supports subtraction") {
  boost::gregorian::date d1{ 1986, 9, 15 };
  boost::gregorian::date d2{ 2019, 8, 1 };
  auto duration = d2 - d1;
  REQUIRE(duration.days() == 12008);
}

TEST_CASE("date and date_duration support addition") {
  boost::gregorian::date d1{ 1986, 9, 15 };
  boost::gregorian::date_duration dur{ 12008 };
  auto d2 = d1 + dur;
  REQUIRE(d2 == boost::gregorian::from_string("2019/8/1"));
}

TEST_CASE("DateTime supports periods") {
  boost::gregorian::date d1{ 1986, 9, 15 };
  boost::gregorian::date d2{ 2018, 1, 19 };
  boost::gregorian::date_period p{ d1, d2 };
  REQUIRE(p.contains(boost::gregorian::date{ 1987, 10, 27 }));
}

#include <chrono>
#include <thread>

TEST_CASE("chrono supports several units of measurement") {
  using namespace std::literals::chrono_literals;
  auto one_s = std::chrono::seconds(1);
  auto thousand_ms = 1000ms;

  REQUIRE(one_s == thousand_ms);
}

TEST_CASE("chrono supports duration_cast") {
  using namespace std::chrono;
  auto million_ns_as_s = duration_cast<seconds>(1'000'000'000ns);
  REQUIRE(million_ns_as_s.count() == 1);
}

TEST_CASE("chrono supports several clocks") {
  auto sys_now = std::chrono::system_clock::now();
  REQUIRE(sys_now.time_since_epoch().count() > 0);

  auto hires_now = std::chrono::high_resolution_clock::now();
  REQUIRE(hires_now.time_since_epoch().count() > 0);

  auto steady_now = std::chrono::steady_clock::now();
  REQUIRE(steady_now.time_since_epoch().count() > 0);
}

TEST_CASE("chrono used to sleep") {
  using namespace std::literals::chrono_literals;
  auto start = std::chrono::system_clock::now();
  std::this_thread::sleep_for(100ms);
  auto end = std::chrono::system_clock::now();
  REQUIRE(end - start >= 100ms);
}

#include <chrono>
#include <cstdio>

struct Stopwatch {
  Stopwatch(std::chrono::nanoseconds& result)
      : result{ result }
      , start{ std::chrono::system_clock::now() } {}
  ~Stopwatch() {
    result = std::chrono::system_clock::now() - start;
  }

  private:
  std::chrono::nanoseconds& result;
  const std::chrono::time_point<std::chrono::system_clock> start;
};
/*
int main() {
  const size_t n = 100'000'000;
  std::chrono::nanoseconds elapsed;
  {
    Stopwatch stopwatch{ elapsed };
    volatile double result{ 1.23e45 };
    for (double i = 1; i < n; i++) {
      result /= i;
    }
  }
  auto time_per_addition = elapsed.count() / double{ n };
  printf("Took %gns per division.", time_per_addition);
}
*/