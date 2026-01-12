// 2026.1.10
// AddressBook.cpp 实现通讯录的功能; 基于双向链表; 
// pan wei

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

#define NAME_LENGTH 16
#define PHONE_LENGTH 32

#define INFO printf

enum {
    OPER_INSERT = 1,
    OPER_PRINT,
    OPER_DELETE,
    OPER_SEARCH,
    OPER_SAVE,
    OPER_LOAD
};


// 在链表最前面加入节点;
#define LIST_INSERT(item, list) do { \
    item->prev = nullptr;               \
    item->next = list;               \
    list = item;                     \
} while (0)

#define LIST_REMOVE(item, list) do {                           \
    if (item->prev != nullptr)  item->prev->next = item->next;    \
    if (item->next != nullptr)  item->next->prev = item->prev;    \
    if (list == item) list = item->next;                       \
    item->prev = item->next = nullptr;                            \
} while (0)

// 1.封装数据结构
struct Person
{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    struct Person *next;
    struct Person *prev;
};

struct AddressBook
{
    struct Person *allpeople;
    int peoplecount;
};

// 接口层, 与底层数据结构隔离;
int person_insert(struct Person **Ppeople, struct Person *ps) {
    if (ps == nullptr) return -1;
    LIST_INSERT(ps, *Ppeople);
}

int person_delete(struct Person **Ppeople, struct Person *ps) {
    if (ps == nullptr) return -1;
    LIST_REMOVE(ps, *Ppeople);
}

struct Person* person_search(struct Person *people, const char *name) {
    struct Person *item = nullptr;
    for (item = people; item != nullptr; item = item->next) {
        if (!strcmp(item->name, name)) {
            break;
        }
    }
    return item;
}

int person_traversal(struct Person *people) {
    struct Person *item = nullptr;
    for (item = people; item != nullptr; item = item->next) {
        INFO("name: %s, phone: %s\n", item->name, item->phone);
    }    
    return 0;
}



int insert_entry(struct AddressBook *adb) {
    if (adb == nullptr) return -1;
    struct Person *p = (struct Person* )malloc(sizeof(struct Person));
    if (p == nullptr) return -2;
    // name;
    INFO("Please Input Name: \n");
    scanf("%s", p->name);
    // phone;
    INFO("Please Input Phone: \n");
    scanf("%s", p->phone);
    // add people;
    if (0 != person_insert(&adb->allpeople, p)) {
        free(p);
        return -3;
    }
    adb->peoplecount++;
    INFO("Insert Success\n");

    return 0;
}

int print_entry(struct AddressBook *adb) {
    if (adb == nullptr) return -1;
    person_traversal(adb->allpeople);
}

int delete_entry(struct AddressBook *adb) {
    if (adb == nullptr) return -1;
    INFO("Please Input Name: \n");
    char name[NAME_LENGTH] = {0};
    scanf("%s", name);

    struct Person* ps = person_search(adb->allpeople, name);
    if (ps == nullptr) {
        INFO("Person don't Exit\n");
        return -2;
    }

    person_delete(&adb->allpeople, ps);
    free(ps);
    return 0;
}


int search_entry(struct AddressBook *adb) {
    if (adb == nullptr) return -1;
    INFO("Please Input Name: \n");
    char name[NAME_LENGTH] = {0};
    scanf("%s", name);  
    struct Person* ps = person_search(adb->allpeople, name);
    if (ps == nullptr) {
        INFO("Person don't Exit\n");
        return -2;
    }  
    INFO("name: %s, phone: %s\n", ps->name, ps->phone);
    return 0;
}



int main(int argc, char *argv[]) {

    struct AddressBook *ADB = ( struct AddressBook* )malloc(sizeof(struct AddressBook));
    if (ADB == nullptr) return -1;
    memset(ADB, 0, sizeof(struct AddressBook));

    while (1)
    {
        int select = 0;
        scanf("%d", &select);

        switch (select) {
            case OPER_INSERT:
                insert_entry(ADB);
                break;
            case OPER_PRINT:
                print_entry(ADB);
                break;
            case OPER_DELETE:
                delete_entry(ADB);
                break;
            case OPER_SEARCH:
                search_entry(ADB);
                break;
            case OPER_SAVE:
                break;
            case OPER_LOAD:
                break;
        }



    }
    

    return 0;
}






















// class Person
// {
// private:
//     std::string name_;
//     std::string phone_;
//     Person *next;
//     Person *prev;
// public:
//     Person(const std::string& input_name, const std::string& input_phone);  
    
// };

// Person::Person(const std::string& input_name, const std::string& input_phone)
//     : name_(input_name), phone_(input_phone) { //name_将input_name拷贝一份到name_中; phone_同理;
// }

















