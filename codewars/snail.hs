module Snail where
import Data.List

snail :: [[Int]] -> [Int]
snail = moveRight
    where
        moveRight [] = []
        moveRight xs = head xs  ++ moveDown (tail xs)
        moveDown [] = []
        moveDown xs = map last xs ++ moveLeft (map init xs)
        moveLeft [] = []
        moveLeft xs = reverse (last xs) ++ moveUp (init xs)
        moveUp [] = []
        moveUp xs = reverse (map head xs) ++ moveRight (map tail xs)


snail' :: [[Int]] -> [Int]
snail' [] = []
snail' (xs:xss) = xs ++ (snail . reverse . transpose) xss