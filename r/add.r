add <- function(firstNumber, secondNumber){
	sum <- firstNumber + secondNumber
	 return ( sum )

}

firstNumber <- readline(prompt = "Enter first number: ")
secondNumber <- readline(prompt = "Enter second number: ")
sum <- add(firstNumber, secondNumber)
print("Sum of ", firstNumber, ", ", secondNumber, " is ", sum, ".")