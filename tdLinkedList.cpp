#include<stdio.h>
#include<stdlib.h>

typedef struct cell{
	int donnee;
	struct cell* svt;
}cell;

//function to add cell in start of the list
cell* insererEnTete(cell* tete,int newdata){
	cell* newCell =(cell*)malloc(sizeof(cell));
	newCell->donnee = newdata;
	newCell->svt = tete;
	return newCell;
}
 //delete a cell in a any position
 void supprimePosition(cell* tete,int position){
 	if(tete==NULL){
 		printf("la list est vide");
 		return; 
	 }
	 cell* curr = tete;
	 //we go testing
	 if(position==0){
	 	tete = curr->svt;
	 	free(curr);
	 }
	 //let's dive into the list :#
	 
  for(int i =0;curr!=NULL && i<position-1;i++){
	 	curr = curr->svt;
	
	 }
	 if(curr ==NULL || curr->svt == NULL){
	 	printf("the postition is bigger than the list");
	 	return;
	 } 
	 
	 cell* deleted = curr->svt;
	 curr->svt =deleted->svt;
	 free(deleted);
	 	 
 }
 //function to add nega
cell* negListe(cell* tete) {
    cell* negativeList = NULL;   // Initialize an empty list for negative numbers
    cell* curr = tete;   // Pointer to iterate through the input list
    cell* prev = NULL;  // Pointer to keep track of the previous node in the input list

    while (curr != NULL) {
        cell* next = curr->svt;  // Save the next node before potentially modifying the list

        if (curr->donnee < 0) {
            // If the current node contains a negative number
            cell* negativeNode = (cell*)malloc(sizeof(cell));  // Create a new node for the negative list
            negativeNode->donnee = curr->donnee;
            negativeNode->svt = negativeList;
            negativeList = negativeNode;

            if (prev == NULL) {
                // If it's the first node, update the input list pointer
                tete = next;
            } else {
                // If it's not the first node, update the previous node's "next" pointer
                prev->svt = next;
            }

            free(curr);  // Free the current node from the input list
        } else {
            // If the current node does not contain a negative number
            prev = curr;  // Update the previous node pointer
        }

        curr = next;  // Move to the next node in the input list
    }

    return negativeList;  // Return the modified list containing negative numbers
}


void afficher(cell* tete){
	while(tete!=NULL){
		printf("%d ->",tete->donnee);
		tete= tete->svt;
	}
}

int main() {
    cell* tete = NULL;
    tete = insererEnTete(tete, 1);
    tete = insererEnTete(tete, -1);
    tete = insererEnTete(tete, -4);
    tete = insererEnTete(tete, 8);
    tete = insererEnTete(tete, -11);
    tete = insererEnTete(tete, 4);
    tete = insererEnTete(tete, 6);

    printf("List: ");
    afficher(tete);
    printf("\n");

    cell* negativeList = negListe(tete);

    printf("list with negative numbers: ");
    afficher(negativeList);
     
     
     //free memory
       while (tete != NULL) {
        cell* temp = tete;
        tete = tete->svt;
        free(temp);
    }

    while (negativeList != NULL) {
        cell* temp = negativeList;
        negativeList = negativeList->svt;
        free(temp);
    }




    return 0;
}


