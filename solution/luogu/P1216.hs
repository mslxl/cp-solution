import Control.Monad

splitNum :: String -> [Int]
splitNum s = map read $ words s

getMap :: IO [[Int]]
getMap = do
  r <- read <$> getLine
  replicateM r (splitNum <$> getLine)

toDeep :: [[Int]] -> Int -> Int -> Int
toDeep map y x
  | y == length map = 0
  | x == length (map !! y) = 0
  | otherwise = max (toDeep map (y + 1) x) (toDeep map (y + 1) (x + 1)) + map !! y !! x

main :: IO ()
main = getMap >>= print . (\x -> toDeep x 0 0)
