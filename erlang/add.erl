-module (add).
-export([add/2, start/0]).

add(firstNumber, secondNumber) ->
	sum = firstNumber + secondNumber,
	io:fwrite("~w~n", [sum]).

start ->
	
	add(firstNumber, secondNumber).