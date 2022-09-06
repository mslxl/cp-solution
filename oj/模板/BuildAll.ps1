Get-Item *.cpp | ForEach-Object { g++ -Wall -Wextra -S $_.FullName }
Pause