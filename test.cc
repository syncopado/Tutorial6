#include <istream>
#include <string>
#include <X11/Xlib.h>
#include "Tester.h"
#include "Component.h"
#include "ComponentList.h"

using namespace std;

Tester tester;

class TestComponent: public Component{
    public:
        TestComponent(int x, int y, int width, int height, const string& id): Component(x, y, width, height, id){};
        TestComponent(const Rectangle& rect, const string& id): Component(rect, id){};
        void draw(Display *display, Window win, GC gc, const Rectangle& box){
            cout<<"Drawing TestComponent: "<<id<<endl;
        }

        void print() const{
            cout<<"TestComponent: "<<id<<endl;
        }
};


int testAddBack();
int testAddIndex();
int testRemoveIndex();
int testRemoveId();

int main(){

    int choice = 0;
    cout << "Which test would you like to run?"<< endl;
    cout << "  (0) Test add back." << endl;
    cout << "  (1) Test add at index" <<endl;
    cout << "  (2) Test remove index" <<endl;
    cout << "  (3) Test remove id" <<endl;
    cout << "Enter the number of the test you would like to run: ";
    cin >> choice;
    int ret = 0;
    switch(choice){
        case 0: ret = testAddBack(); break;
        case 1: ret = testAddIndex(); break;
        case 2: ret = testRemoveIndex(); break;
        case 3: ret = testRemoveId(); break;
    }

    return ret;
  
}

int testAddBack(){

    vector<string> ids = {"TestComponent 0", "TestComponent 1", "TestComponent 2", "TestComponent 3", "TestComponent 4", "TestComponent 5"};
    ComponentList* list = new ComponentList;
    TestComponent* panel0  = new TestComponent(10, 10, 80, 50, "TestComponent 0");
    TestComponent* panel1  = new TestComponent(10, 50, 80, 50, "TestComponent 1");
    TestComponent* panel2  = new TestComponent(10, 60, 80, 50, "TestComponent 2");
    TestComponent* panel3  = new TestComponent(90, 60, 80, 50, "TestComponent 3");
    TestComponent* panel4  = new TestComponent(100, 60, 80, 50, "TestComponent 4");
    TestComponent* panel5  = new TestComponent(100, 180, 450, 50, "TestComponent 5");

    cout<<"Testing add at back"<<endl<<endl;
    list->add(panel1);
    list->add(panel4);
    list->add(panel3);
    list->add(panel2);
    list->add(panel5);
    list->add(panel0);
    

    tester.initCapture();
    for (int i = 0; i < list->getSize(); i++){
        list->get(i)->print();
    }
    tester.endCapture();

    int error = 0;
    tester.findInOrder({1, 4, 3, 2, 5, 0}, ids, error);

    if (error == 0){
        cout<<"Correct Components found in order"<<endl;
    }else{
        cout<<"Not all Components found in order, test failed"<<endl;
        return 1;
    }

    
    cout<<"Test add back passed"<<endl;
    
    return 0;
}


int testAddIndex(){
    vector<string> ids = {"TestComponent 0", "TestComponent 1", "TestComponent 2", "TestComponent 3", "TestComponent 4", "TestComponent 5"};
    ComponentList* list = new ComponentList;
    TestComponent* panel0  = new TestComponent(10, 10, 80, 50, "TestComponent 0");
    TestComponent* panel1  = new TestComponent(10, 50, 80, 50, "TestComponent 1");
    TestComponent* panel2  = new TestComponent(10, 60, 80, 50, "TestComponent 2");
    TestComponent* panel3  = new TestComponent(90, 60, 80, 50, "TestComponent 3");
    TestComponent* panel4  = new TestComponent(100, 60, 80, 50, "TestComponent 4");
    TestComponent* panel5  = new TestComponent(100, 180, 450, 50, "TestComponent 5");

    cout<<"Testing add at back"<<endl<<endl;
    if (!list->add(panel0, 0)){
        cout<<"Failed to add panel0"<<endl;
        return 1;
    }
    if (!list->add(panel1, 1)){
        cout<<"Failed to add panel1"<<endl;
        return 1;
    }
    if (!list->add(panel2, 0)){
        cout<<"Failed to add panel2"<<endl;
        return 1;
    }
    if (!list->add(panel3, 1)){
        cout<<"Failed to add panel3"<<endl;
        return 1;
    }
    if (!list->add(panel4, 4)){
        cout<<"Failed to add panel4"<<endl;
        return 1;
    }
    if (!list->add(panel5, 0)){
        cout<<"Failed to add panel5"<<endl;
        return 1;
    }
    

    tester.initCapture();
    for (int i = 0; i < list->getSize(); i++){
        list->get(i)->print();
    }
    tester.endCapture();

    int error = 0;
    tester.findInOrder({5,2,3,0,1,4}, ids, error);

    if (error == 0){
        cout<<"Correct Components found in correct order"<<endl;
    }else{
        cout<<"Not all Components found in order, test failed"<<endl;
        return 1;
    }

    
    cout<<"Test add back passed"<<endl;

    return 0;

}

int testRemoveIndex(){

    vector<string> ids = {"TestComponent 0", "TestComponent 1", "TestComponent 2", "TestComponent 3", "TestComponent 4", "TestComponent 5"};
    ComponentList* list = new ComponentList;
    TestComponent* panel0  = new TestComponent(10, 10, 80, 50, "TestComponent 0");
    TestComponent* panel1  = new TestComponent(10, 50, 80, 50, "TestComponent 1");
    TestComponent* panel2  = new TestComponent(10, 60, 80, 50, "TestComponent 2");
    TestComponent* panel3  = new TestComponent(90, 60, 80, 50, "TestComponent 3");
    TestComponent* panel4  = new TestComponent(100, 60, 80, 50, "TestComponent 4");
    TestComponent* panel5  = new TestComponent(100, 180, 450, 50, "TestComponent 5");

    cout<<"Testing remove at index"<<endl<<endl;
    list->add(panel0);
    list->add(panel1);
    list->add(panel2);
    list->add(panel3);
    list->add(panel4);
    list->add(panel5);

    list->remove(0);
    list->remove(4);
    list->remove(2);
    

    tester.initCapture();
    for (int i = 0; i < list->getSize(); i++){
        list->get(i)->print();
    }
    tester.endCapture();

    int error = 0;
    tester.findInOrder({1, 2, 4}, ids, error);

    if (error == 0){
        cout<<"Correct Components found in order"<<endl;
    }else{
        cout<<"Not all Components found in order, test failed"<<endl;
        return 1;
    }

    error = 0;
    tester.confirmAbsent({0, 3, 5}, ids, error);

    if (error == 0){
        cout<<"Correct Components removed"<<endl;
    }else{
        cout<<"Not all Components removed, test failed"<<endl;
        return 1;
    }

    int size = list->getSize();
    cout<<"Removing invalid index"<<endl;
    list->remove(5);
    if (list->getSize() != size){
        cout<<"Remove invalid index caused decrease in size"<<endl;
        return 1;
    }


    cout<<"Testing remove all"<<endl;

    while(list->getSize() > 0){
        list->remove(0);
    }

    cout<<"Adding back"<<endl;
    list->add(panel0);
    list->add(panel1);
    list->add(panel2);

    tester.initCapture();
    for (int i = 0; i < list->getSize(); i++){
        list->get(i)->print();
    }
    tester.endCapture();

    error = 0;
    tester.findInOrder({0, 1, 2}, ids, error);

    if (error == 0){
        cout<<"Correct Components found in order"<<endl;
    }else{
        cout<<"Not all Components found in order, test failed"<<endl;
        return 1;
    }
    
    cout<<"Test remove index passed"<<endl;
    
    return 0;
}

int testRemoveId(){

    vector<string> ids = {"TestComponent 0", "TestComponent 1", "TestComponent 2", "TestComponent 3", "TestComponent 4", "TestComponent 5"};
    ComponentList* list = new ComponentList;
    TestComponent* panel0  = new TestComponent(10, 10, 80, 50, "TestComponent 0");
    TestComponent* panel1  = new TestComponent(10, 50, 80, 50, "TestComponent 1");
    TestComponent* panel2  = new TestComponent(10, 60, 80, 50, "TestComponent 2");
    TestComponent* panel3  = new TestComponent(90, 60, 80, 50, "TestComponent 3");
    TestComponent* panel4  = new TestComponent(100, 60, 80, 50, "TestComponent 4");
    TestComponent* panel5  = new TestComponent(100, 180, 450, 50, "TestComponent 5");

    cout<<"Testing remove by id"<<endl<<endl;
    list->add(panel0);
    list->add(panel1);
    list->add(panel2);
    list->add(panel3);
    list->add(panel4);
    list->add(panel5);

    list->remove(ids[0]);
    list->remove(ids[4]);
    list->remove(ids[2]);
    

    tester.initCapture();
    for (int i = 0; i < list->getSize(); i++){
        list->get(i)->print();
    }
    tester.endCapture();

    int error = 0;
    tester.findInOrder({1, 3, 5}, ids, error);

    if (error == 0){
        cout<<"Correct Components found in order"<<endl;
    }else{
        cout<<"Not all Components found in order, test failed"<<endl;
        return 1;
    }

    error = 0;
    tester.confirmAbsent({0, 2, 4}, ids, error);

    if (error == 0){
        cout<<"Correct Components removed"<<endl;
    }else{
        cout<<"Not all Components removed, test failed"<<endl;
        return 1;
    }


    int size = list->getSize();
    cout<<"Removing invalid id"<<endl;
    list->remove("Invalid id");
    if (list->getSize() != size){
        cout<<"Remove invalid id caused decrease in size"<<endl;
        return 1;
    }


    cout<<"Testing remove all"<<endl;

    list->remove(ids[1]);
    list->remove(ids[3]);
    list->remove(ids[5]);

    if (list->getSize() > 0){
        cout<<"Failed to remove all components"<<endl;
        return 1;
    }

    cout<<"Adding back"<<endl;
    list->add(panel0);
    list->add(panel1);
    list->add(panel2);

    cout<<"Testing get by id"<<endl;

    tester.initCapture();
    for (int i = 0; i < list->getSize(); i++){
        list->get(ids[i])->print();
    }
    tester.endCapture();

    error = 0;
    tester.findInOrder({0, 1, 2}, ids, error);

    if (error == 0){
        cout<<"Correct Components found in order"<<endl;
    }else{
        cout<<"Not all Components found in order, test failed"<<endl;
        return 1;
    }
    
    cout<<"Test remove index passed"<<endl;
    
    return 0;
}







