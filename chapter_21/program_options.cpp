#include <boost/program_options.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  using namespace boost::program_options;
  bool is_recursive{}, is_help{};

  options_description description{ "mgrep [options] pattern path1 path2 ..." };
  description.add_options()("help,h", bool_switch(&is_help), "display a help dialog")(
      "threads,t", value<int>()->default_value(4), "number of threads to use")(
      "recursive,r", bool_switch(&is_recursive), "search subdirectories recursively")(
      "pattern", value<std::string>(), "pattern to search for")(
      "path", value<std::vector<std::string>>(), "path to search");

  positional_options_description positional;
  positional.add("pattern", 1);
  positional.add("path", -1);

  command_line_parser parser{ argc, argv };
  parser.options(description);
  parser.positional(positional);

  variables_map vm;
  try {
    auto parsed_result = parser.run();
    store(parsed_result, vm);
    notify(vm);
  } catch(std::exception& e) {
    std::cerr << e.what() << "\n";
    return -1;
  }

  if(is_help) {
    std::cout << description;
    return 0;
  }
  if(vm["pattern"].empty()) {
    std::cerr << "You must provide a pattern.\n";
    return -1;
  }
  if(vm["path"].empty()) {
    std::cerr << "You must provide at least one path.\n";
    return -1;
  }
  const auto threads = vm["threads"].as<int>();
  const auto& pattern = vm["pattern"].as<std::string>();
  const auto& paths = vm["path"].as<std::vector<std::string>>();
  // Continue program here ...
  std::cout << "Ok." << std::endl;
}