N=int(input("Enter length of list : "))
l1=[]
l2=[]
for i in range (0,N) :
  l1.append(int(input(f"Enter {i+1}th value of l1 : ")))
for i in range (0,N) :
  l2.append(int(input(f"Enter {i+1}th value of l2 : ")))
sum=0
for i in range (0,N) :
    sum+=(l1[i]*l2[i])
print(sum)
