puts "How many Natural numbers to print? "
count = gets.to_i
if count <= 0
	puts "Enter a positive number."
	
#end
elsif count == 1
	puts "First natural number is 1."
#end
else 
	print "First #{count} Natural numbers are 1"
	counter = 1;
	until counter == count - 1

		counter = counter + 1
		print ", #{counter}"

	end
	print " and #{count}."
end

