module Main where

add :: integer -> integer -> integer

add firstNumber secondNumber = firstNumber + secondNumber

main = do
	putStrLn "Enter the first number: "
	firstNumberStr <- readLn
	let firstNumber = read firstNumberStr :: Int
	putStrln "Enter the second number: "
	secondNumberStr <- readLn
	let secondNumber = read secondNumberStr :: Int
	print add(firstNumber, secondNumber)