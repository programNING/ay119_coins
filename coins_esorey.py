coinCounts = {}

def countCoins(target):
	if target < 0:
		return 0
	elif target == 0:
		return 1
	return countCoins(target - 1) + countCoins(target - 5) + countCoins(target - 10) + countCoins(target - 25)