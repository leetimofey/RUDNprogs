% Copyright

implement main
    open core, stdio

domains
    ilist = integer*.
    %slist = string*.

domains
%name = string.
%group = integer.
%student = student(name, group).
%students = student*.

class facts
    s : (ilist).

clauses
    s([1, 2, 3]).

class predicates
    contains : (integer, ilist) determ.
clauses
    contains(X, [X | _]) :-
        !.
    contains(X, [_ | T]) :-
        contains(X, T).

class predicates
    addHead : (integer, ilist, ilist [out]).
clauses
    addHead(H, T, [H | T]).

%class predicates
%length_of : (AnyType*, integer [out]). %14:23
%clauses
%length_of([], 0).
% length_of([_ | T], Length + 1) :-
%      length_of(T, Length).
class predicates
    write_list : (A*).
clauses
    write_list([]).
    write_list([H]) :-
        write(H, "."),
        !.
    write_list([H | T]) :-
        write(H, ", "),
        write_list(T).

class predicates
    gen : (integer A, integer N, ilist L [out]) determ.
clauses
    gen(1, 1, [1]).
    gen(A, N, [1 | T]) :-
        A1 = A + 1,
        gen(A1, N, T).

clauses
    run() :-
        s(X),
        write_list(X),
        contains(3, X),
        nl,
        write('3 is in list!'),
        addHead(10, X, Y),
        nl,
        write_list(Y),
        nl,
        gen(1, 10, Z),
        nl,
        write_list(Z),
        nl,
        !.
    run().

end implement main

goal
    console::runUtf8(main::run).
