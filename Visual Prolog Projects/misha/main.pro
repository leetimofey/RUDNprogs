% Copyright
/*
Какие Фильмы показывает определенный кинотеатр
Какие фильмы определенного жанра щас идут в кинотетре
*/

implement main
    open core, file, stdio

domains
    genres =
        crime; drama; action; thriller; biography; history; adventure; fantasy; western; romance; sci_fi; mystery; comedy; war; family; animation;
        musical; music; horror; film_noir; sport.

class facts - kinoDB
    genre : (integer Id, genres Genre).
    cinema : (integer Id, string Name, string Adress, string Telephone).
    film : (integer Id, string Name, string Released, string Director).
    filmGenre : (integer FilmId, integer GenreId).
    showing : (integer CinemaId, integer FilmId, string Date, string Time).

class facts
    s : (real Sum) single.

clauses
    s(0).

class predicates
    filmInCinema : (string CinemaName) nondeterm.
clauses
    filmInCinema(X) :-
        cinema(Cid, X, _, _),
        write("Фильмы в ", X, ":\n"),
        showing(Cid, Fid, _, _),
        film(Fid, Name, _, _),
        write("  ", Name),
        nl,
        fail.
    filmInCinema(X) :-
        cinema(_, X, _, _),
        write("Конец списка"),
        nl.

    run() :-
        console::init(),
        reconsult("..\\selection.txt", kinoDB),
        filmInCinema("Иллюзион"),
        fail.
    run() :-
        succeed.

end implement main

goal
    console::run(main::run).
