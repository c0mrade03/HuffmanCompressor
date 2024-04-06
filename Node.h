#pragma once

class Node
{
private:
  char character;
  int frequency;

public:
  int getFrequency() const;  // Will return the frequency related to the created Node
  char getCharacter() const; // Will return the character that belongs to created Node

private:
  Node *left, *right; // Left and right pointers to the Node

public:
  Node(char character, int frequency); // Constructor to initialize the character and the frequency

  Node(char character); /* Overloaded constructor which may be useful when initializing
                        some ascii characters that are not present in the file but we might want to
                        include evey ascii character; Usefule while maintaining tree structure*/

  // Below functions works as their names suggests

  Node *getLeft() const;
  Node *getRight() const;

  void setLeft(Node *left);
  void setRight(Node *right);
};