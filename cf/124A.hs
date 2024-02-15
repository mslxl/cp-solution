main :: IO()
main = do
  [a, b, r] <- map read <$> words <$> getLine
  if 2 * r > min a b
  then putStr "Second"
  else putStr "First"
