-- 7 Billion Humans (2212:2214M) --
-- 6: Little Exterminator 1 --

a:
if s != hole:
	step s
	pickup c
endif
if s == hole and
 se == hole and
 w != hole and
 nw == hole:
	step w
endif
if s == hole and
 sw == hole and
 e != hole:
	step e
endif
jump a


