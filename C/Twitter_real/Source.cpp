//Jason Avila-Soria
// Program to implement a very simplified list of tweets 
// from a single simulated Twitter account
// Tweets can be added, deleted, and liked

#include <iostream>
using namespace std;

const int MSGSIZE = 100;	// Maximum size for a tweet message
const int CAPACITY = 10;	// Maximum number of tweets

// Structure used to define a tweet entry
struct Tweet
{
	int id;
	char msg[MSGSIZE];
	int likes;
};


/*
* Prints out an entire timeline to the screen
* timeline = timeline of tweets to be printed
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
*/
void displayTimeline(const Tweet timeline[], int usedSize, int selected);
/*
* Edits currently selected tweet
* with a new message entered by the user.
* timeline = timeline in which the tweet is to be edited
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
* If 'selected' represents a valid array position, the
* selected tweet will be updated.
* If 'selected' is not valid a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doEditTweet(Tweet timeline[], int usedSize, int selected);
/*
* Adds a like to the currently selected tweet.
* timeline = timeline in which the tweet is to be edited
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
* If 'selected' represents a valid array position, the
* selected tweet will be updated.
* If 'selected' is not valid a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doLikeTweet(Tweet timeline[], int usedSize, int selected);
/*
* Deleted currently selected tweet.
* timeline = timeline in from which the entry is to be deleted
* usedSize = number of tweets in the timeline
* If 'selected' represents a valid array position:
*   the selected tweet will be deleted
*   usedSize will be updated to reflect the updated number of tweets in the timeline
*   selected will be updated to -1
* If 'selected' is not valid a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doDeleteTweet(Tweet timeline[], int& usedSize, int& selected);
/*
* If there is room in the timeline for new tweets, then this gets
* a new tweet from the user and adds it to the timeline.
* timeline = timeline in which the tweet is to be added
* usedSize = number of tweets in the timeline
* If tweet was able to be added, returns the position number in the
* timeline of where the item was added, and usedSize will be
* updated to reflect the number of tweets now in the timeline.
* If tweet was not able to be added, returns -1, and usedSize
* remains unchanged.
*/
int doAddTweet(Tweet timeline[], int& usedSize);
/*
* Adds a new tweet to the list
* timeline = timeline in which the entry is to be added
* usedSize = number of tweets in the timeline
* message = tweet message to be added
* If tweet was able to be added, returns the position number in the
* timeline of where the item was added, and usedSize will be
* updated to reflect the number of tweets now in the timeline.
* If tweet was not able to be added, returns -1, and usedSize
* remains unchanged.
*/
int addTweet(Tweet timeline[], int& usedSize, const char message[]);
/*
* Returns the next available ID number
* timeline = timeline in which to find the highest ID
* usedSize = number of tweets in the timeline
* If timeline is empty, returns 100;
* otherwise, returns 1 + highest ID number in the timeline
*/
int getNextId(Tweet timeline[], int usedSize);
/*
* Gets a tweet id from the user. Searches a timeline to try
* to find the specified tweet by its id.
* timeline = timeline to be searched
* usedSize = number of tweets in the timeline
* If the tweet is found, the position number of where the tweet
* is stored in the timeline will be returned.  If the tweet is
* not found, a 'not found message' will be printed, and
* the value -1 will be returned.
* If timeline is empty, an 'empty' message will be printed, and
* the value -1 will be returned.
*/
int selectTweet(const Tweet timeline[], int usedSize);


int main()
{
	Tweet timeline[CAPACITY];	// Twitter timeline
	int choice;					// User's menu choice
	int usedSize = 0;			// Num of tweets in the timeline
	int selected = -1;			// Currently selected tweet
	int tmp;					// Temporary variable

	// Add some starter entries for testing purposes
//	for (int x = 0; x < 4; x++) {
		selected = addTweet(timeline, usedSize, "Where do they get the seeds to plant seedless watermelons?");
		selected = addTweet(timeline, usedSize, "Waffles are just pancakes with convenient boxes to hold your syrup.");
		selected = addTweet(timeline, usedSize, "Last night I even struck up a conversation with a spider. Turns out he's a web designer.");
//	}
	
	do
	{
		cout << "1. Display Timeline\n";
		cout << "2. Select Tweet\n";
		cout << "3. Add New Tweet\n";
		cout << "4. Edit Selected Tweet\n";
		cout << "5. Like Selected Tweet\n";
		cout << "6. Delete Tweet\n";
		cout << "7. Exit\n";
		cout << endl;
		cout << "Select: ";

		// Get the numeric entry from the menu
		cin >> choice;

		// Corrects issues where user might enter a non-integer value
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Select: ";
			cin >> choice;
		}

		// Makes the 'enter' key that was pressed after the numeric entry be ignored
		// Should be used after getting any numeric input from the keyboard
		cin.ignore();

		switch (choice)
		{
		case 1:
			displayTimeline(timeline, usedSize, selected);
			break;
		case 2:
			tmp = selectTweet(timeline, usedSize);
			// if selected tweet exists, update selected variable;
			// otherwise leave it unchanged
			if (tmp > -1)
				selected = tmp;
			break;
		case 3:
			tmp = doAddTweet(timeline, usedSize);
			// if tweet was added, make it be the selected tweet;
			// otherwise leave it unchanged
			if (tmp > -1)
				selected = tmp;
			break;
		case 4:
			doEditTweet(timeline, usedSize, selected);
			break;
		case 5:
			doLikeTweet(timeline, usedSize, selected);
			break;
		case 6:
			doDeleteTweet(timeline, usedSize, selected);
			break;
		}

	} while (choice != 7);

	return 0;
}


int doAddTweet(Tweet timeline[], int& usedSize)
{
	char message[MSGSIZE];
	

	// Checks if there is space in the Tweet array and adds a message using the addTweet function if there is sapce, otherwise error message appears.
	if (usedSize < CAPACITY) {
		cout << "Enter tweet:\n";
		cin.getline(message, MSGSIZE);	
		cout << endl;
		
		return addTweet(timeline, usedSize, message);
	}
	else {
		cout << "\nTimeline is full. Cannot add new message\n" << endl;
		return -1;
	}
}


void doEditTweet(Tweet timeline[], int usedSize, int selected)
{

	// Checks if a message is even selected and if there is one selected it edits the selected message, otherwise error message appears.
	if (selected >= 0 && selected < usedSize) {
		cout << "Enter tweet :\n";
		cin.getline(timeline[selected].msg, MSGSIZE);
		cout << endl;
	}
	else {
		cout << "\nNo tweet selected.\n" << endl;
	}
}


void doLikeTweet(Tweet timeline[], int usedSize, int selected)
{
	// Checks if a message is selected and for that message it likes it, otherwise if not selected message an error appears.
	if (selected < usedSize && selected >= 0)
		timeline[selected].likes++;
	else
		cout << "\nNo tweet selected.\n" << endl;
}


void displayTimeline(const Tweet timeline[], int usedSize, int selected)
{

	// Formatting for the Tweet dislay.
	cout << "\nTweets:\n\n";
	printf("Sel\tID\tLikes\tTweet\n");
	
	//Loop to see if any tweets are avialable
	if (usedSize != 0) {

		// Loop to show all tweets.
		for (int i = 0; i < usedSize; ++i)
		{
			// Checks to see which tweet is selected to print an arrow, otherwise print a spacing.
			if (selected == i) {
				printf("-->\t");
			}
			else {
				printf("\t");
			}

			printf("%d\t%d\t%s\n", timeline[i].id, timeline[i].likes, timeline[i].msg);
		}
		cout << endl;
	}
	else {
		printf("\t*** EMPTY ***\n\n");

	}

}


int addTweet(Tweet timeline[], int& usedSize, const char message[])
{
	// If there is space a message is added by getting the id and then parsing the message with the user's input. Sets the new message likes to 0
	// and adds 1 to the used space but returns the place of the last used message
		// This way, when a new message is added, it takes the old message +1
	if (usedSize < CAPACITY) {

		timeline[usedSize].id = getNextId(timeline, usedSize);
		snprintf(timeline[usedSize].msg, MSGSIZE, "%s", message);
		timeline[usedSize].likes = 0;

		//deletes buffer incase excess letters entered

		usedSize++;
		return usedSize - 1;
	}
	else {
		cout << "Timeline is full, Cannot add new tweet.\n\n";
		return -1;
	}
}


int getNextId(Tweet timeline[], int usedSize)
{
	// Sets the minimum ID to 99 (but starts at 100 since the return is ID +1
	int minId = 99;

	for (int i = 0; i < usedSize; i++) {
		// This checks the latest ID used and resets the ID to the latest one used (that way when one is deleted is takes that into account
		// and always shows the right ID when adding a new one)
		if (timeline[i].id > minId) {
			minId = timeline[i].id;
		}
	}

	return minId + 1;
}


void doDeleteTweet(Tweet timeline[], int& usedSize, int& selected)
{
	// Checks if there is a tweet selected
	if (selected >= 0 && selected < usedSize) {
		// For the selected tweet this loop replaces it with the one after until the end of the used tweets
		for (int i = selected; i < usedSize - 1; i++) {
			timeline[i] = timeline[i + 1];
		}

		cout << "\nTweet was deleted.\n\n";
		// Updates used tweets to show one is deleted and resets selected to no selected tweets.
		usedSize--;
		selected = -1;
	}
	else {
		cout << "\nNo tweet is selected.\n\n";
	}
}


int selectTweet(const Tweet timeline[], int usedSize)
{
	
	int tweetSelected;

	// First checks if there are any tweets to select
	if (usedSize == 0) {
		cout << "No tweets\n";
		return -1;
	}

	// This lets the user enter the ID to select
	cout << "Enter ID: ";
	cin >> tweetSelected;

	// Corrects issues where user might enter a non-integer value
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid ID: ";
		cin >> tweetSelected;
	}

	//To remove that "enter"
	cin.ignore();
	cout << endl;

	// Returns the place in the array where the id entered is
	for (int i = 0; i < usedSize; i++) {
		if (timeline[i].id == tweetSelected) {
			return i;
		}
	}

	//If no ID that was entered is found this returns an error message
	cout << "\nID was not found.\n" << endl;
	return -1;
}