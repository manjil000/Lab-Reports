print("=" * 60)
print("       PERCEPTRON LEARNING: LOGIC GATES")
print("       Program by: Prashidda Rai")
print("       Roll No: 22")
print("=" * 60)


# ============================================================
# ACTIVATION FUNCTION
# ============================================================

def activation(x):
    if x >= 0:
        return 1
    else:
        return -1


# ============================================================
# PERCEPTRON TRAINING FUNCTION
# ============================================================

def train_perceptron(data, max_epochs=10, eta=1):

    w1 = 0.0
    w2 = 0.0
    bias = 0.0

    print("\n" + "=" * 50)
    print("  TRAINING")
    print("=" * 50)

    print(f"Initial: w1={w1}, w2={w2}, "
          f"bias={bias}, η={eta}\n")

    for epoch in range(max_epochs):

        print(f"Epoch {epoch + 1}")
        print("-" * 30)

        updates = 0

        for x, target in data:

            x1, x2 = x

            # Calculate net input
            yin = x1 * w1 + x2 * w2 + bias

            # Calculate output
            y = activation(yin)

            # Update only when prediction is wrong
            if y != target:

                dw1 = eta * x1 * target
                dw2 = eta * x2 * target
                db = eta * target

                w1 = w1 + dw1
                w2 = w2 + dw2
                bias = bias + db

                updates += 1

            else:
                dw1 = 0
                dw2 = 0
                db = 0

            status = "OK" if y == target else "WRONG"

            print(
                f"  ({x1:2}, {x2:2}) -> "
                f"y={y:2}, t={target:2} {status} | "
                f"dw=({dw1:3.0f},{dw2:3.0f}) | "
                f"w=({w1:3.0f},{w2:3.0f}) "
                f"b={bias:3.0f}"
            )

        # Check after completing the complete epoch
        correct = 0

        for x, target in data:
            x1, x2 = x
            yin = x1 * w1 + x2 * w2 + bias
            y = activation(yin)

            if y == target:
                correct += 1

        print(f"  Accuracy: {correct}/{len(data)}")

        if correct == len(data):
            print(
                f"\nALL PATTERNS CORRECT! "
                f"Stopping at Epoch {epoch + 1}"
            )
            break

    return w1, w2, bias


# ============================================================
# TESTING FUNCTION
# ============================================================

def test_perceptron(data, w1, w2, bias):

    print("\n" + "=" * 50)
    print("  TESTING")
    print("=" * 50)

    print("\n x1  x2 |  yin |  y | Expected")
    print("-" * 35)

    for x, target in data:

        x1, x2 = x

        yin = x1 * w1 + x2 * w2 + bias

        y = activation(yin)

        status = "OK" if y == target else "WRONG"

        print(
            f" {x1:2}  {x2:2} | "
            f"{yin:4.1f} | "
            f"{y:2} | "
            f"{target:8} {status}"
        )


# ============================================================
# COMMON INPUT DATA
# ============================================================

inputs = [
    ([1, 1]),
    ([1, -1]),
    ([-1, 1]),
    ([-1, -1])
]


# ============================================================
# AND GATE
# ============================================================

print("\n\n" + "#" * 60)
print("                    AND GATE")
print("#" * 60)

and_data = [
    ([1, 1], 1),
    ([1, -1], -1),
    ([-1, 1], -1),
    ([-1, -1], -1)
]

w1, w2, bias = train_perceptron(and_data)

print("\nFinal Weights:")
print(f"w1 = {w1}")
print(f"w2 = {w2}")
print(f"bias = {bias}")

test_perceptron(and_data, w1, w2, bias)


# ============================================================
# OR GATE
# ============================================================

print("\n\n" + "#" * 60)
print("                    OR GATE")
print("#" * 60)

or_data = [
    ([1, 1], 1),
    ([1, -1], 1),
    ([-1, 1], 1),
    ([-1, -1], -1)
]

w1, w2, bias = train_perceptron(or_data)

print("\nFinal Weights:")
print(f"w1 = {w1}")
print(f"w2 = {w2}")
print(f"bias = {bias}")

test_perceptron(or_data, w1, w2, bias)


# ============================================================
# NAND GATE
# ============================================================

print("\n\n" + "#" * 60)
print("                   NAND GATE")
print("#" * 60)

nand_data = [
    ([1, 1], -1),
    ([1, -1], 1),
    ([-1, 1], 1),
    ([-1, -1], 1)
]

w1, w2, bias = train_perceptron(nand_data)

print("\nFinal Weights:")
print(f"w1 = {w1}")
print(f"w2 = {w2}")
print(f"bias = {bias}")

test_perceptron(nand_data, w1, w2, bias)


# ============================================================
# XOR GATE
# ============================================================

print("\n\n" + "#" * 60)
print("                    XOR GATE")
print("#" * 60)

print("\nXOR cannot be learned by a single perceptron.")
print("Using multiple perceptrons to implement XOR.")
print("XOR = (OR) AND (NAND)")


# XOR = OR AND NAND
#
# First perceptron = OR
# Second perceptron = NAND
# Third perceptron = AND


# OR perceptron
or_w1, or_w2, or_b = train_perceptron(or_data)

# NAND perceptron
nand_w1, nand_w2, nand_b = train_perceptron(nand_data)


def OR_neuron(x1, x2):
    return activation(
        x1 * or_w1 +
        x2 * or_w2 +
        or_b
    )


def NAND_neuron(x1, x2):
    return activation(
        x1 * nand_w1 +
        x2 * nand_w2 +
        nand_b
    )


# Generate hidden-layer outputs
xor_hidden_data = []

for x in inputs:

    x1, x2 = x

    h1 = OR_neuron(x1, x2)
    h2 = NAND_neuron(x1, x2)

    xor_hidden_data.append(([h1, h2], 1))


# The final AND neuron gives XOR
xor_final_data = [
    ([1, -1], -1),   # 0,0
    ([1, 1], 1),     # 0,1
    ([1, 1], 1),     # 1,0
    ([-1, 1], -1)    # 1,1
]

xor_w1, xor_w2, xor_b = train_perceptron(
    xor_final_data
)

print("\nFinal XOR Weights:")
print(f"w1 = {xor_w1}")
print(f"w2 = {xor_w2}")
print(f"bias = {xor_b}")


print("\nXOR Testing")
print("\n x1  x2 | OR | NAND | XOR")
print("-" * 30)

for x in inputs:

    x1, x2 = x

    h1 = OR_neuron(x1, x2)
    h2 = NAND_neuron(x1, x2)

    yin = (
        h1 * xor_w1 +
        h2 * xor_w2 +
        xor_b
    )

    output = activation(yin)

    print(
        f" {x1:2}  {x2:2} | "
        f"{h1:2} | "
        f"{h2:4} | "
        f"{output:3}"
    )


print("\n" + "=" * 60)
print("     PERCEPTRON LOGIC GATES COMPLETED")
print("=" * 60)