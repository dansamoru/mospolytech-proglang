#include <iostream>
#include <cmath>

using namespace std;

/* Структура struct_ModelWindow
 *
 * Заголовок окна
 * Координаты левого верхнего угла окна
 * Размер по горизонтали
 * Размер по вертикали
 * Цвет окна
 * Состояние "Видимое/Невидимое"
 * Состояние "С рамкой/Без рамки"
 *
 */

struct struct_ModelWindow {
    string title;
    int x;
    int y;
    int width;
    int height;
    string color;
    bool visible;
    bool framed;
};

/* Функции для структуры struct_ModelWindow
 *
 * метод инициализации init
 * ввод с клавиатуры read
 * вывод на экран display
 * преобразование в строку toString
 *
 * передвижение окна по горизонтали с проверкой на выход за границы экрана
 * передвижение окна по вертикали с проверкой на выход за границы экрана
 * изменение размера окна по горизонтали с проверкой на выход за границы экрана
 * изменение размера окна по вертикали с проверкой на выход за границы экрана
 * изменение цвета окна
 * изменение состояния "Видимое/Невидимое"
 * изменение состояния "С рамкой/Без рамки"
 * опрос состояния "Видимое/Невидимое"
 * опрос состояния "С рамкой/Без рамки"
 *
 *
 */

void init(struct_ModelWindow &window, string title, int x, int y, int width, int height, string color, bool visible,
          bool framed) {
    window.title = title;
    window.x = x;
    window.y = y;
    window.width = width;
    window.height = height;
    window.color = color;
    window.visible = visible;
    window.framed = framed;
}

void read(struct_ModelWindow &window) {
    cout << "Введите заголовок окна: ";
    cin >> window.title;
    cout << "Введите координаты левого верхнего угла окна: ";
    cin >> window.x >> window.y;
    cout << "Введите размеры окна: ";
    cin >> window.width >> window.height;
    cout << "Введите цвет окна: ";
    cin >> window.color;
    cout << "Введите состояние \"Видимое/Невидимое\": ";
    cin >> window.visible;
    cout << "Введите состояние \"С рамкой/Без рамки\": ";
    cin >> window.framed;
}

void display(struct_ModelWindow &window) {
    cout << "Заголовок окна: " << window.title << endl;
    cout << "Координаты левого верхнего угла окна: " << window.x << " " << window.y << endl;
    cout << "Размеры окна: " << window.width << " " << window.height << endl;
    cout << "Цвет окна: " << window.color << endl;
    cout << "Состояние \"Видимое/Невидимое\": " << window.visible << endl;
    cout << "Состояние \"С рамкой/Без рамки\": " << window.framed << endl;
}

string toString(struct_ModelWindow &window) {
    string str;
    str += "Заголовок окна: " + window.title;
    str += "Координаты левого верхнего угла окна: " + to_string(window.x) + " " + to_string(window.y);
    str += "Размеры окна: " + to_string(window.width) + " " + to_string(window.height);
    str += "Цвет окна: " + window.color;
    str += "Состояние \"Видимое/Невидимое\": " + to_string(window.visible);
    str += "Состояние \"С рамкой/Без рамки\": " + to_string(window.framed);
    return str;
}

void moveHorizontal(struct_ModelWindow &window, int dx) {
    if (window.x + dx < 0) {
        window.x = 0;
    } else if (window.x + dx + window.width > 80) {
        window.x = 80 - window.width;
    } else {
        window.x += dx;
    }
}

void moveVertical(struct_ModelWindow &window, int dy) {
    if (window.y + dy < 0) {
        window.y = 0;
    } else if (window.y + dy + window.height > 25) {
        window.y = 25 - window.height;
    } else {
        window.y += dy;
    }
}

void resizeHorizontal(struct_ModelWindow &window, int dx) {
    if (window.width + dx < 0) {
        window.width = 0;
    } else if (window.x + window.width + dx > 80) {
        window.width = 80 - window.x;
    } else {
        window.width += dx;
    }
}

void resizeVertical(struct_ModelWindow &window, int dy) {
    if (window.height + dy < 0) {
        window.height = 0;
    } else if (window.y + window.height + dy > 25) {
        window.height = 25 - window.y;
    } else {
        window.height += dy;
    }
}

void changeColor(struct_ModelWindow &window, string color) {
    window.color = color;
}

void changeVisible(struct_ModelWindow &window, bool visible) {
    window.visible = visible;
}

void changeFramed(struct_ModelWindow &window, bool framed) {
    window.framed = framed;
}

bool isVisible(struct_ModelWindow &window) {
    return window.visible;
}

bool isFramed(struct_ModelWindow &window) {
    return window.framed;
}


/* Класс class_ModelWindow
 *
 * Заголовок окна
 * Координаты левого верхнего угла окна
 * Размер по горизонтали
 * Размер по вертикали
 * Цвет окна
 * Состояние "Видимое/Невидимое"
 * Состояние "С рамкой/Без рамки"
 *
 * метод инициализации init
 * ввод с клавиатуры read
 * вывод на экран display
 * преобразование в строку toString
 *
 * передвижение окна по горизонтали с проверкой на выход за границы экрана
 * передвижение окна по вертикали с проверкой на выход за границы экрана
 * изменение размера окна по горизонтали с проверкой на выход за границы экрана
 * изменение размера окна по вертикали с проверкой на выход за границы экрана
 * изменение цвета окна
 * изменение состояния "Видимое/Невидимое"
 * изменение состояния "С рамкой/Без рамки"
 * опрос состояния "Видимое/Невидимое"
 * опрос состояния "С рамкой/Без рамки"
 *
 */

class class_ModelWindow {
private:
    string title;
    int x;
    int y;
    int width;
    int height;
    string color;
    bool visible;
    bool framed;
public:
    void init(string title, int x, int y, int width, int height, string color, bool visible, bool framed) {
        this->title = title;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->color = color;
        this->visible = visible;
        this->framed = framed;
    }
    
    void read() {
        cout << "Заголовок окна: ";
        cin >> this->title;
        cout << "Координаты левого верхнего угла окна: ";
        cin >> this->x >> this->y;
        cout << "Размер по горизонтали: ";
        cin >> this->width;
        cout << "Размер по вертикали: ";
        cin >> this->height;
        cout << "Цвет окна: ";
        cin >> this->color;
        cout << "Состояние \"Видимое/Невидимое\": ";
        cin >> this->visible;
        cout << "Состояние \"С рамкой/Без рамки\": ";
        cin >> this->framed;
    }
    
    void display() {
        cout << "Заголовок окна: " << this->title << endl;
        cout << "Координаты левого верхнего угла окна: " << this->x << " " << this->y << endl;
        cout << "Размер по горизонтали: " << this->width << endl;
        cout << "Размер по вертикали: " << this->height << endl;
        cout << "Цвет окна: " << this->color << endl;
        cout << "Состояние \"Видимое/Невидимое\": " << this->visible << endl;
        cout << "Состояние \"С рамкой/Без рамки\": " << this->framed << endl;
    }
    
    string toString() {
        string str;
        str += "Заголовок окна: " + this->title + "\n";
        str += "Координаты левого верхнего угла окна: " + to_string(this->x) + " " + to_string(this->y) + "\n";
        str += "Размер по горизонтали: " + to_string(this->width) + "\n";
        str += "Размер по вертикали: " + to_string(this->height) + "\n";
        str += "Цвет окна: " + this->color + "\n";
        str += "Состояние \"Видимое/Невидимое\": " + to_string(this->visible) + "\n";
        str += "Состояние \"С рамкой/Без рамки\": " + to_string(this->framed) + "\n";
        return str;
    }
    
    void moveHorizontal(int dx) {
        if (this->x + dx >= 0 && this->x + dx + this->width <= 80) {
            this->x += dx;
        }
    }
    
    void moveVertical(int dy) {
        if (this->y + dy >= 0 && this->y + dy + this->height <= 25) {
            this->y += dy;
        }
    }
    
    void resizeHorizontal(int dw) {
        if (this->x + this->width + dw >= 0 && this->x + this->width + dw <= 80) {
            this->width += dw;
        }
    }
    
    void resizeVertical(int dh) {
        if (this->y + this->height + dh >= 0 && this->y + this->height + dh <= 25) {
            this->height += dh;
        }
    }
    
    void changeColor(string color) {
        this->color = color;
    }
    
    void changeVisible(bool visible) {
        this->visible = visible;
    }
    
    void changeFramed(bool framed) {
        this->framed = framed;
    }
    
    bool isVisible() {
        return this->visible;
    }
    
    bool isFramed() {
        return this->framed;
    }
};


/* Структура incapstruct_ModelWindow
 * Заголовок окна
 * Координаты левого верхнего угла окна
 * Размер по горизонтали
 * Размер по вертикали
 * Цвет окна
 * Состояние "Видимое/Невидимое"
 * Состояние "С рамкой/Без рамки"
 *
 * метод инициализации init
 * ввод с клавиатуры read
 * вывод на экран display
 * преобразование в строку toString
 */

struct incapstruct_ModelWindow {
    string title;
    int x{};
    int y{};
    int width{};
    int height{};
    string color;
    bool visible{};
    bool framed{};
    
    void init(string title, int x, int y, int width, int height, string color, bool visible, bool framed) {
        this->title = title;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->color = color;
        this->visible = visible;
        this->framed = framed;
    }
    
    void read() {
        cout << "Заголовок окна: ";
        cin >> this->title;
        cout << "Координаты левого верхнего угла окна: ";
        cin >> this->x >> this->y;
        cout << "Размер по горизонтали: ";
        cin >> this->width;
        cout << "Размер по вертикали: ";
        cin >> this->height;
        cout << "Цвет окна: ";
        cin >> this->color;
        cout << "Состояние \"Видимое/Невидимое\": ";
        cin >> this->visible;
        cout << "Состояние \"С рамкой/Без рамки\": ";
        cin >> this->framed;
    }
    
    void display() const {
        cout << "Заголовок окна: " << this->title << endl;
        cout << "Координаты левого верхнего угла окна: " << this->x << " " << this->y << endl;
        cout << "Размер по горизонтали: " << this->width << endl;
        cout << "Размер по вертикали: " << this->height << endl;
        cout << "Цвет окна: " << this->color << endl;
        cout << "Состояние \"Видимое/Невидимое\": " << this->visible << endl;
        cout << "Состояние \"С рамкой/Без рамки\": " << this->framed << endl;
    }
    
    string toString() const {
        string str = "";
        str += "Заголовок окна: " + this->title + "\n";
        str += "Координаты левого верхнего угла окна: " + to_string(this->x) + " " + to_string(this->y) + "\n";
        str += "Размер по горизонтали: " + to_string(this->width) + "\n";
        str += "Размер по вертикали: " + to_string(this->height) + "\n";
        str += "Цвет окна: " + this->color + "\n";
        str += "Состояние \"Видимое/Невидимое\": " + to_string(this->visible) + "\n";
        str += "Состояние \"С рамкой/Без рамки\": " + to_string(this->framed) + "\n";
        return str;
    }
};

/* Класс incapclass_ModelWindow
 * Объект incapstruct_ModelWindow с публичными методами
 */

class incapclass_ModelWindow {
    incapstruct_ModelWindow window;

public:
    void init(string title, int x, int y, int width, int height, string color, bool visible, bool framed) {
        this->window.init(title, x, y, width, height, color, visible, framed);
    }
    
    void read() {
        this->window.read();
    }
    
    void display() {
        this->window.display();
    }
    
    string toString() {
        return this->window.toString();
    }
};


int main() {
    // Работа с struct_ModelWindow
    struct_ModelWindow window1;
    init(window1, "Окно 1", 10, 10, 100, 100, "Красный", true, true);
    display(window1);
    cout << "Структура" << toString(window1) << endl << endl;
    
    // Работа с class_ModelWindow
    class_ModelWindow window2;
    window2.init("Окно 2", 20, 20, 200, 200, "Зеленый", false, false);
    window2.display();
    cout << "Класс" << window2.toString() << endl << endl;
    
    // Работа с incapstruct_ModelWindow
    incapstruct_ModelWindow window3;
    window3.init("Окно 3", 30, 30, 300, 300, "Синий", true, false);
    window3.display();
    cout << "Инкапсуляция" << window3.toString() << endl << endl;
}