// binarySearch.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> size_t find(std::vector<T> data, T value) {
  if (data.size() == 0) {
      throw std::domain_error("No data to find in.");
  } else {
    int middle = (double(data.size() / 2) > data.size() / 2)
                     ? data.size() / 2
                     : data.size() / 2 - 1;
    return data[middle] == value ? middle
           : data[middle] > value
               ? find(std::vector<T>(data.begin() + middle, data.end()), value)
               : find(std::vector<T>(data.begin(), data.begin() + middle - 1),
                      value);
  }
}
int main() {
  std::vector<int> myVector{1, 3, 4, 5, 7, 2, 9, 13, 15};
  std::sort(myVector.begin(), myVector.end());
  std::cout << find(myVector, 4);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и
//   другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый
//   элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий
//   элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" >
//   "Открыть" > "Проект" и выберите SLN-файл.
