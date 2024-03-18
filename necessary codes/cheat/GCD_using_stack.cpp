#include <iostream>
#include <stack>

int d8(int a, int b) {
    if (a == b) {
        return a;
    }

    std::stack<int> s;
    s.push(b);
    s.push(a);

    int c1, c2;

    while ((c1 = s.top(), s.pop(), s.size() > 0) && (c2 = s.top(), s.pop(), c1 != c2)) {
        if (c1 > c2) {
            c1 -= c2;
        } else {
            c2 -= c1;
        }

        s.push(c2);
        s.push(c1);
    }

    return c1;
}

int main() {
    int result = d8(24, 18);
    std::cout << "GCD: " << result << std::endl;

    return 0;
}
