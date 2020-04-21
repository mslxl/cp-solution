module RomanNumerals where

romeNotation :: [String]
romeNotation = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]

romeAmount :: [Integer]
romeAmount = [1000,900,500,400,100,90,50,40,10,9,5,4,1]

pair :: [(Integer,String)]
pair = zip romeAmount romeNotation

subtrahend :: Integer -> (Integer, String)
subtrahend n = head (dropWhile (\(a,_) -> a > n) pair)

solution :: Integer -> String
solution n = m ++ solution (n - rome)
  where
    (rome, m) = subtrahend n
