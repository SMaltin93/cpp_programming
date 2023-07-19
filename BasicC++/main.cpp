#include <utility> // std::pair
#include "hello.h"
int main (int argc, char* argv[]) {
  std::pair<const char *, int> p = parse_args (argc ,argv); // parse arguments and return a pair
  if (p.second != -1) // if the second argument is not -1, call hello
    hello (p.first, p.second); // the pair elements as arguments
}