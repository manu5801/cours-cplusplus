CPP=g++

CFLAG = -Wall -std=c++11

all: ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11


ex1:	 ex1_iterator.cpp
	$(CPP) $(CFLAG) ex1_iterator.cpp -o $@
	echo 'Learn to use iterators'

ex2: 	ex2_vector.cpp
	$(CPP) $(CFLAG) ex2_vector.cpp -o $@
	echo 'Learn to use a vector'

ex3:	ex3_list.cpp
	$(CPP) $(CFLAG) ex3_list.cpp -o $@
	echo 'Learn to use a list'

ex4: 	ex4_deque.cpp
	$(CPP) $(CFLAG) ex4_deque.cpp -o $@
	echo 'Learn to use a deque'
	
ex5:	ex5_queue.cpp
	$(CPP) $(CFLAG) ex5_queue.cpp -o $@
	echo 'Learn to use a queue'
	
ex6: 	ex6_stack.cpp
	$(CPP) $(CFLAG) ex6_stack.cpp -o $@
	echo 'Learn to use a stack'

ex7:	ex7_map.cpp
	$(CPP) $(CFLAG) ex7_map.cpp -o $@
	echo 'Learn to use a map'

ex8:	ex8_string.cpp
	$(CPP) $(CFLAG) ex8_string.cpp -o $@
	echo 'Learn to use string class'

ex9:	ex9_tri.cpp
	$(CPP) $(CFLAG) ex9_tri.cpp -o $@
	echo 'Learn to use the algo sort'

ex10:	ex10_find.cpp
	$(CPP) $(CFLAG) ex10_find.cpp -o $@
	echo 'Learn to use the algo find'

ex11: 	ex11_suppression.cpp
	$(CPP) $(CFLAG) ex11_suppression.cpp -o $@
	echo 'Learn to use free memory of a vector'







# suppression de tous les fichiers temporaires
cleanall: 
	@rm -rfv $(EXEC) *.o *~ ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11
	
clean:
	echo "Suppression de "$(ARG)
	@rm -rfv *.o *~ $(ARG)
