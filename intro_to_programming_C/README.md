# intro_to_programming_C
This subfolder contains some exercises from the intro to procedural programming course, written in C.

# diamonds
1) the user inputs a number
2) if a perfect diamond can be drawn with that number in the middle row (cascading top-middle and bottom-middle), the program draws it
3) if not, the program prints that it isn't possible

# largest_value_matrix_edge
1) the user inputs the number of rows/columns of a square matrix
2) the user inputs the values of all elements of the matrix
3) the program calculates which element in the matrix' edges (top and bottom row, first and last column) has the largest value

# chances_for_cheating_on_tests
1) the user inputs the configuration of a classroom and the number of seats, where Z represents the student with good knowledge, N represents the student with no knowledge,
X represents an empty seat and H represents the user, e.g.:
Z N N Z N
X X N Z N
N N Z H N
Z N N N N
2) the user the inputs the professor's position and the level of their strictness
3) the program calculates the chances of passing the exam based on the fact that H's knowledge grows from the closeness of a Z student and is reduced from the closeness of an N student
test case:
input:
6 7
5 100
Z N Z N X X N
X Z X N X Z X
N N N H N N N
Z N X Z N N Z
N X Z N N N Z
Z N Z N N N Z
output:
Sanse za prolaz su 20.12%

# delicacies_from_the_bakery
this exercise demonstrates handling data in textual files by finding the most affordable baked good from those offered in the file

# flights
this exercise demonstrates handling binary files by finding the affordable flights from the log in the binary file, based on the input of funds
