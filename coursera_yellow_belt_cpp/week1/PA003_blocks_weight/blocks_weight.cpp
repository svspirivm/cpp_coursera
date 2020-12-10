#include<iostream>
#include<vector>
#include<cstdint>

using namespace std;

int main() {
	unsigned amount_of_blocks = 0;
	cin >> amount_of_blocks;
	unsigned density = 0;
	cin >> density;
	uint64_t total_volume = 0;
	while (amount_of_blocks > 0) {
		amount_of_blocks--;
		uint64_t w = 0, h = 0, d = 0;
		cin >> w >> h >> d;
		uint64_t volume = 0;
		volume = w * h * d;
		total_volume += volume;
	}
	uint64_t mass = 0;
	mass = total_volume * density;
	cout << mass;
	return 0;
}