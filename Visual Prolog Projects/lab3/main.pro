% Copyright
/*
Каким пациентам врач выписал больничный
Все пациенты врача и их диагнозы
Все приемы пациента
У кого из врачей было больше всех приемов за определенный день и сколько (приемов)
*/

implement main
    open core, stdio, file, list

domains
    diagnos = diagnos(string Name, string Diagnos).
    visit = visit(string DocName, string Day, string Diagnos, string Receipt, string Sickleave).

class facts - medDB
    карта : (integer Id, string Name, string Gender, string Adress, string Phone, integer Age).
    врач : (integer Id, string Name, string Specialty).
    прием : (integer DocId, integer PatientId, string Day, string Diagnos, string Receipt, string SickLeave).

class predicates
    len : (A*) -> integer N.
clauses
    len([]) = 0.
    len([_ | T]) = len(T) + 1.

class predicates
    больничные : (string Doc) -> string* Sickleaves determ.
    диагнозы : (string Doc) -> diagnos* Diagnoses determ.
    приемы : (string Name) -> visit* Visits determ.
    максимум : (integer* List) -> integer M nondeterm.
    колвоприемовкаждоговрача : (string Day) -> integer* List.
    приемыврача : (integer DocId, string Day) -> integer* List determ.
    выводсписка : (string* List).
    выводдиагнозов : (diagnos* List).
    выводприемов : (visit* List).

clauses
    больничные(Doc) = List :-
        врач(DocId, Doc, _),
        !,
        List =
            [ Name ||
                прием(DocId, PatientId, _, _, _, "да"),
                карта(PatientId, Name, _, _, _, _)
            ].

    диагнозы(Doc) = List :-
        врач(DocId, Doc, _),
        !,
        List =
            [ diagnos(Name, Diagnos) ||
                прием(DocId, PatientId, _, Diagnos, _, _),
                карта(PatientId, Name, _, _, _, _)
            ].

    приемы(Name) = List :-
        карта(PatientId, Name, _, _, _, _),
        !,
        List =
            [ visit(DocName, Day, Diagnos, Receipt, Sickleave) ||
                прием(DocId, PatientId, Day, Diagnos, Receipt, Sickleave),
                врач(DocId, DocName, _)
            ].

    приемыврача(DocId, Day) = List :-
        врач(DocId, _, _),
        !,
        List =
            [ PatientId ||
                прием(DocId, PatientId, Day, _, _, _),
                карта(PatientId, _, _, _, _, _)
            ].

    максимум([H]) = H.
    максимум([H | T]) = H :-
        M = максимум(T),
        H > M,
        !.
    максимум([_ | T]) = M :-
        максимум(T) = M.

    колвоприемовкаждоговрача(Day) =
        [ Kolvo ||
            врач(DocId, _, _),
            List = приемыврача(DocId, Day),
            Kolvo = len(List)
        ].

    выводсписка(List) :-
        foreach Element = getMember_nd(List) and Index = tryGetIndex(Element, List) do
            write("\t", Index + 1, ")", Element),
            nl
        end foreach.

    выводдиагнозов(List) :-
        foreach diagnos(Name, Diagnos) = getMember_nd(List) do
            write("\t", Name, " - ", Diagnos),
            nl
        end foreach.

    выводприемов(List) :-
        foreach visit(DocName, Day, Diagnos, Receipt, Sickleave) = getMember_nd(List) do
            write("\t", DocName, ", ", Day, ", ", Diagnos, ", ", Receipt, ", ", Sickleave),
            nl
        end foreach.

    run() :-
        console::init(),
        reconsult("..\\med.txt", medDB),
        Doc = "Живоглядова Галина Евгеньевна",
        List = больничные(Doc),
        write("Пациенты, которым ", Doc, " выдал(а) больничный: \n"),
        выводсписка(List),
        nl,
        fail.

    run() :-
        Doc = "Раскатова Валентина Данииловна",
        List = диагнозы(Doc),
        write("Пациенты врача ", Doc, " и их диагнозы: \n"),
        выводдиагнозов(List),
        nl,
        fail.

    run() :-
        Name = "Трофимов Тихон Геннадиевич",
        List = приемы(Name),
        write("Информация о всех приемах пациента ", Name, ":\n"),
        выводприемов(List),
        nl,
        fail.

    run() :-
        Day = "02.05.2020",
        List = колвоприемовкаждоговрача(Day),
        Max = максимум(List),
        Index = tryGetIndex(Max, List),
        врач(Index + 1, DocName, _),
        write("У врача ", DocName, " за ", Day, " было больше всех приемов (", Max, ")."),
        nl,
        fail.

    run() :-
        succeed.

end implement main

goal
    console::run(main::run).
