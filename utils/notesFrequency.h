#ifndef NOTESFREQUENCY_H
#define NOTESFREQUENCY_H

#include <initializer_list>
#include <QDebug>

enum octave {
    noteDo0 = 3270,
    noteDo1 = 6541,
    noteDo2 = 13081,
    noteDo3 = 26163,
    noteDo4 = 52325,
    noteDo5 = 104650,
    noteDo6 = 209300,
    noteDo7 = 418601,
    noteDo8 = 837202,
    noteDo9 = 1674404,
    noteDod0 = 3465,
    noteDod1 = 6930,
    noteDod2 = 13859,
    noteDod3 = 27718,
    noteDod4 = 55437,
    noteDod5 = 110873,
    noteDod6 = 221746,
    noteDod7 = 443492,
    noteDod8 = 886984,
    noteDod9 = 1773968,
    noteRe0 = 3671,
    noteRe1 = 7342,
    noteRe2 = 14683,
    noteRe3 = 29366,
    noteRe4 = 58733,
    noteRe5 = 117466,
    noteRe6 = 234932,
    noteRe7 = 469864,
    noteRe8 = 939728,
    noteRe9 = 1879456,
    noteRed0 = 3889,
    noteRed1 = 7778,
    noteRed2 = 15556,
    noteRed3 = 31113,
    noteRed4 = 62225,
    noteRed5 = 124451,
    noteRed6 = 248902,
    noteRed7 = 497803,
    noteRed8 = 995606,
    noteRed9 = 1991212,
    noteMi0 = 4120,
    noteMi1 = 8241,
    noteMi2 = 16481,
    noteMi3 = 32963,
    noteMi4 = 65926,
    noteMi5 = 131851,
    noteMi6 = 263702,
    noteMi7 = 527404,
    noteMi8 = 1054808,
    noteMi9 = 2109616,
    noteFa0 = 4365,
    noteFa1 = 8731,
    noteFa2 = 17461,
    noteFa3 = 34923,
    noteFa4 = 69846,
    noteFa5 = 139691,
    noteFa6 = 279383,
    noteFa7 = 558765,
    noteFa8 = 1117530,
    noteFa9 = 2235060,
    noteFad0 = 4625,
    noteFad1 = 9250,
    noteFad2 = 18500,
    noteFad3 = 36999,
    noteFad4 = 73999,
    noteFad5 = 147998,
    noteFad6 = 295996,
    noteFad7 = 591991,
    noteFad8 = 1183982,
    noteFad9 = 2367964,
    noteSol0 = 4900,
    noteSol1 = 9800,
    noteSol2 = 19600,
    noteSol3 = 39200,
    noteSol4 = 78399,
    noteSol5 = 156798,
    noteSol6 = 313596,
    noteSol7 = 627193,
    noteSol8 = 1254386,
    noteSol9 = 2508772,
    noteSold0 = 5191,
    noteSold1 = 10383,
    noteSold2 = 20765,
    noteSold3 = 41530,
    noteSold4 = 83061,
    noteSold5 = 166122,
    noteSold6 = 332244,
    noteSold7 = 664488,
    noteSold8 = 1328976,
    noteSold9 = 2657952,
    noteLa0 = 5500,
    noteLa1 = 11000,
    noteLa2 = 22000,
    noteLa3 = 44000,
    noteLa4 = 88000,
    noteLa5 = 176000,
    noteLa6 = 352000,
    noteLa7 = 704000,
    noteLa8 = 1408000,
    noteLa9 = 2816000,
    noteLad0 = 5827,
    noteLad1 = 11654,
    noteLad2 = 23308,
    noteLad3 = 46616,
    noteLad4 = 93233,
    noteLad5 = 186466,
    noteLad6 = 372931,
    noteLad7 = 745862,
    noteLad8 = 1491724,
    noteLad9 = 2983448,
    noteSi0 = 6174,
    noteSi1 = 12347,
    noteSi2 = 24694,
    noteSi3 = 49388,
    noteSi4 = 98777,
    noteSi5 = 197553,
    noteSi6 = 395107,
    noteSi7 = 790213,
    noteSi8 = 1580426,
    noteSi9 = 316085,
    silence
};

constexpr std::initializer_list<octave> octaves = {noteDo0, noteDo1, noteDo2, noteDo3, noteDo4, noteDo5, noteDo6, noteDo7, noteDo8, noteDo9, noteDod0, noteDod1, noteDod2, noteDod3, noteDod4, noteDod5, noteDod6, noteDod7, noteDod8, noteDod9, noteRe0, noteRe1, noteRe2, noteRe3, noteRe4, noteRe5, noteRe6, noteRe7, noteRe8, noteRe9, noteRed0, noteRed1, noteRed2, noteRed3, noteRed4, noteRed5, noteRed6, noteRed7, noteRed8, noteRed9, noteMi0, noteMi1, noteMi2, noteMi3, noteMi4, noteMi5, noteMi6, noteMi7, noteMi8, noteMi9, noteFa0, noteFa1, noteFa2, noteFa3, noteFa4, noteFa5, noteFa6, noteFa7, noteFa8, noteFa9, noteFad0, noteFad1, noteFad2, noteFad3, noteFad4, noteFad5, noteFad6, noteFad7, noteFad8, noteFad9, noteSol0, noteSol1, noteSol2, noteSol3, noteSol4, noteSol5, noteSol6, noteSol7, noteSol8, noteSol9, noteSold0, noteSold1, noteSold2, noteSold3, noteSold4, noteSold5, noteSold6, noteSold7, noteSold8, noteSold9, noteLa0, noteLa1, noteLa2, noteLa3, noteLa4, noteLa5, noteLa6, noteLa7, noteLa8, noteLa9, noteLad0, noteLad1, noteLad2, noteLad3, noteLad4, noteLad5, noteLad6, noteLad7, noteLad8, noteLad9, noteSi0, noteSi1, noteSi2, noteSi3, noteSi4, noteSi5, noteSi6, noteSi7, noteSi8, noteSi9};

inline QDebug operator<< (QDebug dbg, octave const& o) {
    dbg<<"Note :";
    switch (o) {
        case noteDo0: dbg<< "noteDo0"; break;
        case noteDo1: dbg<< "noteDo1"; break;
        case noteDo2: dbg<< "noteDo2"; break;
        case noteDo3: dbg<< "noteDo3"; break;
        case noteDo4: dbg<< "noteDo4"; break;
        case noteDo5: dbg<< "noteDo5"; break;
        case noteDo6: dbg<< "noteDo6"; break;
        case noteDo7: dbg<< "noteDo7"; break;
        case noteDo8: dbg<< "noteDo8"; break;
        case noteDo9: dbg<< "noteDo9"; break;
        case noteDod0: dbg<< "noteDod0"; break;
        case noteDod1: dbg<< "noteDod1"; break;
        case noteDod2: dbg<< "noteDod2"; break;
        case noteDod3: dbg<< "noteDod3"; break;
        case noteDod4: dbg<< "noteDod4"; break;
        case noteDod5: dbg<< "noteDod5"; break;
        case noteDod6: dbg<< "noteDod6"; break;
        case noteDod7: dbg<< "noteDod7"; break;
        case noteDod8: dbg<< "noteDod8"; break;
        case noteDod9: dbg<< "noteDod9"; break;
        case noteRe0: dbg<< "noteRe0"; break;
        case noteRe1: dbg<< "noteRe1"; break;
        case noteRe2: dbg<< "noteRe2"; break;
        case noteRe3: dbg<< "noteRe3"; break;
        case noteRe4: dbg<< "noteRe4"; break;
        case noteRe5: dbg<< "noteRe5"; break;
        case noteRe6: dbg<< "noteRe6"; break;
        case noteRe7: dbg<< "noteRe7"; break;
        case noteRe8: dbg<< "noteRe8"; break;
        case noteRe9: dbg<< "noteRe9"; break;
        case noteRed0: dbg<< "noteRed0"; break;
        case noteRed1: dbg<< "noteRed1"; break;
        case noteRed2: dbg<< "noteRed2"; break;
        case noteRed3: dbg<< "noteRed3"; break;
        case noteRed4: dbg<< "noteRed4"; break;
        case noteRed5: dbg<< "noteRed5"; break;
        case noteRed6: dbg<< "noteRed6"; break;
        case noteRed7: dbg<< "noteRed7"; break;
        case noteRed8: dbg<< "noteRed8"; break;
        case noteRed9: dbg<< "noteRed9"; break;
        case noteMi0: dbg<< "noteMi0"; break;
        case noteMi1: dbg<< "noteMi1"; break;
        case noteMi2: dbg<< "noteMi2"; break;
        case noteMi3: dbg<< "noteMi3"; break;
        case noteMi4: dbg<< "noteMi4"; break;
        case noteMi5: dbg<< "noteMi5"; break;
        case noteMi6: dbg<< "noteMi6"; break;
        case noteMi7: dbg<< "noteMi7"; break;
        case noteMi8: dbg<< "noteMi8"; break;
        case noteMi9: dbg<< "noteMi9"; break;
        case noteFa0: dbg<< "noteFa0"; break;
        case noteFa1: dbg<< "noteFa1"; break;
        case noteFa2: dbg<< "noteFa2"; break;
        case noteFa3: dbg<< "noteFa3"; break;
        case noteFa4: dbg<< "noteFa4"; break;
        case noteFa5: dbg<< "noteFa5"; break;
        case noteFa6: dbg<< "noteFa6"; break;
        case noteFa7: dbg<< "noteFa7"; break;
        case noteFa8: dbg<< "noteFa8"; break;
        case noteFa9: dbg<< "noteFa9"; break;
        case noteFad0: dbg<< "noteFad0"; break;
        case noteFad1: dbg<< "noteFad1"; break;
        case noteFad2: dbg<< "noteFad2"; break;
        case noteFad3: dbg<< "noteFad3"; break;
        case noteFad4: dbg<< "noteFad4"; break;
        case noteFad5: dbg<< "noteFad5"; break;
        case noteFad6: dbg<< "noteFad6"; break;
        case noteFad7: dbg<< "noteFad7"; break;
        case noteFad8: dbg<< "noteFad8"; break;
        case noteFad9: dbg<< "noteFad9"; break;
        case noteSol0: dbg<< "noteSol0"; break;
        case noteSol1: dbg<< "noteSol1"; break;
        case noteSol2: dbg<< "noteSol2"; break;
        case noteSol3: dbg<< "noteSol3"; break;
        case noteSol4: dbg<< "noteSol4"; break;
        case noteSol5: dbg<< "noteSol5"; break;
        case noteSol6: dbg<< "noteSol6"; break;
        case noteSol7: dbg<< "noteSol7"; break;
        case noteSol8: dbg<< "noteSol8"; break;
        case noteSol9: dbg<< "noteSol9"; break;
        case noteSold0: dbg<< "noteSold0"; break;
        case noteSold1: dbg<< "noteSold1"; break;
        case noteSold2: dbg<< "noteSold2"; break;
        case noteSold3: dbg<< "noteSold3"; break;
        case noteSold4: dbg<< "noteSold4"; break;
        case noteSold5: dbg<< "noteSold5"; break;
        case noteSold6: dbg<< "noteSold6"; break;
        case noteSold7: dbg<< "noteSold7"; break;
        case noteSold8: dbg<< "noteSold8"; break;
        case noteSold9: dbg<< "noteSold9"; break;
        case noteLa0: dbg<< "noteLa0"; break;
        case noteLa1: dbg<< "noteLa1"; break;
        case noteLa2: dbg<< "noteLa2"; break;
        case noteLa3: dbg<< "noteLa3"; break;
        case noteLa4: dbg<< "noteLa4"; break;
        case noteLa5: dbg<< "noteLa5"; break;
        case noteLa6: dbg<< "noteLa6"; break;
        case noteLa7: dbg<< "noteLa7"; break;
        case noteLa8: dbg<< "noteLa8"; break;
        case noteLa9: dbg<< "noteLa9"; break;
        case noteLad0: dbg<< "noteLad0"; break;
        case noteLad1: dbg<< "noteLad1"; break;
        case noteLad2: dbg<< "noteLad2"; break;
        case noteLad3: dbg<< "noteLad3"; break;
        case noteLad4: dbg<< "noteLad4"; break;
        case noteLad5: dbg<< "noteLad5"; break;
        case noteLad6: dbg<< "noteLad6"; break;
        case noteLad7: dbg<< "noteLad7"; break;
        case noteLad8: dbg<< "noteLad8"; break;
        case noteLad9: dbg<< "noteLad9"; break;
        case noteSi0: dbg<< "noteSi0"; break;
        case noteSi1: dbg<< "noteSi1"; break;
        case noteSi2: dbg<< "noteSi2"; break;
        case noteSi3: dbg<< "noteSi3"; break;
        case noteSi4: dbg<< "noteSi4"; break;
        case noteSi5: dbg<< "noteSi5"; break;
        case noteSi6: dbg<< "noteSi6"; break;
        case noteSi7: dbg<< "noteSi7"; break;
        case noteSi8: dbg<< "noteSi8"; break;
        case noteSi9: dbg<< "noteSi9"; break;
        case silence: dbg<<"silence"; break;
        default: dbg << int(o); break;
    }
    return dbg;
}

enum noteDuration {
    semiquaver,
    quaver,
    crotchet,
    minim,
    semibreve,
    breve
};

struct Note {
    Note (noteDuration type, octave note) : type(type), note(note){};
    noteDuration type;
    octave note;
};

#endif // NOTESFREQUENCY_H
