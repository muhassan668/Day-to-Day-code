#include "Task3.h"

BinaryStore::BinaryStore() {
    head = nullptr;
    length = 0;
}

BinaryStore::BinaryStore(int len) {
    head = nullptr;
    length = len;
}

BinaryStore::~BinaryStore() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete[] current->address;
        delete[] current->value;
        delete current;
        current = nextNode;
    }
}

bool BinaryStore::sameAddress(const char* a, const char* b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

BinaryStore::Node* BinaryStore::findNode(const char* address) {
    Node* current = head;
    while (current != nullptr) {
        if (sameAddress(current->address, address)) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void BinaryStore::add_Address(char* s) {
    add_Address((const char*)s);
}

void BinaryStore::add_Address(const char* s) {
    Node* existing = findNode(s);
    if (existing != nullptr) {
        return;
    }

    Node* newNode = new Node;
    newNode->address = new char[5];
    for (int i = 0; i < 4; i++) {
        newNode->address[i] = s[i];
    }
    newNode->address[4] = '\0';

    newNode->value = nullptr;
    newNode->next = head;
    head = newNode;
    length++;
}

void BinaryStore::set_Byte(char* address, char* value) {
    set_Byte((const char*)address, (const char*)value);
}

void BinaryStore::set_Byte(const char* address, const char* value) {
    Node* node = findNode(address);

    if (node == nullptr) {
        add_Address(address);
        node = findNode(address);
    }

    if (node->value == nullptr) {
        node->value = new char[9];
    }

    for (int i = 0; i < 8; i++) {
        node->value[i] = value[i];
    }
    node->value[8] = '\0';
}

char* BinaryStore::Get(char* address) {
    return Get((const char*)address);
}

char* BinaryStore::Get(const char* address) {
    Node* node = findNode(address);
    if (node == nullptr) {
        return nullptr;
    }
    return node->value;
}

char* BinaryStore::ToString() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    char* result = new char[count * 14 + 1];
    int index = 0;
    current = head;

    while (current != nullptr) {
        for (int i = 0; i < 4; i++) {
            result[index++] = current->address[i];
        }

        result[index++] = ':';

        if (current->value != nullptr) {
            for (int i = 0; i < 8; i++) {
                result[index++] = current->value[i];
            }
        } else {
            for (int i = 0; i < 8; i++) {
                result[index++] = '0';
            }
        }

        result[index++] = '\n';
        current = current->next;
    }

    result[index] = '\0';
    return result;
}

char* BinaryStore::Add(char* a, char* b) {
    return Add((const char*)a, (const char*)b);
}

char* BinaryStore::Add(const char* a, const char* b) {
    return binaryOperation(a, b, '+');
}

bool BinaryStore::comp_EQUAL(char* a, char* b) {
    return comp_EQUAL((const char*)a, (const char*)b);
}

bool BinaryStore::comp_EQUAL(const char* a, const char* b) {
    for (int i = 0; i < 8; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

char* BinaryStore::comp_AND(char* a, char* b) {
    return comp_AND((const char*)a, (const char*)b);
}

char* BinaryStore::comp_AND(const char* a, const char* b) {
    return binaryOperation(a, b, '&');
}

char* BinaryStore::comp_OR(char* a, char* b) {
    return comp_OR((const char*)a, (const char*)b);
}

char* BinaryStore::comp_OR(const char* a, const char* b) {
    return binaryOperation(a, b, '|');
}

char* BinaryStore::comp_NOT(char* a) {
    return comp_NOT((const char*)a);
}

char* BinaryStore::comp_NOT(const char* a) {
    char* result = new char[9];
    for (int i = 0; i < 8; i++) {
        result[i] = (a[i] == '0') ? '1' : '0';
    }
    result[8] = '\0';
    return result;
}

char* BinaryStore::binaryOperation(const char* a, const char* b, char op) {
    char* result = new char[9];

    for (int i = 0; i < 8; i++) {
        if (op == '&') {
            result[i] = ((a[i] == '1') && (b[i] == '1')) ? '1' : '0';
        } else if (op == '|') {
            result[i] = ((a[i] == '1') || (b[i] == '1')) ? '1' : '0';
        } else {
            result[i] = (a[i] == b[i]) ? '0' : '1';
        }
    }

    result[8] = '\0';
    return result;
}