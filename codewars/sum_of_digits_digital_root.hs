module DigitalRoot where
import Data.Char
import Data.List


digitalRoot :: Integral a => a -> a
digitalRoot num | num < 10 = num
                | otherwise = digitalRoot $ fromIntegral $ sum $ map (\x -> ord x - 48) (show $ fromIntegral num)