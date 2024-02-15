import Data.Bits
import Control.Monad

lowbit :: Integer -> Integer
lowbit x = (.&.) (-x) x

calc :: Integer -> [Integer]
calc 1 = [1]
calc x | lowbit x == x = x : (calc $ x `div` 2)
       | otherwise = x : (calc $ x - lowbit x)

solve x = (putStrLn $ show $ length ans) >> (putStrLn $ unwords $ map show $ calc x)
  where ans = calc x

main :: IO()
main = (read <$> getLine) >>= (flip replicateM_ $ ((read <$> getLine) >>= solve))