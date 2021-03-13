#pragma once

class Comparator {
public:
	bool operator()(int left_number, int right_number);

private:
	int characteristics(int number);
};