.section .text
.global pal

pal:
    # rdi = str pointer, rsi = n (length)
    pushq %rbp
    movq %rsp, %rbp
    
    movq $0, %r8 #i = 0
    movq %rsi, %r9     
    shrq $1, %r9 #j = n/2
    
loop:
    cmpq %r9, %r8 # if i >= j
    jge endtrue #return true
    
    movq %rdi, %r10 #get str[i]
    addq %r8, %r10
    movb (%r10), %r10b #character at str[i]
    
    movq %rsi, %r11 #calculate n-i-1
    subq %r8, %r11
    subq $1, %r11
    
    movq %rdi, %r12 #get str[n-i-1]
    addq %r11, %r12
    movb (%r12), %r11b #character at str[n-i-1]
    
    cmpb %r10b, %r11b #compare characters
    jne endfalse #if not equal, return false
        
    next:
        incq %r8 # i++
        jmp loop
    
    endfalse:
        movq $0, %rax #return false
        jmp end
        
    endtrue:
        movq $1, %rax #return true
        
    end:
        popq %rbp #restore base pointer
        ret
        