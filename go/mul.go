package main
import "fmt"

func product(number1, number2, number3 int) int {
	return number1 * number2 * number3	
}

func main(){
	var number1 int
	var number2 int 
	var number3 int
	var result int
	fmt.Printf("Enter the first number: ")
	fmt.Scan(&number1)
	fmt.Printf("Enter the second number: ")
	fmt.Scan(&number2)
	fmt.Printf("Enter the third number: ")
	fmt.Scan(&number3)
	result = product(number1, number2, number3)
	fmt.Printf("Product of %d, %d and %d is %d.", number1, number2, number3, result)
}