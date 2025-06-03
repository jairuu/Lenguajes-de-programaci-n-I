-- Cambiar tipo de columnas en la tabla cliente
ALTER TABLE cliente ALTER COLUMN nombre NVARCHAR(MAX);
ALTER TABLE cliente ALTER COLUMN apellido NVARCHAR(MAX);
ALTER TABLE cliente ALTER COLUMN direccion NVARCHAR(MAX);
ALTER TABLE cliente ALTER COLUMN email NVARCHAR(MAX);

-- Cambiar tipo de columna en la tabla producto
ALTER TABLE producto ALTER COLUMN nombre NVARCHAR(MAX);

-- Cambiar tipo de columnas en la tabla categoria 
ALTER TABLE categoria ALTER COLUMN nombre NVARCHAR(MAX);
ALTER TABLE categoria ALTER COLUMN descripcion NVARCHAR(MAX);
