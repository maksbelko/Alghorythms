// Given a sorted array of distinct integers and a target value, return the
// index if the target is found. If not, return the index where it would be if
// it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include <iostream>
#include <vector>
int searchInsert(std::vector<int> &, int);
int main() {
  std::vector<int> myVec = {1, 3, 5, 6};
  std::cout << searchInsert(myVec, 0);
}
int searchInsert(std::vector<int> &nums, int target) {
  int index = nums.size() / 2;
  int current = nums[index];
  if (current == target) {
    return index;
  }
  bool isBigger = current > target;
  int dif = isBigger ? -1 : 1;
  index += dif;
  while (index >= 0 && index < nums.size()) {
    if (nums[index] == target) {
      return index;
    }
    bool biggerEq = (nums[index] > target) && isBigger;
    bool lowerEq = (nums[index] < target) && !isBigger;
    if (biggerEq || lowerEq) {
      index += dif;
      continue;
    } else {
      return isBigger ? index - dif : index;
    }
  }
  return isBigger ? index - dif : index;
}


