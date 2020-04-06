module Pangram where
import Data.Char
import Data.List

-- https://www.codewars.com/kata/545cedaa9943f7fe7b000048/solutions/haskell

isPangram :: String -> Bool
isPangram str = all (`elem` s) ['a'..'z']
    where
        s = map toLower str