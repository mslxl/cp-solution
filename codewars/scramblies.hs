module Codewars.G964.Scramblies where
import Data.List
import Data.Char

-- https://www.codewars.com/kata/55c04b4cc56a697bb0000048/solutions/haskell

scramble :: String -> String -> Bool
scramble s1 s2 = all (\x->length x <= countNum (head x) ss1) ss2
  where ss1 = group $ sort s1
        ss2 = group $ sort s2
        countNum c [] = 0
        countNum c (x:xs) = if c `elem` x
                            then length x
                            else countNum c xs