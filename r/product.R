product <- function(firstNumber, secondNumber, thirdNumber){
	result = firstNumber * secondNumber * thirdNumber
	return (result)
}

firstNumber <- readline(prompt = "Enter firsr number: ")
secondNumber <- readline(prompt = "Enter second number: ")
thirdNumber <- readline(prompt = "Enter third number: ")
#result <- product(firstNumber, secondNumber, thirdNumber)
print("Product of ", firstNumber, ", ", secondNumber, " and ", thirdNumber, " is ", product(firstNumber, secondNumber, thirdNumber), ".")
