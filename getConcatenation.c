int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ret;
    ret=malloc(numsSize*sizeof(int)*2);
    memcpy(ret,nums,numsSize*sizeof(int));
    memcpy(ret+numsSize*sizeof(int),nums,numsSize*sizeof(int));
    return ret;
    
}
