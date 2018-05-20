inputs = []

for num in range(3):
    inputs.append(int(input()))

totalTime1 = (inputs[1] * 2) + (inputs[2] * 4)

totalTime2 = (inputs[0] * 2) + (inputs[2] * 2)

totalTime3 = (inputs[0] * 4) + (inputs[1] * 2)

if(totalTime1 <= totalTime2 and totalTime1 <= totalTime3):
    print(totalTime1)
elif totalTime2 <= totalTime3:
    print(totalTime2)
else: print(totalTime3)