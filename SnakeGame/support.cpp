#include <iostream>
#include <vector>
#include <random>

using namespace std;

char rand_set_picker(vector<int> c) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, c.size() - 1);
	int rand_index = dist(gen);
	return c[rand_index];
}

int random_picker(int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(a, b);

	return dist(gen);

}
