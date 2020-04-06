module Codewars.G964.Accumule where
import Data.Char

accum :: String -> String
accum s = init $ run (map toLower s) 1
    where
        run [] _ = []
        run (x:xs) i = toUpper x : replicate (i-1) x ++ "-" ++ run xs ( i + 1)