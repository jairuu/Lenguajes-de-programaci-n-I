CREATE TABLE empleado (
    id_empleado INT PRIMARY KEY,
    nombre NVARCHAR(100) NOT NULL,
    direccion NVARCHAR(150),
    telefono NVARCHAR(15),
    sexo CHAR(1),
    id_sucursal INT,
    email NVARCHAR(100),
    anio_contratacion INT
);