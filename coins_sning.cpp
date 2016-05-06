 #include <map> 
 #include <stdlib.h>
 #include <stdio.h>
 #include <iostream>

int us_currency [4] = {1, 5, 10, 25};

int countWays(int money, int largest_coin) {

	int ways = 0;

	if (money < 0) {
		ways = 0;
	}
	else if (money < 5) {
		ways = 1;
	}
	else {

		for (unsigned int i = 0; i < 4; i++) {
			if (largest_coin >= us_currency[i]) {
				ways += countWays(money - us_currency[i], us_currency[i]);
			}
		}
	}

	return ways;

}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "usage: ./programname money_amnt" << std::endl;
		return -1;
	}

	int amnt = atoi(argv[1]);

	for (unsigned int i = 1; i < amnt + 1; i++) {
		std::cout << i << " # count: " << countWays(i, 25) << std::endl;
	}

}