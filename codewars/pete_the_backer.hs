module Baker where

type Ingredient = String
type Amount     = Int
type Recipe     = [(Ingredient, Amount)]
type Storage    = [(Ingredient, Amount)]

-- https://www.codewars.com/kata/525c65e51bf619685c000059/solutions/haskell

cakes :: Recipe -> Storage -> Int
cakes recipe storage =  minimum $ map run recipe
    where
        run item = case lookup (fst item) storage of
                        (Just s) -> div s (snd item)
                        Nothing -> 0