import Data.Char

d2n :: Char -> Int
d2n c = ord c - 64

nameId :: String -> Int
nameId s = foldr ((*).d2n) 1 s `mod` 47

main :: IO()
main = do
  star <- getLine
  team <- getLine
  putStrLn $ if nameId star == nameId team
               then "GO"
               else "STAY"
