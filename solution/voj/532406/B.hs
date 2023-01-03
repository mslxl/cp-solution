main::IO()
main = do
  input <- getLine
  let w = read input::Int
  if even w && w > 2
  then putStr "YES"
  else putStr "NO"
  