# Prefix, Suffix, Substring

s=input("Enter a string:")
pre=[]
suff=[]
sub=[]

# prefix
for i in range(len(s)):
    pre.append(s[:i+1])
print("Prefix:",pre)

#suffix
for i in range(len(s)):
    suff.append(s[len(s)-i-1:])
print("Suffix:",suff)

#substring
for i in range(len(s)):
    for j in range(len(s)-i):
        sub.append(s[j:i+j+1])
print("Substrings:",sub)