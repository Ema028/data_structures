typedef struct _trie
{
    int number;
    struct _trie* paths[11]; //extra for negative sign
}trie;

trie* createTrie() 
{
    trie* node = malloc(sizeof(trie));
    node->number = -1;
    for (int i = 0; i < 11; i++) 
    {
        node->paths[i] = NULL; //start with no children
    }
    return node;
}

bool insertNumber(trie* root, int num) 
{
    trie* current = root;

    if (num < 0) 
    {
        if (current->paths[10] == NULL) 
        {
            current->paths[10] = createTrie();
        }
        current = current->paths[10];
        num = -num; //use absolute value from here on
    }

    //split the number into digits
    int digits[10];
    int count = 0;
    int temp = num;

    if (num == 0) 
    {
        digits[0] = 0;
        count = 1;
    } 
    else 
    {
        while (temp > 0) 
        {
            digits[count] = temp % 10;
            temp /= 10;
            count++;
        }
    }

    //leftmost digit to rightmost
    for (int i = count - 1; i >= 0; i--) 
    {
        int d = digits[i];
        if (current->paths[d] == NULL) 
        {
            current->paths[d] = createTrie();
        }
        current = current->paths[d];
    }

    if (current->number == num) 
    {
        return true; //duplicate
    }

    current->number = num;
    return false;
}

void freeTrie(trie* node) 
{
    if (node == NULL) return;

    //free all child nodes
    for (int i = 0; i < 11; i++) {
        if (node->paths[i] != NULL) 
        {
            freeTrie(node->paths[i]);
        }
    }
    free(node);
}


bool containsDuplicate(int* nums, int numsSize) 
{
    trie* root = createTrie();

    for (int i = 0; i < numsSize; i++)
    {
        if (insertNumber(root, nums[i]))
        {
            freeTrie(root);
            return true;
        }
    }
    freeTrie(root);
    return false;
}
