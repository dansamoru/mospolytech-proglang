#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const unsigned short int SIZE = 5;

struct Airport {
    char flight_number[SIZE * 2]{};
    char departure_name[SIZE]{};
    char arrival_name[SIZE]{};
    char plane_type[SIZE]{};
    unsigned int seats_number{};
};

int main() {
    unsigned int airports_size = 5;
    auto *airports = (Airport *) malloc(sizeof(Airport) * airports_size);
    
    airports[0] = Airport{
            "SU1110",
            "UUEE",
            "URSS",
            "A320",
            158,
    };
    airports[1] = Airport{
            "SU1522",
            "UUEE",
            "USMU",
            "A320",
            158,
    };
    airports[2] = Airport{
            "SU1304",
            "UUEE",
            "URMM",
            "A321",
            236,
    };
    airports[3] = Airport{
            "SU1134",
            "UUEE",
            "URSS",
            "A350",
            316,
    };
    airports[4] = Airport{
            "SU006",
            "UUEE",
            "ULLI",
            "A321",
            236,
    };
    
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
                airports = (Airport *) realloc(airports, sizeof(Airport) * (airports_size + 1));
                
                cout << "\n############################\n# Ввод нового элемента:\n#\n";
                cout << ">>> номер рейса: ";
                cin >> airports[airports_size].flight_number;
                cout << ">>> точка отправления: ";
                cin >> airports[airports_size].departure_name;
                cout << ">>> точка прибытия: ";
                cin >> airports[airports_size].arrival_name;
                cout << ">>> тип самолёта: ";
                cin >> airports[airports_size].plane_type;
                cout << ">>> количество мест: ";
                cin >> airports[airports_size].seats_number;
                cout << "#\n############################\n\n";
                
                airports_size++;
                break;
            }
            case 2: {
                cout << "\n############################\n# Сортировка по типу самолёта:\n#\n";
                cout << ">>> тип самолёта: ";
                char tmp_plane_type[SIZE];
                cin >> tmp_plane_type;
                auto **tmp_ans_arr = (char **) malloc(0);
                int tmp_ans_arr_size = 0;
                for (int i = 0; i < airports_size; ++i) {
                    if (strcmp(airports[i].plane_type, tmp_plane_type) == 0) {
                        tmp_ans_arr = (char **) realloc(tmp_ans_arr, sizeof(char *) * (tmp_ans_arr_size + 1));
                        tmp_ans_arr[tmp_ans_arr_size] = (char *) malloc(sizeof(char) * (SIZE * 3 + 2));
                        snprintf(tmp_ans_arr[tmp_ans_arr_size], sizeof(char) * (SIZE * 3 + 2),
                                 "%s: %s", airports[i].arrival_name, airports[i].flight_number);
                        tmp_ans_arr_size++;
                    }
                }
                
                int m;
                for (int i = 0; i < tmp_ans_arr_size; ++i) {
                    m = i;
                    for (int j = i; j < tmp_ans_arr_size; ++j) {
                        if (strcmp(tmp_ans_arr[i], tmp_ans_arr[j]) > 0) {
                            m = j;
                        }
                    }
                    auto tmp = tmp_ans_arr[i];
                    tmp_ans_arr[i] = tmp_ans_arr[m];
                    tmp_ans_arr[m] = tmp;
                }
                
                cout << "#\n";
                for (int i = 0; i < tmp_ans_arr_size; ++i) {
                    cout << "# " << tmp_ans_arr[i] << endl;
                    delete[] tmp_ans_arr[i];
                }
                cout << "############################" << endl << endl;
                delete[] tmp_ans_arr;
                break;
            }
            default:
                cout << "\n#\n# Команда не найдена!\n#\n\n";
        }
        cout << ">>> Введите номер команды: ";
        cin >> command;
    }
    delete[] airports;
    
    return 0;
}
