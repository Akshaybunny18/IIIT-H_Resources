from swap import swap

def Fi(x):
    (a,b,c)=x
    if b==len(a)-c-1 :
        return x
    else :
        if(a[b]>a[b+1]) :
            swap(a,b,b+1)
        return(a,b+1,c)