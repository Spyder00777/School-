import random
import math
N = int(input("Enter number of Experiments: "))
num = N
storedResults = []
while (N > 0):
        birthdays=[]
        done = False
        count = 0
        while (not done):
                count = count + 1
                next = random.randint(1,365)
                if next in birthdays:
                        done = True
                        storedResults.append(count)
                else:
                        birthdays.append(next)
        N = N - 1
print("End of Simulation")
print(storedResults)
print("The smallest is: " + str(min(storedResults)))
print("The largest is: " + str(max(storedResults)))
avg = (sum(storedResults))/len(storedResults)
print("The average is: " + str(avg))
var = 0
for a in storedResults:
        var = var + math.pow(a - avg,2)
var = var * (1/num)
print("The variance is: " + str(var))
std = math.pow(var,1/2)
print("The standard deviation is: " + str(std))
Std1 = 0
Std2 = 0
Std3 = 0
for a in storedResults:
        if ((avg + std) > a) & ((avg - std) < a):
                Std1 = Std1 + 1
        if ((avg + std*2) > a) & ((avg - std*2) < a):
                Std2 = Std2 + 1
        if ((avg + std*3) > a) & ((avg - std*3) < a):
                Std3 = Std3 + 1
print("The number within 1 Std: " + str(Std1))
print("The number within 2 Std: " + str(Std2))
print("The number within 3 Std: " + str(Std3))
