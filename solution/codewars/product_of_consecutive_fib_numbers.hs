module Codewars.Kata.Fib where

-- | Returns a pair of consecutive Fibonacci numbers a b,
--   where (a*b) is equal to the input, or proofs that the
--   number isn't a product of two consecutive Fibonacci 
--   numbers.

-- https://www.codewars.com/kata/5541f58a944b85ce6d00006a/solutions/haskell


productFib :: Integer -> (Integer, Integer, Bool)
productFib n = case findIndex of (x,i)->(fibs !! i ,fibs !! (i + 1),x == EQ)
    where
        findIndex = findIndex' products 0
        findIndex' (x:xs) i | n == x = (EQ, i)
                            | n > x = findIndex' xs $ i + 1
                            | n < x = (GT, i)

products::[Integer]                           
products = map (\x-> fibs !! x * fibs !!(x+1)) [0..]

fibs::[Integer]
fibs = map fst $ iterate fibStep (0,1)
    where
        fibStep (u,v) = (v,u+v)