# You are given a string str containing only the letters W, D, and L. Your task is to construct a new string from the characters of str, according to the following algorithm:
# 1. Begin with an empty string output = "".
# 2. If str contains a W, then remove it and concatenate a W to the end of output.
# 3. If str contains a D, then remove it and concatenate a D to the end of output.
# 4. If str contains an L, then remove it and concatenate an L to the end of output.
# 5. If str is empty, end the algorithm; otherwise go back to step 2.
# Return the value of output after the algorithm is complete.
# Note that it doesn't matter from where you remove the letter from the string, only the count of the letters left in the string matters.
# Example
# • For str = "LDWDL", the output should be equallyRearranging(str) = "WDLDL".
#   ○ str contains all W, D, and L, so we add them to the output and remove from the initial string one by one and get "WDL"
#   ○ The remaining string contains only letters D and L, so we add them to the output and get "WDLDL" as the answer

# • For str = "DLDD", the output should be equallyRearranging(str) = "DLDD".
#   ○ The string doesn't contain W letters, and do contain both D and L, so we add them to the output and remove from the initial string. The output is "DL" after that
#   ○ The remaining string contains only two letters D and nothing else, so in two more iterations we get the output equal "DLDD"

# Input/Output
# • [execution time limit] 4 seconds (py3)
# • [input] string strA string containing only the letters 'W', 'D' and 'L'.Guaranteed constraints:1 ≤ str.length ≤ 1000.
# • [output] stringReturn the string constructed from the characters of str.
# [Python 3] Syntax Tips
# # Prints help message to the console# Returns a stringdef helloWorld(name):    print("This prints to the console when you Run Tests")    return "Hello, " + name

just use a dict