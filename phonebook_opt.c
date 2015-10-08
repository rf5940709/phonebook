#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
       while (pHead != NULL) {
       	 	if (strcasecmp(lastName, pHead->lastName) == 0){
//         		printf(" %12s  is found!\n", lastName);
            		return pHead;
        	}
        	pHead = pHead->pNext;
    	}
//   	printf(" %12s  is not found!\n", lastName);
	return NULL;
}

entry *append(char lastName[], entry *e)
{
	e->pNext = (entry *) malloc(sizeof(entry));
    	e = e->pNext;
    	strcpy(e->lastName, lastName);
    	e->pNext = NULL;
    	return e;
}

/* optimal version 1 */
lastNameEntry *findNameOptimal(char lastName[], lastNameEntry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0){
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

lastNameEntry *appendOptimal(char lastName[], lastNameEntry *lne)
{
    /* allocate memory for the new entry and put lastName in it.*/
    lne->pNext = (lastNameEntry *) malloc(sizeof(lastNameEntry));
    lne = lne->pNext;
    strcpy(lne->lastName, lastName);
    lne->pNext = NULL;

    return lne;
}
