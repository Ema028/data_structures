// hash function using Knuth's multiplicative method
int hash(int n, int size)
{
    // golden ratio * 2^32
    int A = 2654435761;
    return int(size * ((k * A) % 1));
}

bool containsDuplicate(int* nums, int numsSize) 
{
    int hashtable[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        hashtable[i] = 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int index = hash(nums[i], numsSize);
        if(hashtable[index] != 0)
        {
            return true;
        }
        hashtable[index] = nums[i];
    }
    return false;
}