module Rot13 where

import Data.Char

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
target = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"
dict = zip alphabet target

rot13 :: String -> String
rot13 = map encode
    where encode char = case lookup char dict of
                            (Just x) -> x
                            Nothing -> char