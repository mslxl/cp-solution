module OnesAndZeroes (toNumber) where

-- https://www.codewars.com/kata/578553c3a1b8d5c40300037c/solutions/haskell

toNumber :: [Int] -> Int
toNumber = run 0
    where
        run i [x] = x * 2^i
        run i n = last n * 2^i + run (i + 1) (init n)