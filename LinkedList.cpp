/* LinkedList.cpp -- implementation of linked list
 *
 */

namespace interview {
    template<typename T> ListNode<T>::ListNode(ListNode<T> *prev,
        ListNode<T> *next, T &data):prev(prev), next(next), data(data) {
    }

    template<typename T> LinkedList<T>::LinkedList():_head(NULL),
        _tail(NULL), _iterator(NULL) {
        List<T>::_size = 0;
    }

    template<typename T> LinkedList<T>::~LinkedList() {
        ListNode<T> *iter = _head;
        ListNode<T> *tmp  = NULL;
        while (iter) {
            tmp = iter;
            iter = iter->next;

            delete tmp;
            tmp = NULL;
        }
    }

    template<typename T> bool LinkedList<T>::remove(T &element) {
        bool found = false;
        ListNode<T> *tmp = NULL;

        if (_head && (_head->data == element)) {
            found = true;
            tmp = _head->next;
            delete _head;
            _head = tmp;
        }

        ListNode<T> *iter = _head;
        while (iter && iter->next) {
            if (iter->next->data == element) {
                tmp = iter->next;
                iter->next = tmp->next;
                tmp->prev = iter;
                found = true;
                delete tmp;
                break;
            }
            iter = iter->next;
        }
        List<T>::_size--;
        if (List<T>::_size <= 1) {
            _tail = _head;
        }

        return found;
    }

    template<typename T> bool LinkedList<T>::find(T &element) {
        bool found = false;
        begin();
        while (hasNext()) {
            if (next() == element) {
                found = true;
                /* end loop ASAP */
                break;
            }
        }

        return found;
    }

    template<typename T> void LinkedList<T>::append(T &element) {
        if (_tail) {
            _tail->next = new ListNode<T>(_tail, NULL, element);
            _tail = _tail->next;
        } else {
            _head = _tail = new ListNode<T>(NULL, NULL, element);
        }

        List<T>::_size++;
    }

    template<typename T> void LinkedList<T>::insert(T &element) {
        append(element);
    }

    template<typename T> bool LinkedList<T>::isEmpty() {
        return (List<T>::_size == 0);
    }

    template<typename T> int LinkedList<T>::size() {
        return List<T>::_size;
    }

    template<typename T> void LinkedList<T>::begin() {
        _iterator = _head;
    }

    template<typename T> T LinkedList<T>::next() {
        T tmp = _iterator->data;
        _iterator = _iterator->next;

        return tmp;
    }

    template<typename T> bool LinkedList<T>::hasNext() {
        return (_iterator != NULL);
    }
}
