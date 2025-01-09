# Push_Swap

Step 1: Parse Input
Convert input arguments into integers and store them in stack A. <<<here, parsing is written but not implemented in main. also print it>>>
Ensure error handling:
Check for non-integer input.
Verify no duplicate values.
Handle integer overflows.

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
