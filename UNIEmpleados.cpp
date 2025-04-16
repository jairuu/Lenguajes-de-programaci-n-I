
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <iomanip>

using namespace std;

void imprimirLineaTabla() {
    std::cout << "+"
        << std::setw(6) << std::setfill('-') << "-" << "+"
        << std::setw(15) << "-" << "+"
        << std::setw(15) << "-" << "+"
        << std::setw(15) << "-" << "+"
        << std::setw(12) << "-" << "+"
        << std::setw(15) << "-" << "+"
        << std::setw(12) << "-" << "+"
        << std::setw(20) << "-" << "+"
        << std::setw(12) << "-" << "+"
        << std::setw(12) << "-" << "+"
        << std::setfill(' ') << std::endl;
}

void imprimirEncabezados() {
    imprimirLineaTabla();
    std::cout << "|"
        << std::setw(5) << "ID" << " |"
        << std::setw(14) << "Nombre" << " |"
        << std::setw(14) << "Apellido P" << " |"
        << std::setw(14) << "Apellido M" << " |"
        << std::setw(11) << "Nacimiento" << " |"
        << std::setw(14) << "RFC" << " |"
        << std::setw(11) << "Puesto" << " |"
        << std::setw(19) << "Descripcion" << " |"
        << std::setw(11) << "Centro" << " |"
        << std::setw(11) << "Directivo?" << " |"
        << std::endl;
    imprimirLineaTabla();
}

int main() {
    SQLHENV hEnv;
    SQLHDBC hDbc;
    SQLRETURN ret;

    SQLWCHAR outConnStr[1024];
    SQLSMALLINT outConnStrLen;

    // Asignar gestor de entorno
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

    // Asignar gestor de conexión
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

    // Cadena de conexión
    SQLWCHAR connStr[] = L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=JAIRUU-HOME\\SQLEXPRESS;DATABASE=UNIEmpleados;Trusted_Connection=yes;";

    // Conectar
    ret = SQLDriverConnectW(
        hDbc,
        NULL,
        connStr,
        SQL_NTS,
        outConnStr,
        sizeof(outConnStr) / sizeof(SQLWCHAR),
        &outConnStrLen,
        SQL_DRIVER_NOPROMPT
    );

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        wcout << L"Conectado a la base de datos exitosamente." << endl;
    }
    else {
        wcout << L"Error en la conexión:" << endl;
    }

    // Liberar
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    imprimirEncabezados();

    return 0;
}