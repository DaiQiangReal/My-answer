#https://leetcode-cn.com/problems/diagonal-traverse/description/
class Solution:
	def findDiagonalOrder(self, matrix):
		if matrix==[] or matrix==[[]]:
			return []
		i=0
		j=0
		answer=[]
		leni=len(matrix)
		lenj=len(matrix[0])
		while True:
			answer.append(matrix[i][j])
			while i-1>=0 and j+1<lenj:
				i-=1
				j+=1
				answer.append(matrix[i][j])

			if i+1==leni and j+1==lenj:
				return answer

			if j+1==lenj:
				i+=1
			else:
				j+=1

			answer.append(matrix[i][j])
			while i+1<leni and j-1>=0:
				i+=1
				j-=1
				answer.append(matrix[i][j])
			if i+1==leni and j+1==lenj:
				return answer
			if j-1==-1 and i+1<leni:
				i+=1
			else:
				j+=1

a=Solution()
b=[
	[1,2],
	[3,4],
	[5,6]
]
print(a.findDiagonalOrder(b))
