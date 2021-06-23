# Difference, Reverse, Kleene closure, Positive closure

# Concatenation function
def concat(set_1,set_2):
    z=set();
    for i in set_1:
        for j in set_2:
            z.add(i+j);
    return z;
    
set1=set();
set2=set();
len1=int(input("Enter number of elements of set1: "));
len2=int(input("Enter number of elements of set2: "));
print("\nEnter the elements of set1: ");
for i in range(len1):
    set1.add(input());
print("\nEnter the elements of set2: ");
for i in range(len2):
    set2.add(input());
print("\nSet 1:",set1);
print("Set 2:",set2);

# Difference
print("\nSet 1 - Set 2:",set1-set2);

# Reverse
rev=set();
for i in set1:
    rev.add(i [::-1]);
print("Reverse of set 1:",rev);

# Kleene closure
kleene={'lambda'};
temp=set();
count=int(input("\nEnter the count for kleene closure: "));
for i in range(1,count):
    if(i==1):
        temp=temp.union(set1);
    else:
        temp=concat(temp,set1);
    kleene=kleene.union(temp);
print("Kleene closure of set 1:",kleene);

# Positive closure
positive=set();
temp=set();
count=int(input("\nEnter the count for positive closure: "));
for i in range(count):
    if(i==0):
        temp=temp.union(set1);
    else:
        temp=concat(temp,set1);
    positive=positive.union(temp);
print("Positive closure of set 1:",positive);