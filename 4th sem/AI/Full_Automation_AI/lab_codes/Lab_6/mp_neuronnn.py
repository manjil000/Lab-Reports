print("=" * 60)
print("        MCP NEURON: LOGIC GATES")
print("        Program by: Prashidda Rai")
print("        Roll No: 22")
print("=" * 60)


# --------------------------------------------------
# MCP NEURON FUNCTION
# --------------------------------------------------

def mcp_neuron(inputs, weights, T):
    yin = 0

    for x, w in zip(inputs, weights):
        yin += x * w

    if yin >= T:
        return 1
    else:
        return 0


# --------------------------------------------------
# AND GATE
# --------------------------------------------------

def AND(x1, x2):
    return mcp_neuron([x1, x2], [1, 1], 2)


# --------------------------------------------------
# OR GATE
# --------------------------------------------------

def OR(x1, x2):
    return mcp_neuron([x1, x2], [1, 1], 1)


# --------------------------------------------------
# NOT GATE
# --------------------------------------------------

def NOT(x):
    return mcp_neuron([x], [-1], 0)


# --------------------------------------------------
# NAND GATE
# --------------------------------------------------

def NAND(x1, x2):
    return mcp_neuron([x1, x2], [-1, -1], -1)


# --------------------------------------------------
# NOR GATE
# --------------------------------------------------

def NOR(x1, x2):
    return mcp_neuron([x1, x2], [-1, -1], 0)


# --------------------------------------------------
# XOR GATE
# XOR = (A OR B) AND NOT(A AND B)
# --------------------------------------------------

def XOR(x1, x2):

    # First neuron: OR
    or_output = OR(x1, x2)

    # Second neuron: AND
    and_output = AND(x1, x2)

    # Third neuron: NOT of AND
    not_and = NOT(and_output)

    # Final neuron: AND
    xor_output = AND(or_output, not_and)

    return xor_output


# --------------------------------------------------
# DISPLAY RESULTS
# --------------------------------------------------

inputs = [(0, 0), (0, 1), (1, 0), (1, 1)]


print("\nAND GATE")
print("x1   x2   |   y")
print("----------------")
for x1, x2 in inputs:
    print(f"{x1}    {x2}   |   {AND(x1, x2)}")


print("\nOR GATE")
print("x1   x2   |   y")
print("----------------")
for x1, x2 in inputs:
    print(f"{x1}    {x2}   |   {OR(x1, x2)}")


print("\nNOT GATE")
print("x    |   y")
print("-----------")
for x in [0, 1]:
    print(f"{x}    |   {NOT(x)}")


print("\nNAND GATE")
print("x1   x2   |   y")
print("----------------")
for x1, x2 in inputs:
    print(f"{x1}    {x2}   |   {NAND(x1, x2)}")


print("\nNOR GATE")
print("x1   x2   |   y")
print("----------------")
for x1, x2 in inputs:
    print(f"{x1}    {x2}   |   {NOR(x1, x2)}")


print("\nXOR GATE")
print("x1   x2   |   y")
print("----------------")
for x1, x2 in inputs:
    print(f"{x1}    {x2}   |   {XOR(x1, x2)}")


print("\n" + "=" * 60)
print("     ALL LOGIC GATES IMPLEMENTED SUCCESSFULLY!")
print("=" * 60)