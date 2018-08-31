count = int(input("How many Natural numbers to print? "))
if count <= 0 :
	print("Please enter a positive number.")
	
if count == 1 :
	print("First  Natural number is 1.")
if count > 1 :
	print("First ", count, " Natural numbers are 1", sep='', end='')
	counter = 1;
	for counter in range(2, count):
		print(", ", counter, sep='', end ='')
	print(" and ", count, ".", sep='', end='')
