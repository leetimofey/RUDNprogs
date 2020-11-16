% Copyright
/*
Каким пациентам врач выписал больничный
Все пациенты врача и их диагнозы
Все приемы пациента
Все приемы за день и их количество
*/

implement main
    open core, stdio, file

class facts - medDB
    карта : (integer Id, string Name, string Gender, string Adress, string Phone, integer Age).
    врач : (integer Id, string Name, string Specialty).
    прием : (integer DocId, integer PatientId, string Day, string Diagnos, string Receipt, string SickLeave).

class facts
    s : (real Kolvo) single.

clauses
    s(0).

class predicates
    больничные : (string Doc) nondeterm.
    диагнозы : (string Doc) nondeterm.
    приемы : (string Name) nondeterm.
    приемыЗаДень : (string Day).

clauses
    больничные(Doc) :-
        врач(DocId, Doc, _),
        write("Пациенты, которым ", Doc, " выписал(а) больничный: \n"),
        карта(PatientId, Name, _, _, _, _),
        прием(DocId, PatientId, _, _, _, "да"),
        write(Name),
        nl,
        fail.
    больничные(Doc) :-
        врач(_, Doc, _),
        write("Конец списка\n"),
        nl.

    диагнозы(Doc) :-
        врач(DocId, Doc, _),
        write("Пациенты врача ", Doc, " и их диагнозы: \n"),
        карта(PatientId, Name, _, _, _, _),
        прием(DocId, PatientId, _, Diagnos, _, _),
        write(Name, ", ", Diagnos),
        nl,
        fail.
    диагнозы(Doc) :-
        врач(_, Doc, _),
        write("Конец списка\n"),
        nl.

    приемы(Name) :-
        карта(PatientId, Name, _, _, _, _),
        write("Приемы пациента ", Name, ": \n"),
        прием(DocId, PatientId, Day, Diagnos, Receipt, Sickleave),
        врач(DocId, DocName, _),
        write(DocName, ", ", Day, ", ", Diagnos, ", ", Receipt, ", ", Sickleave),
        nl,
        fail.
    приемы(Name) :-
        карта(_, Name, _, _, _, _),
        write("Конец списка\n"),
        nl.

    приемыЗаДень(Day) :-
        write("Приемы за ", Day, " и их количество: \n"),
        assert(s(0)),
        прием(DocId, PatientId, Day, Diagnos, Receipt, Sickleave),
        врач(DocId, DocName, _),
        карта(PatientId, Name, _, _, _, _),
        s(Kolvo),
        asserta(s(Kolvo + 1)),
        write(DocName, ", ", Name, ", ", Diagnos, ", ", Receipt, ", ", Sickleave),
        nl,
        fail.
    приемыЗаДень(_Day) :-
        write("Конец списка\n"),
        s(Kolvo),
        write("Всего приемов за день: ", Kolvo, "\n"),
        nl.

    run() :-
        console::init(),
        reconsult("..\\med.txt", medDB),
        больничные("Живоглядова Галина Евгеньевна"),
        fail.
    run() :-
        диагнозы("Раскатова Валентина Данииловна"),
        fail.
    run() :-
        приемы("Трофимов Тихон Геннадиевич"),
        fail.
    run() :-
        приемыЗаДень("04.05.2020"),
        fail.
    run() :-
        succeed.

end implement main

goal
    console::run(main::run).
