#include<iostream>

int main() {
    int id = 0;
    auto f = [id] () mutable {
        std::cout << "id: " << id << std::endl;
        ++id;
    };
    // id = 42;
    f();
    f();
    f();
    std::cout << id << std::endl;
}
    