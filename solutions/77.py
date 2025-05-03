class Primes:
    def __init__(self):
        self.primes = [2]

    def __iter__(self):
        self.idx = 0
        return self

    def __next__(self):
        if self.idx >= len(self.primes):
            i = self.primes[-1]
            while True:
                prime = True
                for p in self.primes:
                    if i % p == 0:
                        prime = False
                        break

                if prime:
                    self.primes.append(i)
                    break

                i += 1

        temp = self.idx
        self.idx += 1
        return self.primes[temp]

number_of_ways = [[1]]

p = Primes()
it = iter(p)
max_num = 0
while True:
    next_prime = next(it)

