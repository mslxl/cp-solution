getNumLine :: IO [Int]
getNumLine = map read . words <$> getLine

fillHole :: [Int] -> Int
fillHole (x : xs) = x + f' 0 (x : xs)
  where
    f' ans (x : y : ys)
      | x < y = f' (ans + y - x) (y : ys)
      | otherwise = f' ans (y : ys)
    f' ans _ = ans

main :: IO ()
main = print . fillHole =<< (getLine >> getNumLine)
