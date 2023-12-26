Main idea for stack size >= 5:  
https://rutube.ru/video/a0642f57b19063e83eecbf80b535509e/

1. we push 2 elements to b  
2. sorting1 (from a to b, till size of a == 3):  
--we check if a is sorted (3 4 1 2 == sorted, needs to rotate only)  
--we find min/max in b  
--we check each element in a  
   ........we compare it with b_max and b_min to find place in b (on the top of which element we should push it)  
   ........we check how many moves we shold do (rotate or reverse rotate both a and b)  
--we choose min moves, we do it  
--we push element to b  
3. we sort 3 numbers in a  
4. sorting2 (from b to a, till size of b == 0):  
--we find min/max in a  
--we check each element in b  
	........we compare it with a_max and a_min to find place in a (on the top of which element we should push it)  
	........we check how many moves we shold do (rotate or reverse rotate both a and b)  
--we choose min moves, we do it  
--we push element to a  
5. we rotate a to find min number on the top  
