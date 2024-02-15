@echo off
:loop
echo AC
python rand.py >data.txt
std.exe<data.txt>std.txt
main.exe<data.txt>main.txt
fc std.txt main.txt
if not errorlevel 1 goto loop
echo WA
pause
goto loop