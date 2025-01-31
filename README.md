# indra_2025_problem
## how to run
-"make input NUM=n" from the command line creates an input.txt file with "n" random letters.
-"make" from the command line creates an output.txt file of n-grams (n <= 4) and frequency from input.txt. 
-"make time" times the execution of the make command 

## pre-work (thought) process:
I first thought of the most simple (incorrect) ways that this could be done. I thought that it would be to keep a list of grams 
and go through the list every time I found a new gram. That would be terrible. Worst case analysis:
In the worst case, the program would fill a list with letters and would have to go down that list every time to find the correct gram.
This type of list insertion, in the worst case is O(n^2). n + (n-1) + (n-2) + ... + 1 = (n*(n+1))/2.

Second, I tought that I knew from experience that hashmap worked very wel for looking up existing grams and adding to them.
I knew that a simple hashmap would suffice for the single grams. I then thought that a tree would be necessary for the multi-digit
grams. I thought, for a second, that I could use a full hashmap with multiple hashmaps as children; however, the space for this 
would be 26^2. Therefore, I have to use a variably-sized hashmap with a sorting algorithim to find the location in the map. 

After realizing that C++ has an inbuilt hashmap that can handle this for me, I used that instead of the complicated c-style 
implementation I would have had to use. 

I have to think about the way to iterate through each letter. My first thought is that each lesser gram is included in the first 
1,2,3 characters of the 4 gram, so I just go through the 4 grams from the start. 

Final process: Using an unordered_map from c++ library, the time complexity is O(n) because lookup time is (usually) constant. 

## work process:
1/27 
I always start with the most simple case and I move from there. I was able to get a list of all the 
four grams in the file at the end of the day.

1/28
I realized that it is so much easier to use an inbuilt hashmap, so I will not need to worry about the
internals of the hash function and sizing. If I did do it in C, I would need to make hashmap on my own.
I would make variably sized maps that double in size when about to overflow. I would also use a binary search to look for and insert the grams.

So far, I have an implementation that takes about 5 minutes to complete this algorithm. This is just using one unordered map from the cpp 
library. I am trying to think of ways to improve the time. I think that one big hashmap may not be the fastest way to get this done. 

1/30
I simplified the code to not include some unnecessary checks, but that will not change that the code has a time complexity of ~O(n).
I also made a graph of the timing to double check the time complexity, and it looks like O(n) is correct. 