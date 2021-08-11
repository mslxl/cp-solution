-- Problem 1
myLast (x:xs)=if null xs then x else myLast xs

myLast' [x] = x
myLast' (_:xs) = myLast' xs

myLast'' = head . reverse

myLast''' x = x !! (length x - 1)

-- Problem 2
myButLast = head . drop 1 . reverse

myButLast' (x:xs) = if length xs == 1 then x else myButLast' xs

myButLast'' = last . init

myButLast''' x = x !! (length x - 2)

myButLast'''' (x:[b]) = x
myButLast'''' (x:xs) = myButLast'''' xs

-- Problem 3
elementAt x i = x !! (i-1)

elementAt' _ 0 = error "Index out of bounds"
elementAt' (x:xs) 1 = x
elementAt' (x:xs) i = elementAt' xs ( i - 1) 

elementAt'' = flip $ (last .). take

elementAt''' x i = head $ drop (i-1) x

-- Problem 4
myLength (x:xs) = myLength xs + 1
myLength [] = 0 

myLength' = sum . map (const 1)

-- Problem 5
myReverse (x:xs) = myReverse xs ++ [x]
myReverse [] = []



-- Problem 6
isPalindrome [x] = True
isPalindrome x = (length x `mod` 2 /= 0) &&
                 (head x == last x) &&
                 (isPalindrome $ init $ tail x)

-- Problem 7
data NestedList a = Elem a | List [NestedList a]
flatten :: NestedList a -> [a]
flatten (Elem x) = [x]
flatten (List []) = []
flatten (List xs) =foldl1 (++) $ map flatten xs

-- Problem 8
compress :: String -> String
compress [] = []
compress [x] = [x]
compress (x:y:s) 
  | x /= y = x : compress (y:s)
  | otherwise = compress (y:s)

-- Problem 9
-- I failed
pack :: String -> [String]
pack [] = []
pack (x:xs) = let (first, rest) = span (==x) xs
              in (x:first) : pack rest

