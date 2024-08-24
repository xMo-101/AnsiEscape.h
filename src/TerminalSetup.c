#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int SpecialKeysSetup(struct termios* oldt, struct termios* newt);
int RestoreSetup(struct termios* oldt);

int main() {
    struct termios oldt, newt;
    
    // Modify terminal settings:
    SpecialKeysSetup(&oldt, &newt);

    /*
        YOUR CODE GOES HERE
        For example, let's read a single character in non-canonical mode.
    */
   
    printf("Type a character: ");
    char c;
    read(STDIN_FILENO, &c, 1);
    printf("\nYou typed: %c\n", c);

    // Restore the original settings
    RestoreSetup(&oldt);
    

    return 0;
}

int SpecialKeysSetup(struct termios* oldt, struct termios* newt) {
    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, oldt);
    *newt = *oldt;

    // Modify the settings to disable canonical mode (input is available immediately)
    newt->c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, newt);
    return 0;
}

int RestoreSetup(struct termios* oldt) {
    tcsetattr(STDIN_FILENO, TCSANOW, oldt);
    return 0;
}
