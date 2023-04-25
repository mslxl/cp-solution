-- 7 Billion Humans (2212:2214M) --
-- 10: Emergency Escapades --

a:
if c == 1:
	step n
endif
if c == 4 or
 c == nothing:
	step w
endif
if c == 3:
	step s
endif
if c == 2:
	step e
endif
jump a


