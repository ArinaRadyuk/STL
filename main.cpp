#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "Comparator.h"

using namespace std;

int main() {
    ofstream out("Number.out");
    if (out.fail())
        return 0;

    ifstream in("Number.txt");
    if (in.fail()) {
        out << "File Number.txt can not be found." << endl;
        out.close();
        return 0;
    }

    if (in.peek() == EOF) {
        out << "File is empty!" << endl;
        out.close();
        in.close();
        return 0;
    }

    vector<int> v;
    int number;
    while (in >> number)
        v.push_back(number);

    sort(v.begin(), v.end(), Comparator());
    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        out << v[i] << " ";
    }
}
