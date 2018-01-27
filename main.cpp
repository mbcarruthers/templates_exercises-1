#include <iostream>
#include <cassert>

namespace luc {

template <typename T, size_t N>
class array{
 public:

  const T& data() const {
    return _data;
  }

  constexpr size_t size() const {
    return N;
  }

  T& operator[] (size_t i) {
    return _data[i];
  }

 private:
  T _data[N];
};

}



int main() {
  // Stage 1
  luc::array<int, 32> arr{};
  static_assert(sizeof(arr) == 32 * sizeof(int), "");
  static_assert(arr.size() == 32);

  for(size_t i = 0; i < arr.size(); ++i) {
    arr[i] = static_cast<int>(i);
  }

  for(size_t i = 0; i < arr.size(); ++i) {
    assert(arr[i] == static_cast<int>(i));
  }

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
