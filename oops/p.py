# str=" hello ,hello"
# l=str[0]
# r=str[-1]
# while(l>r):
#   if(l==r):
#     l=l+1
#     r=r-1
#   else:
#     print("not palindrome")
#     break
# else:
#   print("palindrome")

# recursion
# n=int(input("enter the number"))
# def rec(i,n):
#   # base conditon
#   if(i>n):
#     return
#   print(i)
#   # recursive call
#   rec(i+1,n)
# rec(1,n)



# Number of terms
# n = 10

# a, b = 0, 1

# print("Fibonacci Series:")

# for i in range(n):
#     print(a, end=" ")
#     a, b = b, a + b


# # factorial

# n =int(input("enter your number "))

# def fact(n):
#   if (n==0):
#     return 1
  
#   return n * fact(n-1)
# print(fact(n))


# hcf :best way to find hcp through eucleadian priciple
# def gcd(a,b):
#   if (b==0):
#     return a
#   return gcd(b,a%b)
# print(gcd(12,20))

# # lcc
# def lcm(a,b):
#   return a*b/gcd(a,b)
# print(lcm(12,20))



# print("hello")
# n=32
# while(n%2==0):
#   i=n/2
# if (i==1):
#   print("true")
# else :
#   print("no")
# print("hello")
