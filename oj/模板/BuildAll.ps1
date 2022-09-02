Get-Item *.cpp | ForEach-Object { g++ -S $_.FullName }
Pause