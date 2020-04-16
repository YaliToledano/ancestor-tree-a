
#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
using namespace family;

Tree::Tree(string a)
{
    this->name=a;
}
Tree Tree::addFather(string a, string b)
{
    return Tree(b);
}
Tree Tree::addMother(string a, string b)
{
    return Tree(b);
}
string Tree::relation(string a)
{
    return "re";
}
string Tree::find(string a)
{
    return "fi";
}
void Tree::remove(string a)
{
}
void Tree::display()
{
}