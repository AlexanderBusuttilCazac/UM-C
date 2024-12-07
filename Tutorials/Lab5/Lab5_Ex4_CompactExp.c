int sum(int *start, int *end) {
    int total = 0;
    while (start < end) {
        total += *start++; /* add value to total and advance pointer to next element */
    }
    return total;
}
