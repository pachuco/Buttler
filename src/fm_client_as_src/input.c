#include <stdio.h>
#include <stdlib.h>

#include <conio.h>

int main(int argc, char** argv[])
{
    printf("\nClient running...\n"); //async
    printf("Audio playback in realtime...\n"); //async

    printf("\nIf you wish to opt in to control the device, press 'y'.\n");
    printf("To opt out, press 'n'.\n");
    printf("Use 'q' to quit.\n\n");

    while (1) {
        int input = getch();

        if (input == Y_KEY) {
            printf("\n << Opting in >>\n");
        } else if (input == N_KEY) {
            printf("\n << Opting out >>\n");
        } else if (input == Q_KEY) {
            printf("\n << Exiting >> \n");
            exit(0);
        } else {
            //do nothing
        }
    }

    return 0;
}


// on_key_press
// on_x
// on_y
// on_etc

/*on_input_key() {

}

handle_x_key() {

}

handle_y_key() {

}

handle_q_key() {

}
*/
