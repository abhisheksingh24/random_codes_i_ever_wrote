#I cheated a bit by using default arguments in the function definition
#Because I wanted to make this a recursive function
#But I believe these arguments are important and 
#User must be allowed to change these values to see how the working changes

def newton(A, it = 0, max_iter = 100, guess = 1):
    #break when done a specific number of iterations
    #increase max_iter for more precise result
    if it >= max_iter:
        return guess
    new_guess = 0.5 * (guess + A / guess)
    #pass on the updated guess value to next iteration
    return newton(A, it + 1, max_iter, new_guess)

def main():
    while True:
        a = input("Enter a positive number or enter/return to quit: ")
        if not a:
            return
        print("The program's estimate is", newton(int(a)))
        print("Python's estimate is", int(a)**0.5)

main()