fn  main() {
	print!("Enter first number: ");
	let firstNumber: i32 = read!();
	print!("Enter second number: ");
	let secondNumber: i32 = read!();
	print!("Sum of {} and {} is {}", firstNumber, secondNumber, add(firstNumber, secondNumber));


}

fn add(firstNumber, secondNumber){
	sum = firstNumber + secondNumber;
	return sum;
}
