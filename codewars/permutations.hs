module Codewars.Kata.Permutations (permutations) where
import Data.List(delete,nub)

permutations :: String -> [String]
permutations [] = [[]]
permutations xs = [y:ys | y <- nub xs, ys <- permutations (delete y xs)]
