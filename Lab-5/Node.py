class Node(object):

	def __init__(self, data):
		self.left = None
		self.right = None
		self.data = data

	def childrencount(self):
		cnt = 0
		if self.left:
			cnt += 1
		if self.right:
			cnt += 1
		return cnt

	def minValueNode(self):
		current = self
		while(current.left != None):
			current = current.left

		return current

	def deleteNode(self, data):
		if self is None:
			return self

		if data < self.data:
			self.left = self.left.deleteNode(data)

		elif(data > self.data):
			self.right = self.right.deleteNode(data)

		else:
			if self.left is None :
				temp = self.right
				self = None
				return temp

			elif self.right is None :
				temp = self.left
				self = None
				return temp

			temp = self.right.minValueNode()

			self.data = temp.data

			self.right = self.right.deleteNode(temp.data)

		return self

	def search(self, data):
		if data < self.data:
			if self.left is None:
				return 0
			return self.left.search(data)

		elif data > self.data:
			if self.right is None:
				return 0
			return self.right.search(data)
		else:
			return 1

	def findPath(self, data, result=[], flag=False):

		if not self.search(data):
			return None

		if (not flag):
			result = []
			flag = True

		result.append(self.data)

		if data < self.data:
			if self.left is None:
				return None
			return self.left.findPath(data, result, flag)

		elif data > self.data:
			if self.right is None:
				return None
			return self.right.findPath(data, result, flag)

		else:
			return result


	def bulkInsert(self, datas):
		for val in datas:
			self.insert(val)

	def insert(self, data):
		if self.data:
			if data < self.data:
				if self.left is None:
					self.left = Node(data)
				else:
					self.left.insert(data)

			elif data > self.data:
				if self.right is None:
					self.right = Node(data)
				else:
					self.right.insert(data)
		else:
			self.data = data

	def inorder(self, result=[], flag=False):

		if (not flag):
			result = []
			flag = True

		if self.left is not None:
			self.left.inorder(result, flag)
		result.append(self.data)
		if self.right is not None:
			self.right.inorder(result, flag)

		return result

	def preorder(self, result=[], flag=False):
		if (not flag):
			result = []
			flag = True

		result.append(self.data)
		if self.left is not None:
			self.left.preorder(result, flag)
		if self.right is not None:
			self.right.preorder(result, flag)
		return result

	def postorder(self, result=[], flag=False):
		if (not flag):
			result = []
			flag = True

		if self.left is not None:
			self.left.postorder(result, flag)
		if self.right is not None:
			self.right.postorder(result, flag)
		result.append(self.data)
		return result

	def printGivenLevel(self , level, result=[], flag=False):
		if self is None:
			return

		if (not flag):
			result = []
			flag = True

		if level == 1:
			result.append(self.data)

		elif level > 1 :
			if self.left != None:
				self.left.printGivenLevel(level-1, result, flag)
			if self.right != None:
				self.right.printGivenLevel(level-1, result, flag);

		return result

	def height(self):
		if self is None:
			return 0
		else :
			lheight = 0
			rheight = 0

			if self.left != None:
				lheight = self.left.height()
			if self.right != None:
				rheight = self.right.height()

			if lheight > rheight :
				return lheight+1
			else:
				return rheight+1


	def printLevelOrder(self):
		h = self.height()
		result = []
		for i in range(1, h+1):
			print(self.printGivenLevel(i))
			result.append(self.printGivenLevel(i))

		return result
