#include "Node.h"

Node::Node(char character, int frequency) // Initializing the member variables with the help of constructor
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

int Node::getFrequency() const // Gets the frequency associated with the node
{
  return frequency;
}

char Node::getCharacter() const // Gets the character associated with the node
{
  return character;
}

void Node::setLeft(Node *left) // Sets the left Node of the root node
{
  this->left = left;
}

void Node::setRight(Node *right) // Sets the right Node of the root node
{
  this->right = right;
}

Node *Node::getLeft() const // Gets the left node
{
  return left;
}

Node *Node::getRight() const // Gets the right node
{
  return right;
}