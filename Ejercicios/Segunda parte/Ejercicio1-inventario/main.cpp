#include <iostream>
#include <string>
#include <vector>
using namespace std;

string productos [5][3] = {
    { "001", "iphone X", "0" },
    { "002", "Laptop Dell", "2" },
    { "003", "Monitor Samsung", "2" },
    { "004", "Mouse", "100" },
    { "005", "HeadSet", "25" },
};

vector <string> movimientos;

void listarproductos() {
    system("cls");
    cout << endl;
    cout << "Listado de productos" << endl;
    cout << "********************" << endl;
    cout << "Codigo, Descripcion y Existencia" << endl;
    
    for (int i =0; i < 5; i++)
    {
         cout << productos[i][0] << " | " << productos[i][1] << " | " << productos[i][2]<< endl;
    }
}

bool movimientoInventario(string codigo, int cantidad, string tipoMovimiento) {
    for (int i = 0; i < 5; i++)
    {
        if (productos[i][0] == codigo) {        
            if (tipoMovimiento == "+") {
                productos[i][2] = to_string(stoi(productos[i][2]) + cantidad);
            } else {
                productos[i][2] = to_string(stoi(productos[i][2]) - cantidad);
            }
            return true;
        }
    }
    return false;
}

void ingresoDeInventario() {
    string codigo = "";
    int cantidad = 0;

    system("cls");
    cout << endl;
    cout << "Ingreso de productos al Inventario" << endl;
    cout << "**********************************" << endl; 
    cout << "Ingrese el codigo del producto ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;

    movimientoInventario(codigo, cantidad, "+");
}

void salidaDeInventario() {
    string codigo = "";
    int cantidad = 0;

    system("cls");
    cout << endl;
    cout << "Salida de productos del Inventario" << endl;
    cout << "**********************************" << endl; 
    cout << "Ingrese el codigo del producto ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;

    movimientoInventario(codigo, cantidad, "-");
}

void ajusteNegativo()
{
    string codigo = "";
    int cantidad = 0;

    system("cls");
    cout << endl;
    cout << "Ajuste negativo de Inventario" << endl;
    cout << "**********************************" << endl; 
    cout << "Ingrese el codigo del producto ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;

    bool resultado = movimientoInventario(codigo, cantidad, "-");
    if(resultado)
    {
      string valor = codigo + " | " + to_string(cantidad) + " | -";
       movimientos.push_back(valor); 
    }
    else
    {
        cout<<"No se encontro un producto con el codigo ingresado"<<endl;
    }
}

void ajustePositivo()
{
    string codigo = "";
    int cantidad = 0;

    system("cls");
    cout << endl;
    cout << "Ajuste positivo de Inventario" << endl;
    cout << "**********************************" << endl; 
    cout << "Ingrese el codigo del producto ";
    cin >> codigo;
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << endl;

    bool resultado = movimientoInventario(codigo, cantidad, "+");
    if(resultado)
    {
       string valor = codigo + " | " + to_string(cantidad) + " | +";
       movimientos.push_back(valor); 
    }
    else
    {
        cout<<"No se encontro un producto con el codigo ingresado"<<endl;
    }
}

void ajusteDeInventario()
{
    int tipoMovimiento;
    cout<<"Que tipo de ajuste hara: 1.Positivo 2.Negativo"<<endl;
    cin>>tipoMovimiento;
    switch (tipoMovimiento)
    {
    case 1:
        ajustePositivo();
        break;
    case 2:
        ajusteNegativo();
        break;
    
    default:
        break;
    }
}

void printMovimientos()
{
    cout<<"HISTORIAL DE AJUSTES"<<endl;
    for (std::size_t i = 0; i < movimientos.size(); i++) 
    {
        cout << movimientos[i] << endl;
    }
    cout<<"===================================="<<endl;
}

int main(int argc, char const *argv[])
{
    int opcion = 0;

    while (true) {
        system("cls");

        cout << "Sistema de Invenntario";
        cout << endl;
        cout << "**********************";
        cout << endl;
        cout << endl;
        cout << "1 - Productos" << endl;
        cout << "2 - Ingreso de Inventario" << endl;
        cout << "3 - Salida de Inventario" << endl;
        cout << "4 - Ajuste de Inventario" << endl;
        cout << "5 - Mostrar historial de Ajustes de Inventario" << endl;
        cout << "0 - Salir " << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> opcion;
        
        switch (opcion)
        {
        case 1:
            listarproductos();
            break;
        case 2:
            ingresoDeInventario();
            break;

        case 3:
            salidaDeInventario();
            break;
        case 4:
            ajusteDeInventario();
            break;
        case 5:
            printMovimientos();
            break;
        default:
            break;

        }
        system("pause");
        cout << endl;

        if (opcion == 0) {
            break;
        }

    }
}
