% This is homework 5 for CSE240 in PROLOG.  The following problem cover various aspects and functions of the prolog language.  
% 
%
% @author Adam Clifton,
% @version 2018.09.30


% PROBLEM 1:  the above header



% PROBLEM 2: Write the following statement as prolog clauses (one fact and one rule):  “weather is hot. if weather is hot, everyone like it.”

%facts
hot(weather).
%rules
likes(_X,weather) :- hot(weather).



% PROBLEM 3: Do these different queries produce the same result in prolog? Why? 

% ?- N is -(+(5,6),4).  % this takes the inner parenthesis first, adds 5 to 6, then does the outer parenthesis to subtract 4.  Result is 7.
% ?- N is (5+6)-4.		% this adds the parenthesis then subtracts 4. Result is 7



% PROBLEM 4: For each of the following English statements write a prolog program. 

% Facts & Rules
%(1) jane is a woman. 
	woman(jane).
%(2) john is a man. 
	man(john).
%(3) john is healthy.
	healthy(john).
%(4) jane is healthy. 
	healthy(jane).
%(5) john is wealthy. 
	wealthy(john).
%(6) anyone is a traveler if he is healthy and wealthy. 
	traveler(X) :- healthy(X), wealthy(X).
%(7) anyone can travel if he is a traveler. 
	travel(X) :- traveler(X).

% Goals (queries). 
%(8) Who can travel? 
	travel(X).
	% John can travel because he is healthy and wealthy
%(9) Who is healthy and wealthy? 
	healthy(X), wealthy(X). 
	% John 



% PROBLEM 5: What answers do you get for below queries for this given program? 

% Facts & Rules
vegetarian(jose).
vegetarian(james).   
vegetable(carrot).   
vegetable(egg_plant).   
likes(jose, X) :- vegetable(X).   
loves(Who, egg_plant) :- vegetarian(Who). 
 
% This are queries. You do not need to copy the ?- symbol
?- vegetable(X).   
	carrot
?- vegetable(potato). 
	false
?- likes(jose, What). 
	carrot
?- likes(Who, egg_plant). 
	Jose
?- loves(Who, egg_plant).
	Jose
	
	
	
% PROBLEM 6: Given the fact, rules, and queries below
 
 % Facts & Rules  
 fib(1,1). 
 fib(2,1). 
 fib(N,R):- 
	N >= 3, 
	N1 is N-1, 
	N2 is N-2, 
	fib(N1,R1), 
	fib(N2,R2), 
	R is R1+R2. %fib function ((n-1) + (n-2))
	
 % Goals (queries) 
 ?- fib(9,R). 	% 34
 ?- fib(9,9).	% false
 
a) Write English statement for the facts and rule.  
	%facts
	The fibonacci sequence of 1 is 1.
	The fibonacci sequence of 2 is 1.
	%rule
	The fibonacci sequence is defined as result F(N) = ( (F(N-1)) + (F(N-2)) ) if number N is greater than or equal to 3. 
	
b) Describe step by step how the fib (3) is calculated. 
	The program looks to match fib(3) value to 1, 2 or >=3.
	3 is not 1.
	3 is not 2.
	3 is >= 3.  Calculate fib(N,R) where F(N) = ( (F(N-1)) + (F(N-2)) ).  
		N1 and N2 are calculated first, then placed into the above function. F(N) = ( (F(N1)) + (F(N2)) )
		F(2) = 1. F(1) = 1. R is then calculated.
		R = ((1) + (1)) = 1 + 1 = 2
			R = 2.
	
c) What is the answer of the two queries listed in blue. Explain them.
	fib(9,R). 	% This is taking the number 9 and applying the fibonacci sequence (((n-1) + (n-2)) to it.  The result is 34.
	fib(9,9).	% This is testing whether application the fibonacci sequence of 9 results in the number 9. 
				% The result is false.  The correct result is 34.


				
% PROBLEM 7: For below English sentences write applicable Prolog facts, rules & goals. 

a) John reads programming book. 
	%facts
	reads(John, programming_book).
	
b) Anyone likes sparky if he,she is an ASU student. .
	%facts and rules
	ASU(student).
	likes(X, sparky) :- ASU(student).
	
c) Who likes sparky?
	%rules
	likes(Who, sparky).
	
d) Jane hates any city if it is big and crowded.		
	%facts and rules
	big(city).
	crowded(city).
	hates_city(Jane) :- big(city), crowded(city).


	
	
% PROBLEM 8: Write the facts and rules, that compute the sum of the first n numbers. For example,  
 
%facts
sum(0,0).

% rules
% the factorial of X is N+X1
% if N > 0 and
% N1 is N-1 and
% the sum of N1 is F1

sum(N,X) :-
    N > 0,
    N1 is N-1,
    sum(N1,X1),
    X is N + X1.  

?- sum(3, X). 
X=6 
?- sum(5,X). 
X=15 
?- sum(7,X). 
X=28 




% PROBLEM 9: Given the following facts 
cats(tom). 
black_spots(tom). 
dog(pluto). 
white_spots(pluto). 

Write in Prolog the following sentence: “If someone owns something, he loves it” 

	loves(Who, What) :- owns(Who, What).
  


