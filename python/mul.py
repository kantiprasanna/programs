def product(number1, number2, number3):
	return number1 * number2 * number3
	

number1 = int(input("Enter first number: "))
number2 = int(input("Enter second number: "))
number3 = int(input("Enter third number: "))
product = product(number1, number2, number3)
print("Product of ", number1, ", ", number2, " and ", number3, " is ", product, "." , sep='')
