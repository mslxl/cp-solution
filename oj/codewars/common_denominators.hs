module Codewars.Kata.CommonDenominators where
import Data.Foldable

-- https://www.codewars.com/kata/54d7660d2daf68c619000d95/solutions/haskell

type Ratio a = (a, a) -- Data.Ratio not suitable for this kata

convertFracs :: Integral a => [Ratio a] -> [Ratio a]
convertFracs xs = let lcm = lcms $ map snd xs in
    map (\(n,d) -> ( n * (lcm `div` d),lcm)) xs
    where lcms = foldl1 lcm


convertFracs' :: Integral a => [Ratio a] -> [Ratio a]
convertFracs' xs = [(lcm `div` d * n,cd)|(n,d)<-xs]
    where cd = foldl1 lcm $ map snd xs