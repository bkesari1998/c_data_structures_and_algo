CC = gcc 
CFLAGS = -Wall -Wextra 
UNITY_DIR = /Users/bharatkesari/dev/Unity/src
INCLUDE_DIR = include

sorting_test: sorting_test.o sorting.o unity.o
	$(CC) $(CFLAGS) unity.o sorting.o sorting_test.o -o sorting_test

sorting_test.o: sorting_test.c $(INCLUDE_DIR)/sorting.h $(UNITY_DIR)/unity.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(UNITY_DIR) -c sorting_test.c -o sorting_test.o

unity.o: $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY_DIR)/unity.c -o unity.o

sorting.o: sorting.c $(INCLUDE_DIR)/status.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c sorting.c -o sorting.o

clean:
	rm -rf *.o
