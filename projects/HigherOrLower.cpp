#include <iostream>

using std::cout;
using std::cin;

int guessNumber = (rand() % 100);

int main()
{
    int guess;
    cout << "Basic guessing game Higher Or Lower 1 to 100 \n";
    cout << "Guess The Number: ";
    cin >> guess;

    if (guess == guessNumber) {
        cout << "That's correct congrats \n";
        return 0;
    }
    else if (guess > guessNumber) {
        cout << "Guess Lower\n";
    }
    else if (guess < guessNumber) {
        cout << "Guess Higher\n";
    }

    main();
}
