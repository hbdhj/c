/*
Copyright 2017 <Deng Haijun>
*/
#ifndef GITHUB_C_HACKERRANK_COMMON_H_
#define GITHUB_C_HACKERRANK_COMMON_H_
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::set;
using std::map;
using std::sort;
using std::queue;
using std::unordered_set;
using std::unordered_map;
using std::priority_queue;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* createListFromArray(int* arr, int len) {
    if (sizeof(arr) == 0)
        return NULL;
    ListNode* head = NULL;
    for (int i = len - 1; i >= 0; i--) {
        ListNode* pNode = new ListNode(arr[i]);
        pNode->next = head;
        head = pNode;
    }
    return head;
}

template<class T>
T* createListFromArray(int* arr, int len) {
    if (sizeof(arr) == 0)
        return NULL;
    T* head = NULL;
    for (int i = len - 1; i >= 0; i--) {
        T* pNode = new T(arr[i]);
        pNode->next = head;
        head = pNode;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val;
        if (tmp->next)
            cout << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

void printVector(vector<int> v) {
    if (v.size() == 0)
        cout << "[]" << endl;
    cout << "[";
    int sz = v.size();
    for (int i = 0; i < sz-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[sz-1] << "]" << endl;
}

TreeNode* createTreeFromArray(int* arr, int len) {
    if (sizeof(arr) == 0)
        return NULL;
    TreeNode** tree = new TreeNode*[len];
    TreeNode* root = new TreeNode(arr[0]);
    tree[0] = root;
    for (int i = 1; i < len; i++) {
        if (arr[i] != '#')
            tree[i] = new TreeNode(arr[i]);
        if (i%2) {
            tree[(i-1)/2]->left = tree[i];
        } else {
            tree[i/2-1]->right = tree[i];
        }
    }
    return root;
}

template<class T>
T* createTreeFromArray(int* arr, int len) {
    if (sizeof(arr) == 0)
        return NULL;
    T** tree = new T*[len];
    T* root = new T(arr[0]);
    tree[0] = root;
    for (int i = 1; i < len; i++) {
        if (arr[i] != '#')
            tree[i] = new T(arr[i]);
        if (i%2) {
            tree[(i-1)/2]->left = tree[i];
        } else {
            tree[i/2-1]->right = tree[i];
        }
    }
    return root;
}

int getLinkLength(ListNode *head) {
    int ret = 0;
    ListNode* p = head;
    while (p != NULL) {
        ret++;
        p = p->next;
    }
    return ret;
}

ListNode* listWalk(ListNode *head, int n) {
    ListNode* p = head;
    while ((n--) && (p != NULL)) {
        p = p->next;
    }
    return p;
}
#endif  // GITHUB_C_HACKERRANK_COMMON_H_

