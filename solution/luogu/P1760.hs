{-# LANGUAGE Strict #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char

int :: String -> Integer
int x = fromIntegral $ int' x 0
  where
    int' [] num = num
    int' (x : xs) num = int' xs $ num * 10 + (ord x - ord '0')

solve :: Integer -> Integer
solve 1 = 1
solve x = 1 + 2 * solve (x - 1)

putInt :: Integer -> IO ()
putInt 0 = putStr "0"
putInt x = putInt' x
  where
    putInt' 0 = return ()
    putInt' n = do
      putInt' $ n `div` 10
      putStr . show $ n `mod` 10
      return ()

main :: IO ()
main = getLine >>= putInt . solve . int
