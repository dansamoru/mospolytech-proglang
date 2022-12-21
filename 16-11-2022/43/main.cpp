#include <iostream>

using namespace std;

/* Класс Date
 * Поля даты
 * Считает количество дней между двумя датами
 */

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    
    int GetYear() const {
        return year;
    }
    
    int GetMonth() const {
        return month;
    }
    
    int GetDay() const {
        return day;
    }
};

/* Класс Account
 * Баланс
 * Дата открытия счёта
 * Увеличение на 0.01% в день от переданной даты
 */

class Account {
private:
    Date open;
    double balance;
public:
    Account(Date date, double balance) : open(date.GetYear(), date.GetMonth(), date.GetDay()) {
        this->balance = balance;
    }
    
    double GetBalance() const {
        return balance;
    }
    
    void UpdateBalance(Date date) {
        int days = 0;
        int year = date.GetYear() - open.GetYear();
        int month = date.GetMonth() - open.GetMonth();
        int day = date.GetDay() - open.GetDay();
        if (day < 0) {
            month--;
            day += 30;
        }
        if (month < 0) {
            year--;
            month += 12;
        }
        days = year * 365 + month * 30 + day;
        for (int i = 0; i < days; i++) {
            balance += balance * 0.0001;
        }
    }
};

int main() {
    int year, month, day;
    double balance;
    cin >> year >> month >> day >> balance;
    Date date(year, month, day);
    Account account(date, balance);
    cin >> year >> month >> day;
    date = Date(year, month, day);
    account.UpdateBalance(date);
    cout << account.GetBalance();
    return 0;
}