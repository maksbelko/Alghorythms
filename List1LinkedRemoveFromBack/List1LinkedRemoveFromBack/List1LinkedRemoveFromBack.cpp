// List1LinkedRemoveFromBack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 ListNode* removeNthFromEnd(ListNode* head, int n);
int main()
{
    ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* current = node;
    while (current) {
        std::cout << current->val;
        current = current->next;
    }
    current = removeNthFromEnd(node, 1);
    while (current) {
        std::cout << current->val;
        current = current->next;
    }

    delete node->next->next;
    delete node->next;
    delete node;
    
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head->next && n == 1) {
        return nullptr;
    }
    ListNode* current = head;
    int len = 1;
    while (current->next != nullptr) {
        current = current->next;
        len++;
    }
    if (len == n) {
        ListNode* nodeToReturn = head->next;
        head->next = nullptr;
        return nodeToReturn;
    }
    current = head;
    int index = 1;
    
    while (len - index != n) {
        current = current->next;
        index++;
    }
    ListNode* toRemove = current->next;
    current->next = current->next->next;
    toRemove->next = nullptr;
    return head;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
