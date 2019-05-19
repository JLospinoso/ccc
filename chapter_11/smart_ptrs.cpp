#define CATCH_CONFIG_MAIN
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <catch2/catch.hpp>
#include <utility>

struct DeadMenOfDunharrow {
  DeadMenOfDunharrow(const char* m = "")
      : message{ m } {
    oaths_to_fulfill++;
  }
  ~DeadMenOfDunharrow() {
    oaths_to_fulfill--;
  }
  const char* message;
  static int oaths_to_fulfill;
};
int DeadMenOfDunharrow::oaths_to_fulfill{};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr evaluates to ") {
  SECTION("true when full") {
    ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
    REQUIRE(aragorn);
  }
  SECTION("false when empty") {
    ScopedOathbreakers aragorn;
    REQUIRE_FALSE(aragorn);
  }
}

TEST_CASE("ScopedPtr is an RAII wrapper.") {
  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  {
    ScopedOathbreakers legolas{ new DeadMenOfDunharrow };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
  }
  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}

TEST_CASE("ScopedPtr.reset() ") {
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
  SECTION("destructs object.") {
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    aragorn.reset();
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
  }
  SECTION("can replace an object.") {
    auto message = "It was made by those who are Dead.";
    auto new_dead_men = new DeadMenOfDunharrow{ message };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
    aragorn.reset(new_dead_men);
    REQUIRE(aragorn->message == message);
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
}

TEST_CASE("ScopedPtr supports pointer semantics, like") {
  auto message = "The way is shut.";
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{ message } };
  SECTION("operator*") {
    REQUIRE((*aragorn).message == message);
  }
  SECTION("operator->") {
    REQUIRE(aragorn->message == message);
  }
  SECTION("get(), which returns a raw pointer") {
    REQUIRE(aragorn.get() != nullptr);
  }
}

TEST_CASE("ScopedPtr supports comparison with nullptr") {
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
  ScopedOathbreakers legolas{};
  SECTION("operator==") {
    REQUIRE(legolas == nullptr);
  }
  SECTION("operator!=") {
    REQUIRE(aragorn != nullptr);
  }
}

TEST_CASE("ScopedPtr supports swap") {
  auto message1 = "The way is shut.";
  auto message2 = "Until the time comes.";
  ScopedOathbreakers aragorn1{ new DeadMenOfDunharrow{ message1 } };
  ScopedOathbreakers aragorn2{ new DeadMenOfDunharrow{ message2 } };
  REQUIRE(aragorn1->message == message1);
  aragorn1.swap(aragorn2);
  REQUIRE(aragorn2->message == message1);
  REQUIRE(aragorn1->message == message2);
}

void by_ref(const ScopedOathbreakers&) {}
void by_val(ScopedOathbreakers) {}
TEST_CASE("ScopedPtr can") {
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
  SECTION("be passed by reference") {
    by_ref(aragorn);
  }
  SECTION("not be copied") {
    // DOES NOT COMPILE:
    // by_val(aragorn);
    // auto son_of_arathorn = aragorn;
  }
  SECTION("not be moved") {
    // DOES NOT COMPILE:
    // by_val(std::move(aragorn));
    // auto son_of_arathorn = std::move(aragorn);
  }
}

#include <boost/smart_ptr/scoped_array.hpp>

TEST_CASE("ScopedArray supports operator[]") {
  boost::scoped_array<int> squares{ new int[5]{ 1, 4, 9, 16, 25 } };
  REQUIRE(squares[0] == 1);
  REQUIRE(squares[1] == 4);
  REQUIRE(squares[2] == 9);
}

#include <memory>

using UniqueOathbreakers = std::unique_ptr<DeadMenOfDunharrow>;

TEST_CASE("UniquePtr can be used in move") {
  auto aragorn = std::make_unique<DeadMenOfDunharrow>();
  SECTION("construction") {
    auto son_of_arathorn{ std::move(aragorn) };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
  SECTION("assignment") {
    auto son_of_arathorn = std::make_unique<DeadMenOfDunharrow>();
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
    son_of_arathorn = std::move(aragorn);
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
}

TEST_CASE("UniquePtr to array supports operator[]") {
  std::unique_ptr<int[]> squares{ new int[5]{ 1, 4, 9, 16, 25 } };
  REQUIRE(squares[0] == 1);
  REQUIRE(squares[1] == 4);
  REQUIRE(squares[2] == 9);
}

auto my_deleter = [](int* x) { /* ... */ };
std::unique_ptr<int, decltype(my_deleter)> my_up{ new int, my_deleter };

std::shared_ptr<int> sh_ptr{ new int{ 10 }, [](int* x) { delete x; }, std::allocator<int>{} };
auto sh_ptr1 = std::allocate_shared<int>(std::allocator<int>{}, 10);

using SharedOathbreakers = std::shared_ptr<DeadMenOfDunharrow>;

TEST_CASE("SharedPtr can be used in copy") {
  auto aragorn = std::make_shared<DeadMenOfDunharrow>();
  SECTION("construction") {
    auto son_of_arathorn{ aragorn };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
  SECTION("assignment") {
    SharedOathbreakers son_of_arathorn;
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    son_of_arathorn = aragorn;
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
  SECTION("assignment, and original gets discarded") {
    auto son_of_arathorn = std::make_shared<DeadMenOfDunharrow>();
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
    son_of_arathorn = aragorn;
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
}

using WeakOathbreakers = std::weak_ptr<DeadMenOfDunharrow>;

TEST_CASE("WeakPtr") {
  auto message = "The way is shut.";
  SECTION("lock() yields a shared pointer") {
    auto aragorn = std::make_shared<DeadMenOfDunharrow>(message);
    WeakOathbreakers legolas{ aragorn };
    auto sh_ptr = legolas.lock();
    REQUIRE(sh_ptr->message == message);
    REQUIRE(sh_ptr.use_count() == 2);
  }
  SECTION("lock() yields empty when shared pointer empty") {
    WeakOathbreakers legolas;
    {
      auto aragorn = std::make_shared<DeadMenOfDunharrow>(message);
      legolas = aragorn;
    }
    auto sh_ptr = legolas.lock();
    REQUIRE(sh_ptr == nullptr);
  }
}

#include <boost/smart_ptr/intrusive_ptr.hpp>

using IntrusivePtr = boost::intrusive_ptr<DeadMenOfDunharrow>;

size_t ref_count{};
void intrusive_ptr_add_ref(DeadMenOfDunharrow* d) {
  ref_count++;
}

void intrusive_ptr_release(DeadMenOfDunharrow* d) {
  ref_count--;
  if(ref_count == 0)
    delete d;
}

TEST_CASE("IntrusivePtr") {
  REQUIRE(ref_count == 0);
  IntrusivePtr aragorn{ new DeadMenOfDunharrow };
  REQUIRE(ref_count == 1);
  {
    IntrusivePtr legolas{ aragorn };
    REQUIRE(ref_count == 2);
  }
  REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}

static size_t n_allocated;
static size_t n_deallocated;

template <typename T>
struct MyAllocator {
  using value_type = T;

  MyAllocator() noexcept = default;
  template <typename U>
  MyAllocator(const MyAllocator<U>&) noexcept {}

  T* allocate(size_t n) {
    auto p = operator new(sizeof(T) * n);
    ++n_allocated;
    return static_cast<T*>(p);
  }

  void deallocate(T* p, size_t n) {
    operator delete(p);
    ++n_deallocated;
  }
};

template <typename T1, typename T2>
bool operator==(const MyAllocator<T1>&, const MyAllocator<T2>&) {
  return true;
}

template <typename T1, typename T2>
bool operator!=(const MyAllocator<T1>&, const MyAllocator<T2>&) {
  return false;
}

TEST_CASE("Allocator") {
  auto message = "The way is shut.";
  MyAllocator<DeadMenOfDunharrow> my_alloc;
  {
    auto aragorn = std::allocate_shared<DeadMenOfDunharrow>(my_alloc, message);
    REQUIRE(aragorn->message == message);
    REQUIRE(n_allocated == 1);
    REQUIRE(n_deallocated == 0);
  }
  REQUIRE(n_allocated == 1);
  REQUIRE(n_deallocated == 1);
}

#include <cstdio>

using FileGuard = std::shared_ptr<FILE>;

void say_hello(FileGuard file) {
  fprintf(file.get(), "HELLO DAVE");
}

int main22() {
  auto file = fopen("HAL9000", "w");
  if(!file)
    return errno;
  FileGuard file_guard{ file, fclose };
  // File open here
  say_hello(std::move(file_guard));
  // File closed here
  return 0;
}
