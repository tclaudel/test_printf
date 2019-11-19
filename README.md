# test_printf

To use this test, clone it in your repo, compile with your libftprintf.a

Default test : `gcc -Wall -Wextra test.c -g3 libftprintf.a && ./a.out`

exemple all test : `gcc -Wall -Wextra test.c -g3 libftprintf.a && ./a.out a`

to check differents option run with whose differents av[1] 

- `./a.out a` for all tests
- `./a.out d` for %d
- `./a.out s` for %s
- `./a.out c` for %c
- `./a.out p` for %p
- `./a.out x` for %x
- `./a.out X` for %X
- `./a.out u` for %u
- `./a.out o` for %%
- `./a.out m` fot mixed tests

you can also check your unittest with solotest.c, just modify between |...| and add some args

**42/Lyon tclaudel**
