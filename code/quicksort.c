#include <iostream>
#include <vector>

using namespace std;

// template<T>
// class Simplesharedptr
void quicksort(std::vector<int> &nums, int l, int r) {
  if (l+1 >= r) return;
  int first = l, last = r - 1, key = nums[first];
  while (first < last) {
    while (first < last && nums[last] >= key) {
      --last;
    }
    nums[first] = nums[last];
    while (first < last && nums[first] <= key) {
      ++first;
    }
    nums[last] = nums[first];
  }
  nums[first] = key;
  quicksort(nums, l, first);
  quicksort(nums, first+1,r);
}

int main() {
  std::vector<int> nums{1,4,5,2,8,3,4};
  quicksort(nums, 0, nums.size());
  for (auto num: nums) {
    cout << num << ",";
  }
  cout << endl;
  return 0;
}