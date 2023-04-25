module Narcissistic where
import Data.List

-- https://www.codewars.com/kata/5287e858c6b5a9678200083c/solutions/haskell

narcissistic :: Integral n => n -> Bool
narcissistic n = run (show num) == num
    where
        num = fromIntegral n::Integer
        len = length $ show num
        run [x] = (read [x]::Integer ) ^ len
        run (x:xs) = read [x] ^ len + run xs