# Since you love games of chance, you've decided to participate in a dice-rolling competition. The competition involves rolling three 6-sided dice, and the results of each die are represented by the integers a, b, and c respectively. Scores are calculated according to the following rules:

# If all three dice had the same value (a = b = c) then you earn 1000 * a.
# If exactly two of them are the same, you earn 500 * x (where x is the value of the two equal dice).
# If all of them are different, you earn 100 * min(a, b, c).
# Given the values of a, b, and c, your task is to calculate and return your total score.

# Example
# For a = 3, b = 3, and c = 3, the output should be diceTotalScore(a, b, c) = 3000.
# Since all of the dice have the same value, your total score is equal to 1000 * 3 = 3000.
# For a = 3, b = 6, and c = 3, the output should be diceTotalScore(a, b, c) = 1500.
# Since exactly two of the values are the same (a = c = 3), your total score is equal to 500 * 3 = 1500.
# For a = 3, b = 2, and c = 5, the output should be diceTotalScore(a, b, c) = 200.
# Since all of these values are different, your total score is equal to 100 * min(a, b, c) = 100 * 2 = 200.

# Input/Output
# [execution time limit] 4 seconds (py3)
# [input] integer a
# An integer representing the value of the first die.
# Guaranteed constraints:
# 1 ≤ a ≤ 6.
# [input] integer b
# An integer representing the value of the second die.
# Guaranteed constraints:
# 1 ≤ b ≤ 6.
# [input] integer c
# An integer representing the value of the third die.
# Guaranteed constraints:
# 1 ≤ c ≤ 6.
# [output] integer

# Return your total score