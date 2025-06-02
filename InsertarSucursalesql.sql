INSERT INTO sucursal (id_sucursal, nombre, direccion, telefono, ciudad, estado, id_encargado) VALUES
(1, 'Akira''s Boutique: Las Mercedes', 'Calle Roble #507 Fracc. Las Mercedes', '4447831225', 'San Luis Potosí', 'San Luis Potosí', 1),
(2, 'Akira''s Boutique: Obraje', 'Calle Dr. Jesús Díaz de León #438 col. Obraje', '4493780921', 'Aguascalientes', 'Aguascalientes', 6),
(3, 'Akira''s Boutique: Galerías Mazatlán', 'Av. de la Marina #6204, Marina, local 35', '6692932059', 'Mazatlán', 'Sinaloa', 11),
(4, 'Akira''s Boutique: Zapopan', 'Av. Manuel J. Clouthier 525 col. Benito Juárez', '3337841230', 'Zapopan', 'Jalisco', 16),
(5, 'Akira''s Boutique: Melchor', 'Av. Melchor Ocampo #2528 Zona Centro', '6143906721', 'Chihuahua', 'Chihuahua', 21),
(6, 'Akira''s Boutique: Constitución', 'Calle Constitución #106 Zona Centro', '6181962954', 'Durango', 'Durango', 26),
(7, 'Akira''s Boutique: Centro', 'Av. Hidalgo #338 Zacatecas Centro', '4929301250', 'Zacatecas', 'Zacatecas', 31);


-- Agregar encargado de la nueva sucursal (ID 41)
INSERT INTO empleado (id_empleado, nombre, direccion, telefono, sexo, id_sucursal, email, anio_contratacion)
VALUES (41, 'Gabriel Moreno Ramírez', 'Calle Fresno #180 col. Primavera', '4778123400', 'M', 8, 'gabriel.moreno@akira.com', 2021);

INSERT INTO sucursal (id_sucursal, nombre, direccion, telefono, ciudad, estado, id_encargado)
VALUES (8, 'Akira''s Boutique: Primavera', 'Calle Fresno #180 col. Primavera', '4778123400', 'León', 'Guanajuato', 41);

INSERT INTO empleado (id_empleado, nombre, direccion, telefono, sexo, id_sucursal, email, anio_contratacion) VALUES
(42, 'Patricia Vázquez', 'Col. Industrial', '4778123401', 'F', 8, 'patricia.vazquez@akira.com', 2022),
(43, 'Juan Pablo Herrera', 'Col. Las Torres', '4778123402', 'M', 8, 'juan.herrera@akira.com', 2020),
(44, 'Liliana Ruiz', 'Col. Reforma', '4778123403', 'F', 8, 'liliana.ruiz@akira.com', 2023),
(45, 'Esteban Núñez', 'Fracc. Jardines', '4778123404', 'M', 8, 'esteban.nunez@akira.com', 2021);


