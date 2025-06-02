CREATE TABLE sucursal (
    id_sucursal INT PRIMARY KEY,
    nombre NVARCHAR(100),
    direccion NVARCHAR(150),
    telefono NVARCHAR(15),
    ciudad NVARCHAR(50),
    estado NVARCHAR(50),
    id_encargado INT,
    FOREIGN KEY (id_encargado) REFERENCES empleado(id_empleado)
);