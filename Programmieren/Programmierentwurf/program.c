#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cjson/cJSON.h>
// External dependency. <ADD PACKAGE NAMES FOR APT>
// Requires adding an extra argument to gcc: -lcjson
// gcc program.c -lcjson -o program

struct comic {
    int comicID;
    char comicSeries[50+1];
    char comicName[50+1];
    int pages;
    struct comic * prev;
    struct comic * next; 
};

struct comic * ptr = NULL;

// Function prototypes
int press_enter();
int menu();
struct comic * create_new_list(struct comic * ptr);
struct comic * add_element(struct comic * ptr);
int fill_element(struct comic * ptr);
struct comic * remove_element(struct comic * ptr);
int print_list_to_screen(struct comic * ptr);
int write_to_json(struct comic * ptr);
int read_from_json(struct comic **ptr);

int main() {
    menu();
}

int press_enter() {
    printf("Press Enter to continue...");
    while (getchar() != '\n') {
        // This makes sure to clear any possible leftover characters from the input buffer. In case anyone presses something that makes the buffer pass over to this function, which is not wanted!
    }
    getchar();
}

int menu() {
    int choice;

    system("clear"); // This will likely not work on Windows, but it should work on any Unix-like system (it works on Linux.)
    // Unlike C#, I cannot seem to be able to make it one printf spread among lines to make it appear more organized. So ultimately, it seems as if having multiple printfs is better for code legibility.
    printf("COMIC MANAGEMENT SYSTEM\nPlease select one option:\n\n");
    printf(" 1. Create new list\n");
    printf(" 2. Add new element to list\n");
    printf(" 3. Delete element from list\n");
    printf(" 4. Show list on screen\n");
    printf(" 5. Write list to disk\n"); 
    printf(" 6. Read list from disk\n");
    printf(" 0. End program\n\n");
    printf(" Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        ptr = create_new_list(ptr);
        break;
    case 2:
        add_element(ptr);
        break;
    case 3:
        delete_element(ptr);
        break;
    case 4:
        print_list_to_screen(ptr);
        break;
    case 5:
        write_to_json(ptr);
        break;
    case 6:
        read_from_json(&ptr);
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("ERROR");
        break;
    }
    menu();
}

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
    press_enter();
    return(ptr);
}

struct comic * add_element(struct comic * ptr) {
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
    press_enter();
    return(ptr);
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
 
    printf(" pages: ");
    scanf("%d", &ptr->pages);
    // No getchar(); here, as this is the final operation and the press enter operation consumes leftover newlines already.

    return 0;
}

struct comic * remove_element(struct comic * ptr) {
    int elementSelection;
    printf("Enter")
    scanf("%d", elementSelection);
}

int write_to_json(struct comic *ptr) {
    if (!ptr) {
        printf("This is an empty list.\n");
        press_enter();
        return -1;
    }

    cJSON *json_array = cJSON_CreateArray(); // Create JSON array

    while (ptr) {
        cJSON *json = cJSON_CreateObject(); // Create JSON object for each comic
        cJSON_AddNumberToObject(json, "comicID", ptr->comicID);
        cJSON_AddStringToObject(json, "comicSeries", ptr->comicSeries);
        cJSON_AddStringToObject(json, "comicName", ptr->comicName);
        cJSON_AddNumberToObject(json, "pages", ptr->pages);

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

    press_enter();
    return 0;
}

int read_from_json(struct comic **ptr) { 
    FILE *fp = fopen("data.json", "r"); 
    if (!fp) { 
        printf("Error: Unable to open the file.\n"); 
        press_enter();
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
        current->pages = cJSON_GetObjectItem(json_item, "pages")->valueint;

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
    press_enter();
    return 0;
}


int print_list_to_screen (struct comic * ptr) {
    int i = 1;
    printf ("Screen output of list\n\n");
    if (ptr) {
        printf(" element %d: comicID: %d\tcomicSeries: %s\t comicName: %s \tpages: %d\n", i, ptr->comicID, ptr->comicSeries, ptr->comicName, ptr->pages);
        i++;
        while (ptr->next) {
            ptr = ptr->next;
            printf(" element %d: comicID: %d\tcomicSeries: %s\t comicName: %s \tpages: %d\n", i, ptr->comicID, ptr->comicSeries, ptr->comicName, ptr->pages);
            i++;
        }
    printf("\n\n");
    } else {
        printf("This is an empty list.\n");
    }
    press_enter();
    return(i);
}