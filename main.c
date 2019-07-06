#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Get random parking fee
    int feeDue;
    srand(time(NULL));
    feeDue = rand() % (200 + 1 - 0) + 0;
    printf("Parking Fee R%d.00\nPlease input amount payed\n", feeDue);

    //Scan input from user and calculate change due
    int feePayed;
    scanf("%d", &feePayed);
    printf("Amount payed: R%d.00\n", feePayed);

    int changeDue;
    if (feePayed < feeDue) {
        printf("Insufficient amount, please enter a value bigger than R%d.00\n", feeDue);
        scanf("%d", &feePayed);
    }
    changeDue = feePayed - feeDue;
    printf("Change due: R%d.00\n", changeDue);

    //Calculate change to be dispensed and print
    div_t counter;

    counter = div(changeDue, 100);
    int hundred = counter.quot;
    changeDue = changeDue - (hundred * 100);

    counter = div(changeDue, 50);
    int fifty = counter.quot;
    changeDue = changeDue - (fifty * 50);

    counter = div(changeDue, 20);
    int twenty = counter.quot;
    changeDue = changeDue - (twenty * 20);

    counter = div(changeDue, 10);
    int ten = counter.quot;
    changeDue = changeDue - (ten * 10);

    counter = div(changeDue, 5);
    int five = counter.quot;
    changeDue = changeDue - (five * 5);

    counter = div(changeDue, 2);
    int two = counter.quot;
    changeDue = changeDue - (two * 2);

    counter = div(changeDue, 1);
    int one = counter.quot;

    printf("Returned:\nR100: %d\nR50: %d\nR20: %d\nR10: %d\nR5: %d\nR2: %d\nR1: %d\n", hundred, fifty, twenty, ten, five, two, one);


    return 0;
}
