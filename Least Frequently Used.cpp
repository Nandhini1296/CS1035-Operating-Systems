#include<stdio.h>


#define EMPTY -1


struct page_frame  //Structure for Page Frame
{
    int value, age, frequency;
};

void output(int error_code, int size, struct page_frame pf[]) //Funtion for Printing the Page Frame
{
    int i;
    for (i = 0; i < size; i++) {
        if (pf[i].value == EMPTY)
            printf(" NIL ");
        else
            printf("%d", pf[i].value);
    }


    if (error_code == 0)
        printf(" S");
    else if (error_code != 0)
        printf("F");
    if (i == 3)
        printf("\n");
}

int main() {
    int page_values[12], i, count = 0, j, k = 0, position = 0, old, old_f, position_f = 0, m, state = 0, similar, n, fn,hello;
    struct page_frame pf[3];

    printf("\t PAGE REPLACEMENT ALGORITHM : LEAST FREQUENTLY USED");

    printf("\n Enter  the Number of Page Values :  ");

    scanf("%d", &n);

    printf("\n Enter the Number of Page Frames : ");
    scanf("%d", &fn);
    printf("\n Enter the Page Values :  ");

    for (i = 0; i < n; i++) {
        scanf("%d", &page_values[i]);
    }

    for (i = 0; i < fn; i++) {
        pf[i].value = EMPTY;
        pf[i].age = 0;
        pf[i].frequency = 0;
    }

    for (i = 0; i < n; i++) {
        hello = 0;
        state = 0;
        for (j = 0; j < fn; j++) {

            if (pf[j].value == EMPTY) {
                pf[j].value = page_values[i];
                pf[j].age++;
                output(0, fn, pf);
                break;

            } else if (pf[j].value == page_values[i]) {
                printf("\n Page Value Found!\n.");
                pf[j].age == 0;
                pf[i].frequency++;
                output(0, fn, pf);
                break;

            } else if (state != 1) {
                ++hello;
                ++pf[j].age;
            }
        }
        if (hello == fn)
        {
            old = pf[0].age;
            old_f = pf[0].frequency;
            position = 0;
            position_f = 0;
            similar = 0;
            for (m = 1; m < fn; m++) {
                if (pf[m].age > old) {
                    old = pf[m].age;
                    position = m;
                }
                if (pf[m].frequency < old_f) {
                    old_f = pf[m].frequency;
                    position_f = m;
                } else if (pf[m].frequency == old_f)
                    similar++;
            }
            if (similar >= 1) {
                pf[position].value = page_values[i];
                pf[position].age = 0;
                pf[position].frequency = 0;
            } else {
                pf[position_f].value = page_values[i];
                pf[position_f].age = 0;
                pf[position_f].frequency = 0;
            }
            printf("\n Page FAULT! Page Frame Replaced!");
            output(-1, fn, pf);
            count++;
        }
    }
    printf("\n\n Total No. of Faults : %d \n", count);
    getchar();
}