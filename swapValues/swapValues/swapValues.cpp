// swapValues.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include <iostream>

template <typename T> void swapPtrs(T **ppa, T **ppb) {
  T *tempPtr = *ppa;
  *ppa = *ppb;
  *ppb = tempPtr;
};

template <typename T> void swapValuesByPtrs(T *pa, T *pb) {
  T tempValue = *pa;
  *pa = *pb;
  *pb = tempValue;
}
template <typename T> void swapValuesByRefs(T& aRef, T& bRef) {
	T tempValue = aRef;
	aRef = bRef;
	bRef = tempValue;
}

int main() {

  int a = 8;
  int b = 6;
  int *pa = &a;
  int *pb = &b;
  std::cout << "Before swap\n";
  std::cout << "a:\t " << a << std::endl;
  std::cout << "b:\t " << b << std::endl;
  std::cout << "pa:\t" << pa << std::endl;
  std::cout << "*pa:\t " << *pa << std::endl;
  std::cout << "pb:\t " << pb << std::endl;
  std::cout << "*pb:\t " << *pb << std::endl;
  
  swapValuesByRefs(*pa, *pb);
  
  std::cout << "After swap values by refs\n";
  std::cout << "a:\t " << a << std::endl;
  std::cout << "b:\t " << b << std::endl;
  std::cout << "pa:\t" << pa << std::endl;
  std::cout << "*pa:\t" << *pa << std::endl;
  std::cout << "pb:\t " << pb << std::endl;
  std::cout << "*pb:\t " << *pb << std::endl;

  swapValuesByPtrs(pa, pb);
  std::cout << "After swap values by pointers\n";
  std::cout << "a:\t " << a << std::endl;
  std::cout << "b:\t " << b << std::endl;
  std::cout << "pa:\t" << pa << std::endl;
  std::cout << "*pa:\t" << *pa << std::endl;
  std::cout << "pb:\t " << pb << std::endl;
  std::cout << "*pb:\t " << *pb << std::endl;

  swapPtrs(&pa, &pb);
  std::cout << "After swap pointers\n";
  std::cout << "a:\t " << a << std::endl;
  std::cout << "b:\t " << b << std::endl;
  std::cout << "pa:\t" << pa << std::endl;
  std::cout << "*pa:\t" << *pa << std::endl;
  std::cout << "pb:\t " << pb << std::endl;
  std::cout << "*pb:\t " << *pb << std::endl;
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
