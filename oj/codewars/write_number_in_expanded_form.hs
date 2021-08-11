module Kata where
import Data.List

-- https://www.codewars.com/kata/5842df8ccbd22792a4000245/solutions/haskell

expandedForm :: Int -> String
expandedForm i = drop 3 $ foldl (\b a -> b ++ " + " ++ show a) "" $ filter (/= 0) $ reverse $ multiply $ nums i
  where
    nums n = if n > 9
             then (n `mod` 10) : nums (n `div` 10) 
             else [n]
    multiply = zipWith (curry addZero) [1 .. ]
    addZero (nZero,num) = num * 10^(nZero-1)