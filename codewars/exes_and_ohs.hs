module Codewars.Kata.XO where
import Data.Char
import Data.List

-- https://www.codewars.com/kata/55908aad6620c066bc00002a/solutions/haskell/all/best_practices

-- | Returns true if the number of
-- Xs is equal to the number of Os
-- (case-insensitive)
xo :: String -> Bool
xo = eq . run (0,0) . map toLower
    where
        run (f,s) ('x':xs) = run  (f + 1,s) xs
        run (f,s) ('o':xs) = run  (f,s + 1) xs
        run s (x:xs) = run s xs
        run s [] = s
        eq (f,s) = f == s
    