cnt = 0
for a in range(46):
    for b in range(46):
        for c in range(46):
            for d in range(46):
                if a + b + c + d >= 90: cnt += 1

print(cnt)
