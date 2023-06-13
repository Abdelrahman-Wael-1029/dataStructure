//
// Created by abdelrahman wael on 6/13/2023.
//

#include "AVLTree.h"

template<class T>
void AVLTree<T>::preorder(node<T> *temp) {
    if (temp == nullptr)
        return;
    std::cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

template<class T>
node<T> *AVLTree<T>::insert(node<T> *temp, T data) {
    if (temp == nullptr) {
        return new node<T>(data);
    }
    if (temp->data > data) {
        temp->left = insert(temp->left, data);
    } else {
        temp->right = insert(temp->right, data);
    }

    temp->height = calcHeight(temp);

    int balance = calcBalance(temp);

    if (balance == -2) {
        if (calcBalance(temp->right) == -1) {
            temp = RRRotation(temp);
        } else {
            temp = RLRotation(temp);
        }
    } else if (balance == 2) {
        if (calcBalance(temp->left) == 1) {
            temp = LLRotation(temp);
        } else {
            temp = LRRotation(temp);
        }
    }
    return temp;
}

template<class T>
bool AVLTree<T>::isEmpty() {
    return !siz;
}

template<class T>
T AVLTree<T>::findMax(node<T> *temp) {
    if (temp == nullptr)
        return T();
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->data;
}

template<class T>
T AVLTree<T>::findMin(node<T> *temp) {
    if (temp == nullptr)
        return T();
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->data;
}

template<class T>
int AVLTree<T>::size() {
    return siz;
}

template<class T>
node<T> *AVLTree<T>::remove(node<T> *&temp, T data) {
    if (temp == nullptr) {
        return temp;
    }
    if (temp->data > data) {
        temp->left = remove(temp->left, data);
    } else if (temp->data < data) {
        temp->right = remove(temp->right, data);
    } else {
        if (temp->left == nullptr || temp->right == nullptr) {
            node<T> *temp2 = temp->left ? temp->left : temp->right;
            if (temp2 == nullptr) {
                temp = nullptr;
            } else {
                *temp = *temp2;
                delete temp2;
                temp2 = nullptr;
            }
        } else {
            node<T> *temp2 = temp->right;
            while (temp2->left != nullptr) {
                temp2 = temp2->left;
            }

            temp->data = temp2->data;
            temp->right = remove(temp->right, temp2->data);
        }
    }

    if (temp == nullptr) {
        return temp;
    }

    temp->height = calcHeight(temp);
    int balance = calcBalance(temp);

    if (balance == -2) {
        if (calcBalance(temp->right) == -1) {
            temp = RRRotation(temp);
        } else {
            temp = RLRotation(temp);
        }

    } else if (balance == 2) {
        if (calcBalance(temp->left) == 1) {
            temp = LLRotation(temp);
        } else {
            temp = LRRotation(temp);
        }
    }
    return temp;
}

template<class T>
node<T> *AVLTree<T>::successor(T data) {
    if (root == nullptr) {
        return nullptr;
    }
    node<T> *ans = nullptr, *temp = root;
    while (temp != nullptr) {
        if (temp->data > data) {
            ans = temp;
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return ans;
}

template<class T>
int AVLTree<T>::calcBalance(node<T> *temp) {
    if (temp == nullptr || (temp->left == nullptr && temp->right == nullptr))
        return 0;
    if (temp->left == nullptr) {
        return -temp->right->height;
    }
    if (temp->right == nullptr) {
        return temp->left->height;
    }
    return (temp->left->height) - (temp->right->height);
}

template<class T>
int AVLTree<T>::calcHeight(node<T> *temp) {
    if (temp == nullptr)
        return 0;
    if (temp->left == nullptr && temp->right == nullptr)
        return 1;
    if (temp->left == nullptr)
        return temp->right->height + 1;
    if (temp->right == nullptr)
        return temp->left->height + 1;
    return std::max(temp->left->height, temp->right->height) + 1;
}

template<class T>
node<T> *AVLTree<T>::RRRotation(node<T> *temp) {
    return temp = leftRotation(temp);
}

template<class T>
node<T> *AVLTree<T>::LLRotation(node<T> *temp) {
    return temp = rightRotation(temp);
}

template<class T>
node<T> *AVLTree<T>::RLRotation(node<T> *temp) {
    temp->right = rightRotation(temp->right);
    return temp = RRRotation(temp);
}

template<class T>
node<T> *AVLTree<T>::LRRotation(node<T> *temp) {
    temp->left = leftRotation(temp->left);
    return temp = LLRotation(temp);
}

template<class T>
node<T> *AVLTree<T>::rightRotation(node<T> *temp) {
    node<T> *lef = temp->left;
    temp->left = lef->right;
    lef->right = temp;
    temp->height = calcHeight(temp);
    lef->height = calcHeight(lef);
    return lef;
}

template<class T>
node<T> *AVLTree<T>::leftRotation(node<T> *temp) {
    node<T> *rit = temp->right;
    temp->right = rit->left;
    rit->left = temp;
    temp->height = calcHeight(temp);
    rit->height = calcHeight(rit);
    return rit;
}

template<class T>
bool AVLTree<T>::search(T data) {
    node<T> *temp = root;
    while (temp != nullptr) {
        if (temp->data == data) {
            return true;
        }
        if (temp->data > data) {
            temp = temp->left;
        } else
            temp = temp->right;
    }
    return false;
}

template<class T>
void AVLTree<T>::preorder() {
    preorder(root);
}

template<class T>
void AVLTree<T>::insert(T data) {
    if (search(data)) {
        std::cout << "This data is already exist\n";
        return;
    }
    root = insert(root, data);
    ++siz;
}

template<class T>
void AVLTree<T>::remove(T data) {
    if (!search(data)) {
        std::cout << "This data is not exist\n";
        return;
    }
    root = remove(root, data);
    --siz;
}

template<class T>
AVLTree<T>::AVLTree() : root(nullptr), siz(0) {}


template
class AVLTree<int>;

template
class AVLTree<float>;

template
class AVLTree<double>;

template
class AVLTree<char>;

template
class AVLTree<std::string>;

template
class AVLTree<bool>;

template
class AVLTree<long>;

template
class AVLTree<long long>;

template
class AVLTree<long double>;

template
class AVLTree<unsigned int>;

template
class AVLTree<unsigned long>;

template
class AVLTree<unsigned long long>;

template
class AVLTree<unsigned char>;

template
class AVLTree<unsigned short>;
