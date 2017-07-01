#include <stdio.h>

struct cache {//lru
    int first; // most recently used
    int second; // second most recently used
    int third; // least recently used
};

int main() {
    struct cache c;
    c.first = -1; // indicating that the pages are empty
    c.second = -1;
    c.third = -1;
    int pages[100]; // array to hold all the individual pages
    int count = 0, faults = 0; // count: total pages, faults: number of page faults
    int i, j;

    printf("Enter number of pages: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);//lru
    }

    for (i = 0; i < count; i++) {
        int page = pages[i];
        int isFault = 0;
        if (c.first == page) {
            c.first = page;
        } else if (c.first == -1) {
            c.first = page;
            isFault = 1;
        } else if (c.second == page) {
            c.second = c.first;
            c.first = page;
        } else if (c.second == -1) {
            c.second = c.first;
            c.first = page;
            isFault = 1;
        } else if (c.third == page) {
            c.third = c.second;
            c.second = c.first;
            c.first = page;
        } else if (c.third == -1) {
            c.third = c.second;
            c.second = c.first;
            c.first = page;
            isFault = 1;
        } else {
            c.third = c.second;
            c.second = c.first;
            c.first = page;
            isFault = 1;
        }
        if (isFault) {
            printf("%d\t%d\t%d\t%s\n", c.first, c.second, c.third, "✗");
            faults++;
        } else {
            printf("%d\t%d\t%d\t%s\n", c.first, c.second, c.third, "✓");
        }
    }

    printf("Number of page faults: %d", faults);

    return 0;
}