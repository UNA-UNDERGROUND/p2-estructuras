#include <iterator>


template<typename T>
struct istream_it {
  std::istream& is;
  using It = std::istream_iterator<T>;
  istream_it(std::istream& is) : is(is) {}
  It begin() { return It(is); }
  It end() { return It(); }
};