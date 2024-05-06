#include <iostream> 
#include <cstdlib> // для rand() и srand() 
#include <ctime> // для time() 
#include <queue>
#include "queue.hpp"

using namespace std;

const int MIN_PER_HR = 60; 

bool newcustomer(double x) ; // появился ли новый клиент?

int main () {
    // Подготовка 
    srand(time(0)); // случайная инициализация rand() 
    cout << "Case Study: Bank of Heather Automatic Teller\n"; 
    cout << "Enter maximum size of queue: "; // ввод максимального размера очереди 
    int qs; 
    cin >> qs; 
    queue<Item> line; // очередь может содержать до qs людей 
    cout << "Enter the number of simulation hours: "; // ввод количества эмулируемых часов 
    int hours; // часы эмуляции 
    cin >> hours; 
    // Эмуляция будет запускать один цикл в минуту 
    long cyclelimit = MIN_PER_HR * hours; // количество циклов 
    cout << "Enter the average number of customers per hour: "; 
    // Ввод количества клиентов в час 
    double perhour; // среднее количество появлений за час 
    cin >> perhour; 
    double min_per_cust; // среднее время между появлениями 
    min_per_cust = MIN_PER_HR / perhour; 
    Item temp; // данные нового клиента 
    long turnaways = 0; // не допущены в полную очередь

    // присоединены к очереди 
    // обслужены во время эмуляции 
    // общая длина очереди 
    // время до освобождения банкомата 
    // общее время в очереди 
    long customers = 0; 
    long served = 0; 
    long sum_line = 0; 
    int wait_time = 0; 
    long line_wait = 0; 
    // Запуск моделирования 
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (line.size() > qs) 
                turnaways++; 
            else { 
                customers++;
                temp.set(cycle); 
                line.push(temp);  
            }
        } 
        if (wait_time <= 0 && !line.empty()) { 
            line.pop(); 
            wait_time = temp.ptime(); 
            line_wait += cycle - temp.when(); 
            served++;
        }
        // обслуживание следующего клиента 
        // в течение wait_time минут 
        if (wait_time > 0) 
            wait_time--; 
        sum_line += line.size(); 
    }
    // Вывод результатов 
    if (customers > 0) {
        // принято клиентов 
        // обслужено клиентов 
        // не принято клиентов 
        // средний размер очереди 
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl; 
        cout << " turnaways: " << turnaways << endl; 
        cout << "average queue size: "; 
        cout.precision (2); 
        cout.setf(ios_base::fixed, ios_base::floatfield); 
        cout << (double) sum_line / cyclelimit << endl; 
        cout << " average wait time: " // среднее время ожидания (минут) 
        << (double) line_wait / served << " minutes\n";
    } 
    else 
        cout << "No customers! \n"; 
    cout << "Done!\n"; 
    return 0;
}
// клиентов нет 
// x = среднее время в минутах между клиентами 
// возвращается значение true, если в эту минуту появляется клиент 
bool newcustomer(double x) {
    return (rand() * x / RAND_MAX < 1);
}