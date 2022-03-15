#include <iostream>
#include <string>
#include <unordered_map>

bool isUnique(std::string str) {
    if (str.size() > 128) return false;
    std::unordered_map<char, int> charCounter;
    for (int i=0; i<str.size(); i++){
        if (charCounter.find(str[i]) != charCounter.end()) return false;
        charCounter[str[i]] = 1;
    }
    return true;
}

int main() {
    std::cout << "Is Unique" << std::endl;
    std::string result = isUnique("abca") ? std::string("") : std::string("not ");
    std::cout << "abc is " << result << "unique";
}