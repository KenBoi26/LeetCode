class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for i in tokens:
            if i == "+":
                num1 = stack[-1]
                stack.pop()
                num2 = stack[-1]
                stack.pop()
                stack.append(num1+num2)
            elif i == "-":
                num1 = stack[-1]
                stack.pop()
                num2 = stack[-1]
                stack.pop()
                stack.append(num2-num1)
            elif i == "*":
                num1 = stack[-1]
                stack.pop()
                num2 = stack[-1]
                stack.pop()
                stack.append(num2*num1)
            elif i == "/":
                num2 = stack[-1]
                stack.pop()
                num1 = stack[-1]
                stack.pop()
                stack.append(int(num1/num2))
            else:
                stack.append(int(i))
        

        return int(stack[-1])