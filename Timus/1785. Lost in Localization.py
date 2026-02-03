
n = int(input())

ranges = [(5, "few"), (10, "several"), (20, "pack"), (50, "lots"), 
          (100, "horde"), (250, "throng"), (500, "swarm"), (1000, "zounds")]

for limit, word in ranges:
    if n < limit:
        print(word)
        break
else:
    print("legion")

