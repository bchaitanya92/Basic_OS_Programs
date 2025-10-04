'''
Output:

--> Compile the writer and reader programs one by one using below command:
braham@braham:~/Desktop/program$ gcc writer.c -o writer
braham@braham:~/Desktop/program$ gcc reader.c -o reader

--> Open two terminals:
./writer

./reader

--> Check the both terminal to see the output...
braham@braham:~/Desktop/program$ ./writer
Writer: FIFO created
Writer: FIFO opened for writing
Writer: Message written to FIFO


braham@braham:~/Desktop/program$ ./reader
Reader: Message received: Hello from writer process!
'''