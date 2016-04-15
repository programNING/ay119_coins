/* Counting the # ways to pay amount n using 1, 5, 10, 25 cents
 Given like 30 cents:
 can always do 1 x 25
 split the amount by subtracting 25 -> n => N1, N2
 call split on N1, N2
 10 cents: [10], [5 5], [1 1 1 1 1 5], [1 1 1 1 1 1 1 1 1 1]
 the amnt ways you can split ten is the amnt ways u can split
 5 + the amnt ways you can split 5
 so split(30) = split(5) + split(25)?
 split(25) = split(10) + split(15)
 split(10) = split(5) + split(5)
 split(5) = 2 (base case?)
 split(n) where n < 5: 1 way (pennies)
*/

 #include <map> 

int amounts[] = {1, 5, 10, 25}

std::map<int, int> memo;

int countWays(int money) {

	// check to see if in memo already

	if (memo[money] != 0) {
		return memo[money];
	}

	int ways = 0;

	// TODO: figure out what to do if money = 1, 5, 10, 25
	// imma just put a bunch of gross conditional statements

	if (money - 25 > 0) {
		ways = countWays(money - 25) + countWays(25);
	}

	else if (money - 10 > 0) {
		ways = countWays(money - 10) + countWays(10);
	}

	else if (money - 5 > 0) {
		ways = countWays(money - 5) + countWays(5);
	}

	else {
		ways = 1; // if money < 5 then only 1 way to make it
	}

	if (money == 5 || ways == 10 || ways == 25) {
		ways += 1;
	}

	memo[money] = ways;

	return ways;

}