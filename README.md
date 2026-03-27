# Competitive Programming and Problem Solving

A comprehensive collection of **300+ problem solutions**, **battle-tested templates**, and **curated learning resources** for competitive programming and coding interviews.

> This repository is actively maintained and updated with new solutions and algorithms.

---

## What's Inside

| Category | Count |
|----------|-------|
| Problem Solutions | 300+ |
| Algorithm Categories | 20+ |
| Reusable Templates | 5 Data Structures |
| Learning Resources | 12 PDFs |
| Online Judge Platforms | 5 |

---

## Problem Solutions by Platform

| Platform | Problems | Focus Areas |
|----------|----------|-------------|
| **[CSES Problem Set](./CSES/)** | 103 | Classical algorithms, comprehensive topic coverage |
| **[LeetCode](./LeetCode/)** | 79 | Interview patterns, data structure mastery |
| **[Timus Online Judge](./Timus/)** | 65 | Implementation, mathematical reasoning |
| **[SPOJ](./SPOJ/)** | 31 | Advanced algorithms, optimization |
| **[LightOJ](./LightOJ/)** | 21 | Number theory, combinatorics |

---

## Algorithms & Topics Covered

### Graph Algorithms
- Shortest Paths: **Dijkstra**, **Bellman-Ford**, **Floyd-Warshall**
- Traversals: **BFS**, **DFS**, **Topological Sort**
- Connectivity: **Strongly Connected Components (Kosaraju's)**
- Minimum Spanning Tree: **Kruskal's**, **Prim's**
- Cycle Detection, Bipartite Checking

### Dynamic Programming
- Classical: **LIS**, **LCS**, **Edit Distance**, **Knapsack**
- Grid DP, Coin Change variants
- Bitmask DP, Digit DP
- Meet in the Middle techniques

### Tree Algorithms
- **Lowest Common Ancestor (LCA)** with Binary Lifting
- Tree Diameter, Tree Distances
- Subtree Queries, Path Queries

### Range Queries
- **Segment Tree** (with Lazy Propagation)
- **Binary Indexed Tree (Fenwick Tree)**
- **Sparse Table** for RMQ
- 2D Prefix Sums, Difference Arrays

### String Algorithms
- **Polynomial Hashing** (anti-hack design)
- **KMP** Pattern Matching
- Palindrome Queries, Z-Algorithm

### Mathematics & Number Theory
- Prime Factorization, Sieve of Eratosthenes
- GCD/LCM, Modular Arithmetic
- Combinatorics, Fibonacci variants
- Counting Divisors, Coprime Pairs

### Geometry
- **Convex Hull** (Graham Scan)
- Point Location, Line Intersection
- Manhattan Distance optimization

### Sorting & Searching
- Binary Search variants
- Two Pointers technique
- Sliding Window algorithms
- Custom comparators

### Interview Patterns (LeetCode)
- Arrays & Hashing
- Stack & Monotonic Stack
- Priority Queue / Heaps
- Backtracking & Recursion

---

## Reusable Templates

Production-ready, well-documented templates in [`Useful Templates/`](./Useful%20Templates/):

| Template | Description |
|----------|-------------|
| **[Segment Tree](./Useful%20Templates/Reusable%20Templates/Segment%20Tree.cpp)** | Generic lazy propagation with templated node/lazy types |
| **[Binary Indexed Tree](./Useful%20Templates/Reusable%20Templates/Binary%20Indexed%20Tree%20(BIT).cpp)** | Range updates & range queries |
| **[Sparse Table](./Useful%20Templates/Reusable%20Templates/Sparse%20Table.cpp)** | RMQ in O(1) with O(n log n) preprocessing |
| **[String Hashing](./Useful%20Templates/Reusable%20Templates/Hashing.cpp)** | Polynomial rolling hash with collision resistance |
| **[Policy Based DS](./Useful%20Templates/Reusable%20Templates/Policy%20Based%20Data%20Structure.cpp)** | GNU PBDS ordered_set with order statistics |

### STL Mastery Guides
- [`Examples1.cpp`](./Useful%20Templates/Clever%20Implementations/Examples1.cpp) - STL algorithms: `any_of`, `all_of`, `count_if`, `binary_search`, `accumulate`
- [`Examples2.cpp`](./Useful%20Templates/Clever%20Implementations/Examples2.cpp) - `partial_sum`, `adjacent_difference`, `transform`, `iota`

---

## Learning Resources

A carefully curated library of essential books in [`Useful Learning Resources/`](./Useful%20Learning%20Resources/):

### Competitive Programming
| Book | Author | Description |
|------|--------|-------------|
| Introduction to Algorithms (4th Ed.) | CLRS | The definitive algorithms textbook |
| Competitive Programmer's Handbook | Antti Laaksonen | CSES companion, highly practical |
| Guide to Competitive Programming | Antti Laaksonen | Condensed CP reference |
| Competitive Programming 3 & 4 | Steven & Felix Halim | Comprehensive problem-solving guide |
| CP-Algorithms Offline | cp-algorithms.com | Complete algorithm encyclopedia |

### Coding Interviews
| Book | Description |
|------|-------------|
| Cracking the Coding Interview | 189 problems with solutions |
| Elements of Programming Interviews (C++) | In-depth problem analysis |
| Programming Interviews Exposed | Interview strategies and patterns |
| 25 Coding Patterns for FAANG | Pattern recognition guide |

---

## Repository Structure

```
.
├── CSES/                          # 103 problems organized by topic
│   ├── Graph Algorithms/          # Dijkstra, SCC, MST, BFS/DFS
│   ├── Dynamic Programming/       # LIS, Edit Distance, Grid DP
│   ├── Range Queries/             # Segment Tree, BIT, Sparse Table
│   ├── Tree Algorithms/           # LCA, Binary Lifting
│   ├── Mathematics/               # Number Theory, Combinatorics
│   ├── String Algorithms/         # Hashing, KMP
│   ├── Geometry/                  # Convex Hull, Point problems
│   └── ...                        # 5 more categories
│
├── LeetCode/                      # 79 problems by technique
│   ├── Arrays and Hashing/
│   ├── Backtracking/
│   ├── Binary Search/
│   ├── Stack/
│   ├── Priority Queue/
│   └── ...
│
├── SPOJ/                          # 31 classical problems
├── LightOJ/                       # 21 math-heavy problems
├── Timus/                         # 65 implementation problems
│
├── Useful Templates/
│   ├── Reusable Templates/        # Data structure implementations
│   └── Clever Implementations/    # STL guides and patterns
│
└── Useful Learning Resources/     # 12 essential PDFs
```

---

## Code Quality

All solutions follow consistent practices:

- **Modern C++17/20** features (structured bindings, auto, lambdas)
- **Fast I/O** setup for competitive programming
- **Clean, readable code** with meaningful variable names
- **Time complexity** notes in templates
- **Source attribution** for adapted algorithms

---

## Getting Started

**New to Competitive Programming?**

1. Start with the [CSES Introductory Problems](./CSES/Introductory%20Problems/)
2. Read the *Competitive Programmer's Handbook* (included in resources)
3. Progress through CSES topics systematically
4. Use the templates as reference implementations

**Preparing for Interviews?**

1. Explore [LeetCode solutions](./LeetCode/) organized by pattern
2. Study the *25 Coding Patterns* PDF
3. Practice with increasing difficulty within each category

**Looking for Specific Algorithms?**

- Check the [CSES folders](./CSES/) organized by algorithm type
- Browse [Reusable Templates](./Useful%20Templates/Reusable%20Templates/) for implementations

---

## Languages

- **Primary**: C++ (optimized for competitive programming)
- **Secondary**: Python (for math-heavy problems)

---

## Contributing

This is a personal learning repository, but feel free to:
- Open issues for bugs or improvements
- Suggest better implementations
- Share alternative approaches

---

## License

This repository is for educational purposes. Problem statements belong to their respective online judges.

---

*Happy Coding!*
