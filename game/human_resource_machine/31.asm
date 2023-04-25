-- HUMAN RESOURCE MACHINE PROGRAM --

a:
    BUMPUP   14
b:
    INBOX   
    JUMPZ    d
    COPYTO   [14]
    BUMPUP   14
    JUMP     b
c:
d:
    BUMPDN   14
    JUMPZ    a
    COPYFROM [14]
    OUTBOX  
    JUMP     c


