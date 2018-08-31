count = int(input("Enter the number upto which even numbers are required? "))
if count <= 0 :
	print("Please enter a positive number.")
	
if count == 1 :
	print("There are no even numbers.")
if count >= 2 :
	print("Even numbers upto ", count, " are 2", sep='', end='')
	if(count > 3):
		for counter in range(4, count, 2):
			print(", ", counter, sep='', end ='')
		if(count % 2 == 0):
			print(", ", count, ".", sep='', end='')
