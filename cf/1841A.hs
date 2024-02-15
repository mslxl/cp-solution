import Control.Monad

calc :: Int -> String
calc x | x < 5 = "Bob"
       | otherwise = "Alice"

main :: IO()
main = (read <$> getLine) >>= ((flip replicateM_) solve)
  where
    solve = (calc . read <$> getLine) >>= putStrLn