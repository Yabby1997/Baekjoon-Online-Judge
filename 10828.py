import sys

class Stack :
    def __init__(self):                                 
        self.stackList = []
        
    def push(self, inputNum) :
        self.stackList.append(inputNum)
        
    def size(self) :
        return len(self.stackList)
        
    def empty(self) :
        if self.size() == 0 :
            return 1
        else :
            return 0
            
    def top(self) :
        if self.size() != 0 :
            return self.stackList[-1]                   #-1 INDEX MEANS REAR OF LIST
        else :
            return -1
            
    def pop(self) :
        if self.empty() == 0 :
            temp = self.stackList[self.size() - 1]
            del self.stackList[self.size() - 1]
            return temp
        else :
            return -1

numOfInput = int(sys.stdin.readline())
testStack = Stack()

for i in range(numOfInput) :
    command = sys.stdin.readline()                      #SYS.STDIN.READLINE() READS INPUT INCLUDING NEW LINE
    command = command.rstrip('\n');                     #DELETE NEW LINE WITH RSTRIP
    if command.split()[0] == "push" :
        testStack.push(int(command.split()[1]))
    elif command == "size" :
        print(testStack.size())
    elif command == "empty" :
        print(testStack.empty())
    elif command == "top" :
        print(testStack.top())
    elif command == "pop" :
        print(testStack.pop())
