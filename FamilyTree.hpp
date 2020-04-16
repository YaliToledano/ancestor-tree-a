
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace family
{

class Tree
{
    string name;

public:
    Tree(string a);

    Tree addFather(string a, string b);
    Tree addMother(string a, string b);
    string relation(string a);
    string find(string a);
    void remove(string a);
    void display();
};
} // namespace family