def product (firstNumber, secondNumber, thirdNumber)
	return firstNumber * secondNumber * thirdNumber
end

puts("Enter the first number: ")
firstNumber = gets.to_i
puts("Enter the second number: ")
secondNumber = gets.to_i
puts("Enter the third number: ")
thirdNumber = gets.to_i
result = product(firstNumber, secondNumber, thirdNumber)
print "Product of #{firstNumber}, #{secondNumber} and #{thirdNumber} is #{result}."