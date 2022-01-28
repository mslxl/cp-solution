-- 几年后重做，这算法更能笑死我
solve :: String -> (Int, Int)
solve s = solve' s (0, 0)
  where
    solve' :: String -> (Int, Int) -> (Int, Int)
    solve' [] t = t
    solve' ('b' : 'o' : 'y' : xs) (b, g) = solve' xs (b + 1, g)
    solve' ('b' : 'o' : xs) (b, g) = solve' xs (b + 1, g)
    solve' ('b' : xs) (b, g) = solve' xs (b + 1, g)
    solve' ('o' : 'y' : xs) (b, g) = solve' xs (b + 1, g)
    solve' ('o' : xs) (b, g) = solve' xs (b + 1, g)
    solve' ('y' : xs) (b, g) = solve' xs (b + 1, g)
    solve' ('g' : 'i' : 'r' : 'l' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('g' : 'i' : 'r' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('g' : 'i' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('g' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('i' : 'r' : 'l' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('i' : 'r' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('i' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('r' : 'l' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('r' : xs) (b, g) = solve' xs (b, g + 1)
    solve' ('l' : xs) (b, g) = solve' xs (b, g + 1)
    solve' (x : xs) t = solve' xs t

putAns :: (Int, Int) -> IO ()
putAns (b, g) = print b >> putStr (show g)

main :: IO ()
main = getLine >>= putAns . solve
