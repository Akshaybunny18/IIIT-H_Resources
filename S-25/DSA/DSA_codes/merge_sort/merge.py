def merge(lis,start,end) :
    li=[]
    k=0
    i=start
    j=(start+end)//2+1
    mid=(start+end)//2
    while(i<=mid and j<=end) :
        if lis[i]>lis[j] :
            li.append(lis[j])
            j+=1
            k+=1
        else :
            li.append(lis[i])
            k+=1
            i+=1
    while(i<=mid) :
        li.append(lis[i])
        k+=1
        i+=1
    while(j<=end) :
        li.append(lis[j])
        j+=1
        k+=1
    for a in range(0,k,1) :
        lis[start+a]=li[a]
def merec(lis,start,end) :
    if start!=end :
        merec(lis,start,(start+end)//2)
        merec(lis,(start+end)//2+1,end)
        merge(lis,start,end)
    else :
        return
x=int(input("Enter length of list : "))
l=[]
for a in range (1,x+1,1) :
    l.append(int(input(f"Enter value of {a}th element of list : ")))
merec(l,0,x-1)
print(l)
