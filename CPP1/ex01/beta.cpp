
#include <iostream>
#include <iomanip>
#include <string>

#define MAX_CONTACTS 8

class Contact {
private: //el que un atributo sea privado o publico determina cómo puede ser accedido y modificado desde fuera de la clase. Los publicos se pueden acceder directamente, los privados no. Si se necesita acceder o modificar un atributo privado desde fuera de la clase, se suelen proporcionar métodos públicos (getter y setter) para hacerlo de manera controlada.
// Getter: Es un método que permite obtener (leer) el valor de un atributo privado de la clase. Generalmente, los getters son métodos constantes, ya que no modifican el estado de la clase.
// Setter: Es un método que permite modificar el valor de un atributo privado de la clase. Los setters normalmente incluyen algún tipo de validación para asegurar que el valor que se va a asignar sea válido.
	
	std::string firstName; //std::string practicamente sustituye a char * en C++; Solo usamos C cuando estamos muy concienciados con el rendimiento en operacioes de bajo nivel o cuando queremos crear código compatible con C. En la norma de C no nos dejan usar alloc() así que no lo vamos a usar nunca.
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:

//Si una clase no tiene un construtor explicito C++ le asigna uno, reliza las siguientes acciones:
//- Los miembros primitivos (int, char...) se inicializan con memoria aleatoria, a menos que tengan algun valor por defecto
//- Los miembros objeto usan el constructor por defecto de ese objeto
//- Los const (cosntantes) no pueden ser inicializados implicitamente
//- Los punteros se inicializan a NULL
// EDIT: al parecer la nomeclatura explicito solo se usa con los del tipo "explicit" (ejemplo: explicit MyClass(int value)). se carcaterizan porque evitan conversiones implicitas de tipo cuando no se les pasa un tipo compatible. Los constructores no tiene tipo de retorno (son funciones especiales), uno implicito tendra esta apariencia: MyClass(int value). Distingimos entre constructores explicitos, implicitos y por defecto.

    void setContact(std::string f, std::string l, std::string n, std::string p, std::string d) {
        firstName = f;
        lastName = l;
        nickname = n;
        phoneNumber = p;
        darkestSecret = d;
    }

    void displayContact() const {
        std::cout << "First Name: " << firstName << std::endl; //endl inserta un salto de linea y fuerza el flushing (vaciar) del buffer de salida. Lo que provoca que todos los datps pendientes de impresion en el buffer de salida (cosas enviadas con cout por ejemplo) se impriman inmediatamente.
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    }

    void displaySummary(int index) const { //const al final de la declaración de una función miembro significa que la función no modificará ningún miembro de la clase a la que pertenece.
        std::cout << std::setw(10) << index << " | " //setw() limita el MINIMO de caracteres del siguiente flujo de salida. Rellena los espacios que quedan en blanco
                  << std::setw(10) << truncate(firstName) << " | "
                  << std::setw(10) << truncate(lastName) << " | "
                  << std::setw(10) << truncate(nickname) << std::endl;
    }

private:
    std::string truncate(std::string str) const {
        return (str.length() > 10) ? str.substr(0, 9) + "." : str; //str.substr(0, 9) : estamos invocando a la funcion substr de la clase string a la que hemos apopodado str a la que accedemos mediante (str.). La funcion recibe los argumentos 0 y 9. Donde 0 es el indice desde el que empieza a recorrer el string y 9 es el numero de carcateres con el que va a crear la substring
    } //'?' es el operador ternario. Su sintaxis es: condición ? valor_si_verdadero : valor_si_falso; Se recomienda usar parentesis, como en este ejemplo para mejorar la legibilidad. Ademas el operador ternario tiene una prioridad mas baja sobre los operadores de comparacion. Cagarla es facil
};

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS]; //si queremos que sea dinamico podemos usar otros objetos como vector
    int contactCount;
    int oldestIndex;

public:
    PhoneBook() : contactCount(0), oldestIndex(0) {} // " : contactCount(0), oldestIndex(0)" lista de inicialización, es una parte del constructor que permite inicializar directamente los miembros de datos de una clase antes de que se ejecute el cuerpo del constructor.
	// MiClase(int a, int b, const std::string& str) : x(a), y(b), nombre(str)
	// string& str: es una referencia a un string preexistente. Las referencias no pueden ser NULL y no necesitan ser desreferenciadas explicitamente. Ademas cuando trabajamos con referencias la sintaxis es la misma que si estuvieramos trabajando con el objeto original
    void addContact() {
        std::string f, l, n, p, d;
        std::cout << "Enter First Name: ";
        std::getline(std::cin, f); //std::getline: Esta función se utiliza para leer una línea completa de texto desde una entrada estándar (usualmente el teclado) y almacenarla en una variable. std::cin: Es el objeto de entrada estándar en C++. Hace referencia al flujo de entrada desde el teclado. f: Es la variable donde se almacenará la línea leída.
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, l);
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, n);
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, p);
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, d);

        contacts[oldestIndex].setContact(f, l, n, p, d);

        if (contactCount < MAX_CONTACTS)
            contactCount++;
        oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;

        std::cout << "Contact added successfully!" << std::endl;
    }

    void searchContact() const {
        if (contactCount == 0) {
            std::cout << "PhoneBook is empty!" << std::endl;
            return;
        }

        std::cout << std::setw(10) << "Index" << " | "
                  << std::setw(10) << "First Name" << " | "
                  << std::setw(10) << "Last Name" << " | "
                  << std::setw(10) << "Nickname" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;

        for (int i = 0; i < contactCount; i++)
            contacts[i].displaySummary(i);

        std::cout << "Enter index of contact to view details: ";
        int index;
        std::cin >> index; //recibe datos del terminal hasta que el usuario pulsa Enter, si el dato no coincide con el tipo de variable en el que queremos almacenarlo la variable da error
        std::cin.ignore(); //descartar caracteres no deseados del buffer de entrada, evitando problemas en futuras lecturas. Cuando usas std::cin >> variable;, cin solo lee la parte necesaria para la variable, dejando el resto de los caracteres en el buffer. std::cin.ignore(); se usa para limpiar esos caracteres no deseados. conviene usarlo si despues vamos a usar std::getline()

        if (index >= 0 && index < contactCount)
            contacts[index].displayContact();
        else
            std::cout << "Invalid index!" << std::endl;
    }
};

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command!" << std::endl;
    }

    return 0;
}
