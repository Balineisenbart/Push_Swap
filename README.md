# Push_Swap

!!! replace or rewrite ft_split & free_split_array(in utils.c) , replace printfw/ ft_printf!!!

check if malloc fails, does it need to be freed?

Step 1: Parse Input
X ---- Convert input arguments into integers and store them in stack A. 
X ---- Ensure error handling:
X ---- Check for non-integer input.
X ---- Verify no duplicate values.
Handle integer overflows. <<<<verify that ft_atoi handles this and frees stack if error occurs>>>>

Step 2a: create operations
X ---- write code for operations. ~~pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr~~

Step 2b: test output

Step 2c: check for order in stack a
X ---- if already sorted just return
if parts are already sorted use for optimized chunk sorting

Step 2: Divide into Chunks
Pre-sort the array to calculate chunk boundaries.
Example: For 100 numbers, divide into chunks of 10 numbers each.
Store chunks in a helper array.

Step 3: Push Chunk Elements to Stack B
Iterate through stack A and push elements belonging to the current chunk to stack B.
Logic:
Use pb to push the element from stack A to stack B.
Rotate stack A to bring the next chunk element to the top.

Step 4: Greedy Sorting in Stack B
Use the greedy approach to sort elements in stack B.
Bring the largest element to the top and push it back to stack A.
Logic:
Find the largest element in stack B.
Use rb or rrb to rotate it to the top.
Use pa to push it to stack A.

Step 5: Repeat for All Chunks
Process each chunk, push it to stack B, sort it, and push it back to stack A.
Use dynamic chunk sizes if needed for optimization.


#### helpful commands ####

ctags --c-kinds=f -x *.c | sed -E 's/[0-9]+\s+.c\s+//g;s/$/;/g' > functions.h //extracts function prototypes