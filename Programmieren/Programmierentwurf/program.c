#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h> // Purpose: Defining int value limits flexibly for input protection

// This dependency has been installed into the project's directory and does not need to be installed by the reviewer.
#include"dependencies/cJSON/cJSON.c"
#include"dependencies/cJSON/cJSON.h"

/* External dependency. 
For APT: sudo apt install libcurl4-openssl-dev
Requires adding extra arguments to gcc: -lcurl
gcc program.c -lcurl -o program */
#include<curl/curl.h>

struct comic {
    int comicID;
    char comicSeries[50+1];
    char comicName[50+1];
    struct comic * prev;
    struct comic * next; 
};

struct comic * ptr = NULL;

// == Function prototypes ==
// User Interaction Functions
int pressEnter();
char getYesNo();
int menu();

// Comic List Management Functions
struct comic * createNewList(struct comic * ptr);
struct comic * addNode(struct comic * ptr);
int fillNode(struct comic * ptr);
struct comic * removeNodeSelection(struct comic * ptr);
struct comic * removeNodeExecution(struct comic * ptr);

// Display and Sorting Functions
struct comic * jumpToHead(struct comic * ptr);
int printListToScreen(struct comic * ptr);
struct comic * sortList(struct comic * ptr);

// Memory Management Function
struct comic * freeList(struct comic *ptr);

// JSON File Functions
struct comic * readFromJSON(struct comic *ptr, const char *filename);
int writeToJSON(struct comic * ptr);

// Network Functions
struct comic * downloadManager(struct comic *ptr);
size_t writeFileCallback(void *ptr, size_t size, size_t nmemb, FILE *stream);
int downloadJSONFile(const char *url, const char *filename);

int main() {
    menu();
}

// ========== USER INTERACTION FUNCTIONS ==========

int pressEnter() {
    printf("Press Enter to continue...");
    getchar(); // Wait for Enter key
    return 0;
}

char getYesNo() {
    char choice;

    while (1) {  // Keep looping until valid input is given
        printf(" (y/n): ");
        int result = scanf("%c", &choice);

        if (result == 1 && (choice == 'y' || choice == 'n')) {
            while (getchar() != '\n');
            return choice;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

int menu() {
    int choice;
    int validationChoice;

    system("clear"); // This will likely not work on Windows, but it should work on any Unix-like system (it works on Linux.)
    // Unlike C#, I cannot seem to be able to make it one printf spread among lines to make it appear more organized. So ultimately, it seems as if having multiple printfs is better for code legibility.
    printf("\n========================================\n");
    printf("            Comic Manager Menu          \n");
    printf("========================================\n");
    printf(" 1. Create New List\n");
    printf(" 2. Add Comic to List\n");
    printf(" 3. Remove Comic from List\n");
    printf(" 4. Display Comics\n");
    printf(" 5. Sort Comics by ID\n");
    printf(" 6. Drop List\n");
    printf(" 7. Load Comics from JSON\n");
    printf(" 8. Save Comics to JSON\n");
    printf(" 9. Load Comics from Online Database\n");
    printf(" 0. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    
    validationChoice = scanf("%d", &choice);
    while (getchar() != '\n');

    if (validationChoice != 1)
    {
        printf("Invalid input. Enter a valid number.\n");
    } else {
        switch (choice) {
            case 1:
                ptr = createNewList(ptr);
                break;
            case 2:
                ptr = addNode(ptr);
                break;
            case 3:
                ptr = removeNodeSelection(ptr);
                break;
            case 4:
                printListToScreen(ptr);
                break;
            case 5:
                ptr = sortList(ptr);
                break;
            case 6:
                ptr = freeList(ptr);
                break;
            case 7:
                ptr = readFromJSON(ptr, "data.json");
                break;
            case 8:
                writeToJSON(ptr);
                break;
            case 9:
                ptr = downloadManager(ptr);
                break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Enter a valid number.\n");
                break;
            }
    }
    pressEnter();
    menu();
}

// ========== COMIC LIST MANAGEMENT FUNCTIONS ==========

// Creates a list if one doesn't exist yet and prompts the user to add an node to the list.
struct comic * createNewList(struct comic * ptr) {
    if (ptr) {
        printf("A list already exists.\n");
    } 
    else {
        ptr = (struct comic *) malloc(sizeof(struct comic));
        ptr->prev = NULL; // Key characteristic for first node
        ptr->next = NULL; // Key characteristic for last node
        fillNode(ptr);
    }
    return ptr;
}

// If a list exists, the function traverses it until the end, adds an node there and lets the user fill it.
struct comic * addNode(struct comic * ptr) {
    if (!ptr) {
        printf("List doesn't exist.\n");
    } 
    else {
        while (ptr->next) { 
            ptr = ptr->next;
        }
        ptr->next = (struct comic *) malloc (sizeof (struct comic));
        ptr->next->prev = ptr; // Makes the prev pointer of the new node point to the existing node (in order to be able to go back) 
        ptr = ptr->next; // Now point to the new node
        ptr->next = NULL; // Set the next pointer to NULL to signalize that it's the last node.
        fillNode(ptr);
        printf("Operation complete.\n");
    }
    return ptr;
}

// Lets the user fill in data for the currently selected node. Only in use in combination with adding a new node.
int fillNode(struct comic *ptr) {
    if (ptr == NULL) {
        printf("Error: Null pointer passed to fillNode.\n");
        return -1;
    }

    printf(" Please enter the following data:\n\n");

    while (1) {
        char input[100];
        long tempID;

        printf(" comicID: ");
        // Instead of the classical scanf method which is not able to detect numbers out of bounds and just saves the numbers as -1, the value is saved as a string and then converted into a long to do the necessary checks for input validity.
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char *endptr; // endptr points to the first character that could not be parsed to a long using strtol
            tempID = strtol(input, &endptr, 10); // 10 is the base of the conversion, 10 for decimal system

            if (endptr == input) { // No valid characters found in the input
                printf("Invalid input. Please enter a valid integer.\n");
            } else if (tempID < INT_MIN || tempID > INT_MAX) { // Input out of range for an int
                printf("Invalid input. comicID must be between %d and %d.\n", INT_MIN, INT_MAX);
            } else if (*endptr != '\n' && *endptr != '\0') { // Means that there are characters which aren't numbers
                printf("Invalid input. Please enter only an integer.\n");
            } else {
                ptr->comicID = (int)tempID;
                break; 
            }
        } else {
            printf("Error reading input.\n");
            return -1;
        }
    }

    printf(" comicSeries: ");
    if (fgets(ptr->comicSeries, sizeof(ptr->comicSeries), stdin) != NULL) {
        if (strchr(ptr->comicSeries, '\n') == NULL) { // Length check: As pressing enter would result in a \n, lack thereof would mean that the input is longer than the variable can hold. This is not critical, but requires clearing the input buffer.
            while (getchar() != '\n');
        }
        ptr->comicSeries[strcspn(ptr->comicSeries, "\n")] = '\0'; // Removes newline by setting to the null-terminator
    } else {
        printf("Error reading input.\n");
        return -1; 
    }

    printf(" comicName: ");
    if (fgets(ptr->comicName, sizeof(ptr->comicName), stdin) != NULL) {
        if (strchr(ptr->comicName, '\n') == NULL) {
            while (getchar() != '\n');
        }
        ptr->comicName[strcspn(ptr->comicName, "\n")] = '\0';
    } else {
        printf("Error reading input.\n");
        return -1; 
    }

    return 0;
}

// Allows the user to select and review the node they wish to delete and asks for confirmation before executing the deletion function
struct comic * removeNodeSelection(struct comic * ptr) {
    int nodeSelection;
    int i = 0;
    struct comic * selectedNode = NULL;

    if (!ptr) {
        printf("This is an empty list.\n");
    } else {
        while (1) {
            ptr = jumpToHead(ptr);

            struct comic * temp = ptr;
            i = 0;

            printf("Enter which node you want to delete: ");
            scanf("%d", &nodeSelection);
            while (getchar() != '\n');  // Clear input buffer

            if (nodeSelection < 0) {
                printf("Cannot select negative numbers!\n");
            } else {
                while (temp && i < nodeSelection) { // Traverse list
                    temp = temp->next;
                    i++;
                }
                if (!temp) {
                    printf("An node this far doesn't exist! Try again.\n");
                } else {
                    selectedNode = temp;
                    break;  // Valid selection, exit loop
                }
            }
        } 
        printf("%-10s %-5s %-50s %-50s\n", "Node", "ID", "Series", "Name");
        printf("-------------------------------------------------------------------------------------------\n");
        printf("%-10d %-5d %-50s %-50s\n", nodeSelection, selectedNode->comicID, selectedNode->comicSeries, selectedNode->comicName);
        printf("Are you sure you want to delete this node?");
        char response = getYesNo();
        
        if (response == 'y') {
            ptr = jumpToHead(ptr); // Ensure ptr is at the head of the list
            i = 0;
            while (i < nodeSelection) {
                ptr = ptr->next;
                i++;
            }
            ptr = removeNodeExecution(ptr);
        } else if (response == 'n') {
            printf("Process interrupted.\n");
        }
    }
    return ptr;
}

// Deletes the selected node. Depending on the position of the node, the deletion process differs.
struct comic * removeNodeExecution(struct comic * ptr) {
    if (ptr == NULL) {
        printf("Invalid node.\n");
        return ptr;
    }

    struct comic * newHead = ptr; // Assume the head doesn't change

    // If the node to be deleted is the head of the list
    if (ptr->prev == NULL) {
        newHead = ptr->next;
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
    }

    // If the node to be deleted is not the head of the list
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    // If the node to be deleted is not the tail of the list
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
    printf("Node removed.\n");
    return newHead;
}

// ========== DISPLAY AND SORTING FUNCTIONS ==========

// Traverses the list backwards until it's at its head.
struct comic * jumpToHead(struct comic * ptr) {
    while (ptr->prev != NULL) {
        ptr = ptr->prev;
    }
    return ptr;
}

int printListToScreen(struct comic * ptr) {
    int i = 0;
    printf ("Screen output of list\n\n");
    if (ptr) {
        ptr = jumpToHead(ptr);
        
        printf("%-10s %-5s %-50s %-50s\n", "Node", "ID", "Series", "Name");
        printf("-------------------------------------------------------------------------------------------\n");
        while (ptr) {
            printf("%-10d %-5d %-50s %-50s\n", i, ptr->comicID, ptr->comicSeries, ptr->comicName);
            ptr = ptr->next;
            i++;
        }
        printf("\n");
    } else {
        printf("This is an empty list.\n");
    }
    return i;
}

// Uses the insertion sort algorithm to sort the list by the comic IDs (in ascending order)
struct comic * sortList(struct comic *ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return ptr;
    }
    ptr = jumpToHead(ptr);
    if (ptr->next == NULL) {
        printf("The list has less than 2 nodes. Nothing to sort.\n");
        return ptr;
    }

    struct comic *sorted = NULL;  // Start with an empty sorted list
    struct comic *current = ptr;

    while (current != NULL) {
        struct comic *next = current->next;  // Keep track of the next node
        current->prev = current->next = NULL; // Isolates current node from the rest of the list

        if (sorted == NULL || sorted->comicID >= current->comicID) {
            // Insert at the beginning if sorted is empty or current has smaller ID
            current->next = sorted;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
        } else { // Traverse the sorted list to find the correct position
            struct comic *temp = sorted;
            while (temp->next != NULL && temp->next->comicID < current->comicID) {
                temp = temp->next;
            }
            // Insert current between temp and temp->next
            current->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
            temp->next = current;
            current->prev = temp;
        }
        current = next;  // Move to the next node
    }
    printf("List was successfully sorted.\n");
    return sorted;  // Return the new sorted list
}

// ========== MEMORY MANAGEMENT FUNCTION ==========

// Completely gets rid of the list
struct comic * freeList(struct comic *ptr) {
    struct comic *temp;

    if (ptr == NULL) {
        printf("List is already empty.\n");
        return ptr;
    }

    // Traverse the list and free each node
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;  // Move to the next node first
        free(temp);
    }

    printf("List has been successfully freed.\n");
    return ptr;
}

// ========== JSON FILE FUNCTIONS ==========

// Reads from a JSON file by reading into a buffer and parsing it into an array (in cJSON terms)
struct comic * readFromJSON(struct comic *ptr, const char *filename) { 
    FILE *fp = fopen(filename, "r"); // Read mode
    if (!fp) { 
        printf("Error: Unable to open the file.\n"); 
        return ptr; 
    } 

    // Determine file size
    fseek(fp, 0, SEEK_END);  
    long file_size = ftell(fp);
    rewind(fp); // As fseek moved the file pointer to the end of the file, it's necessary to bring it back to the beginning.

    char *json_data = (char *)malloc(file_size + 1);
    if (!json_data) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return ptr;
    }

    // Read file into allocated memory: json_data is where we store the data, 1 means that we read the file byte-by-byte, file_size is the number of nodes to be read and fp is what we read from.
    fread(json_data, 1, file_size, fp);
    json_data[file_size] = '\0';  // Null-terminate
    fclose(fp);

    // Parse JSON as an array
    cJSON *json_array = cJSON_Parse(json_data);
    free(json_data);
    if (!json_array || !cJSON_IsArray(json_array)) {
        printf("Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        cJSON_Delete(json_array);
        return ptr;
    }

    struct comic *current = ptr, *prev = NULL;
    cJSON *json_item = NULL;

    // Iterate over JSON and update existing nodes
    cJSON_ArrayForEach(json_item, json_array) {
        if (!current) {
            // If list is shorter than JSON, allocate new nodes
            current = (struct comic *)malloc(sizeof(struct comic));
            if (!current) {
                printf("Memory allocation failed.\n");
                cJSON_Delete(json_array);
                return ptr;
            }
            current->prev = prev;
            current->next = NULL;
            if (prev) prev->next = current;
            else ptr = current;  // Update head pointer
        }

        // Update values
        current->comicID = cJSON_GetObjectItem(json_item, "comicID")->valueint;
        strcpy(current->comicSeries, cJSON_GetObjectItem(json_item, "comicSeries")->valuestring);
        strcpy(current->comicName, cJSON_GetObjectItem(json_item, "comicName")->valuestring);

        prev = current;
        current = current->next;
    }

    // If there are extra nodes in the list, free them
    while (current) {
        struct comic *temp = current;
        current = current->next;
        free(temp);
    }
    if (prev) prev->next = NULL; // Terminate list

    cJSON_Delete(json_array);
    printf("List successfully overridden from JSON!\n");
    return ptr;
}

// Writes the currently existing list into a JSON file
int writeToJSON(struct comic *ptr) {
    if (!ptr) {
        printf("This is an empty list.\n");
        return -1;
    }

    cJSON *json_array = cJSON_CreateArray(); // Create JSON array (in cJSON terms)

    while (ptr) {
        cJSON *json = cJSON_CreateObject();
        cJSON_AddNumberToObject(json, "comicID", ptr->comicID);
        cJSON_AddStringToObject(json, "comicSeries", ptr->comicSeries);
        cJSON_AddStringToObject(json, "comicName", ptr->comicName);

        cJSON_AddItemToArray(json_array, json);
        ptr = ptr->next;
    }

    char *json_str = cJSON_Print(json_array);

    FILE *fp = fopen("data.json", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        cJSON_Delete(json_array);
        return -1;
    }

    fputs(json_str, fp);
    fclose(fp);

    cJSON_free(json_str);
    cJSON_Delete(json_array);

    printf("JSON file written successfully!\n");

    return 0;
}

// ========== NETWORK FUNCTIONS ==========

// Checks whether a comics.json file exists and downloads it if necessary. Ultimately, it reads from that comics.json file.
struct comic * downloadManager(struct comic *ptr) {
    FILE *fp = fopen("comics.json", "r"); 
    if (!fp) { 
        downloadJSONFile("https://azmindroma.de/dhbw/comics.json", "comics.json");
    }
    ptr = readFromJSON(ptr, "comics.json");
    return ptr;
}

// Callback function used by libcurl in order to write downloaded data into a file, set as CURLOPT_WRITEFUNCTION 
size_t writeFileCallback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Downloads url and saves it into filename using libcurl
int downloadJSONFile(const char *url, const char *filename) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize curl.\n");
        return 0;
    }

    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing: %s\n", filename);
        curl_easy_cleanup(curl);
        return 0;
    }

    // Configuration of the curl request
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFileCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);
    fclose(file);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        printf("Failed to download file: %s\n", curl_easy_strerror(res));
        remove(filename); // Remove incomplete file
        return 0;
    }

    printf("Downloaded %s successfully.\n", filename);
    return 1;
}
