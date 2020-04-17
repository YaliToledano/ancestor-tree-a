#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;

/*
TEST_CASE("realtion test") {
family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
     .addMother("Isaac", "Sarah")
	 .addFather("Avraham", "Terah");

     family::Tree T2 ("jojo");
     T2.addFather("jojo", "jos")
        .addMother("jojo", "rivka")
        .addFather("jos", "jotaro")
        .addMother("jos", "holly")
        .addFather("rivka", "gio")
        .addMother("rivka", "dio")
        .addFather("jotro", "kill")
        .addMother("jotro", "hoe")
        .addFather("holly", "shit")
        .addMother("holly", "omg")
        .addFather("dio", "snapdragon")
        .addMother("dio", "joska")
        .addFather("gio", "lisa-lisa")
        .addMother("gio", "mario")
        .addFather("lisa-lisa", "muda")
        .addMother("lisa-lisa", "wry")
        .addFather("muda", "golden")
        .addMother("muda", "wind");

    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));

    CHECK( T2.relation("jos") ==string("father"));
    CHECK( T2.relation("rivka") ==string("mother"));
    CHECK( T2.relation("jotaro") ==string("grandfather"));
    CHECK( T2.relation("gio") ==string("grandfather"));
    CHECK( T2.relation("holly") ==string("grandmother"));
    CHECK( T2.relation("dio") ==string("grandmother"));
    CHECK( T2.relation("kill") ==string("great-grandfather"));
    CHECK( T2.relation("shit") ==string("great-grandfather"));
    CHECK( T2.relation("lisa-lisa") ==string("great-grandfather"));
    CHECK( T2.relation("snapdragon") ==string("great-grandfather"));
    CHECK( T2.relation("hoe") ==string("great-grandmother"));
    CHECK( T2.relation("omg") ==string("great-grandmother"));
    CHECK( T2.relation("mario") ==string("great-grandmother"));
    CHECK( T2.relation("joska") ==string("great-grandmother"));
    CHECK( T2.relation("muda") ==string("great-great-grandfather"));
    CHECK( T2.relation("why") ==string("great-great-grandmother"));
    CHECK( T2.relation("golden") ==string("great-great-great-grandfather"));
    CHECK( T2.relation("wind") ==string("great-great-great-grandmother"));
    CHECK(T2.relation("jojo")==string("me"));
}
TEST_CASE("find Test") {

family::Tree T2 ("jojo");
     T2.addFather("jojo", "jos")
        .addMother("jojo", "rivka")
        .addFather("jos", "jotaro")
        .addMother("jos", "holly")
        .addFather("rivka", "gio")
        .addMother("rivka", "dio")
        .addFather("jotro", "kill")
        .addMother("jotro", "hoe")
        .addFather("holly", "shit")
        .addMother("holly", "omg")
        .addFather("dio", "snapdragon")
        .addMother("dio", "joska")
        .addFather("gio", "lisa-lisa")
        .addMother("gio", "mario")
        .addFather("lisa-lisa", "muda")
        .addMother("lisa-lisa", "wry")
        .addFather("muda", "golden")
        .addMother("muda", "wind");

    CHECK( T2.find("father") ==string("jos"));
    CHECK( T2.find("mother") ==string("rivka"));
    CHECK( T2.find("grandfather") ==string("jotaro"));
    CHECK( T2.find("grandfather") ==string("gio"));
    CHECK( T2.find("grandmother") ==string("holly"));
    CHECK( T2.find("grandmother") ==string("dio"));
    CHECK( T2.find("great-grandfather") ==string("kill"));
    CHECK( T2.find("great-grandfather") ==string("shit"));
    CHECK( T2.find("great-grandfather") ==string("lisa-lisa"));
    CHECK( T2.find("great-grandfather") ==string("snapdragon"));
    CHECK( T2.find("great-grandmother") ==string("hoe"));
    CHECK( T2.find("great-grandmother") ==string("omg"));
    CHECK( T2.find("great-grandmother") ==string("mario"));
    CHECK( T2.find("great-grandmother") ==string("joska"));
    CHECK( T2.find("great-great-grandfather") ==string("wry"));
    CHECK( T2.find("great-great-grandfather") ==string("muda"));
    CHECK( T2.find("great-great-great-grandfather") ==string("wind"));
    CHECK( T2.find("great-great-great-grandfather") ==string("golden"));
    CHECK( T2.find("me")==string("jojo"));
}


TEST_CASE("Test remove")
{
    family::Tree T2 ("jojo");
    T2.addFather("jojo", "jos")
        .addMother("jojo", "rivka")
        .addFather("jos", "jotaro")
        .addMother("jos", "holly")
        .addFather("rivka", "gio")
        .addMother("rivka", "dio")
        .addFather("jotro", "kill")
        .addMother("jotro", "hoe")
        .addFather("holly", "shit")
        .addMother("holly", "omg")
        .addFather("dio", "snapdragon")
        .addMother("dio", "joska")
        .addFather("gio", "lisa-lisa")
        .addMother("gio", "mario")
        .addFather("lisa-lisa", "muda")
        .addMother("lisa-lisa", "wry")
        .addFather("muda", "golden")
        .addMother("muda", "wind");

    T2.remove("wind");
    CHECK(T2.relation("wind") == "unrealted");
    T2.remove("lisa-lisa");
    CHECK(T2.relation("lisa-lisa") == "unrealted");
    CHECK(T2.relation("muda") == "unrealted");
    CHECK(T2.relation("wry") == "unrealted");
    CHECK(T2.relation("golden") == "unrealted");
    T2.remove("holly");
    CHECK(T2.relation("holly") == "unrealted");
    CHECK(T2.relation("omg") == "unrealted");
    CHECK(T2.relation("shit") == "unrealted");
    T2.remove("dio");
    CHECK(T2.relation("snapdragon") == "unrealted");
    CHECK(T2.relation("dio") == "unrealted");
    CHECK(T2.relation("joska") == "unrealted");
    T2.remove("gio");
    CHECK(T2.relation("gio") == "unrealted");
    CHECK(T2.relation("mario") == "unrealted");
}

TEST_CASE("Test add")
{
    family::Tree T2 ("jojo");
    T2.addFather("jojo", "jos")
        .addMother("jojo", "rivka")
        .addFather("jos", "jotaro")
        .addMother("jos", "holly")
        .addFather("rivka", "gio")
        .addMother("rivka", "dio")
        .addFather("jotro", "kill")
        .addMother("jotro", "hoe")
        .addFather("holly", "shit")
        .addMother("holly", "omg")
        .addFather("dio", "snapdragon")
        .addMother("dio", "joska")
        .addFather("gio", "lisa-lisa")
        .addMother("gio", "mario")
        .addFather("lisa-lisa", "muda")
        .addMother("lisa-lisa", "wry")
        .addFather("muda", "golden")
        .addMother("muda", "wind");

    CHECK( T2.relation("jos") ==string("father"));
    CHECK( T2.relation("rivka") ==string("mother"));
    CHECK( T2.relation("jotaro") ==string("grandfather"));
    CHECK( T2.relation("gio") ==string("grandfather"));
    CHECK( T2.relation("holly") ==string("grandmother"));
    CHECK( T2.relation("dio") ==string("grandmother"));
    CHECK( T2.relation("kill") ==string("great-grandfather"));
    CHECK( T2.relation("shit") ==string("great-grandfather"));
    CHECK( T2.relation("lisa-lisa") ==string("great-grandfather"));
    CHECK( T2.relation("snapdragon") ==string("great-grandfather"));
    CHECK( T2.relation("hoe") ==string("great-grandmother"));
    CHECK( T2.relation("omg") ==string("great-grandmother"));
    CHECK( T2.relation("mario") ==string("great-grandmother"));
    CHECK( T2.relation("joska") ==string("great-grandmother"));
    CHECK( T2.relation("muda") ==string("great-great-grandfather"));
    CHECK( T2.relation("why") ==string("great-great-grandmother"));
    CHECK( T2.relation("golden") ==string("great-great-great-grandfather"));
    CHECK( T2.relation("wind") ==string("great-great-great-grandmother"));
    CHECK(T2.relation("jojo")==string("me"));
}


TEST_CASE("Test all") {
    family::Tree T3 ("yali"); 
	T3.addFather("yali", "moshe")   
	 .addMother("yali", "oshri")   
	 .addFather("moshe", "dorit")
	 .addMother("moshe", "dori")
	 .addFather("oshri", "papi")
     .addMother("oshri", "mami")
     .addMother("papi", "Hana")
     .addMother("Hana", "pop")
	 .addFather("pop", "dan");
      //test realation function
    CHECK( T3.relation("moshe") ==string("father"));
    CHECK( T3.relation("oshri") ==string("mother"));
    CHECK( T3.relation("dorit") ==string("grandfather"));
    CHECK( T3.relation("mami") ==string("grandmother"));
    CHECK( T3.relation("Hana") ==string("great-grandmother"));
    CHECK( T3.relation("pop") ==string("great-great-grandmother"));
    CHECK( T3.relation("dan") ==string("great-great-great-grandfather"));
    CHECK(T3.relation("yali")==string("me"));
        //test find function
    CHECK( T3.relation("father") ==string("moshe"));
    CHECK( T3.relation("mother") ==string("oshri"));
    CHECK( T3.relation("grandfather") ==string("dorit"));
    CHECK( T3.relation("grandmother") ==string("mami"));
    CHECK( T3.relation("great-grandmother") ==string("Hana"));
    CHECK( T3.relation("great-great-grandmother") ==string("pop"));
    CHECK( T3.relation("great-great-great-grandmother") ==string("dan"));
    CHECK(T3.relation("me")==string("yali"));
     //test realation function
    CHECK( T3.relation("moshe") ==string("father"));
    CHECK( T3.relation("oshri") ==string("mother"));
    CHECK( T3.relation("dorit") ==string("grandfather"));
    CHECK( T3.relation("mami") ==string("grandmother"));
    CHECK( T3.relation("Hana") ==string("great-grandmother"));
    CHECK( T3.relation("pop") ==string("great-great-grandmother"));
    CHECK( T3.relation("dan") ==string("great-great-great-grandfather"));
    CHECK(T3.relation("yali")==string("me"));
        //test find function
    CHECK( T3.relation("father") ==string("moshe"));
    CHECK( T3.relation("mother") ==string("oshri"));
    CHECK( T3.relation("grandfather") ==string("dorit"));
    CHECK( T3.relation("grandmother") ==string("mami"));
    CHECK( T3.relation("great-grandmother") ==string("Hana"));
    CHECK( T3.relation("great-great-grandmother") ==string("pop"));
    CHECK( T3.relation("great-great-great-grandmother") ==string("dan"));
    CHECK(T3.relation("me")==string("yali"));
    
}
*/
