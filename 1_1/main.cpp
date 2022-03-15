#include <iostream>
#include <string>
#include <unordered_map>

bool isUnique(std::string str)
{
    int checkingBits = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (checkingBits & (1 << (str[i] - 'a')))
            return false;
        checkingBits |= 1 << (str[i] - 'a');
    }
    return true;
}

int main()
{
    std::cout << "Is Unique" << std::endl;
    std::string result = isUnique("abc") ? std::string("") : std::string("not ");
    std::cout << "abc is " << result << "unique";
}