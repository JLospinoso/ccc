#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>

TEST_CASE("std::string supports constructing") {
  SECTION("empty strings") {
    std::string cheese;
    REQUIRE(cheese.empty());
  }
  SECTION("repeated characters") {
    std::string roadside_assistance(3, 'A');
    REQUIRE(roadside_assistance == "AAA");
  }
}

TEST_CASE("std::string supports constructing from C-string") {
  auto word{ "gobbledygook" };
  REQUIRE(std::string(word) == "gobbledygook");
  REQUIRE(std::string(word, 6) == "gobble");
}

TEST_CASE("std::string supports") {
  std::string word("catawampus");
  SECTION("copy constructing") {
    REQUIRE(std::string(word) == "catawampus");
  }
  SECTION("move constructing") {
    REQUIRE(std::string(move(word)) == "catawampus");
  }
  SECTION("constructing from substrings") {
    REQUIRE(std::string(word, 0, 3) == "cat");
    REQUIRE(std::string(word, 4) == "wampus");
  }
}

TEST_CASE("constructing a string with") {
  SECTION("std::string(char*) stops at embedded nulls") {
    std::string str("idioglossia\0ellohay!");
    REQUIRE(str.length() == 11);
  }
  SECTION("operator\"\"s incorporates embedded nulls") {
    using namespace std::string_literals;
    auto str_lit = "idioglossia\0ellohay!"s;
    REQUIRE(str_lit.length() == 20);
  }
}

TEST_CASE("string's c_str method makes null-terminated strings") {
  std::string word{ "horripilation" };
  auto as_cstr = word.c_str();
  REQUIRE(as_cstr[0] == 'h');
  REQUIRE(as_cstr[1] == 'o');
  REQUIRE(as_cstr[11] == 'o');
  REQUIRE(as_cstr[12] == 'n');
  REQUIRE(as_cstr[13] == '\0');
}

#include <string_view>

size_t count_v(std::string_view my_view) {
  size_t result{};
  for(auto letter : my_view)
    if(letter == 'v' || letter == 'V')
      result++;
  return result;
}

TEST_CASE("std::string_view converts from a") {
  SECTION("C-style string") {
    REQUIRE(count_v("overinvolve") == 3);
  }
  SECTION("std::string") {
    std::string word("ovoviviparous");
    REQUIRE(count_v(word) == 3);
  }
}

TEST_CASE("std::string supports comparison with") {
  using namespace std::literals::string_literals;
  std::string word("allusion");
  SECTION("operator== and !=") {
    REQUIRE(word == "allusion");
    REQUIRE(word == "allusion"s);
    REQUIRE(word != "Allusion"s);
    REQUIRE(word != "illusion"s);
    REQUIRE_FALSE(word == "illusion"s);
  }
  SECTION("operator<") {
    REQUIRE(word < "illusion");
    REQUIRE(word < "illusion"s);
    REQUIRE(word > "Allusion"s);
    REQUIRE("pal"s < "palindrome"s);
  }
}

TEST_CASE("std::string supports appending with") {
  std::string word("butt");
  SECTION("push_back") {
    word.push_back('e');
    REQUIRE(word == "butte");
  }
  SECTION("operator+=") {
    word += "erfinger";
    REQUIRE(word == "butterfinger");
  }
  SECTION("append char") {
    word.append(1, 'e');
    REQUIRE(word == "butte");
  }
  SECTION("append char*") {
    word.append("stockings", 5);
    REQUIRE(word == "buttstock");
  }
  SECTION("append (half-open range)") {
    std::string other("onomatopoeia");
    word.append(other.begin(), other.begin() + 2);
    REQUIRE(word == "button");
  }
}

TEST_CASE("std::string supports removal with") {
  std::string word("therein");
  SECTION("pop_back") {
    word.pop_back();
    word.pop_back();
    REQUIRE(word == "there");
  }
  SECTION("clear") {
    word.clear();
    REQUIRE(word.empty());
  }
  SECTION("erase using half-open range") {
    word.erase(word.begin(), word.begin() + 3);
    REQUIRE(word == "rein");
  }
  SECTION("erase using an index and length") {
    word.erase(5, 2);
    REQUIRE(word == "there");
  }
}

TEST_CASE("std::string resize") {
  std::string word("shamp");
  SECTION("can remove elements") {
    word.resize(4);
    REQUIRE(word == "sham");
  }
  SECTION("can add elements") {
    word.resize(7, 'o');
    REQUIRE(word == "shampoo");
  }
}

TEST_CASE("std::string replace works with") {
  std::string word("substitution");
  SECTION("a range and a char*") {
    word.replace(word.begin() + 9, word.end(), "e");
    REQUIRE(word == "substitute");
  }
  SECTION("two ranges") {
    std::string other("innuendo");
    word.replace(word.begin(), word.begin() + 3, other.begin(), other.begin() + 2);
    REQUIRE(word == "institution");
  }
  SECTION("an index/length and a string") {
    std::string other("vers");
    word.replace(3, 6, other);
    REQUIRE(word == "subversion");
  }
}

TEST_CASE("std::string substr with") {
  std::string word("hobbits");
  SECTION("no arguments copies the string") {
    REQUIRE(word.substr() == "hobbits");
  }
  SECTION("position takes the remainder") {
    REQUIRE(word.substr(3) == "bits");
  }
  SECTION("position/index takes a substring") {
    REQUIRE(word.substr(3, 3) == "bit");
  }
}

TEST_CASE("std::string find") {
  using namespace std::literals::string_literals;
  std::string word("pizzazz");
  SECTION("locates substrings from strings") {
    REQUIRE(word.find("zz"s) == 2);
  }
  SECTION("accepts a position argument") {
    REQUIRE(word.find("zz"s, 3) == 5);
  }
  SECTION("locates substrings from char*") {
    REQUIRE(word.find("zaz") == 3);
  }
  SECTION("returns npos when not found") {
    REQUIRE(word.find('x') == std::string::npos);
  }
}

TEST_CASE("std::string rfind") {
  using namespace std::literals::string_literals;
  std::string word("pizzazz");
  SECTION("locates substrings from strings") {
    REQUIRE(word.rfind("zz"s) == 5);
  }
  SECTION("accepts a position argument") {
    REQUIRE(word.rfind("zz"s, 3) == 2);
  }
  SECTION("locates substrings from char*") {
    REQUIRE(word.rfind("zaz") == 3);
  }
  SECTION("returns npos when not found") {
    REQUIRE(word.rfind('x') == std::string::npos);
  }
}

TEST_CASE("std::string find_first_of") {
  using namespace std::literals::string_literals;
  std::string word("I am a Zizzer-Zazzer-Zuzz as you can plainly see.");
  SECTION("locates characters within another string") {
    REQUIRE(word.find_first_of("Zz"s) == 7); // (Z)izzer
  }
  SECTION("accepts a position argument") {
    REQUIRE(word.find_first_of("Zz"s, 11) == 14); // (Z)azzer
  }
  SECTION("returns npos when not found") {
    REQUIRE(word.find_first_of("Xx"s) == std::string::npos);
  }
}

TEST_CASE("std::string") {
  using namespace std::literals::string_literals;
  std::string word("I am a Zizzer-Zazzer-Zuzz as you can plainly see.");
  SECTION("find_last_of finds last element within another string") {
    REQUIRE(word.find_last_of("Zz"s) == 24); // Zuz(z)
  }
  SECTION("find_first_not_of finds last element within another string") {
    REQUIRE(word.find_first_not_of(" -IZaeimrz"s) == 22); // Z(u)zz
  }
  SECTION("find_first_not_of finds last element within another string") {
    REQUIRE(word.find_last_not_of(" .es"s) == 43); // plainl(y)
  }
}

TEST_CASE("STL string conversion function") {
  using namespace std::literals::string_literals;
  SECTION("stoi") {
    REQUIRE(std::stoi("8675309"s) == 8675309);
  }
  SECTION("stoi") {
    REQUIRE_THROWS_AS(std::stoi("1099511627776"s), std::out_of_range);
  }
  SECTION("stoul with all valid characters") {
    size_t last_character{};
    const auto result = std::stoul("0xD3C34C3D"s, &last_character, 16);
    REQUIRE(result == 0xD3C34C3D);
    REQUIRE(last_character == 10);
  }
  SECTION("stoul") {
    size_t last_character{};
    const auto result = std::stoul("42six"s, &last_character);
    REQUIRE(result == 42);
    REQUIRE(last_character == 2);
  }
  SECTION("stod") {
    REQUIRE(std::stod("2.7182818"s) == Approx(2.7182818));
  }
}

TEST_CASE("std::string_view supports") {
  SECTION("default construction") {
    std::string_view view;
    REQUIRE(view.data() == nullptr);
    REQUIRE(view.size() == 0);
    REQUIRE(view.empty());
  }
  SECTION("construction from string") {
    std::string word("sacrosanct");
    std::string_view view(word);
    REQUIRE(view == "sacrosanct");
  }
  SECTION("construction from C-string") {
    auto word = "viewership";
    std::string_view view(word);
    REQUIRE(view == "viewership");
  }
  SECTION("construction from C-string and length") {
    auto word = "viewership";
    std::string_view view(word, 4);
    REQUIRE(view == "view");
  }
}

TEST_CASE("std::string_view is modifiable with") {
  std::string_view view("previewing");
  SECTION("remove_prefix") {
    view.remove_prefix(3);
    REQUIRE(view == "viewing");
  }
  SECTION("remove_suffix") {
    view.remove_suffix(3);
    REQUIRE(view == "preview");
  }
}

#include <boost/algorithm/string/predicate.hpp>
#include <string>

TEST_CASE("boost::algorithm::") {
  using namespace boost::algorithm;
  using namespace std::literals::string_literals;
  std::string word("pneumatic");
  SECTION("starts_with tests a strings beginning") {
    REQUIRE(starts_with(word, "pne"s));
  }
  SECTION("istarts_with is case insensitive") {
    REQUIRE(istarts_with(word, "PnE"s));
  }
}

TEST_CASE("boost::algorithm::all evaluates a predicate for all elements") {
  using namespace boost::algorithm;
  std::string word("juju");
  REQUIRE(all(word, [](auto c) { return c == 'j' || c == 'u'; }));
}

#include <boost/algorithm/string/finder.hpp>

TEST_CASE("boost::algorithm::is_alnum") {
  const auto finder = boost::algorithm::nth_finder("na", 1);
  std::string word("Carl Brutananadilewski");
  const auto result = finder(word.begin(), word.end());
  REQUIRE(result.begin() == word.begin() + 12); // Brutana(n)adilewski
  REQUIRE(result.end() == word.begin() + 14); // Brutanana(d)ilewski
}

#include <boost/algorithm/string/case_conv.hpp>

TEST_CASE("boost::algorithm::to_upper") {
  using namespace boost::algorithm;
  std::string powers("difficulty controlling the volume of my voice");
  SECTION("upper-cases a string") {
    to_upper(powers);
    REQUIRE(powers == "DIFFICULTY CONTROLLING THE VOLUME OF MY VOICE");
  }
  SECTION("_copy leaves the original unmodified") {
    auto result = to_upper_copy(powers);
    REQUIRE(powers == "difficulty controlling the volume of my voice");
    REQUIRE(result == "DIFFICULTY CONTROLLING THE VOLUME OF MY VOICE");
  }
}

#include <boost/algorithm/string/replace.hpp>

TEST_CASE("boost::algorithm::replace_first") {
  using namespace boost::algorithm;
  std::string publisher("No Starch Press");
  SECTION("replaces the first occurrence of a string") {
    replace_first(publisher, "No", "Medium");
    REQUIRE(publisher == "Medium Starch Press");
  }
  SECTION("has a case-insensitive variant") {
    auto result = ireplace_first_copy(publisher, "No", "Medium");
    REQUIRE(publisher == "No Starch Press");
    REQUIRE(result == "Medium Starch Press");
  }
}

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <vector>

TEST_CASE("boost::algorithm::split") {
  using namespace boost::algorithm;
  std::string publisher("No Starch Press");
  SECTION("splits a range based on a predicate") {
    std::vector<std::string> tokens;
    split(tokens, publisher, is_space());
    REQUIRE(tokens[0] == "No");
    REQUIRE(tokens[1] == "Starch");
    REQUIRE(tokens[2] == "Press");
  }
}

#include <boost/algorithm/string/join.hpp>
#include <vector>

TEST_CASE("boost::algorithm::join staples tokens together") {
  using namespace boost::algorithm;
  std::vector<std::string> tokens{ "We invited the strippers", "JFK", "and Stalin." };
  auto result = join(tokens, ", ");
  REQUIRE(result == "We invited the strippers, JFK, and Stalin.");
}

#include <boost/algorithm/string/find.hpp>

TEST_CASE("boost::algorithm::find_head computes the head") {
  std::string word("blandishment");
  const auto result = boost::algorithm::find_head(word, 5);
  REQUIRE(result.begin() == word.begin()); // (b)landishment
  REQUIRE(result.end() == word.begin() + 5); // bland(i)shment
}

#include <regex>

TEST_CASE("std::basic_regex constructs from a string literal") {
  std::regex regex{ R"((\w{2})(\d{5})(-\d{4})?)" };
  REQUIRE(regex.mark_count() == 3);
}

TEST_CASE("std::sub_match") {
  std::regex regex{ R"((\w{2})(\d{5})(-\d{4})?)" };
  std::smatch results;
  SECTION("returns true given matching string") {
    std::string zip("NJ07936-3173");
    const auto matched = std::regex_match(zip, results, regex);
    REQUIRE(matched);
    REQUIRE(results[0] == "NJ07936-3173");
    REQUIRE(results[1] == "NJ");
    REQUIRE(results[2] == "07936");
    REQUIRE(results[3] == "-3173");
  }
  SECTION("returns false given non-matching string") {
    std::string zip("Iomega Zip 100");
    const auto matched = std::regex_match(zip, results, regex);
    REQUIRE_FALSE(matched);
  }
}

TEST_CASE("when only part of a string matches a regex, std::regex_") {
  std::regex regex{ R"((\w{2})(\d{5})(-\d{4})?)" };
  std::string sentence("The string NJ07936-3173 is a ZIP Code.");
  SECTION("match returns false ") {
    const auto matched = std::regex_match(sentence, regex);
    REQUIRE_FALSE(matched);
  }
  SECTION("search returns true when only part of a string matches a regex") {
    const auto matched = std::regex_search(sentence, regex);
    REQUIRE(matched);
  }
}

TEST_CASE("std::regex_replace") {
  std::regex regex{ "[aeoiu]" };
  std::string sentence("queueing and cooeeing in eutopia");
  const auto result = std::regex_replace(sentence, regex, "_");
  REQUIRE(result == "q_____ng _nd c_____ng _n __t_p__");
}

#include <boost/tokenizer.hpp>
#include <string>

TEST_CASE("boost::tokenizer splits token-delimited strings") {
  std::string palindrome("A man, a plan, a canal, Panama!");
  std::string result;
  boost::char_separator<char> comma{ "," };
  boost::tokenizer<boost::char_separator<char>> tokens{ palindrome, comma };
  auto itr = tokens.begin();
  REQUIRE(*itr == "A man");
  itr++;
  REQUIRE(*itr == " a plan");
  itr++;
  REQUIRE(*itr == " a canal");
  itr++;
  REQUIRE(*itr == " Panama!");
  itr++;
  REQUIRE(itr.at_end());
}
