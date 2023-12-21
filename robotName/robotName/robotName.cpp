// robotName.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include "robot.h"
#include <iostream>
#include <set>
#include <string>

static bool validate_name(const std::string &name);
int main() {
  std::cout << "Hello World!\n";
  std::set<std::string> existingNames = { "RX234" };
  try {
      Robot robot(existingNames);
      std::cout << "Robot name: " << robot.name()
          << "\nValid: " << validate_name(robot.name());
      robot.reset(existingNames);
      std::cout << "Robot name: " << robot.name()
          << "\nValid: " << validate_name(robot.name());
  }
  catch (...) {
      std::cout << "smth wenr wrong";
  }
}

static bool validate_name(const std::string &name) {

  return name.length() != 5
             ? false
             : isupper(name[0]) && isupper(name[1]) && isdigit(name[2]) &&
                   isdigit(name[3]) && isdigit(name[4]);
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
