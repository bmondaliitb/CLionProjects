#include <iostream>
#include "thread"
#include "vector"
#include "mutex"
#include "unordered_set"

class Error{
public:
   std::unordered_set<unsigned int >  Error;
   mutable std::atomic<unsigned int> count{};
   void add(unsigned int value)
   {
       std::lock_guard<std::mutex> lock(m_mutex);
       Error.insert(value);
       count=count+1;
   }
private:
    mutable std::mutex m_mutex; // !< To guard m_numTruthPassedCuts
};


class Container
{
public:
    template<class T>
    void add(T obj, unsigned int data)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        // addition of data
        obj.push_back(data);
    }
    /*
    double get(int which)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        // getting copy of value
        return ROB.at(which);
    }
     */
    void remove(size_t which)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        // delete specified object
    }

    template<class T>
    void print(T obj)
    {
        for (auto & data : obj)
            std::cout<<data<<std::endl;
    }
public:
    std::vector<unsigned int> ROB1;
    std::vector<unsigned int> ROB2;
private:
    std::mutex m_mutex;
};

int main() {
    Container counter;

    auto increment_and_print = [&counter]() {
        for (int i = 0; i < 100; i++) {

            counter.add<>(counter.ROB1, i);
            std::cout << std::this_thread::get_id() << '\t' << /*counter.get(i) <<*/ '\n';

            // Note: Writing to std::cout actually needs to be synchronized as well
            // by another std::mutex. This has been omitted to keep the example small.
        }
    };

    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);

    thread1.join();
    thread2.join();

    std::cout<<"-------------------------"<<std::endl;
    counter.print(counter.ROB1);
    Error error1;
    Error error2;
    return 0;
}
