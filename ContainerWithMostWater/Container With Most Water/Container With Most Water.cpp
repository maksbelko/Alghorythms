// You are given an integer array height of length n.There are n vertical lines
// drawn such that the two endpoints of the ith line are(i, 0) and
// (i,height[i]).

// Find two lines that together with the x - axis form a container, such that
// the container contains the most water.

// Return the maximum amount of water a container can store.
#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height);
int main() {
  std::cout << "Hello World!\n";
  int myints[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
  std::cout << maxArea(fifth);
}
int maxArea(std::vector<int> &height) {
  int left = 0;
  int right = height.size() - 1;
  int maxArea = 0;

  while (left < right) {
    int currentArea =
        (height[left] < height[right] ? height[left] : height[right]) *
        (right - left);
    maxArea = currentArea > maxArea ? currentArea : maxArea;
    // moving only the least height to reduce number of iterations
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return maxArea;
};
