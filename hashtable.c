typedef struct node
{
    int n;
    struct node* next;
}node;

// hash function usando Knuth's multiplicative method
int hash(int n, int size)
{
    // golden ratio * 2^32
    unsigned int A = 2654435761;
    unsigned x = (n * A) % size;
    return x;
}

void freeHashtable(node** array, int size)
{
    // free tds as linked lists
    for (int i = 0; i < size; i++)
    {
        node* tmp = array[i];
        while (tmp != NULL)
        {
            node* to_free = tmp;
            tmp = tmp->next;
            free(to_free);
        }
    }
    free(array);
}

bool containsDuplicate(int* nums, int numsSize) 
{
    node** hashtable = calloc(numsSize, sizeof(node*)); // array de nodes, calloc inicializa com zeros
    if (hashtable == NULL)
    {
        return false;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int index = hash(nums[i], numsSize);
        node* tmp = hashtable[index];
        while(tmp != NULL)
        {
            if(tmp -> n == nums[i])
            {
                freeHashtable(hashtable, numsSize);
                return true;
            }
            tmp = tmp->next;
        }
    
        node* list = malloc(sizeof(node));
        if(list == NULL)
        {
            freeHashtable(hashtable, numsSize);
            return false;
        }
        list -> n = nums[i];
        list -> next = hashtable[index];
        hashtable[index] = list;
    }
    freeHashtable(hashtable, numsSize);
    return false;
}
