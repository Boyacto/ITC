#ifndef DoublyLinkedList2_h
#define DoublyLinkedList2_h

#include "NodeD.h"
#include "Queue.h"
#include "Error.h"
#include <string> 

using namespace std;

template<class T>
class DoublyLinkedList2 {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
    void mergeSort(int ini, int fin);
    void merge(int ini, int mid, int fin);
public:
    DoublyLinkedList2();
    void operator=(initializer_list<T> list);
    void operator=(DoublyLinkedList2<T> list);
    T& operator[](int index);
    void addFirst(T data);
    void addLast(T data);
    bool deleteData(T data); 
    bool deleteAt(int index); 
    T getData(int index); 
    void updateAt(int index, T newData);
    void updateData(T data, T newData);
    void insertAt(int index, T newData);
    void duplicate();
    void removeDuplicates();
    int findData(T data);
    void sort();
    void clear();
    void print();
    void printReverse();
    bool isEmpty();
    int getSize();
    bool existsErrorIn(Error er);
    int getErrorIndex(Error er);
    string stringify();
};

template<class T>
DoublyLinkedList2<T>::DoublyLinkedList2() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
T& DoublyLinkedList2<T>::operator[](int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeD<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DoublyLinkedList2<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T i : list) {
            addLast(i);
        }
    } else {
        throw runtime_error("Error: DoublyLinkedList2 no esta vacia");   
    }
}

template<class T>
void DoublyLinkedList2<T>::operator=(DoublyLinkedList2<T> list) {
    clear();
    for (int i=1; i<=list.size; i++) {
        addLast(list[i]);
    }

}

template<class T>
void DoublyLinkedList2<T>::addFirst(T data) {
    if (!isEmpty()) {
        head->prev = new NodeD<T>(data, head, NULL); 
        head = head->prev;
    } else {
        head = new NodeD<T>(data);
        tail = head;
    }
    size++;
}

template<class T>
void DoublyLinkedList2<T>::addLast(T data) {
    if (!isEmpty()) {
        tail->next = new NodeD<T>(data,NULL, tail);
        tail = tail->next;
    } else {
        tail = new NodeD<T>(data);
        head = tail;
    }
    size++;
}

template<class T>
bool DoublyLinkedList2<T>::deleteData(T data) {
    if (!isEmpty()) {
        if (head->data == data) {
            NodeD<T>* aux = head;
            head = aux->next;
            head->prev = NULL;
            delete aux; // Libera espacio de memoria
            size--;
            if (head == NULL) {
                tail = NULL;
            }
            return true;
        } else {
            if (head->next != NULL) {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                while (aux != NULL) {
                    if (aux->data == data) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                }
            }
        }
    }
    return false;
}

template<class T>
bool DoublyLinkedList2<T>::deleteAt(int index) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            NodeD<T>* aux = head;
            head = aux->next;
            if (head == NULL) {
                tail = NULL;
            } else {
                head->prev = NULL;
            }
            delete aux;
            size--;
            return true;
        } else {
            if (head->next != NULL) {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                int i = 2;
                while (aux != NULL) {
                    if (i == index) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                    i++;
                }
            }
        }
    }
    return false;
}

template<class T>
T DoublyLinkedList2<T>::getData(int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeD<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
            
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DoublyLinkedList2<T>::updateAt(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index <= size/2) {
            NodeD<T>* aux = head;
            int i = 1;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DoublyLinkedList2<T>::updateData(T data, T newData) {
    NodeD<T>* aux = head;
    while(aux != NULL) {
        if (aux->data == data) {
            aux->data = newData;
            return;
        }
        aux = aux->next;
    }
    throw out_of_range("Data not found");
}

template<class T>
void DoublyLinkedList2<T>::insertAt(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            head->prev = new NodeD<T>(newData,head,NULL);
            head = head->prev;
            size++;
            return;
        } else {
            if (index == size) {
                tail->next = new NodeD<T>(newData, NULL, tail);
                tail = tail->next;
                size++;
                return;
            } else {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                int i = 2;
                while(aux->next != NULL) {
                    if (i == index) {
                        prev->next = new NodeD<T>(newData,aux,prev);
                        size++;
                        return;
                    }
                    prev = aux;
                    aux = aux->next;
                    i++;
                }
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DoublyLinkedList2<T>::merge(int ini, int mid, int fin) {
    Queue<T> listL;
    Queue<T> listR;
    int pos,f1,f2,i,j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;   
    for (i=1;i<=f1;i++) {
        listL.enqueue(getData(ini+i-1));
    }
    for (j=1;j<=f2;j++) {
        listR.enqueue(getData(mid+1+j-1));
    }
    i = 1;
    j = 1;
    while (i<=f1 && j<=f2) {
        if (listL.front()<=listR.front()) {
            updateAt(pos,listL.dequeue());
            i++;
        } else {
            updateAt(pos,listR.dequeue());
            j++;
        }
        pos++;
    }
    while (i<=f1) {
        updateAt(pos,listL.dequeue());
        i++;
        pos++;
    }
    while (j<=f2) {
        updateAt(pos,listR.dequeue());
        j++;
        pos++;
    }
}

template<class T>
void DoublyLinkedList2<T>::mergeSort(int ini, int fin) {
    if (ini < fin) {
        int mid = (ini + fin) / 2;
        mergeSort(ini,mid);
        mergeSort(mid+1,fin);

        merge(ini,mid,fin);
    }
}

template<class T>
void DoublyLinkedList2<T>::sort() {
    mergeSort(1,size);
}

template<class T>
int DoublyLinkedList2<T>::findData(T data) {
    int posI = 1;
    int posF = size;
    int posM = (posI + posF) / 2;
    bool found = false;
    sort();
    while (posI <= posF && !found) {
        if (data < getData(posM)) {
            posF = posM - 1;
            
        } else {
            if (data > getData(posM)) {
                posI = posM + 1;
                
            } else {
                if (data == getData(posM)) {
                    found = true;
                }
            }
        }
        posM = (posI + posF) / 2;
        
    }
    if (found) {
        return posM;
    } else {
        //throw runtime_error("Not found in list");
        
        return -1;
    }
}

template<class T>
void DoublyLinkedList2<T>::duplicate() {
    // NodeD<T>* aux = head;
    // while (aux != NULL) {
    //     aux->next = new NodeD<T>(aux->data,aux->next);
    //     size++;
    //     aux = aux->next->next;
    // }
}

template<class T>
void DoublyLinkedList2<T>::removeDuplicates() {
    // NodeD<T>* aux = head;
    // DoublyLinkedList2<T> list = *this;
    // clear();
    // for (int i=1; i<list.size; i++) {
    //     if (!findData(aux->data)) {
    //         addLast(aux->data);
    //     }
    // }
}

template<class T>
void DoublyLinkedList2<T>::print() {
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


template <class T>
bool DoublyLinkedList2<T>::existsErrorIn(Error er){
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data == er){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

template <class T>
int DoublyLinkedList2<T>::getErrorIndex(Error er){
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data.errorType == er.errorType){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}

template<class T>
string DoublyLinkedList2<T>::stringify(){
    NodeD<T>* aux = head;
    string output ="";
    for (int i=1; i<=size; i++) {
        output += aux->data.errorType+":"+to_string(aux->data.frequency)+",";
        aux = aux->next;
    }
    return output;
}

template<class T>
void DoublyLinkedList2<T>::printReverse() {
    NodeD<T>* aux = tail;
    for (int i=size; i>=1; i--) {
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
}

template<class T>
void DoublyLinkedList2<T>::clear() {
    int i = 1;
    while (i<=size) {
        NodeD<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
    tail = NULL;
}

template<class T>
bool DoublyLinkedList2<T>::isEmpty() {
    return size == 0;
}

template<class T>
int DoublyLinkedList2<T>::getSize() {
    return size;
}
#endif