import random
words = ["aeroplane", "computer", "attendance", "academic", "calender", "techsquad", "xenophobia", "claustrophobia", "logophile", "ardent", "notion", "psychologist"]
name = input("Enter your name: ")
lives = 3
choice = random.randint(0, len(words) - 1)
currentWord = words[choice]
guessWord = "_ " * len(currentWord)

correctCount = 0
while(lives != 0 and correctCount != len(currentWord)):
	print(guessWord)
	c = input("Enter the character: ")
	if(c in currentWord):
		print("Yes")
		guessWord.replace(c, "-")
	else:
		lives -= 1
		print("No")

if(lives == 0):
	print("Game over")
else:
	print("You win!!!!")