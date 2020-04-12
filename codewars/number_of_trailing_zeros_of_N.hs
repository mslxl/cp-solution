module Zeros where
-- https://www.codewars.com/kata/52f787eb172a8b4ae1000a34/solutions/haskell/all/newest
zeros :: Int -> Int
zeros n | n > 4 = (n `div` 5) + zeros (n `div` 5) 
        | otherwise = 0