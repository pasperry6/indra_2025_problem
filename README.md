# indra_2025_problem
# questions:
1. what is the input file type?
2. what is the output file type and format?
3. 

# to check:
1. works with cpp 11.
2. worst case analysis.


# pre-work (thought) process:
I first thought of the most simple (incorrect) ways that this could be done. I thought that it would be to keep a list of grams 
and go through the list every time i found a new gram. That would be terrible. Worst case analysis:
In the worst case, the program would fill a list with letters and would have to go down that list every time to find the correct gram. 
Just for the single grams, this would cost ~n*26 (when a hashmap would cost ~n). For the 2 grams, almost every gram would be new, and 
this would be O(n^2).   

Second, I tought that I knew from experience that hashmap worked very wel for looking up existing codes and adding to them.
I knew that a simple hashmap would suffice for the single grams. I then thought that a tree would be necessary for the multi-digit
grams. I thought, for a second, that I could use a full hashmap with multiple hashmaps as children; however, the space for this 
would be 26^2. Therefore, I have to use a variably-sized hashmap with a sorting algorithim to find the location in the map. 

I have to think about the way to iterate through each letter. My first thought is that each lesser gram is included in the first 
1,2,3 characters of the 4 gram, so I just go through the 4 grams from the start. 

# work process:
1/27 
I always start with the most simple case and I move from there. I was able to get a list of all the 
four grams in the file at the end of the day.

1/28
I realized that it is so much easier to use an inbuilt hashmap, so I will not need to worry about the
internals of the hash function and sizing. If I did do it in C, I would need to make hashmap on my own.
I would make variably sized maps that double in size when about to overflow. I would also use a binary search to look for and insert the grams.