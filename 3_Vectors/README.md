This program has two classes for different kind of vectors.

Class Double n-dimensional vector. 
Methods for this class are:
- operator[] - returns element on this index.If this index is not in bounds return 0.
- operators +,-,+=,-= respectively summation and subtraction.
- operators *,*=  multiplication to vector with number.
- operators /,/=  dividing to vector with number.
- operator% - makes scalar multiplication of two vectors.
If the operation requires vectors with equal dimension the smaller one makes resizing.

Class Bool vector (consist only bool values) with 32 elements he has to take exactly 4 bytes.
Methods for this class are:
- operator[] - returns element which is on that index. If index is not in bounds return -1.
- method set(int) - changes value of element in that index to  1. If index is not in bounds return false.
- method clear(int) - changes value in that index to 0. If index is not in bounds return false.
