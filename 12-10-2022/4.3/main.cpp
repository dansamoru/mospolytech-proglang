#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Airport {
    string flight_number;
    string departure_name;
    string arrival_name;
    string plane_type;
    unsigned int seats_number{};
};

int main() {
    vector <Airport> airports = {
            Airport{
                    "B103",
                    "UUEE",
                    "UWGG",
                    "SU95",
                    98,
            }, Airport{
                    "B110",
                    "UUEE",
                    "ULLI",
                    "A320",
                    158,
            }, Airport{
                    "B116",
                    "UUEE",
                    "URMM",
                    "A321",
                    236,
            }, Airport{
                    "B102",
                    "UUEE",
                    "UNNT",
                    "A320",
                    158,
            }, Airport{
                    "B118",
                    "UUEE",
                    "URSS",
                    "A321",
                    236,
            }};
    
    unsigned short int command = 3;
    cout << "Рейсовый менеджер" << endl;
    cout << "############################" << endl;
    cout << "#    Доступные команды:    #" << endl;
    cout << "#                          #" << endl;
    cout << "# 0 - выход                #" << endl;
    cout << "# 1 - ввести новый элемент #" << endl;
    cout << "# 2 - сортировать          #" << endl;
    cout << "#                          #" << endl;
    cout << "############################" << endl;
    cout << endl << ">>> Введите номер команды: ";
    cin >> command;
    while (command != 0) {
        switch (command) {
            case 1: {
                airports.emplace_back();
                cout << "\n############################\n# Ввод нового элемента:\n#\n";
                cout << ">>> номер рейса: ";
                cin >> airports[airports.size() - 1].flight_number;
                cout << ">>> точка отправления: ";
                cin >> airports[airports.size() - 1].departure_name;
                cout << ">>> точка прибытия: ";
                cin >> airports[airports.size() - 1].arrival_name;
                cout << ">>> тип самолёта: ";
                cin >> airports[airports.size() - 1].plane_type;
                cout << ">>> количество мест: ";
                cin >> airports[airports.size() - 1].seats_number;
                cout << "#\n############################\n\n";
                break;
            }
            case 2: {
                cout << "\n############################\n# Сортировка по типу самолёта:\n#\n";
                cout << ">>> тип самолёта: ";
                string tmp_plane_type;
                cin >> tmp_plane_type;
                vector <string> tmp_ans_arr(0);
                for (int i = 0; i < airports.size(); ++i) {
                    if (airports[i].plane_type == tmp_plane_type) {
                        tmp_ans_arr.push_back(airports[i].arrival_name + ": " +
                                              airports[i].flight_number);
                    }
                }
                sort(tmp_ans_arr.begin(), tmp_ans_arr.end());
                
                cout << "#\n";
                for (int i = 0; i < tmp_ans_arr.size(); ++i) {
                    cout << "# " << tmp_ans_arr[i] << endl;
                }
                cout << "############################" << endl << endl;
                
                break;
            }
            default:
                cout << "\n#\n# Команда не найдена!\n#\n\n";
        }
        cout << ">>> Введите номер команды: ";
        cin >> command;
    }
    
    return 0;
}
