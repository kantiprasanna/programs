#add = -> (firstNumber, secondNumber) {firstNumber + secondNumber}
def add (firstNumber, secondNumber)
	return firstNumber + secondNumber
end

puts "Enter the first number: "
firstNumber = gets.to_i
puts "Enter the second number: "
secondNumber = gets.to_i
sum = add(firstNumber, secondNumber)
print "Sum of #{firstNumber} and #{secondNumber} is #{sum}."
