import Data.Bits
import Control.Monad

mex:: Integer -> Integer
mex 0 = 0
mex x = iter x 1 2 1
	where
		iter i l r row | l <= i && i <= r = row
									 | otherwise = iter i (r + 1) (r + 2 + (r - l)) (row + 1)


solve:: [Integer] -> Bool
solve = (==) 0 . foldl1 xor . map mex 

main = do
	n <- read <$> getLine
	nums <- replicateM n (read <$> getLine)
	answer $ solve nums
	where
		answer True = putStrLn "YES"
		answer False = putStrLn "NO"


