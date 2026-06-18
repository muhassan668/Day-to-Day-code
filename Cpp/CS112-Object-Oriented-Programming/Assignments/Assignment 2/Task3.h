#ifndef TASK3_H
#define TASK3_H

class BinaryStore {
private:
    struct Node {
        char* address;
        char* value;
        Node* next;
    };

    Node* head;
    int length;

    char* binaryOperation(const char* a, const char* b, char op);
    bool sameAddress(const char* a, const char* b);
    Node* findNode(const char* address);

public:
    BinaryStore();
    BinaryStore(int len);
    ~BinaryStore();

    void add_Address(char* s);
    void add_Address(const char* s);

    void set_Byte(char* address, char* value);
    void set_Byte(const char* address, const char* value);

    char* Get(char* address);
    char* Get(const char* address);

    char* ToString();

    char* Add(char* a, char* b);
    char* Add(const char* a, const char* b);

    bool comp_EQUAL(char* a, char* b);
    bool comp_EQUAL(const char* a, const char* b);

    char* comp_AND(char* a, char* b);
    char* comp_AND(const char* a, const char* b);

    char* comp_OR(char* a, char* b);
    char* comp_OR(const char* a, const char* b);

    char* comp_NOT(char* a);
    char* comp_NOT(const char* a);
};

#endif