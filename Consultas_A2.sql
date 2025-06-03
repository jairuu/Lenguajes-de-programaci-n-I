--  1. Seleccionar los clientes del a�o 2021
SELECT DISTINCT c.*
FROM cliente c
JOIN factura f ON c.id_cliente = f.id_cliente
WHERE YEAR(f.fecha) = 2021;

--  2. Seleccionar los clientes de 2022 (hasta el momento)
SELECT DISTINCT c.*
FROM cliente c
JOIN factura f ON c.id_cliente = f.id_cliente
WHERE YEAR(f.fecha) = 2022;

--  3. Seleccionar los clientes de diciembre de 2021
SELECT DISTINCT c.*
FROM cliente c
JOIN factura f ON c.id_cliente = f.id_cliente
WHERE MONTH(f.fecha) = 12 AND YEAR(f.fecha) = 2021;

--  4. �Qu� compras han realizado los siguientes clientes?
SELECT c.nombre, c.apellido, f.id_factura, f.fecha, d.id_producto, d.cantidad, d.precio, p.nombre AS producto
FROM cliente c
JOIN factura f ON c.id_cliente = f.id_cliente
JOIN detalle d ON f.id_detalle = d.id_detalle
JOIN producto p ON d.id_producto = p.id_producto
WHERE (c.nombre = 'Valentina Anastasia' AND c.apellido = 'Huerta Corral')
   OR (c.nombre = 'Zayra Manuela' AND c.apellido = 'G�mez L�pez')
   OR (c.nombre = 'Dante Eduardo' AND c.apellido = 'Dolores Meza')
   OR (c.nombre = 'Ana Maribel' AND c.apellido = 'Cedillo N��ez')
   OR (c.nombre = 'Rodrigo Ismael' AND c.apellido = 'Silva Ugarte');

-- 5. Seleccionar el producto que m�s ventas ha tenido (por cantidad)
SELECT TOP 1 p.nombre, SUM(d.cantidad) AS total_vendido
FROM detalle d
JOIN producto p ON d.id_producto = p.id_producto
GROUP BY p.nombre
ORDER BY total_vendido DESC;

-- 6. �Qu� producto tiene m�s cantidad en stock?
SELECT TOP 1 nombre, stock
FROM producto
ORDER BY stock DESC;

-- 7. Ordenar, de la m�s antigua a la m�s reciente, las compras
SELECT *
FROM factura
ORDER BY fecha ASC;

--  8. Ordenar alfab�ticamente los nombres de todos los clientes
SELECT *
FROM cliente
ORDER BY nombre ASC, apellido ASC;

-- 9. Seleccionar productos de categor�as espec�ficas
SELECT p.nombre AS producto, c.nombre AS categoria
FROM producto p
JOIN categoria c ON p.id_categoria = c.id_categoria
WHERE c.nombre IN ('Falda', 'Pantal�n', 'Chamarra', 'Zapato', 'Accesorios');

-- 10. Seleccionar los encargados de las sucursales
SELECT s.nombre AS sucursal, e.nombre AS encargado
FROM sucursal s
JOIN empleado e ON s.id_encargado = e.id_empleado;

-- 11. Seleccionar los empleados que trabajan en la sucursal Constituci�n
SELECT e.*
FROM empleado e
JOIN sucursal s ON e.id_sucursal = s.id_sucursal
WHERE s.nombre LIKE '%Constituci�n%';

-- 12. �Qu� clientes son mayores de 30 a�os?
SELECT *, DATEDIFF(YEAR, fec_nac, GETDATE()) AS edad
FROM cliente
WHERE DATEDIFF(YEAR, fec_nac, GETDATE()) > 30;