# Compiler-Design

Collection of beginner-friendly Lex &amp; Yacc programs

# :gear: Run programs

Lex Programs:

```bash
  lex filename.l
  cc lex.yy.c -ll
  ./a.out
```

Yacc Programs:

```bash
  lex filename.l
  yacc -d filename.y
  cc lex.yy.c y.tab.c -ll
  ./a.out
```