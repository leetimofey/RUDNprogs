% Copyright
/*
Какие Фильмы показывает определенный кинотеатр
Какие у фильма жанры
В каком кинотеатре и какие фильмы сейчас в прокате определенного жанра
Сколько фильмов определенного режиссера в топе
*/

implement main
    open core, file, stdio, math

domains
    genres =
        crime; drama; action; thriller; biography; history; adventure; fantasy; western; romance; sci_fi; mystery; comedy; war; family; animation;
        musical; music; horror; film_noir; sport.
    cinema_film = cinema_film(string Cinema, string Film).
    distance = distance(integer Cid, real Dst).

class facts - kinoDB
    genre : (integer GenreId, genres Genre).
    cinema : (integer Id, string Name, string Adress, string Telephone, real Latitude, real Longitude).
    film : (integer Id, string Name, string Released, string Director).
    filmGenre : (integer FilmId, integer GenreId).
    showing : (integer CinemaId, integer FilmId, string Date, string Time).

class predicates  %Вспомогательные предикаты
    len : (A*) -> integer N.
clauses
    len([]) = 0.
    len([_ | T]) = len(T) + 1.

class predicates
    calcilateDistance : (real SrcLatitude, real SrcLongitude, real DstLatitude, real DstLongitude) -> real Distance.
clauses
    calcilateDistance(SrcLatitude, SrcLongitude, DstLatitude, DstLongitude) = Distance :-
        X =
            sqrt(
                sin((SrcLatitude - abs(DstLatitude)) * pi / 180 / 2) * sin((SrcLatitude - abs(DstLatitude)) * pi / 180 / 2)
                    + cos(SrcLatitude * pi / 180) * cos(abs(DstLatitude * pi / 180)) * sin((SrcLongitude - DstLongitude) * pi / 180 / 2)
                        * sin((SrcLongitude - DstLongitude) * pi / 180 / 2)),
        NewX = convert(math::inCircle, X),
        Distance = 6371 * 2 * arcsin(NewX).

class predicates
    filmInCinema : (string CinemaName) -> string* Films determ.
    getGenres : (string CinemaName) -> genres* G determ.
    getStreamByGenre : (genres X) -> cinema_film* Cifi determ.
    numFilmsByDirector : (string Director) -> string* Names.
    getAllCinemaDst : (real SrcLatitude, real SrcLongitude) -> real* Result.

clauses
    filmInCinema(X) = List :-
        cinema(Cid, X, _, _, _, _),
        !,
        List =
            [ Name ||
                showing(Cid, Fid, _, _),
                film(Fid, Name, _, _)
            ].

    getGenres(X) = List :-
        film(Cid, X, _, _),
        !,
        List =
            [ Name ||
                filmGenre(Cid, Gen),
                genre(Gen, Name)
            ].

    getStreamByGenre(X) = List :-
        write("Фильмы жанра ", X, " идут в кинотеатрах:\n"),
        genre(Id, X),
        !,
        List =
            [ cinema_film(Cname, Fname) ||
                showing(Cid, Fid, _, _),
                cinema(Cid, Cname, _, _, _, _),
                filmGenre(Fid, Id),
                film(Fid, Fname, _, _)
            ].

    numFilmsByDirector(X) = [ Name || film(_, Name, _, X) ].

    getAllCinemaDst(SrcLatitude, SrcLongitude) =
        [ Dst ||
            cinema(_, _, _, _, Lat, Lon),
            Dst = calcilateDistance(SrcLatitude, SrcLongitude, Lat, Lon)
        ].

class predicates  %Вывод на экран
    beautifyOutputStr : (string* Str).
    beautifyCiFi : (cinema_film* Cifi).
    beautifyGenre : (genres* Gen).

clauses
    beautifyOutputStr(L) :-
        foreach Elem = list::getMember_nd(L) and Idx = list::tryGetIndex(Elem, L) do
            write("\t", Idx + 1, ". ", Elem),
            nl
        end foreach.

    beautifyCiFi(L) :-
        foreach cinema_film(Cname, Fname) = list::getMember_nd(L) do
            writef("\t% <---> %\n", Cname, Fname)
        end foreach.

    beautifyGenre(L) :-
        foreach Elem = list::getMember_nd(L) do
            write("\t", Elem),
            nl
        end foreach.

clauses
    run() :-
        console::init(),
        reconsult("..\\selection.txt", kinoDB),
        X = "Иллюзион",
        L = filmInCinema(X),
        write("Фильмы в ", X, ":\n"),
        beautifyOutputStr(L),
        nl,
        nl,
        fail.

    run() :-
        X = "The Dark Knight",
        L = getGenres("The Dark Knight"),
        write("Жанры ", X, ":\n"),
        beautifyGenre(L),
        nl,
        nl,
        fail.
    run() :-
        X = thriller,
        L = getStreamByGenre(X),
        beautifyCiFi(L),
        write(len(L), " фильмов жанра ", X, " сейчас в кино."),
        nl,
        nl,
        fail.

    run() :-
        X = "Christopher Nolan",
        L = numFilmsByDirector(X),
        write("Всего фильмов режиссера ", X, " = ", len(L), ". Их названия: \n"),
        beautifyOutputStr(L),
        fail.

    run() :-
        %55.753648
        %37.619952
        SrcLat = 55.753648,
        SrcLon = 37.619952,
        D = getAllCinemaDst(SrcLat, SrcLon),
        Min = list::minimum(D),
        Idx = list::tryGetIndex(Min, D),
        cinema(Idx + 1, Name, _, _, _, _),
        nl,
        write("Ближайший кинотеатр к вам это: ", Name),
        fail.
    run() :-
        succeed.

end implement main

goal
    console::run(main::run).
