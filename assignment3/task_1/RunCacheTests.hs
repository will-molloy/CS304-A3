#!/bin/runhaskell
 
{-# LANGUAGE OverloadedStrings #-}
import System.Process
import Data.List

main :: IO ()
main =
   putStrLn "N size_of_a linear random" >> mapM_ line (fmap (\x -> 2 ^ x) range) 

line :: Int -> IO ()
line n = do
    tLinear <- readProcess cmdLinear theArgs [] 
    tRandom <- readProcess cmdRandom theArgs [] 

    putStrLn $ formatLine tLinear tRandom
    where theArgs = "--repetitions" : "1000" : "--array_size" : show n : []
          formatLine a b = intercalate "\t" [show n, show $ n * 4, clean a, clean b]
          clean = stripZero . filter rmDot . filter rmNewLine . filter rmSpace 
          rmDot x = x /= '.'
          rmNewLine x = x /= '\n'
          rmSpace x = x /= ' '
          stripZero = dropWhile (=='0') 
 
cmdLinear :: FilePath
cmdLinear = "./cachetest1"
 
cmdRandom :: FilePath
cmdRandom = "./cachetest2"
 
range = [11..24] -- 2^11 (2048K < L1 cache of 32k) -> 2^24 (16M > L3 cache of 4M)


