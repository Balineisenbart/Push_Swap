# Push_Swap

!!! replace or rewrite ft_split & free_split_array(in utils.c) , replace printf w/ ft_printf!!!

Step 1: Parse Input
X ---- Convert input arguments into integers and store them in stack A. 
X ---- Ensure error handling:
X ---- Check for non-integer input.
X ---- Verify no duplicate values.
Handle integer overflows. <<<<verify that ft_atoi handles this and frees stack if error occurs>>>>

Step 2a: create operations
X ---- write code for operations. ~~pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr~~

Step 2b: test output
2&3:
X ---- manual
test using checker function
4&5:
test using checker function
6+:
test using checker function

Step 2c: check for order in stack a
X ---- if already sorted just return
if parts are already sorted use for optimized chunk sorting
--------------------------------------------------------------------
1️⃣ Find LIS (or multiple LIS sequences) in Stack A

If LIS is large enough (~50% of input), use one LIS.
If LIS is too small (~10-30%), split into multiple LIS sequences.
Mark LIS elements in Stack A so they remain there.
2️⃣ Push Non-LIS Elements to Stack B (pb)

Push elements not in LIS to Stack B while balancing its structure.
Avoid overloading Stack B to prevent excessive rb/rrb rotations later.
3️⃣ Efficient Reinsertion of Stack B into Stack A (pa)

Compare head_b (top) and tail_b (bottom) to find the closest fit in Stack A.
Push the closest element first to minimize rotations (pa or rrb + pa).
Adjust Stack A’s order after each pa with sa, ra, or rra if needed.
4️⃣ After Each Move (sa, ra, rrr, ss), Check Stack B

If head_b fits into A, push it immediately (pa).
If tail_b is closer, rrb then pa to avoid unnecessary rotations.
Keep Stack B as small as possible by prioritizing insertions.
5️⃣ Final Alignment of Stack A

Rotate Stack A (ra or rra) until the smallest element is at the top.
--------------------------------------------------------------------
Step 6: Funcheck passes?
Step 7: Normcheck passes?

#### helpful commands ####

ctags --c-kinds=f -x *.c | sed -E 's/[0-9]+\s+.c\s+//g;s/$/;/g' > functions.h //extracts function prototypes
ARG="3 -232 231"; ./push_swap $ARG | ./checker_linux $ARG > checks output
inside gdb:
-> use backtrace(bt) :: to show the downstram function calls
-> use watch _variable_ ; continue :: to follow a variable and print its content throughout the code