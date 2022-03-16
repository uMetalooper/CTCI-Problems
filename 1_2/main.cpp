#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool matched(int s1map[], int s2map[]) {
    for (int i = 0; i < 26; i++) {
        if (s1map[i] != s2map[i])
            return false;
    }
    return true;
}

bool checkPermutation(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    unordered_map<char, int> freqCounter;
    for (char c : s1)
    {
        if (freqCounter.find(c) == freqCounter.end())
            freqCounter[c] = 0;
        freqCounter[c]++;
    }
    for (char c : s2)
    {
        if (freqCounter.find(c) == freqCounter.end())
            return false;
        freqCounter[c]--;
    }
    for (auto pair : freqCounter)
    {
        if (pair.second != 0)
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    bool result = checkPermutation(argv[1], argv[2]);
    cout << (result ? "true" : "false");
}