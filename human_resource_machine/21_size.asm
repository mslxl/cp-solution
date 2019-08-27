-- HUMAN RESOURCE MACHINE PROGRAM --

a:
    COPYFROM 5
    COPYTO   0
b:
    INBOX   
    JUMPZ    c
    ADD      0
    COPYTO   0
    JUMP     b
c:
    COPYFROM 0
    OUTBOX  
    JUMP     a


