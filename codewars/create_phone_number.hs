module CreatePhoneNumber where
-- https://www.codewars.com/kata/525f50e3b73515a6db000b83/solutions/haskell/all/newest
createPhoneNumber :: [Int] -> String
createPhoneNumber xs = let pBlock = map (head . show) $ take 3 xs
                           pNum = map (head . show) $ take 3 $ drop 3 xs
                           pTail = map (head . show) $ drop 6 xs
                        in '(' : pBlock ++ ") " ++ pNum ++ "-" ++ pTail
                        