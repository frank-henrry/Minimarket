#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <string.h>
#include <chrono>
#include <map>
#include <stdlib.h>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 5
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
struct prdctos
{
    string nombre;
    int cantidad;
    string codigo;

    float costo;
};

struct clts
{

    string activos, morosos, nombre;
};
struct vts
{

    string cliente, producto;
    int cantidad, m_pagar, costo;
    string code;
};

// PROTOTIPOS DE LAS FUNCIONES
void dibujarCuadro(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);
void CursorOn(bool visible, DWORD size);
void CursorOff();
void limpia();
void cambio(char a[]);
void login();
void leerPasw(char frase[]);
void menu();

// FUNCION PRINCIPAL MAIN: Aqui dentro de main llamamos a las demas funciones.
int main()
{
    system("cls");
    system("COLOR F0");
    dibujarCuadro(0, 0, 78, 24); // Cuadro grande
    dibujarCuadro(1, 1, 77, 3);  // Cuadro del titulo
    CursorOff();
    gotoxy(16, 2);
    printf("\t\tMINIMARKET"); // titulo del programa
    login();

    getch();
    return 0;
}

// FUNCION LOGIN: Se crean 2 variables, de usuario y contraseña y se comparan para mostrar sus respectivos mensajes
void login()
{

    CursorOn(1, 10);
    char user[] = "tienda";   // el usuario
    char contra[] = "12345"; // contraseña
    char user2[20], contra2[20];
    int x = 1000;
    int f = 41;

    gotoxy(35, 6);
    printf("LOGIN");
    dibujarCuadro(18, 9, 60, 15);
    gotoxy(23, 11);
    printf("Usuario: ");
    fgets(user2, 20, stdin);
    cambio(user2);

    gotoxy(23, 13);
    printf("Clave:   ");
    leerPasw(contra2);

    CursorOff();

    for (int i = 0; i < 3; i++)
    {
        gotoxy(33, 19);
        printf("Cargando");
        gotoxy(f, 19);
        printf(".");
        f += 1;
        Sleep(x);
    }

    f = 51;

    if ((strcmp(user2, user)) == 0 && (strcmp(contra2, contra)) == 0)
    {
        gotoxy(30, 19);
        printf("                                     ");
        for (int i = 0; i < 3; i++)
        {
            gotoxy(30, 19);
            printf("Accediendo al Sistema");
            gotoxy(f, 19);
            printf(".");
            f += 1;
            Sleep(x);
        }
        limpia();
        menu();
    }

    else
    {
        gotoxy(35, 19);
        printf("                                     ");
        gotoxy(30, 19);
        printf("Datos incorrectos");
        gotoxy(18, 20);
        printf("Presione una tecla para volver a ingresar..");
        getch();
        limpia();
        login();
    }
}

// FUNCION LEER CONTRASEñA: proceso que permite mostrar asteriscos en la contraseña
void leerPasw(char frase[])
{
    int i = 0;
    cout.flush();
    int aux = 0;

    do
    {
        frase[i] = (unsigned char)getch();

        if (frase[i] != 8) // no es retroceso
        {
            cout << '*'; // muestra por pantalla
            i++;

            if (frase[i - 1] == 13)
            {
                printf("\b \b");
            }
        }

        else if (i > 0) // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--; // el caracter a borrar e el backspace
        }

        cout.flush();

    } while (frase[i - 1] != 13); // si presiona ENTER

    frase[i - 1] = 0;
}

// FUNCION CAMBIO: Cambia el caracter \n por \0
void cambio(char a[])
{
    int aux;
    aux = strlen(a);
    a[aux - 1] = '\0';
}
vector<prdctos> productos(20);
vector<clts> clientes(20);
vector<vts> ventas(20);
// ESTA FUNCION LA HICE DE PRUEBA SOLO PARA MOSTRAR MENSAJES, AQUI DEBEN COLOCAR EL PROGRAMA QUE USTEDES DESEAN
void menu()
{
    system("cls");
    system("color 70");
    int opcion, opcion2, opcion3;
    int nprdts = 0, opcion_prdts;
    int opcion_p;
    int opcion_vts;
    int nventas = 0; // contadores

    string nom;
    /* para sacar el tiempo real de la maquina */
    auto now = std::chrono::system_clock::now();
    time_t end_time = std::chrono::system_clock::to_time_t(now);
    vector<string> usuarios;
    vector<string> claves;

    /*nombre para los usuarios  */
    usuarios.push_back("admi");
    usuarios.push_back("caja1");
    usuarios.push_back("caja2");

    /* contraseña para los usuarios */
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    string usuario, password, usua;

    map<string, pair<string, float>> productoso;
    string codigo;
    float total = 0.0;
    bool finalizar = false;
    /* productos almacenados */
    productoso["123456789012"] = make_pair("Leche_chica", 2.5);
    productoso["234567890123"] = make_pair("Pan_integral", 3.5);
    productoso["345678901234"] = make_pair("Huevos_1casilla", 12.0);
    productoso["456789012345"] = make_pair("Jabon_bolivar", 1.5);
    productoso["567890123456"] = make_pair("sal", 1.5);
    productoso["667890123457"] = make_pair("azucar_1k/g", 4.0);
    productoso["767890123458"] = make_pair("aceite_mediana", 4.5);
    productoso["867890123459"] = make_pair("arroz_1k/g", 3.5);
    productoso["967890123451"] = make_pair("pilas_AA", 1.2);
    productoso["123456789011"] = make_pair("Leche_grande", 5.5);
    productoso["767890123422"] = make_pair("aceite_grande", 9.5);
    productoso["967890123433"] = make_pair("pilas_AAA", 2.2);
    productoso["967890123444"] = make_pair("pilas_AD", 3.5);
    map<string, pair<string, float>> productos_compra;
    /* si es 0 dejara de hacer compras */
    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\n\t\t\t   SISTEMA DE VENTAS    \n"; /* elegir lo que desea realizar */
        cout << "\t\t\t  -------------------\n\n";
        cout << "\t(1) administrador\n";/* es una cuenta privada */
        cout << "\t(2) caja_1\n";
        cout << "\t(3) caja_2\n";
        cout << "\t(4) salir\n";

        cin >> opcion;

        switch (opcion)
        {

        case 1:
            do
            {
                /* administrador  */
                cout << "\t\t\tIngresar usuario" << endl;
                cout << "\t\t\t----------------" << endl;
                cout << "\n\tUsuario: "; /* nombre de usuario y contraseña */
                cin >> usuario;

                char caracter;

                cout << "\tPassword: ";
                caracter = getch();

                password = "";

                while (caracter != ENTER)
                {
                    if (caracter != BACKSPACE)
                    {
                        password.push_back(caracter);
                        cout << "*";
                    }
                    else
                    {
                        if (password.length() > 0)
                        {
                            cout << "\b \b";
                            password = password.substr(0, password.length() - 1);
                        }
                    }
                    caracter = getch();
                }
                /* para la clave */
                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i] == usuario && claves[i] == password)
                    {
                        ingresa = true;
                        break;
                    }
                }

                if (!ingresa)
                {
                    cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
                    cin.get();
                    contador++;
                }
                break;
            } while (ingresa == false && contador < INTENTOS);

            if (ingresa == false)
            {
                cout << "\n\tUsted no pudo ingresar al sistema" << endl;
            }
            else
            {
                cout << "\n\n\tBienvenido al sistema" << endl;
            }
            
            do
            {
                /* lo que el usuario desea realizar */
                system("cls");
                cout << "\n\tPRODUCTOS\n";
                cout << "\t(1) Agregar productos\n";
                cout << "\t(2) ventas realizadas\n";
                cout << "\t(3) Ver productos agregados\n";
                cout << "\t(4) Volver al menu\n";
                cout << "\t(5) salir\n";
                cout << "\n\tQue desea realizar?\t";
                cin >> opcion_prdts;
                switch (opcion_prdts)
                {
                case 1:
                    /* agregar productos */
                    int ingr_prdcts;
                    cout << "\n\tCUANTOS PRODUCTOS DESEAS AGREGAR: \t";
                    cin >> ingr_prdcts;
                    for (int i = 0; i < ingr_prdcts; i++)
                    {
                        cout << "\n\tPRODUCTO " << i + 1;
                        cout << "\n\tCODIGO:\t";
                        cin >> productos[i].codigo;
                        cout << "\tNOMBRE:\t";
                        cin >> productos[i].nombre;
                        cout << "\tCOSTO:\t";
                        cin >> productos[i].costo;
                        cout << "\tCANTIDAD: ";
                        cin >> productos[i].cantidad;
                        nprdts++;
                    }
                    system("cls");
                    cout << "\n\t(1) ATRAS";
                    cout << "\n\t(2) MENU\n";
                    cout << "\t(3) SALIR\n";
                    cout << "\n\tQue desea realizar?\t";
                    cin >> opcion3;
                    opcion2 = 1;
                    if (opcion3 == 3)
                        exit(0);
                    break;
                case 2:
                    /* ver las ventas realizadas */
                    system("cls");
                    cout << "\n\t(1) VENTAS REALIZADAS";
                     system("cls");
                     cout << "\n\tVENTA"
                          << "\t\tUNIDAD"
                          << "\t\tVENTA TOTAL: " << total << " $";
                    cout << "\n\t-----"
                         << "\t-----"
                         << "\t---------"
                         << "\t-------"
                          << "\t------"
                          << "\t-------" << endl;
                        /* muestra las ventas realizadas */
                     for (auto &par : productos_compra)
                     {
                         string codigo = par.first;
                         pair<string, float> producto = par.second;
                         cout << "\t"
                              << "CODIGO: " << codigo << " / PRODUCTO: " << producto.first << " - $" << producto.second << endl;
                     }
                     system("pause");
                     system("cls");
                     cout << "\n\t(1) ATRAS";
                     cout << "\n\t(2) MENU\n";
                     cout << "\t(3) SALIR\n";
                     cout << "\n\tQue desea realizar?\t";
                     cin >> opcion3;
                     opcion2 = 1;
                     if (opcion3 == 3)
                         exit(0);
                     break;
                case 3:
                    /* ver productos agregados  */
                    system("cls");
                    cout << "\n\tProductos Registrados:\n";
                    cout << "\n\tCODIGO"
                         << "\tCOSTO"
                         << "\tCANTIDAD"
                         << "\tNOMBRE";
                    cout << "\n\t------"
                         << "\t-----"
                         << "\t--------"
                         << "\t------";
                    for (int i = 0; i < nprdts; i++)
                    {
                        cout << "\n\t" << productos[i].codigo << "\t" << productos[i].costo << "\t   " << productos[i].cantidad << " \t\t" << productos[i].nombre;
                    }
                    cout << "\n\n\t(1) ATRAS";
                    cout << "\n\t(2) MENU\n";
                    cout << "\t(3) SALIR\n";
                    cout << "\n\tQue desea realizar?\t";
                    cin >> opcion3;
                    opcion2 = 1;
                    if (opcion3 == 3)
                        exit(0);
                    break;

                case 4:
                    opcion3 = 2;
                    opcion2 = 1;
                    break;
                case 5:
                    
                    if(opcion3==5)
                        exit(0);
                    break;
                }

            } while (opcion3 == 1);
            break;

        case 2:
            /* caja1 */
            do
            {
                system("cls");
                cout << "\t\t\tIngresar usuario" << endl;/* ingresa nombre de usuario y contraseña */
                cout << "\t\t\t----------------" << endl;
                cout << "\n\tUsuario: ";
                cin >> usuario;
                char caracter;
                cout << "\tPassword: ";
                caracter = getch();
                password = "";

                while (caracter != ENTER)
                {

                    if (caracter != BACKSPACE)
                    {
                        password.push_back(caracter);
                        cout << "*";
                    }
                    else
                    {
                        if (password.length() > 0)
                        {
                            cout << "\b \b";
                            password = password.substr(0, password.length() - 1);
                        }
                    }
                    caracter = getch();
                }
                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i] == usuario && claves[i] == password)
                    {
                        ingresa = true;
                        break;
                    }
                }

                if (!ingresa)
                {
                    cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
                    cin.get();
                    contador++;
                }

            } while (ingresa == false && contador < INTENTOS);

            if (ingresa == false)
            {
                cout << "\n\tUsted no pudo ingresar al sistema" << endl;
            }
            else
            {
                cout << "\n\n\tBienvenido al sistema" << endl;
            }
            do
            {
                /* 5555555555555 */
                system("cls");
                cout << "\n\tVENTAS\n"; /* elegir la opcion de se desea realizar */
                cout << "\t(1) VENDER\n";
                cout << "\t(2) Volver al menu\n";
                cout << "\n\tQue desea realizar?\t";
                cin >> opcion_vts;

                switch (opcion_vts)
                {
                case 1:
                    /* aqui se realiza las ventas */
                    while (!finalizar)
                    {
                        /* codigo de barra de los productos almacenados */
                        cout << "Ingrese el codigo de barras del producto (0 para finalizar la compra): ";
                        cin >> codigo;

                        if (codigo == "0")
                        {
                            finalizar = true;
                        }
                        else if (productoso.count(codigo) > 0)
                        {
                            pair<string, float> producto = productoso[codigo];

                            productos_compra[codigo] = producto;
                            total += producto.second;
                        }
                        else
                        {
                            cout << "Producto no encontrado." << endl;
                        }
                    }

                    cout << "ingrese el nombre del cliente" << endl;
                    cin >> nom;

                    system("cls");
                    /* boleta de ventas */
                    cout << "////////////////////////////////////////" << endl;
                    cout << "\tHUANUCO - Leoncio prado - Rupa Rupa" << endl;
                    cout << "\tAV.ENRIQUE PIMENTEL - TINGO MARIA" << endl;
                    cout << "------------- Boleta de Venta ------------" << endl;
                    /* nombre del cliente */
                    cout << "\tcliente: " << nom << endl;
                    cout << "\tfecha y hora: " << ctime(&end_time) << endl;
                    for (auto &par : productos_compra)
                    {
                        string codigo = par.first;
                        pair<string, float> producto = par.second;
                        cout << "\t" << producto.first << " - $" << producto.second << endl;
                    }
                    cout << "---------------------------------------" << endl;
                    cout << "solicite su comprobante de pago correspondiente"
                         << "     "
                         << "Total de la compra: $" << total << endl;/* precio total de la compra */
                    cout << "\t\tGRACIAS POR SU COMPRA"<<endl;
                    system("pause");
                    system("cls");
                    cout << "\n\t(1) ATRAS";
                    cout << "\n\t(2) MENU\n";
                    cout << "\t(3) SALIR\n";
                    cout << "\n\tQue desea realizar?\t";
                    cin >> opcion3;
                    opcion2 = 1;
                    if (opcion3 == 3)
                        exit(0);
                    break;

                case 2:
                    opcion3 = 2;
                    opcion2 = 1;
                    break;
                }
            } while (opcion3 == 1);

            break;
        case 3:
            /* caja2 */
            do
            {
                system("cls");
                cout << "\t\t\tIngresar usuario" << endl;/* ingresa el usuario y la contraseña */
                cout << "\t\t\t----------------" << endl;
                cout << "\n\tUsuario: ";
                cin >> usuario;
                char caracter;
                cout << "\tPassword: ";
                caracter = getch();

                password = "";

                while (caracter != ENTER)
                {

                    if (caracter != BACKSPACE)
                    {
                        password.push_back(caracter);
                        cout << "*";
                    }
                    else
                    {
                        if (password.length() > 0)
                        {
                            cout << "\b \b";
                            password = password.substr(0, password.length() - 1);
                        }
                    }
                    caracter = getch();
                }

                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i] == usuario && claves[i] == password)
                    {
                        ingresa = true;
                        break;
                    }
                }
                if (!ingresa)
                {
                    cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
                    cin.get();
                    contador++;
                }

            } while (ingresa == false && contador < INTENTOS);

            if (ingresa == false)
            {
                cout << "\n\tUsted no pudo ingresar al sistema" << endl;
            }
            else
            {
                cout << "\n\n\tBienvenido al sistema" << endl;
            }
            do
            {
                system("cls");
                /* elegir lo que desea realizar */
                cout << "\n\tVENTAS\n";
                cout << "\t(1) VENDER\n";
                cout << "\t(2) Volver al menu\n";
                cout << "\n\tQue desea realizar?\t";
                cin >> opcion_p;

                switch (opcion_p)
                {
                case 1:/* realizar ventas */
                    while (!finalizar)
                    {
                        /* codigo de barra de los productos almacenados */
                        cout << "Ingrese el codigo de barras del producto (0 para finalizar la compra): "; 
                        cin >> codigo;

                        if (codigo == "0")
                        {
                            finalizar = true;
                        }
                        else if (productoso.count(codigo) > 0)
                        {
                            pair<string, float> producto = productoso[codigo];

                            productos_compra[codigo] = producto;
                            total += producto.second;
                        }
                        else
                        {
                            cout << "Producto no encontrado." << endl;
                        }
                    }

                    /* nombre del cliente */
                    cout << "ingrese el nombre del cliente" << endl;
                    cin >> nom;

                    system("cls");
                    /* boleta de ventas */
                    cout << "////////////////////////////////////////" << endl;
                    cout << "\tHUANUCO - Leoncio prado - Rupa Rupa" << endl;
                    cout << "\tAV.ENRIQUE PIMENTEL - TINGO MARIA" << endl;
                    cout << "------------- Boleta de Venta ------------" << endl;
                    cout << "\tcliente: " << nom << endl;
                    cout << "\tfecha y hora: " << ctime(&end_time) << endl;
                    for (auto &par : productos_compra)
                    {
                        string codigo = par.first;
                        pair<string, float> producto = par.second;
                        cout << "\t" << producto.first << " - $" << producto.second << endl;
                    }
                    cout << "---------------------------------------" << endl;
                    cout << "solicite su comprobante de pago correspondiente"
                         << "     "
                         << "Total de la compra: $" << total << endl; /* precio total de la compra */
                    cout << "\t\tGRACIAS POR SU COMPRA"<<endl;
                    system("pause");
                    system("cls");

                    cout << "\n\t(1) ATRAS";
                    cout << "\n\t(2) MENU\n";
                    cout << "\t(3) SALIR\n";
                    cout << "\n\tQue desea realizar?\t";
                    cin >> opcion3;
                    opcion2 = 1;
                    if (opcion3 == 3)
                        exit(0);
                    break;

                case 2:
                    opcion3 = 2;
                    opcion2 = 1;
                    break;
                }

            } while (opcion3 == 1);
            break;

        case 4:
            if (opcion3 == 3)
                exit(0);
            break;
        }

    } while (opcion2 == 1);
}

//************************************FUNCIONES ADICIONALES************************************************************

// FUNCION GOTOXY: Permite posicionar en pantalla mediante coordenadas X/Y
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

// FUNCION DIBUJAR CUADRO
void dibujarCuadro(int x1, int y1, int x2, int y2)
{

    int i;
    for (i = x1; i < x2; i++)
    {
        gotoxy(i, y1);
        printf("-"); // linea horizontal superior
        gotoxy(i, y2);
        printf("-"); // linea horizontal inferior
    }

    for (i = y1; i < y2; i++)
    {
        gotoxy(x1, i);
        printf("|"); // linea vertical izquierda
        gotoxy(x2, i);
        printf("|"); // linea vertical derecha
    }
    gotoxy(x1, y1);
    printf("|");
    gotoxy(x1, y2);
    printf("|");
    gotoxy(x2, y1);
    printf("|");
    gotoxy(x2, y2);
    printf("|");
}

// FUNCION LIMPIAR PANTALLA
void limpia()
{
    int i, j;
    for (i = 5; i <= 23; i++)
    {
        for (j = 3; j <= 76; j++)
        {
            gotoxy(j, i);
            printf(" ");
        }
    }
}

// FUNCION PARA OCULTAR EL CURSOR
void CursorOff()
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

// FUNCION PARA APARECER EL CURSOR
void CursorOn(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
    if (size == 0)
    {
        size = 20; // default cursor size Changing to numbers from 1 to 20, decreases cursor width

        CONSOLE_CURSOR_INFO lpCursor;
        lpCursor.bVisible = visible;
        lpCursor.dwSize = size;
        SetConsoleCursorInfo(console, &lpCursor);
    }
}
