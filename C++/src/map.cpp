#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> m;
    m[1] = "a";
    m[2] = "b";
    m[3] = "c";
    
    // 迭代器
    for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
        int key = it->first;
        string& value = it->second;
        cout << key << ": " << value << endl;
    }
    
    // ranged-based for loop
    for (auto& p : m) {
        int key = p.first;
        string& value = p.second;
        cout << key << ": " << value << endl;
    }
    
    // range-based for loops together with structured bindings
    for (const auto &[k, v] : m) {
        cout << k << ": " << v << endl;
    }
    
}