-- HUMAN RESOURCE MACHINE PROGRAM --

    JUMP     b
a:
    ADD      15
    OUTBOX  
    COPYFROM 1
    OUTBOX  
b:
    COPYFROM 14
    COPYTO   1
    INBOX   
c:
    SUB      15
    JUMPN    a
    COPYTO   0
    BUMPUP   1
    COPYFROM 0
    JUMP     c


