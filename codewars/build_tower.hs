module Codewars.BuildTower where
import Data.List

-- https://www.codewars.com/kata/576757b1df89ecf5bd00073b/solutions/haskell

buildTower :: Int -> [String]
buildTower total = map buildFloor [1..total]
  where buildFloor i = air (total - i) ++ block (2 * i - 1) ++ air (total - i)
        block num = replicate num '*'
        air num = replicate num ' '