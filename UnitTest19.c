// Tyler Anglet
// COP 3502, Spring 2022

// ============================
// TriePrediction: UnitTest19.c
// ============================
// Tests other functionality of newNodeCount()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TriePrediction.h"

void failwhale(char *err_msg)
{
	printf("fail whale :( --- %s\n", err_msg);
	exit(0);
}

// get how many words occur in the trie
int count_words(TrieNode *trie)
{
  int i;
  int count = 0;
  
  // empty trie has nothing in it
  if (trie == NULL)
    return 0;
    
  for (i = 0; i < 26; i++)
    count += count_words(trie->children[i]);
    
  // add word count
  count += trie->count;
    
  return count;
}

int count_nodes(TrieNode *trie)
{
  int i;
  int count = 0;
  
  // empty trie has nothing in it
  if (trie == NULL)
    return 0;
    
  for (i = 0; i < 26; i++)
    count += count_nodes(trie->children[i]);
    
  // add this node
  count += 1;
    
  return count;
} 

int unit_test(int argc, char **argv)
{
  int wordCount1, wordCount2, nodeCount1, nodeCount2;
	TrieNode *root;
  
  root = buildTrie("corpus01.txt");
  
  // test NULL edge case
  if (newNodeCount(NULL, NULL) != 0)
    failwhale("newNodeCount with NULL str and NULL root should return zero");
  
  if (newNodeCount(root, NULL) != 0)
    failwhale("newNodeCount with NULL str should be zero");
    
  // make sure newNodeCount doesn't change the trie
  nodeCount1 = count_nodes(root);
  wordCount1 = count_words(root);
  
  // look for nodes
  newNodeCount(root, "cherry");
  newNodeCount(root, "cherries");
  newNodeCount(root, "testing");
  newNodeCount(root, NULL);
    
  nodeCount2 = count_nodes(root);
  wordCount2 = count_words(root);
  
  if (nodeCount1 != nodeCount2)
    failwhale("your newNodeCount is making nodes! this should not happen");
  
  if (wordCount1 != wordCount2)
    failwhale("your newNodeCount is changing a ->count value! this should not happen");
    
  destroyTrie(root);
    
  printf("Success!\n");

	return 0;
}
