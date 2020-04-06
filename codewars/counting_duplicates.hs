module Codwars.Kata.Duplicates where
import Data.List
import Data.Char

-- https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1/solutions/haskell

duplicateCount :: String -> Int
duplicateCount str = sum $ map (\c->if isDuplicate c text then 1 else 0) alphabet
    where 
        text = map toLower str
        alphabet = ['a'..'z'] ++ ['0'..'9']
        isDuplicate x str = sum  (map (\c->if c==x then 1 else 0) str) > 1

        
duplicateCount' :: String -> Int
duplicateCount' str = length $ filter (\x->length x > 1) $ group $ sort $ map toLower str