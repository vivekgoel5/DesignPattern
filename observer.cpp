/**
 * Suppose you’re planning a trip and for that you want to create a group chat (subject) on Facebook Messenger and add your friends (observers) to this chat so that you all can send messages (state) in this group and plan everything out at once place rather than planning separately in DMs, which would be hard to keep track of for this usecase.
 * Ref: https://medium.com/@lokeshbihani99/observer-pattern-in-c-366a1e9226f6
 */

#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& newMessage) = 0;
};

// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject class
class GroupChat : public Subject {
private:
    vector<Observer*> observers;
    vector<string> messages;
public:
    void subscribe(Observer* observer) override {
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) override {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(messages.back());
        }
    }

    void sendMessage(const string& msg) {
        messages.push_back(msg);
        notify();
    }
};

// Concrete Observer class
class Friend : public Observer {
private:
    string name;
public:
    Friend(const string& n) : name(n) {}

    void update(const string& newMessage) override {
        cout << name << " received a message: " << newMessage << endl;
    }
};

int main() {
    GroupChat chat;

    Friend friend1("Alice");
    Friend friend2("Bob");
    Friend friend3("Charlie");

    chat.subscribe(&friend1);
    chat.subscribe(&friend2);
    chat.subscribe(&friend3);

    chat.sendMessage("Hey everyone, let's plan our trip!");

    return 0;
}
