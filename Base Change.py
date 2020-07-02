alpha = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
#initializing dictionary as empty
val = {}

def repToDecimal(num, base):
    #following loop fills in the value for each digit
    for i in range(base):
        val[alpha[i]] = i 

    # m here is pow(base, i)
    # to avoid raising to power each time
    # we multiply m with base in every iteration
    m = 1
    res = 0
    # iterate string in reverse order so that LSB is read first
    for i in num[: : -1]:
        #dictionary val is used to get corresponding value of current digit
        d = val[i.upper()]
        res += d * m
        m *= base
    return res

def main():
    print(repToDecimal('10', 10))
    print(repToDecimal('10', 8))
    print(repToDecimal('10', 2))
    print(repToDecimal('10', 16))

main()