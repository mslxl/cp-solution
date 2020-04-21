module Hamming where

hamm :: [Integer]
hamm = 1 : map (2*) hamm `union` map (3*) hamm `union` map (5*) hamm
  where
    union a@(x:xs) b@(y:ys) = case compare x y of
                                LT -> x : union xs b
                                EQ -> x : union xs ys
                                GT -> y : union a ys
hamming :: Int -> Int
hamming n = fromInteger $ hamm !! (n-1)
