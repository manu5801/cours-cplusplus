CPP=g++

CFLAG = -Wall -std=c++11

all: ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11


ex1: 
	$(CPP) $(CFLAG) ex1_iterator.cpp -o $@
	echo 'Learn to use iterators'

ex2: 
	$(CPP) $(CFLAG) ex2_vector.cpp -o $@
	echo 'Learn to use a vector'

ex3:
	$(CPP) $(CFLAG) ex3_list.cpp -o $@
	echo 'Learn to use a list'

ex4: 	
	$(CPP) $(CFLAG) ex4_deque.cpp -o $@
	echo 'Learn to use a deque'
	
ex5:
	$(CPP) $(CFLAG) ex5_queue.cpp -o $@
	echo 'Learn to use a queue'
	
ex6: 
	$(CPP) $(CFLAG) ex6_stack.cpp -o $@
	echo 'Learn to use a stack'

ex7:
	$(CPP) $(CFLAG) ex7_map.cpp -o $@
	echo 'Learn to use a map'

ex8:
	$(CPP) $(CFLAG) ex8_string.cpp -o $@
	echo 'Learn to use string class'

ex9:
	$(CPP) $(CFLAG) ex9_tri.cpp -o $@
	echo 'Learn to use the algo sort'

ex10:
	$(CPP) $(CFLAG) ex10_find.cpp -o $@
	echo 'Learn to use the algo find'

ex11: 
	$(CPP) $(CFLAG) ex11_suppression.cpp -o $@
	echo 'Learn to use free memory of a vector'







# suppression de tous les fichiers temporaires
cleanall: 
	@rm -rfv $(EXEC) *.o *~ ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11
	
clean:
	echo "Suppression de "$(ARG)
	@rm -rfv *.o *~ $(ARG)
