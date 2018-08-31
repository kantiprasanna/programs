print "How many natural numbers to print? ";

$count = <STDIN>;
chomp $count;
if ($count < 0) 
{
	print "Enter a positive number.";
	# body...
} elsif ($count == 1) {
	print "First even number is 1.";
	# elsif...
} else{
	$counter = 1;
	print "First $count natural numbers are 1";
	while ($counter <= ($count - 1)) {
		$counter = $counter + 1;
		print", $counter";
	}
	print ".";
	# else...
}





