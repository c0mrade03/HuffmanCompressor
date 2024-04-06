#include "Node.h"

Node::Node(char character, int frequency)
{
  this->left = this->right = nullptr;
  this->character = character;
  this->frequency = frequency;
}

Node::Node(char character)
{
  this->left = this->right = nullptr;
  this->character = character;
}

int Node::getFrequency() const
{
  return frequency;
}

char Node::getCharacter() const
{
  return character;
}

void Node::setLeft(Node *left)
{
  this->left = left;
}

void Node::setRight(Node *right)
{
  this->right = right;
}

Node *Node::getLeft() const
{
  return left;
}

Node *Node::getRight() const
{
  return right;
}