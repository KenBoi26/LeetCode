class MinStack:

    stack = []
    minimum = []

    def __init__(self):
        self.minimum.append(2**32)

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.minimum.append(min(self.minimum[-1],val))

    def pop(self) -> None:
        self.stack.pop()
        self.minimum.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minimum[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()