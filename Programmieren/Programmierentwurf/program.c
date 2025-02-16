#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cjson/cJSON.h>
#include <curl/curl.h>
// External dependency. <ADD PACKAGE NAMES FOR APT>
// Requires adding an extra argument to gcc: -lcjson -lcurl
// gcc program.c -lcjson -lcurl -o program

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
int press_enter();
char get_yes_no();
int menu();

// Comic List Management Functions
struct comic * create_new_list(struct comic * ptr);
void add_element(struct comic * ptr);
int fill_element(struct comic * ptr);
struct comic * remove_element_selection(struct comic * ptr);
void remove_element_execution(struct comic * ptr);

// Display and Sorting Functions
int print_list_to_screen(struct comic * ptr);
struct comic * sort_list(struct comic * ptr);

// Memory Management Function
void free_list(struct comic **ptr);

// JSON File Functions
int read_from_json(struct comic **ptr, const char *filename);
int write_to_json(struct comic * ptr);

// Network Functions
void download_manager();
size_t write_file_callback(void *ptr, size_t size, size_t nmemb, FILE *stream);
int download_json_file(const char *url, const char *filename);


int main() {
    menu();
}

// ========== USER INTERACTION FUNCTIONS ==========

int press_enter() {
    printf("Press Enter to continue...");
    while (getchar() != '\n' && getchar() != EOF);  // Only consume the newline // Clear any leftover input
    getchar(); // Wait for Enter key
}

char get_yes_no() {
    char choice;

    while (1) {  // Keep looping until valid input is given
        printf(" (y/n): ");
        int result = scanf("%c", &choice); // Space before %c eats up newlines

        if (result == 1 && (choice == 'y' || choice == 'n')) {
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
    printf(" 5. Sort Comics\n");
    printf(" 6. Drop List\n");
    printf(" 7. Load Comics from JSON\n");
    printf(" 8. Save Comics to JSON\n");
    printf(" 9. Load Comics from Online Database\n");
    printf(" 0. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    
    validationChoice = scanf("%d", &choice);

    if (validationChoice != 1)
    {
        printf("Invalid input. Enter a valid number. ");
    } else {
        switch (choice) {
            case 1:
                ptr = create_new_list(ptr);
                break;
            case 2:
                add_element(ptr);
                break;
            case 3:
                remove_element_selection(ptr);
                break;
            case 4:
                print_list_to_screen(ptr);
                break;
            case 5:
                ptr = sort_list(ptr);
                break;
            case 6:
                free_list(&ptr);
                break;
            case 7:
                read_from_json(&ptr, "data.json");
                break;
            case 8:
                write_to_json(ptr);
                break;
            case 9:
                download_manager();
                break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Enter a valid number. ");
                break;
            }
    }
    press_enter();
    menu();
}

// ========== COMIC LIST MANAGEMENT FUNCTIONS ==========

struct comic * create_new_list(struct comic * ptr) {
    if (ptr) {
        printf("A list already exists.\n");
    } 
    else {
        ptr = (struct comic *) malloc(sizeof(struct comic)); // Allocates memory with the size of the structure
        ptr->prev = NULL; // Key characteristic for first node
        ptr->next = NULL; // Key characteristic for last node
        fill_element(ptr); // Fill first node
    }
    return ptr;
}

void add_element(struct comic * ptr) {
    if (!ptr) {
        printf ("List doesn't exist.\n");
    } 
    else {
        while (ptr->next) { 
            ptr = ptr->next; // Goes through all the nodes to add a new one at the end 
        }
        ptr->next = (struct comic *) malloc (sizeof (struct comic)); // The new node is assigned its necessary space
        ptr->next->prev = ptr; // Makes the prev pointer of the new node point to the existing node (in order to be able to go back) 
        ptr = ptr->next; // Now point to the new node
        ptr->next = NULL; // Set the next pointer to NULL to signalize that it's the last node.
        fill_element(ptr);
        printf("Operation complete.");
    }
    return;
}

int fill_element(struct comic *ptr) {
    printf(" Please enter the following data:\n\n");

    printf(" comicID: ");
    scanf("%d", &ptr->comicID);
    getchar(); // Consume leftover newline

    printf(" comicSeries: ");
    fgets(ptr->comicSeries, sizeof(ptr->comicSeries), stdin);
    ptr->comicSeries[strcspn(ptr->comicSeries, "\n")] = '\0'; // Makes sure to remove any newlines by replacing the first occurance of \n with the null terminator.

    printf(" comicName: ");
    fgets(ptr->comicName, sizeof(ptr->comicName), stdin);
    ptr->comicName[strcspn(ptr->comicName, "\n")] = '\0';
    // No getchar(); here, as this is the final operation and the press enter operation consumes leftover newlines already.

    return 0;
}

struct comic * remove_element_selection(struct comic * ptr) {
    int elementSelection;
    int i = 0;
    struct comic * selectedNode = NULL;

    if (!ptr) {
        printf("This is an empty list.\n");
    } else {
        while (1) {
            struct comic * temp = ptr;
            i = 0;

            printf("Enter which element you want to delete: ");
            scanf("%d", &elementSelection);
            while (getchar() != '\n');  // Clear input buffer

            if (elementSelection < 0) {
                printf("Cannot select negative numbers!\n");
            } else {
                while (temp && i < elementSelection) { // Traverse list
                    temp = temp->next;
                    i++;
                }
                if (!temp) {
                    printf("An element this far doesn't exist! Try again.\n");
                } else {
                    selectedNode = temp;
                    break;  // Valid selection, exit loop
                }
            }
        } 
        printf("%-10s %-5s %-50s %-50s\n", "Element", "ID", "Series", "Name");
        printf("-------------------------------------------------------------------------------------------\n");
        printf("%-10d %-5d %-50s %-50s\n", elementSelection, selectedNode->comicID, selectedNode->comicSeries, selectedNode->comicName);
        printf("Are you sure you want to delete this element?");
        char response = get_yes_no();  // User enters y/n
        
        if (response == 'y') {
            i = 0;
            while (i < elementSelection) {
                ptr = ptr->next;
                i++;
            }
            remove_element_execution(ptr);
        } else if (response == 'n') {
            printf("Process interrupted.\n");
        }
    }

}

void remove_element_execution(struct comic * ptr) {
    if (ptr->prev == NULL) {
        if (ptr->next != NULL) {
            ptr->next->prev = NULL; 
        }
        free(ptr);
        printf("Element removed.");
        return;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
    printf("Element removed.");
}

// ========== DISPLAY AND SORTING FUNCTIONS ==========

int print_list_to_screen (struct comic * ptr) {
    int i = 0;
    printf ("Screen output of list\n\n");
    if (ptr) {
        printf("%-10s %-5s %-50s %-50s\n", "Element", "ID", "Series", "Name");
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

struct comic *sort_list(struct comic *ptr) {
    if (ptr == NULL || ptr->next == NULL) {
        // List is empty or has only one element, no need to sort
        return ptr;
    }

    struct comic *sorted = NULL;  // Start with an empty sorted list
    struct comic *current = ptr;

    while (current != NULL) {
        struct comic *next = current->next;  // Keep track of the next element
        current->prev = current->next = NULL; // Isolate current node

        if (sorted == NULL || sorted->comicID >= current->comicID) {
            // Insert at the beginning if sorted is empty or current has smaller ID
            current->next = sorted;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
        } else {
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

    return sorted;  // Return the new sorted head
}

// ========== MEMORY MANAGEMENT FUNCTION ==========

void free_list(struct comic **ptr) {
    struct comic *temp;

    // Check if the list is empty
    if (*ptr == NULL) {
        printf("List is already empty.\n");
        return;
    }

    // Traverse the list and free each node
    while (*ptr != NULL) {
        temp = *ptr;
        *ptr = (*ptr)->next;  // Move to the next node first
        free(temp);           // Free the current node
    }

    printf("List has been successfully freed.\n");
}

// ========== JSON FILE FUNCTIONS ==========

int read_from_json(struct comic **ptr, const char *filename) { 
    FILE *fp = fopen(filename, "r"); 
    if (!fp) { 
        printf("Error: Unable to open the file.\n"); 
        return 1; 
    } 

    // Determine file size
    fseek(fp, 0, SEEK_END);  
    long file_size = ftell(fp);
    rewind(fp);  

    // Allocate memory dynamically for file content
    char *json_data = (char *)malloc(file_size + 1);
    if (!json_data) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    // Read file into allocated memory
    fread(json_data, 1, file_size, fp);
    json_data[file_size] = '\0';  // Null-terminate
    fclose(fp);

    // Parse JSON as an array
    cJSON *json_array = cJSON_Parse(json_data);
    free(json_data); // Free memory after parsing
    if (!json_array || !cJSON_IsArray(json_array)) {
        printf("Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        cJSON_Delete(json_array);
        return 1;
    }

    struct comic *current = *ptr, *prev = NULL;
    cJSON *json_item = NULL;

    // Iterate over JSON and update existing nodes
    cJSON_ArrayForEach(json_item, json_array) {
        if (!current) {
            // If list is shorter than JSON, allocate new nodes
            current = (struct comic *)malloc(sizeof(struct comic));
            if (!current) {
                printf("Memory allocation failed\n");
                cJSON_Delete(json_array);
                return 1;
            }
            current->prev = prev;
            current->next = NULL;
            if (prev) prev->next = current;
            else *ptr = current;  // Update head pointer
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
    return 0;
}

int write_to_json(struct comic *ptr) {
    if (!ptr) {
        printf("This is an empty list.\n");
        return -1;
    }

    cJSON *json_array = cJSON_CreateArray(); // Create JSON array

    while (ptr) {
        cJSON *json = cJSON_CreateObject(); // Create JSON object for each comic
        cJSON_AddNumberToObject(json, "comicID", ptr->comicID);
        cJSON_AddStringToObject(json, "comicSeries", ptr->comicSeries);
        cJSON_AddStringToObject(json, "comicName", ptr->comicName);

        cJSON_AddItemToArray(json_array, json); // Add object to array
        ptr = ptr->next; // Move to next node
    }

    char *json_str = cJSON_Print(json_array); // Convert array to JSON string

    FILE *fp = fopen("data.json", "w");
    if (fp == NULL) {
        printf("ERROR opening file\n");
        cJSON_Delete(json_array);
        return -1;
    }

    fputs(json_str, fp);
    fclose(fp);

    // Free memory after writing to JSON
    cJSON_free(json_str);
    cJSON_Delete(json_array);

    printf("JSON file written successfully!\n");

    return 0;
}

// ========== NETWORK FUNCTIONS ==========

void download_manager() {
    FILE *fp = fopen("comics.json", "r"); 
    if (!fp) { 
        download_json_file("https://azmindroma.de/dhbw/comics.json", "comics.json");
        read_from_json(&ptr, "comics.json");
        return;
    } else {
        read_from_json(&ptr, "comics.json");
    }
}

size_t write_file_callback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int download_json_file(const char *url, const char *filename) {
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

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_file_callback);
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
