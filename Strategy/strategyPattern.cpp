#include <iostream>
#include <list> 

using namespace std;

class SortBehavior{
    public:
        virtual void sort() const = 0;
};

class Merge : public SortBehavior{
    public:
        virtual void sort() const override{
            cout << "\nMergeSort activated!!";
        }
};

class Quick : public SortBehavior{
    public:
        virtual void sort() const override{
            cout << "\nQuickSort activated!!";
        }
};

class Bubble : public SortBehavior{
    public:
        virtual void sort() const override{
            cout << "\nBubbleSort activated!!";
        }
};


class SearchBehavior{
    public:
        virtual void search() const = 0;
};

class Sequential: public SearchBehavior{
    public:
        virtual void search() const override{
            cout << "\nSequential search activated!!";
        };
};

class BinaryTree: public SearchBehavior{
    public:
        virtual void search() const override{
            cout << "\nBinaryTree search activated!!";
        };
};

class Hashtable: public SearchBehavior{
    public:
        virtual void search() const override{
            cout << "\nHashtable search activated!!";
        };
};

class Collection{
    private:
        SortBehavior* sort;
        SearchBehavior* search;
    public:
        Collection(){}
        
        void setSort(SortBehavior* sort){ this->sort = sort; }
        void setSearch(SearchBehavior* search){ 
            this->search = search; 
        }
        
        void print() const { 
            sort->sort(); 
            search->search();
        }
};

int main()
{
    Merge m; Quick q; Bubble b;
    
    Sequential s; BinaryTree bt; Hashtable ht;
    
    Collection collector1;
    collector1.setSort(&q);
    collector1.setSearch(&bt);
    
    
    Collection collector2;
    collector2.setSort(&b);
    collector2.setSearch(&ht);
    
    collector1.print();
    cout << endl;
    collector2.print();
    
    return 0;
}

