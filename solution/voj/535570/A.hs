main = let wrap = show . solve . read
  in interact $unlines . map wrap . lines
  where
    solve a | a <= 2 = a
            | otherwise = sum $map solve $  (flip (-) <$> [1,2]) <*> pure a
