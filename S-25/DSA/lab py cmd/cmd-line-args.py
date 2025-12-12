import sys    
n = len(sys.argv)  
if n <= 1:
   print("No arguments were given")
else:
   i = 0
   while (i < n): 
      print(sys.argv[i]) 
      i = i+1
      continue
