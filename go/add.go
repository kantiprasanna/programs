package main

import "fmt"

func add(number1, number2 int) int {
	return number1 + number2
}

func main() {
	var number1 int
	var number2 int
	var sum int
	fmt.Print("Enter the first number: ")
	fmt.Scan(&number1)
	fmt.Print("Enter the second number: ")
	fmt.Scan(&number2)
	sum = add(number1, number2)
	fmt.Printf("Sum of %d and %d is %d.", number1, number2, sum)
}
