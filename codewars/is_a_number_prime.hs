module IsPrime where

isPrime :: Integer -> Bool
isPrime x
  | x <= 1 = False
  | x == 2 = True
  | otherwise = run 2
    where 
      run k
        | x `mod` k == 0 = False
        | fromInteger k <= sqrt (fromInteger x) = run (k + 1)
        | otherwise = True
