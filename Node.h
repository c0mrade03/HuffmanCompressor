#pragma once

class Node
{
private:
  char character;
  int frequency;

public:
  int getFrequency() const;
  char getCharacter() const;

private:
  Node *left, *right;

public:
  Node(char character, int frequency);
  Node(char character);

  Node *getLeft() const;
  Node *getRight() const;

  void setLeft(Node *left);
  void setRight(Node *right);
};