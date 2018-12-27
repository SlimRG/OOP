#include "TStack.h"

template <class T, class TT> TStack<T, TT>::TStack()  {
	head = nullptr;
};

template <class T, class TT> void TStack<T, TT>::Push(std::shared_ptr<T> container) {
    std::shared_ptr < TStackItem <T> > item(new TStackItem<T>(container));
	item->SetNext(head);
	head = item;
    size++;
}

template <class T, class TT> void TStack<T, TT>::RemoveItemSq(IRemoveCriteria<double>* criteria) {
    for(auto i : *this) {
        T copy;
        while(!i->IsEmpty()) {
            std::shared_ptr<TT> value = i->Pop();
            double sq = value->Square();
            if(criteria->isIt(&sq)) {
                std::cout << "Delete item" << std::endl;
            } else {
                copy.Push(value);
            }
        }
        while(!copy.IsEmpty()) {
            i->Push(copy.Pop());
        }
    }
}

// template <class T, class TT> template <class A> void TStack<T, TT>::RemoveItemAll(IRemoveCriteriaAll<A>* criteria) {
//         for(auto i : *this) {
//         T copy;
//         while(!i->empty()) {
//             std::shared_ptr<TT> value = i->Pop();
//             if(criteria->isIt(&*value)) {
//                 std::cout << "Delete item" << std::endl;
//             } else {
//                 copy.Push(value);
//             }
//         }
//         while(!copy.empty()) {
//             i->Push(copy.Pop());
//         }
//     }
// }

template <class T, class TT> void TStack<T, TT>::Insert(std::shared_ptr<TT> obj) {
    bool inserted = false;
    if(head != nullptr) {
        for(auto i : *this) {
            if(i->size < 5) {
                i->Push(obj);
                inserted = true;
                break;
            }
        }
    }

    if(!inserted) {
        std::shared_ptr<T> cont = std::make_shared<T>();
        cont->Push(obj);
        Push(cont);
    }
}

template <class T, class TT> bool TStack<T, TT>::Empty() {
    return size == 0;
}

template <class T, class TT> void TStack<T, TT>::Pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		head = head->GetNext();
	}
}

template <class T, class TT> TStack<T, TT>::~TStack() {
}

template <class T, class TT> std::ostream &operator<<(std::ostream &os, TStack<T, TT> &stack) {
    if(stack.Empty()) {
        os << "Empty";
        return os;
    }
    std::shared_ptr< TStackItem<T> > item = stack.head;

	while (item != nullptr) {
		os << *item;
		item = item->GetNext();
	}

    return os;
}

template <class T, class TT> std::shared_ptr<T> TStack<T, TT>::Front() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetFigure();
    } else {
        result = nullptr;
    }
    return result;
}

template <class T, class TT> TIterator< TStackItem<T>, T > TStack<T, TT>::begin() {
    return TIterator< TStackItem<T>, T >(head);
}

template <class T, class TT> TIterator< TStackItem<T>, T > TStack<T, TT>::end() {
    return TIterator< TStackItem<T>, T >(nullptr);
}

template class TStack< TBTree<std::shared_ptr <Figure> >, Figure >;
template std::ostream &operator<<(std::ostream &os, TStack< TBTree<std::shared_ptr <Figure> >, Figure > &stack);
