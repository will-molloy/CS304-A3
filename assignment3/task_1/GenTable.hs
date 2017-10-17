#!/bin/runhaskell
 
{-# LANGUAGE OverloadedStrings #-}
import System.Process
import Data.List
 
main :: IO ()
main =
    putStrLn tabuStart >> putHline >> mapM_ line (fmap (\x -> 2 ^ x) range) >> putHline >> putStr tabuEnd
 
line :: Int -> IO ()
line n = do
    tLinear <- readProcess cmdLinear theArgs [] 
    tRandom <- readProcess cmdRandom theArgs [] 
    putStrLn "\\hline"
    putStr $ formatLine tLinear tRandom
    putStrLn "\\\\"
    where theArgs = "--repetitions" : "10000" : "--array_size" : show n : []
          formatLine a b = intercalate " & " [show n, show $ n * 4, clean a, clean b]
          clean = stripZero . filter rmDot
          rmDot x = x /= '.'
          stripZero = dropWhile (=='0')
 
cmdLinear :: FilePath
cmdLinear = "./cachetest1"
 
cmdRandom :: FilePath
cmdRandom = "./cachetest2"
 
range = [11..24] -- 2^11 (2048 < L1 cache of 32k) -> 2^24 (16M > L3 cache of 6M)
 
putHline = putStrLn "\\hline"
 
tabuStart = "\\begin{tabu} to 1\\linewidth { | X[c] | X[c] | X[c] | X[c] |}\n" ++
    "\\textit{N} & Size of \\texttt{a} & time per iteration/ns & time per iteration/ns \\% \\\\ \n \\hline \n " ++
    " & & Case 1: Linear & Case 2: Random \\\\\n"
 
tabuEnd = "\\end{tabu}"
