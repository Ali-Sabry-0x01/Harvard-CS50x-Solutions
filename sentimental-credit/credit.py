import sys
s = input("Number: ")
length = len(s)
if length < 13 or length > 16 :
    print ("INVALID")
    sys.exit()
else:
    card_list = [int(x) for x in s[::-1]]
    total1  , total2 = 0 , 0
    for i in range(1 , length , 2) :
        n = card_list[i]*2
        if n > 9 :
            two = str(n)
            n = int(two[0]) + int(two[1])
        total1 += n
    for i in range(0 , length , 2) :
        total2 += card_list[i]
    if (total1 + total2)% 10 == 0 :
        # chech all banks
        if length == 15 and (s[0:2] == "34" or s[0:2] == "37"):
            print ("AMEX")
            sys.exit()
        elif length == 16 and (int(s[0:2]) > 50 and int(s[0:2]) < 56):
            print ("MASTERCARD")
            sys.exit()
        elif s[0] == "4" and (length == 13 or length == 16):
            print("VISA")
            sys.exit()
        else:
            print("INVALID")
            sys.exit()
    else:
        print ("INVALID")
        sys.exit()
