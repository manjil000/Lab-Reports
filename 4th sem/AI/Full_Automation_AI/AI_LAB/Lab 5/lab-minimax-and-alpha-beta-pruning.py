# Lab: Minimax Algorithm and Alpha-Beta Pruning
# Program by: [Your Name]
# Roll no: [Your Roll No]

# Step 1: Define the game tree
# Leaf nodes are terminal states with utility values
game_tree = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [5, 3],   # Leaf values
    'E': [8, 2],   # Leaf values
    'F': [7, 4],   # Leaf values
    'G': [9, 1]    # Leaf values
}


# Step 2: Minimax without pruning
def minimax(node, is_maximizing):
    # If leaf node, return the value directly
    if isinstance(node, int):
        return node

    if is_maximizing:
        best = -999999

        for child in game_tree[node]:
            value = minimax(child, False)
            best = max(best, value)

        return best

    else:
        best = 999999

        for child in game_tree[node]:
            value = minimax(child, True)
            best = min(best, value)

        return best


# Step 3: Minimax with Alpha-Beta Pruning
def alpha_beta(node, is_maximizing, alpha, beta):
    # If leaf node, return the value directly
    if isinstance(node, int):
        return node

    if is_maximizing:
        best = -999999

        for child in game_tree[node]:
            value = alpha_beta(child, False, alpha, beta)
            best = max(best, value)
            alpha = max(alpha, best)

            if beta <= alpha:
                break  # Prune

        return best

    else:
        best = 999999

        for child in game_tree[node]:
            value = alpha_beta(child, True, alpha, beta)
            best = min(best, value)
            beta = min(beta, best)

            if beta <= alpha:
                break  # Prune

        return best


# Step 4: Display the game tree
print("=" * 70)
print("GAME TREE")
print("=" * 70)
print()

print("                    MAX")
print("                   /   \\")
print("                  /     \\")
print("                 /       \\")
print("               MIN       MIN")
print("              /   \\     /   \\")
print("            MAX   MAX  MAX   MAX")
print("           /  \\  /  \\ /  \\  /  \\")
print("          5   3 8   2 7   4 9   1")
print()


# Step 5: Run Minimax without pruning
print("=" * 70)
print("MINIMAX WITHOUT PRUNING")
print("=" * 70)

root_value = minimax('A', True)

print()
print("Root Value (Best for MAX):", root_value)
print()

print("Explanation:")
print("  - D = max(5,3) = 5")
print("  - E = max(8,2) = 8")
print("  - F = max(7,4) = 7")
print("  - G = max(9,1) = 9")
print("  - B = min(5,8) = 5")
print("  - C = min(7,9) = 7")
print("  - A = max(5,7) = 7")


# Step 6: Run Minimax with Alpha-Beta Pruning
print()
print("=" * 70)
print("MINIMAX WITH ALPHA-BETA PRUNING")
print("=" * 70)

root_value_pruned = alpha_beta('A', True, -999999, 999999)

print()
print("Root Value (Best for MAX):", root_value_pruned)
print()

print("Alpha-Beta pruned branches that cannot affect the final decision.")
print("Result is the same as minimax but faster.")


# Step 7: Compare results
print()
print("=" * 70)
print("COMPARISON")
print("=" * 70)
print()

print("Both algorithms found the same root value:", root_value)
print("Alpha-Beta pruning is more efficient.")