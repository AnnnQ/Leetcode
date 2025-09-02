#输入获取
arr = list(map(lambda s: s.split(","), input().split(";")))

def compareWithZero(val, constraint):
    if constraint == ">" :
        return val > 0
    elif constraint == ">=" :
        return val >= 0
    elif constraint == "<" :
        return val < 0
    elif constraint == "<=" :
        return val <= 0
    else:
        return False
    
#算法入口
def getResult(arr):
    a11, a12, a13, a14, a15 = map(float, arr[0])
    a21, a22, a23, a24, a25 = map(float, arr[1])
    a31, a32, a33, a34, a35 = map(float, arr[2])
    x1, x2, x3, x4, x5 = map(float, arr[3])
    b1, b2, b3 = map(float, arr[4])
    y1, y2, y3 = arr[5]

    diff1 = a11 * x1 + a12 * x2 + a13 * x3 + a14 * x4 + a15 * x5 - b1
    diff2 = a21 * x1 + a22 * x2 + a23 * x3 + a24 * x4 + a25 * x5 - b2
    diff3 = a31 * x1 + a32 * x2 + a33 * x3 + a34 * x4 + a35 * x5 - b3

    flag = compareWithZero(diff1, y1) and compareWithZero(diff2, y2) and compareWithZero(diff3, y3) 

    maxDiff = max(abs(diff1), abs(diff2), abs(diff3))

    print(f"{flag} {int(maxDiff)}".lower())

#调用入口
getResult(arr)

