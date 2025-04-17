
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <iomanip>
#include <string>

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
    SQLHSTMT hStmt;
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

    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        wcout << L"Error en la conexión a la base de datos." << endl;
        return 1;
    }

    wcout << L"Conectado exitosamente a la base de datos." << endl;

    // Consulta SQL
    SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
    SQLWCHAR sqlQuery[] = L"SELECT NumeroEmpleado, Nombre, ApellidoPaterno, ApellidoMaterno, FechaNacimiento, RFC, Puesto, DescripcionPuesto, NumeroCentro, EsDirectivo FROM Empleado";

    SQLExecDirectW(hStmt, sqlQuery, SQL_NTS);

    // Variables para resultados
    int id, esDirectivo;
    char nombre[50], apP[50], apM[50], fecha[11], rfc[14], puesto[50], desc[100], centro[7];

    imprimirEncabezados();

    // Vincular columnas y recorrer resultados
    while (SQLFetch(hStmt) == SQL_SUCCESS) {
        SQLGetData(hStmt, 1, SQL_C_LONG, &id, 0, NULL);
        SQLGetData(hStmt, 2, SQL_C_CHAR, nombre, sizeof(nombre), NULL);
        SQLGetData(hStmt, 3, SQL_C_CHAR, apP, sizeof(apP), NULL);
        SQLGetData(hStmt, 4, SQL_C_CHAR, apM, sizeof(apM), NULL);
        SQLGetData(hStmt, 5, SQL_C_CHAR, fecha, sizeof(fecha), NULL);
        SQLGetData(hStmt, 6, SQL_C_CHAR, rfc, sizeof(rfc), NULL);
        SQLGetData(hStmt, 7, SQL_C_CHAR, puesto, sizeof(puesto), NULL);
        SQLGetData(hStmt, 8, SQL_C_CHAR, desc, sizeof(desc), NULL);
        SQLGetData(hStmt, 9, SQL_C_CHAR, centro, sizeof(centro), NULL);
        SQLGetData(hStmt, 10, SQL_C_LONG, &esDirectivo, 0, NULL);

        cout << "|"
            << setw(5) << id << " |"
            << setw(14) << nombre << " |"
            << setw(14) << apP << " |"
            << setw(14) << apM << " |"
            << setw(11) << fecha << " |"
            << setw(14) << rfc << " |"
            << setw(11) << puesto << " |"
            << setw(19) << desc << " |"
            << setw(11) << centro << " |"
            << setw(11) << (esDirectivo ? "Si" : "No") << " |"
            << endl;
    }

    imprimirLineaTabla();

    // Liberar recursos
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    return 0;
}