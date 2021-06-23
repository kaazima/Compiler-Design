n=int(input('Enter the number of productions: '))
grammar=[]
augment=[]
nt=[]

# Input given grammar
print('Enter the grammar: (use "->" for productions)')
for i in range (0,n):
    grammar.append(input())
    nt.append(grammar[i][0])
    
# Augment given grammar   
augment.append('A->'+nt[0]+'$')
for i in range (0,n):
    for j in grammar[i].split('->')[1].split('|'):
        augment.append(grammar[i].split('->')[0]+'->'+j)
print('\nGrammar after augmentation is:')
print(augment)

# Finding first set
def firstset(s):
    first=[]
    if(s[0] not in nt):
        return s[0]
    for i in augment:
        if(i[0]==s[0]):
            temp=i.split('->')[1][0]
            if(temp not in nt):
                first.append(temp)
            else:
                f=firstset(temp)
                for j in f:
                  if(j not in first):
                    first.append(j)
    return first
    
# Closure of initial state
def closure(rule,la):
  res=[[rule,la]]
  t=rule.split("->")[1]
  for i in augment:
    if(i[0]==t[0]):
      temp=[i,firstset(t[1:]+la)]
      res.append(temp)
    for j in res:
      t=j[0].split("->")[1]
      for i in augment:
        if(i[0]==t[0]):
          temp=[i,firstset(t[1:]+j[1])]
          if(temp not in res):
            res.append(temp)
  return res

print('\nInitial state of the given grammar in LR(1) parsing is:')
print(closure(augment[0],'?'))
