{-# LANGUAGE TupleSections #-}
import Data.List
import Data.IORef
import Data.Fixed

import Control.Monad
import Control.Applicative

import System.IO
import System.Environment
import System.Directory
import System.Posix.Directory
import System.Posix.Files
-- ** Pure World **
langDict = [("py","Python"),
            ("cpp","Cpp"),
            ("h","Cpp"),
            ("hs","Haskell"),
            ("kt","Kotlin"),
            ("md","Text"),
            ("txt","Text"),
            ("json","Config"),
            ("code-snippets","Config"),
            ("gitignore","Config"),
            ("rs","Rust"),
            ("asm","Asm"),
            ("js","JavaScript")]

ignoreDir = [".","..",".git"]

type DigitFixed = Fixed E3

getLangNameByFile :: FilePath -> String
getLangNameByFile path = matchName
  where
    extension = reverse $ takeWhile (/= '.') $ reverse path
    matchName = maybe (extension ++ "?") id (lookup extension langDict)

getLangTotalSize :: [(String,Integer)] -> [(String, Integer)]
getLangTotalSize ls = foldl sizeSum [] $ sortOn name ls
  where
    name (n,s) = n 
    sizeSum [] a = [a]
    sizeSum b@((bn,bi):bs) a@(an,ai)
      | bn == an = (bn,bi+ai) : bs
      | otherwise = a : b

getLangPercentage :: [(String, Integer)] -> [(String,DigitFixed)]
getLangPercentage ls = map percentage $ getLangTotalSize ls
  where
    totalSize = sum $ map snd ls
    percentage (name,size) = (name,) (fromInteger size / fromInteger totalSize :: DigitFixed)
    

showPercentage :: [(String,DigitFixed)] -> String
showPercentage [] = ""
showPercentage ((name,percent):ls) = name ++ "\t\t" ++ show (percent * 100) ++ "%\n" ++ showPercentage ls

-- ** Impure World **

workDir :: IO FilePath
workDir = getArgs >>= (\xs -> if null xs then getWorkingDirectory else head <$> getArgs)


getAllFiles :: FilePath -> IO [FilePath]
getAllFiles path = do
  child <- getDirectoryContents path
  -- let children = map (\name -> path++"/"++name) $ filter (\x -> (x/=".") && (x/="..")) child
  let children = map (\name -> path++"/"++name) $ filter (`notElem` ignoreDir) child
  status <- mapM (\m -> (m,) <$> getFileStatus m) children
  let file = map fst $ filter (not . isDirectory . snd) status
  let dir = map fst $ filter (isDirectory . snd) status
  childFile <- mapM getAllFiles dir
  return $ file ++ concat childFile


pairFileSize :: [FilePath] -> IO [(FilePath, Integer)]
pairFileSize = mapM pair
  where
    pair path =(path,) <$> getFileSize path

main :: IO()
main = do
  pair <- workDir >>= getAllFiles >>= pairFileSize
  let langData = getLangPercentage $ map (\(p,s) -> (,s) $ getLangNameByFile p) pair
  putStrLn $ showPercentage $ sortOn (length . fst) langData
