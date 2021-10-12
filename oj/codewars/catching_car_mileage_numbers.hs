module Awesome.Numbers where
import Data.List
import Data.Char

-- https://www.codewars.com/kata/52c4dd683bfd3b434c000292/train/haskell

data Answer = No | Almost | Yes deriving (Show, Read, Eq, Ord)

isInteresting :: Integer -> [Integer] -> Answer
isInteresting x xs  | x == 98 || x == 99 = Almost
                    | x < 98 = No
                    | isAllEnough x = Yes
                    | isAllEnough $ x + 1 = Almost
                    | isAllEnough $ x + 2 = Almost
                    | otherwise = No
    where
        isAllEnough num= any (\func-> func num) [isAllZero, isAllSame, isIncrementing, isDecrementing, isPalindrome, isMatchOne xs]

isAllZero :: Integer -> Bool
isAllZero num = is $ nub $ drop 1 $ show num
    where
        is x = length x == 1 && head x == '0' 

isAllSame :: Integer -> Bool
isAllSame num = (==) 1 $ length $ nub $ show num

isIncrementing :: Integer -> Bool
isIncrementing num = increment (ord (head $ show num) - 48) (show num)
    where
        increment _ [] = True
        increment 0 (x:xs) = x == '0' && null xs
        increment 9 (x:xs) = '9' == x && increment 0 xs
        increment i (x:xs) = chr (i + 48) == x && increment (i+1) xs

isDecrementing :: Integer -> Bool
isDecrementing num = decrement (ord (head $ show num) - 48) (show num)
    where
        decrement _ [] = True
        decrement 0 (x:xs) = x =='0' && null xs
        decrement i (x:xs) = chr (i + 48) == x && decrement (i-1) xs

isMatchOne:: [Integer] -> Integer -> Bool
isMatchOne = flip elem

isPalindrome:: Integer -> Bool
isPalindrome = run . show
    where 
        run [] = True
        run [_] = True
        run xs = (head xs == last xs) && run (init $ tail xs)