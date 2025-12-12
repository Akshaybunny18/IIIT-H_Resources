def hi(l1,l2) :
    sum=0
    for i in range (0,len(l1)) :
        sum+=(l1[i]*l2[i])
    return sum
N=int(input('Enter value of N : '))
M=int(input('Enter value of M : '))
K=int(input('Enter value of K : '))
list1=[]
list2=[]
list3=[]
for i in range (0,N):
    list1.append([])
    for j in range (0,M):
        list1[i].append(int(input(f"Enter value of matrix 1 ({i},{j}) position : ")))
for i in range (0,M):
    list2.append([])
    for j in range (0,K):
        list2[i].append(int(input(f"Enter value of matrix 2 ({i},{j}) position : ")))
for i in range (0,N):
    list3.append([])
    for j in range (0,K):
        l1=[]
        for k in range(0,M):
            l1.append(list2[k][j])
        list3[i].append(hi(list1[i],l1))
print(list3)            
