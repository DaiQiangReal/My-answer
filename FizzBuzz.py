#https://leetcode-cn.com/problems/fizz-buzz/description/
class Solution:
	def fizzBuzz(self, n):
		answer=[]
		for i in range(1,n+1):
			if i%3==0 and i%5==0:
				answer.append("FizzBuzz")
				continue
			if i%3==0:
				answer.append("Fizz")
				continue
			if i%5==0:
				answer.append("Buzz")
				continue
			answer.append(str(i))
		return answer

d=Solution()
print(d.fizzBuzz(15))