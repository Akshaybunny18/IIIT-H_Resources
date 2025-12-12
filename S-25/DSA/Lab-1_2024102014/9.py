p1=1
p2=1
x=int(input("Enter value of N : "))
if x==1 :
    print("0")
else :
    print("0\n1")
    while(x!=2) :
        print(p2)
        x-=1
        p1,p2=p2,p1+p2
