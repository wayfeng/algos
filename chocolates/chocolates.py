#!/usr/bin/env python3

# You need to buy N chocolates from 6 types:
# type I has only 1 available, type II 2, and type III 3.
# the rest have unlimited supply, number of type IV can be any integer,
# number of type V has to be an even number,
# and number of type VI has to be multiple of 3.
# calculate how many ways there are to buy N chocolates.
def counts(n):
    chocolates = {}
    chocolates[0] = lambda x: [i for i in range(0, min(x, 1)+1)]
    chocolates[1] = lambda x: [i for i in range(0, min(x, 2)+1)]
    chocolates[2] = lambda x: [i for i in range(0, min(x, 3)+1)]
    chocolates[3] = lambda x: [i for i in range(0, x+1) if i % 1 == 0]
    chocolates[4] = lambda x: [i for i in range(0, x+1) if i % 2 == 0]
    chocolates[5] = lambda x: [i for i in range(0, x+1) if i % 3 == 0]

    solution = [0] * 6
    def recur(n, idx, sol):
        res = 0
        if n == 0 or idx > 5:
            return res
        for c in chocolates[idx](n):
            sol[idx] = c
            if n == c:
                res += 1
                #print(sol)
            elif n > c:
                res += recur(n-c, idx+1, sol)
            sol[idx] = 0
        return res

    return recur(n, 0, solution)

if __name__ == '__main__':
    print(counts(1))
    print(counts(2))
    print(counts(3))
    print(counts(4))
    print(counts(96))
