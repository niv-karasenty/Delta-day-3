#include <stdio.h>

// אני לא בטוח שהבנתי את ההוראות ב100 אחוז יכול להיות שהיה אפשר להשתמש במצביע קבוע ולהחליף את הערך שנמצא בתוכו בלי להחליף את הכתובת אליה הוא מצביע
// Defining the trash value 20 as the starting number of the channel
#define START_VALUE (20)
const int channel_number = START_VALUE;

int main() {
    // Creating a pointer to a const int value
    const int *channel_pointer = &channel_number;
    int new_channel;

    printf("The starting channel value is: %d\n", *channel_pointer);
    printf("Enter the new channel: ");
    if (scanf("%d", &new_channel) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    const int new_channel_const = new_channel;
    channel_pointer = &new_channel_const;

    // Pay attention that the new_channel_const is a regualr const, we have just moved the pointer channel pointer to another const
    printf("The new channel is: %d", *channel_pointer);

    return 0;
}