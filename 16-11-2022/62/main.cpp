#include <iostream>

using namespace std;


/* Класс Account
 *
 * Вложенный класс Date
 * Поля даты
 * Считает количество дней между двумя датами
 *
 * Баланс
 * Дата открытия счёта
 * Увеличение на 0.01% в день от переданной даты
 */

class Account {
public:
    class Date {
        int day;
        int month;
        int year;
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
        
        int getDay() const {
            return day;
        }
        
        int getMonth() const {
            return month;
        }
        
        int getYear() const {
            return year;
        }
        
        int daysBetween(const Date &date) const {
            int days = 0;
            int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int daysInMonthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int *daysInMonthPtr = daysInMonth;
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                daysInMonthPtr = daysInMonthLeap;
            if (year == date.getYear()) {
                if (month == date.getMonth()) {
                    days = day - date.getDay();
                } else {
                    for (int i = month; i < date.getMonth(); i++) {
                        days += daysInMonthPtr[i];
                    }
                    days += day;
                    days -= date.getDay();
                }
            } else {
                for (int i = month; i < 12; i++) {
                    days += daysInMonthPtr[i];
                }
                days += day;
                for (int i = 0; i < date.getMonth(); i++) {
                    days += daysInMonthPtr[i];
                }
                days += date.getDay();
            }
            return days;
        }
    };
    
    Account(double b, int d, int m, int y) : balance(b), date(d, m, y) {}
    
    double getBalance() const {
        return balance;
    }
    
    void increaseBalance(const Date &date) {
        int days = date.daysBetween(this->date);
        for (int i = 0; i < days; i++) {
            balance += balance * 0.0001;
        }
    }

private:
    Date date;
    double balance;
};

int main() {
    double balance;
    int day, month, year;
    cout << "Введите баланс: ";
    cin >> balance;
    cout << "Введите дату открытия счёта (день месяц год): ";
    cin >> day >> month >> year;
    Account account(balance, day, month, year);
    cout << "Введите дату (день месяц год): ";
    cin >> day >> month >> year;
    account.increaseBalance(Account::Date(day, month, year));
    cout << "Баланс: " << account.getBalance() << endl;
    return 0;
}

