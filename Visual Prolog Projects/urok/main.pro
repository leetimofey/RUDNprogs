% Copyright

implement main
    open core, stdio

class predicates
    fib : (integer N, integer64 Fib [out]) determ.

class facts
    s : (integer Check) single.

clauses
    s(0).

clauses
    fib(0, 0) :-
        !.
    fib(1, 1) :-
        !.
    fib(N, F) :-
        N1 = N - 1,
        N2 = N - 2,
        fib(N1, F1),
        fib(N2, F2),
        F = F1 + F2.

    run() :-
        assert(s(0)),
        s(Check),
        fib(Check, F),
        write(F),
        asserta(s(Check + 1)),
        fail.
    run().

end implement main

goal
    console::runUtf8(main::run).
