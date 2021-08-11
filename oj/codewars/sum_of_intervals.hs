module SumOfIntervals (sumOfIntervals) where
import Data.List

sumOfIntervals :: [(Int, Int)] -> Int
sumOfIntervals intervals = length $ nub $ foldl1 (++) $ map (\(x, y) -> [x..(y - 1)]) intervals 

