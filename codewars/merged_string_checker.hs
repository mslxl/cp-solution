module Codewars.Exercise.MergeChecker where

-- https://www.codewars.com/kata/54c9fcad28ec4c6e680011aa/solutions/haskell

isMerge :: String -> String -> String -> Bool
isMerge ss as [] = ss == as
isMerge ss [] bs = ss == bs
isMerge s a b = match s a b|| match s b a
    where
        match [] (_:_) _ = False
        match [] _ (_:_) = False
        match (c:cs) (x:xs) o = c == x && isMerge cs xs o