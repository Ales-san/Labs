#include <iostream>
#include "queue_.h"
#include "get_min.h"

int main() {

    int a, b;
    std::cout << "Enter two numbers:";
    std::cin >> a >> b;
    std::cout << "The least number: " << get_min(a, b) << '\n';

    char c, d;
    std::cout << "Enter two symbols:";
    std::cin >> c >> d;
    std::cout << "The least symbol: " << get_min(c, d) << '\n';

    std::string e, f;
    std::cout << "Enter two strings:";
    std::cin >> e >> f;
    std::cout << "The least string: " << get_min(e, f) << '\n';

    Queue <char, 26> q;
    for(int i = 0; i < 26; i++) {
        q.push('a' + i);
        std::cout << q.size() << '\n';
    }
    for(int i = 0; i < 26; i++) {
        std::cout << q.pop() << ' ';
        std::cout << q.size() << '\n';
    }
    for(int i = 0; i < 26; i++) {
        q.push('a' + i);
        std::cout << q.size() << '\n';
    }
    for(int i = 0; i < 26; i++) {
        std::cout << q.pop() << ' ';
        std::cout << q.size() << '\n';
    }

    Queue <int, 1> A;
    A.push(1);
    try {
        std::cout << "Let's try to push in the full queue\n";
        A.push(1);
        std::cout << "It's ok!\n";
    } catch (QueueOverflowException e) {
        std::cout << "Exception caught!\n";
    }

    A.pop();
    try {
        std::cout << "Let's try to pop from the empty queue\n";
        A.pop();
        std::cout << "It's ok!\n";
    } catch (EmptyQueueException e) {
        std::cout << "Exception caught!\n";
    }
    return 0;
}
