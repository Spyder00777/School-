# Christopher Ochs
# April 17, 2016
class Tree:
    def __init__(self, cargo, left=None, right=None):
        self.cargo = cargo
        self.left = left
        self.right = right

def yes(ques):
    ans = str(input(ques)).lower()
    return ans[0] == "y"

def walkDecisionTree(root):
        while root.left is not None:
            prompt = root.cargo + "? "
            if yes(prompt):
                root = root.right
            else:
                root = root.left
        answernode = root
        return answernode

def addNewQ(leaf):
        oldguess= leaf.cargo
        prompt  = "What is the animal's name?"
        newanimal  = input(prompt)
        prompt  = "What question would distinguish a {0} from a {1}? "
        question = input(prompt.format(newanimal, oldguess))
        leaf.cargo = question
        prompt = "If the animal were {0} the answer would be? "
        if yes(prompt.format(newanimal)):
            leaf.left = Tree(oldguess)
            leaf.right = Tree(newanimal)
        else:
            leaf.left = Tree(newanimal)
            leaf.right = Tree(oldguess)      
 

def animalQnA(root):
    # Loop until the user quits
    while True:
        print()
        if not yes("Are you thinking of an animal? "): break
        answernode = walkDecisionTree(root)
        prompt = "Is it a " + answernode.cargo + "? "
        if yes(prompt):
            print("I rule!")
        else:
            addNewQ(answernode)
        

def printAllAnimals(t):
    global animalCounter
    if t.left == None:
        print(animalCounter, t.cargo)
        animalCounter += 1
    else:
        printAllAnimals(t.left)
        printAllAnimals(t.right)

def printAllQuestions(t):
    global questionCounter
    if t.left and t.right:
        print(questionCounter,t.cargo,'?')
        questionCounter += 1
        printAllQuestions(t.left)
        printAllQuestions(t.right)

def printTreeStats():
    print("Here are the TreeStats:")
    print("Total number of non-empty nodes in the tree =",questionCounter+animalCounter)
    print("Total number of question nodes in the tree =",questionCounter)
    print("Total number of animals in the tree =",animalCounter)

def printLongestPathLength(t):
    global distA
    global distB
    if(distA>distB):
        distB = distA
    if (t.right and t.left):
          distA += 1
          printLongestPathLength(t.left)
          printLongestPathLength(t.right)

def printLongestPath(t,p):
    global path
    if (len(path) < len(p)):
        path = [] + p
    if(t.left and t.right):
        p.append('no')
        printLongestPath(t.left,p)
        p.pop()
        p.append('yes')
        printLongestPath(t.right,p)
        p.pop()    

root = Tree("Have feathers", Tree("Have fur", Tree("snake"), Tree("Have claws", Tree("Have bark", Tree("mouse"), Tree("dog")), Tree("cat"))), Tree("bird"))
animalQnA(root)
print("Q&A is over: Here are animals")
animalCounter = 0
printAllAnimals(root)

print('\nQuestion 1')
print('Here are the questions')
questionCounter = 0
printAllQuestions(root)

print('\nQuestion 2')
printTreeStats()

print('\nQuestion 3')
distA = 1
distB = 1
printLongestPathLength(root)
print('Max path length:',distA)

print('\nQuestion 4')
path =[]
p = []
printLongestPath(root,p)
path.append("no")
for x in path:
    print(x)

