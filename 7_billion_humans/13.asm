-- 7 Billion Humans (2144) --
-- 13: Injection Sites 2 --

pickup s
a:
if e == worker and
 s == datacube or
 w == worker:
	step e
endif
step s
if w != datacube or
 c != nothing:
	jump a
endif
drop


