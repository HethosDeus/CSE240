;;;HOMEWORK 4: Use LISP to practice various types of functions and problems using booleans, lists and recursion. 
;;;
;;; Assignment 4 for CSE240
;;;
;;; Adam Clifton
;;; @version 2018.09.24



;;;PROBLEM 1:  the header above



;;;PROBLEM 2: Describe what the following code does when it is executed. 
;;;Also, provide an equivalent method/function foo in Java or C/C++

(defun foo (x y)
  (+ x y)
)
 ; running f
(print (foo 10 20))
 ; running f one more time
(print( foo 30 40))
(print (foo 40 50)) 

;;; The above preceding program assigned variables to the function named foo, similar
;;; to a creating a method and signature in OOP. The function foo executes the
;;; following function when it is run:  x + y.  Then, the program calls and prints method
;;; foo with parameters for x=10 and y=20, outputing the result of the function as 30,
;;; then also displaying 30 again as a print function call.  
;;; This is repeated twice with new variables assignments for x and y with (30 40)
;;; and (40 50), respectively. The equivalent program in cpp is as follows:
;;;
;;;#include <iostream>
;;;using namespace std;
;;;
;;;void foo (int x, int y){
;;;   cout << (x + y) << endl;
;;;}
;;;int main(){
;;;    foo(10,20);
;;;    foo(30,40);
;;;    foo(40,50);
;;;    return 0;
;;;}



;;;PROBLEM 3:  Describe what the below program does and provide an equivalent in Java, C/C++.

(defun myPrint (l)
  (if (not (null l))
      (progn
        (print ( car l))
        (myPrint (cdr l)))))
;running f
(myPrint (quote (1 2 3 4 5 ) ) )
;running f again
(myPrint (quote (6 7 8 9 0 ) ) )
;running f one more time
(myPrint (quote ("a" "e" "i" "o" "u" ) ) )

;;; The above program creates function called myPrint with one variable called 'l'. When myPrint
;;; is called, if the variable 'l' is not NULL, the function will print the first element of 'l'. 
;;; Then, myPrint is called to print the remaing elements in 'l' until it reached an empty element
;;; and prints NIL. When the function is called with quote (1 2 3 4 5 ), it first prints 1, then
;;; prints the remaining 2 3 4 5 and NIL.  quote (6 7 8 9 0) returns 6, then 7 8 9 0 and NIL. 
;;; quote ("a" "e" "i" "o" "u") returns a, the e i o u and NIL.  A similar function in C++ is:

;;;public class myPrint{
;;;
;;;	static void first (String x)
;;;	{
;;;		System.out.println(x.substring(0, 1));
;;;	}
;;;
;;;	static void rest (String x)
;;;	{
;;;		System.out.println(x.substring(1, x.length()) + "\n");
;;;	}
;;;
;;;   public static void main(String []args){   
;;;        String quote1 = "12345";
;;;        myPrint.first(quote1);
;;;     myPrint.rest (quote1);
;;;        
;;;        String quote2 = "67890";
;;;        myPrint.first(quote2);
;;;        myPrint.rest (quote2);
;;;        
;;;        String quote3 = "aeiou";
;;;        myPrint.first(quote3);
;;;       myPrint.rest (quote3);
;;;     }
;;;} 



;;; PROBLEM 4:  Write ITERATIVE function that calculates the factorial of a positive integer and returns the result.
;;;public static double factorial1 (double n) {
;;;		double sum = 1;
;;;		for (double i=0; i < n; i++)
;;;			sum = sum * (1 + i);
;;;		return sum;
;;;}

(defun factorial1 (n)
  (let ((sum 1))
    (dotimes (i n)
      (setf sum (* sum (+ 1 i))))
    sum) )	



;;;PROBLEM 5:  Write RECURSIVE function that calculates the factorial of a positive integer and returns a result.

;;;public static double factorial2 (double n) {
;;;		if (n<=1)
;;;			return 1;
;;;		else
;;;			return n * factorial2 (n-1);
;;;}

(defun factorial2 (n)
  (if (<= n 0)
      1
      (* n (factorial2 (- n 1)) )))


		
;;; PROBLEM 6:  Write a function, named amount, that takes a list and returns the number of times 
;;; the symbol 'a' occurs in it. Note: do not count a's that might occur in a sublist within the list.

(defun amount (list)
  (count 'a list))  ;(count; search term ;  list to search)



;;;PROBLEM 7: Write a recursive function that returns the Fibonacci number where the Fibonacci sequence is defined as

;;;fib(0)=0, fib(1)=1 and fib(n)=fib(n-1)+fib(n-2) for n > 1. 
;;;examples:
;;;n =       0 1  2  3  4  5  6   7   8  9   ...
;;;fib(n) =  0 1  1  2  3  5  8  13  21  34  ...

(defun fib (n)
  (cond
   ((eq n 0) 0) 
   ((eq n 1) 1)
   ((+ (fib (- n 1)) (fib (- n 2))))))  ;fib sequence ((n-1) + (n-2))



;;;PROBLEM 8: Write a function, named small, that takes 2 numbers and returns the smaller of the two.

(defun small (x y)
  (if (< x y) x y))  ;if x smaller, return x, else return y



;;;PROBLEM 9:  Write a function, named sum, that takes an integer n and returns the summation of n and all 
;;; the positive integers preceiding it; eg, passsing 5 will return 15, 1+2+3+4+5 = 15

(defun sum(n)
  (if (<= n 0)
      0
    (+ n (sum(- n 1)))))  ;recursive call (n + (n-1))



;;;PROBLEM 10:  In a comment, descrive what the following code does when it is executed; explain each line and
;;;whether the result is a symbol or a list

;;;(setq x '(a b)       ; This sets sets a quote of x to the quote of the list (a b). 
                        ; The result of this line is a symbol.  Calling x results in a list.
;;;(setq y '(a b c))	; This sets a quote of x to the quote of the list (a b c).  
                        ; The result this line is a symbol.  Calling y results in a list.
;;;(print (car x))	; This prints the first item in the list x.  The result of the line is a list.
;;;(print (car y))	; This prints the first item in the list y.  The result of the line is a list.
;;;(print (cdr x))	; This prints all the items but the first in the list x.  The result of the line is a list.
;;;(print (cdr y))	; This prints all the items but the first in the list x.  The result of the line is a list. 
;;;(print car (cdr x)))	; This prints the second item in the list x (the first element of the "rest" of the list x
                        ; is the second element). 
			; The result of the line is a list. 
;;;(print car (cdr y)))	; This prints the second item in the list y (the first element of the "rest" of the list y
                        ; is the second element). 
			; The result of the line is a list. 
;;;(print (cadr x))	; This prints the second item in the list x.  The result of the line is a list.
;;;(print (cadr y))	; This prints the second item in the list y.  The result of the line is a list.
;;;(print (append x y))	; This hooks and prints multiple lists together, in this case x and y. The result of the line is a list.



;    test function definition
(defun test ()
  (print " CSE 240 Assignment 4.  Adam Clifton (akclifto@asu.edu) ")
  #\newline
  (print (factorial1 100))
  #\newline
  (print (factorial2 100))
  #\newline
  (print (amount '(b c (a) a )))
  #\newline
  (print (fib 7))
  #\newline
  (print (small 5 7))
  #\newline
  (print (sum 5))
)

(print (test))

