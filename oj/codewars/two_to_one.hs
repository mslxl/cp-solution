module Codewars.G964.Longest where
import Data.List

-- https://www.codewars.com/kata/5656b6906de340bd1b0000ac/solutions/haskell

longest :: String -> String -> String
longest s1 s2 = process $ s1 ++ s2
    where
        process = map head . group . sort

longest' :: String -> String -> String
longest' s1 s2 = sort . nub $ s1 ++ s2