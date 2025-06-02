-- 1) Todos los empleados de la sucursal "Galerías Mazatlán"
SELECT e.nombre AS Empleado, s.nombre AS Sucursal
FROM empleado e
JOIN sucursal s ON e.id_sucursal = s.id_sucursal
WHERE s.nombre = 'Akira''s Boutique: Galerías Mazatlán';

-- 2) Encargados por sucursal
SELECT s.nombre AS Sucursal, e.nombre AS Encargado
FROM sucursal s
JOIN empleado e ON s.id_encargado = e.id_empleado;

-- 3) Total de empleados por sucursal
SELECT s.nombre AS Sucursal, COUNT(*) AS Total_Empleados
FROM sucursal s
JOIN empleado e ON s.id_sucursal = e.id_sucursal
GROUP BY s.nombre;

-- 4) Empleados contratados en el año 2023
SELECT nombre, anio_contratacion
FROM empleado
WHERE anio_contratacion = 2023;

