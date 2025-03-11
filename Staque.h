#include <iostream>
#include <math.h>
using namespace std;

typedef int StaqueElement;

class Staque {
    public:
        /***** Default Constructor *****/
        Staque();                        

        /***** Copy Constructor *****/
        Staque(const Staque& original);

        /***** Destructor *****/
        ~Staque();

        /***** Copy Assignment Operator *****/
        const Staque & operator=(const Staque & rightHandSide);

        /***** empty() -- checks if staque is empty *****/
        bool empty() const;
        
        /***** front() *****/
        StaqueElement front() const;

        /***** insert() *****/
        void insert(const StaqueElement & value);

        /***** removeEven() *****/
        void removeEven();

        /***** removeOdd() *****/
        void removeOdd();

        /***** Display Function *****/
        void display(ostream & out) const;

    private:
        /***** Node Class *****/
        class Node {
            public:
                StaqueElement data;
                Node* next;
                char frontOrBack;
                Node(StaqueElement value, Node* link = 0) { 
                    data = value; 
                    next = link; 
                }
        };

        typedef Node* NodePointer;
        NodePointer myFront;
        NodePointer myBack;
};






