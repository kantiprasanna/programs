package main
import "fmt"


func main() {
	var count int
	var counter int
	fmt.Print("How many natural numbers to print? ")
	fmt.Scan(&count)
	if count <= 0 {
		fmt.Print("Please enter a positive number.")
		
	}
	 if count == 1 {
		fmt.Print("First Natural number is 1.")
		
	}
	if count > 1 {
		counter = 1
		fmt.Printf("First %d Natural numbers are 1", count)
		for i := 0; i < count - 2; i++ {
			counter = counter + 1
			fmt.Printf(", %d", counter)

			
		}
		fmt.Printf(" and %d.", count)
	}
}