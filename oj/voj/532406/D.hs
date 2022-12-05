import Control.Monad

solve::IO()
solve = do
  line <- getLine
  if length line <= 10
  then putStrLn line
  else putStrLn $ [head line] ++ show (length line - 2) ++ [last line]


main::IO()
main = getLine >>= flip replicateM_ solve . read
