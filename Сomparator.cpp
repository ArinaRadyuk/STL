#include "Comparator.h"
#include <vector>

using namespace std;

bool Comparator::operator()(int left_number, int right_number) {
    return (characteristics(left_number) > characteristics(right_number));
}

int Comparator::characteristics(int number) {
    vector<int> digit;
    while (number > 0) {
        int remainder = number % 10;
        digit.push_back(remainder);
        number /= 10;
    }
    int count = 1;
    for (int i = (static_cast<int>(digit.size()) - 1); i > 0; --i) {
        if (digit[i] != digit[i - 1])
            break; 
        ++count;
    }
    for (int i = 0; i < (static_cast<int>(digit.size()) - 1); ++i) {
        if (digit[i] != digit[i + 1])
            break; 
        ++count;
    }
    return count;
}