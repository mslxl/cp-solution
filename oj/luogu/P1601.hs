main :: IO ()
main = (*) <$> readNum <*> readNum >>= putStr . show
  where
    readNum :: IO Integer
    readNum = read <$> getLine
