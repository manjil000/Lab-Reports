print("=" * 60)
print("       HEBB'S NETWORK: LOGIC GATES")
print("       Program by: Prashidda Rai")
print("       Roll No: 22")
print("=" * 60)


# Convert binary to bipolar
def bipolar(x):
    return 1 if x == 1 else -1


# Hebbian training function
def hebb_train(inputs, targets):
    w1 = 0
    w2 = 0
    b = 0

    for (x1, x2), t in zip(inputs, targets):
        x1 = bipolar(x1)
        x2 = bipolar(x2)
        t = bipolar(t)

        w1 += x1 * t
        w2 += x2 * t
        b += t

    return w1, w2, b


# Prediction function
def predict(x1, x2, w1, w2, b):
    x1 = bipolar(x1)
    x2 = bipolar(x2)

    yin = (x1 * w1) + (x2 * w2) + b

    if yin > 0:
        return 1
    elif yin < 0:
        return 0
    else:
        return -1


# Input combinations
inputs = [(0, 0), (0, 1), (1, 0), (1, 1)]


# Target outputs for each gate
gates = {
    "AND":  [0, 0, 0, 1],
    "OR":   [0, 1, 1, 1],
    "NAND": [1, 1, 1, 0],
    "NOR":  [1, 0, 0, 0]
}


# Train and test each gate
for gate, targets in gates.items():

    print("\n" + "=" * 40)
    print(f"        {gate} GATE")
    print("=" * 40)

    # Train network
    w1, w2, b = hebb_train(inputs, targets)

    print(f"Learned Weight w1 = {w1}")
    print(f"Learned Weight w2 = {w2}")
    print(f"Learned Bias b    = {b}")

    print("\nx1   x2   | Target | Output")
    print("-" * 32)

    # Test all inputs
    for (x1, x2), target in zip(inputs, targets):
        output = predict(x1, x2, w1, w2, b)
        print(f"{x1}    {x2}    |   {target}    |   {output}")

    print("\nTraining Result: ",
          "Successful" if
          all(predict(x1, x2, w1, w2, b) == target
              for (x1, x2), target in zip(inputs, targets))
          else "Unsuccessful")

print("\n" + "=" * 60)
print("   ALL LOGIC GATES TESTED SUCCESSFULLY!")
print("=" * 60)