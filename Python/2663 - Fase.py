points = []
totalClassify = 0

competitorsQnt = int(input())

minNextPhase = int(input())

for i in range(competitorsQnt):
    points.append(int(input()))

points.sort(reverse = True)

for i in range(competitorsQnt):
    if(i <= minNextPhase - 1):
        totalClassify += 1
    elif points[i - 1] == points[i]:
        totalClassify += 1
    else:
        break

print(totalClassify)