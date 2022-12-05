
solve::IO()
solve = do
  header <- getLine
  let h = map read $ words header
  let n = head h
  let k = last h
  list <- map (\x -> read x ::Int) . words <$> getLine
  let lele = list !! k
  print $ sum $ map (\x -> if x == lele then 1 else 0) list

  
main:: IO[()]
main = replicate <$> (read <$> getLine) <*> solve