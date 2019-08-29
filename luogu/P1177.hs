-- O2 优化害死人
-- 会加以 // 开头的‘注释'

-- 语言劣势 会TLE+MLE
-- 总之不能满分

-- 两者思路都在下面了
-- 放弃优化了
import Control.Monad
import Control.Applicative

filterSplit :: (a -> Bool) -> [a] -> ([a],[a])
filterSplit _ [] = ([],[])
filterSplit f (x:xs) | f x = ((x:l),r)
                     | otherwise = (l,(x:r))
    where (l,r) = filterSplit f xs

quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort [x] = [x]
quickSort (x:xs) = quickSort l ++ [x] ++ quickSort r
    where (l,r) = filterSplit (<x) xs

quickSort' :: (Ord a) => [a] -> [a]
quickSort' [] = []
quickSort' (x:xs) = quickSort [i | i <- xs, i <= x]
    ++ [x]
    ++ quickSort [i | i <- xs, i > x]

main::IO()
main = do
    getLine
    array <- fmap (map read . words) getLine :: IO[Int]
    let re = quickSort array
    sequence_ $ map (\x -> putStr $ show x ++ " ") re