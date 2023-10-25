#include <iostream>
#include <Windows.h>
#include "Definitions.h"
using namespace std;


Node* newCanvas()
{
	// TODO: Write the code for the function
	//Create a new node and initialize it to all spaces
	Node* temp = new Node;
	if (temp == NULL) return NULL;
	
	initCanvas(temp->item);


	return temp;
}


Node* newCanvas(Node* oldNode)
{
	// TODO: Write the code for the function
	//Create a new node and copy the old node
	Node* temp = new Node;
	if (temp == NULL) return NULL;
	copyCanvas(temp->item, oldNode->item);
	return temp;
}


void play(List& clips)
{
	// loops as long as the ESCAPE key is not currently being pressed
	clear(3);
	//Play the clips as long ESC isn't pressed
	while (!(GetKeyState(VK_ESCAPE) & 0x8000))
	{
		playRecursive(clips.head, clips.count);

	}
}


void playRecursive(Node* head, int count)
{
	// TODO: Write the code for the function
	//Beginning of the clips
	if (head == NULL)
	{
		return;
	}
	//Continues to call the function until it gets to the beginning
	playRecursive(head->next, count-1);

	clear(2);
	gotoxy(MAXROWS + 1, 0);
	cout << "Hold <ESC> to stop       Clip:  " << count;

	displayCanvas(head->item);


	Sleep(100);
	// Pause for 100 milliseconds to slow down animation
}


void addUndoState(List& undoList, List& redoList, Node* &current)
{
	//Adds the current node to an undo list and deletes the redo list
	Node* CopiedNode = newCanvas(current);
	if (CopiedNode == NULL) return;

	addNode(undoList, CopiedNode);

	deleteList(redoList);
	redoList.count = 0;
}


void restore(List& undoList, List& redoList, Node* &current)
{
	//Makes the first in undo the current and adds the old current to the redo
	if (undoList.head == NULL) return;

	addNode(redoList, current);

	current = undoList.head;
	undoList.head = undoList.head->next;
	undoList.count--;
}


void addNode(List& list, Node* nodeToAdd)
{
	//Adds a node to the list
	nodeToAdd->next = list.head;
	list.head = nodeToAdd;
	list.count++;
}


Node* removeNode(List& list)
{
	// TODO: Write the code for the function
	//Removes a node from a list and subtracts 1 from the count
	Node* temp;
	if (list.head == NULL) return NULL;

	temp = list.head;
	list.head = list.head->next;
	delete temp;
	list.count--;

	return NULL;
}

void deleteList(List& list)
{
	//Deletes the entire list until empty
	while (list.head != NULL) {
		Node* temp = list.head;
		list.head = list.head->next;
		delete temp;
		list.count--;
	}
}



bool loadClips(List& clips, char filename[])
{
	//creates new list of clips and starts parsing filenames together to -1, -2....
	deleteList(clips);
	char fileNameN[FILENAMESIZE - 12];
	Node* cpy = NULL;

	int i = 2;

	snprintf(fileNameN, FILENAMESIZE - 12, "%s%s", filename, "-1");

	cpy = newCanvas();

	//if it cant load it returns error message + false, otherwise adds nodes to the clips for as long as it can read xxx-1, xxx-2.... until a number isnt reached
	if (!loadCanvas(cpy->item, fileNameN))
	{
		clear(3);
		cerr << "ERROR: File cannot be read.\n";
		system("pause");
		return false;
	}

	while (loadCanvas(cpy->item, fileNameN))
	{
		addNode(clips, cpy);
		cpy = newCanvas();
		fileNameN[0] = '\0';
		snprintf(fileNameN, FILENAMESIZE - 12, "%s-%d", filename, i);
		++i;
	}
	
	cout << "Clips loaded!\n";
	system("pause");
	return true;
}


bool saveClips(List& clips, char filename[])
{
	//init 2 pointers to not lose track of memory locations
	Node* tmp = NULL;
	Node* original = clips.head;
	//counter for the saving of the clips (1, 2, 3...)
	int i = 2;

	char fileNameN[FILENAMESIZE - 12];
	//parses fileename to ...-1
	snprintf(fileNameN, FILENAMESIZE - 12, "%s%s", filename, "-1");

	//calls the save function for as long as the clips head has something in it and saves each file with i being the counter
	//if there is nothing in the clips, return false
	if (clips.head == NULL)
	{
		return false;
	}
	while (clips.head != NULL)
	{
		tmp = clips.head;
		saveCanvas(tmp->item, fileNameN);
		fileNameN[0] = '\0';
		snprintf(fileNameN, FILENAMESIZE - 12, "%s-%d", filename, i);
		++i;
		clips.head = clips.head->next;
	}
	clips.head = original;
	cout << "Files Saved!\n";
	system("pause");
	return true;
}