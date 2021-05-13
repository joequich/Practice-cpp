#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main() {

    vector<int> intArray(10);

    int length = 0;

    for (int i = 0; i < 6; i++) {
        intArray[length] = i;
        length++;
    }

    // imprimir arreglo
    cout << "\n";

    for (int i = 0; i < length; i++) {
        cout << "Index " << i << " contains " << intArray[i] << "\n";
    }
   
    /** eliminar el primer elemento */
    for (int i = 1; i < length; i++) {
        intArray[i - 1] = intArray[i];
    }

    length--;

    // imprimir arreglo
    cout << "\n";
    cout << "eliminar el primer elemento\n";
    
    for (int i = 0; i < length; i++) {
        cout << "Index " << i << " contains " << intArray[i] << "\n";
    }

    /** eliminar el segundo elemento */
    for (int i = 2; i < length; i++) {
        intArray[i - 1] = intArray[i];
    }

    length--;

    // imprimir arreglo
    cout << "\n";
    cout << "eliminar el segundo elemento\n";
    
    for (int i = 0; i < length; i++) {
        cout << "Index " << i << " contains " << intArray[i] << "\n";
    }


    return 0;
}
