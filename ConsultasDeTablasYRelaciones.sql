SELECT * FROM empleado;

SELECT * FROM sucursal;


SELECT 
    e.id_empleado,
    e.nombre AS nombre_empleado,
    e.direccion AS direccion_empleado,
    e.telefono AS telefono_empleado,
    e.sexo,
    e.email,
    e.anio_contratacion,
    s.nombre AS nombre_sucursal,
    s.ciudad,
    s.estado
FROM empleado e
JOIN sucursal s ON e.id_sucursal = s.id_sucursal;

SELECT 
    s.id_sucursal,
    s.nombre AS nombre_sucursal,
    s.direccion,
    s.telefono,
    s.ciudad,
    s.estado,
    e.nombre AS nombre_encargado
FROM sucursal s
JOIN empleado e ON s.id_encargado = e.id_empleado;
