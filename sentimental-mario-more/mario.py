from cs50 import get_float
def calc(i , j) :
    counter = 0
    while (i / j) >= 1 :
        i -=j
        counter +=1
    return i , counter
total = 0
while True :
    change = 100 * get_float("Change: ")
    if change >= 0 :
        break
change , coins = calc (change , 25)
total += coins
change , coins = calc (change , 10)
total += coins
change , coins = calc (change , 5)
total += coins
change , coins = calc (change , 1)
total += coins
print (total)
