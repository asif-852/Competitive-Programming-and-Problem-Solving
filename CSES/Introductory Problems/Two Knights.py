
for k in range (1, int(input()) + 1):
    total_squares = (k ** 2) * (k ** 2 - 1) // 2
    attacks = (k - 1) * (k - 2) + (k - 2) * (k - 1)     # the number of placements of (2 x 3) and (3 x 2) grid in (N x N) chessboard
    attacks *= 2                                        # Each placement can have 2 attacking combinations
    print(total_squares - attacks)
    