// Tyler Angley
// COP 3502, Spring 2022

// ============================
// TriePrediction: UnitTest18.c
// ============================
// Tests edge cases for processInputFile();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TriePrediction.h"

void failwhale(char *err_msg)
{
	printf("fail whale :( --- %s\n", err_msg);
	exit(0);
}

int unit_test(int argc, char **argv)
{
  TrieNode *root;
  
  // make a trie with this corpus
  root = buildTrie("corpus07.txt");
  if (processInputFile(root, "thisFileDoesNotExist") != 1)
    failwhale("processInputFile doesn't return 1 when input file doesn't exist");

  destroyTrie(root);

  printf("Success!\n");

  return 0;
}
