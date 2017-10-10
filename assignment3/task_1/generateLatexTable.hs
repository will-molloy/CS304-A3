#!/bin/runhaskell
 
{-# LANGUAGE OverloadedStrings #-}
import System.Process
import Data.List
 
main :: IO ()
main =
    putStrLn tabuStart >> putStr tabuStart >> putHline >> mapM_ line (fmap (\x -> 2 ^ x) range) >> putHline >> putStr tabuEnd
 
line :: Int -> IO ()
line n = do
    tLinear <- readProcess cmdLinear theArgs [] 
    tRandom <- readProcess cmdRandom theArgs [] 
    putStrLn "\\hline"
    putStr $ formatLine tLinear tRandom
    putStrLn "\\\\"
    where theArgs = "--array_size" : show n : []
          formatLine a b = intercalate " & " [show n, show $ n * 4, clean a, clean b, show $ diff a b]
          clean = stripZero . filter rmDot
          rmDot x = x /= '.'
          stripZero = dropWhile (=='0')
          diff a b = (fromIntegral (read $ clean b :: Integer) - fromIntegral (read $ clean a :: Integer)) / fromIntegral (read $ clean b :: Integer)
 
cmdLinear :: FilePath
cmdLinear = "./cachetest1"
 
cmdRandom :: FilePath
cmdRandom = "./cachetest2"
 
range = [11..24] -- (2^11, 2048 -> ..)
 
putHline = putStrLn "\\hline"
 
tabuStart = "\\begin{tabu} to 1\\linewidth { | X[c] | X[c] | X[c] | X[c] | X[c] }\n" ++
    "N & Size of \\texttt{a} & time per iteration/ns & time per iteration/ns & Difference \\% \\\\ \n \\hline \n " ++
    " & & case 1 & case 2 & \\\\\n"
 
tabuEnd = "\\end{tabu}"

