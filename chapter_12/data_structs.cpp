#define CATCH_CONFIG_MAIN
#include <boost/logic/tribool.hpp>
#include <catch2/catch.hpp>

using boost::logic::indeterminate;
boost::logic::tribool t = true, f = false, i = indeterminate;

TEST_CASE("Boost tribool converts to bool") {
  REQUIRE(t);
  REQUIRE(!f);
  REQUIRE(indeterminate(i));
  REQUIRE_FALSE(!t);
  REQUIRE_FALSE(f);
  REQUIRE_FALSE(indeterminate(t));
}

TEST_CASE("Boost Tribool supports Boolean operations") {
  auto t_or_f = t || f;
  REQUIRE(t_or_f);
  REQUIRE(indeterminate(t && indeterminate));
  REQUIRE(indeterminate(f || indeterminate));
  REQUIRE(indeterminate(!i));
}

#include <optional>

struct TheMatrix {
  TheMatrix(int x)
      : iteration{ x } {}
  const int iteration;
};

enum Pill { Red, Blue };

std::optional<TheMatrix> take(Pill pill) {
  if(pill == Pill::Blue)
    return TheMatrix{ 6 };
  return {};
}

TEST_CASE("std::optional") {
  SECTION("contains types") {
    if(auto matrix_opt = take(Pill::Blue)) {
      REQUIRE(matrix_opt->iteration == 6);

      auto& matrix = matrix_opt.value();
      REQUIRE(matrix.iteration == 6);

      REQUIRE(matrix_opt.has_value());
    } else {
      FAIL();
    }
  }

  SECTION("can be empty") {
    auto matrix_opt = take(Pill::Red);
    if(matrix_opt)
      FAIL();
    REQUIRE_FALSE(matrix_opt.has_value());
  }
}

#include <utility>

struct Socialite {
  const char* birthname;
};
struct Valet {
  const char* surname;
};

TEST_CASE("std::pair") {
  Socialite bertie{ "Wilberforce" };
  Valet reginald{ "Jeeves" };
  std::pair<Socialite, Valet> inimitable_duo{ bertie, reginald };
  SECTION("permits access to members") {
    REQUIRE(inimitable_duo.first.birthname == bertie.birthname);
    REQUIRE(inimitable_duo.second.surname == reginald.surname);
  }
  SECTION("works with structured binding") {
    //auto& [a, b] = inimitable_duo;
    //REQUIRE(a.first.birthname == bertie.birthname);
    //REQUIRE(b.second.surname == jeeves.surname);
  }
}

#include <tuple>

struct Acquaintance {
  const char* nickname;
};
using Trio = std::tuple<Socialite, Valet, Acquaintance>;
TEST_CASE("std::tuple permits access to members") {
  Socialite bertie{ "Wilberforce" };
  Valet reginald{ "Jeeves" };
  Acquaintance hildebrand{ "Tuppy" };
  Trio truculent_trio{ bertie, reginald, hildebrand };
  auto& bertie_ref = std::get<0>(truculent_trio);
  REQUIRE(bertie_ref.birthname == bertie.birthname);

  auto& tuppy_ref = std::get<Acquaintance>(truculent_trio);
  REQUIRE(tuppy_ref.nickname == hildebrand.nickname);
}

#include <any>
struct EscapeCapsule {
  EscapeCapsule(int x)
      : id{ x } {}
  int id;
};

TEST_CASE("std::any") {
  std::any hagunemnon;
  hagunemnon.emplace<EscapeCapsule>(60);
  auto capsule = std::any_cast<EscapeCapsule>(hagunemnon);
  REQUIRE(capsule.id == 60);
  REQUIRE_THROWS_AS(std::any_cast<float>(hagunemnon), std::bad_any_cast);
}

#include <variant>

struct BugblatterBeast {
  BugblatterBeast()
      : is_ravenous{ true }
      , id{ 42 } {}
  bool is_ravenous;
  int id;
};

// Can only default construct if the first alternative is default constructibel).
TEST_CASE("std::variant") {
  std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
  REQUIRE(hagunemnon.index() == 0);
  hagunemnon.emplace<EscapeCapsule>(60);

  REQUIRE(std::get<1>(hagunemnon).id == 60);
  REQUIRE(std::get<EscapeCapsule>(hagunemnon).id == 60);

  REQUIRE_THROWS_AS(std::get<0>(hagunemnon), std::bad_variant_access);
  if(auto bugblat_ptr = std::get_if<0>(&hagunemnon))
    FAIL();

  auto id = std::visit([](auto& x) { return x.id; }, hagunemnon);
  REQUIRE(id == 60);
}
