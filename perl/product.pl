sub product {
	($firstNumber, $secondNumber, $thirdNumber) = @_;
	$result = $firstNumber * $secondNumber * $thirdNumber;
	return $result;
}

print "Enter first number: ";
$firstNumber = <STDIN>;
#print "DEBUGG : First number is $firstNumber."
print "Enter second number: ";
$secondNumber = <STDIN>;
print "Enter third number: ";
$thirdNumber = <STDIN>;
$result = product($firstNumber, $secondNumber, $thirdNumber);
print "Product of $firstNumber, $secondNumber and $thirdNumber is $result.";