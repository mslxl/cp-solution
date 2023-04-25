main :: IO()
main = do
  fstLine <- getLine
  let n,m = map read $ words $ fstLine ::[Int]
