sub add{
	($firstNumber, $secondNumber) = @_;  
	$sum = $firstNumber + $secondNumber;
	return $sum;
}


print "Enter first number: ";
$firstNumber = 3; #<STDIN>;
print "Enter second number: ";
$secondNumber = <STDIN>;
$sum = add($firstNumber , $secondNumber);
print "Sum of $firstNumber and $secondNumber is $sum."
