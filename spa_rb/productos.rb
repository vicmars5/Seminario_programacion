class Productos
	def initialize()
	end
	
	def capturar
		puts "\nDame identificador del producto: "
		@id_producto=gets()
		puts "\nDame nombre: "
		@nombre=gets()
		puts "\nDame descripción: "
		@descripcion=gets()
		puts "\nDame precio: "
		@precio=gets()
	end

	def mostrar
		puts "\nIdentificador del producto: " + @id_producto
		puts "\nNombre del producto: " + @nombre
		puts "\nDescipcion del producto: " +@descripcion
		puts "\nPrecio: " + @precio
	end

	def buscar
		puts "\nEscribe el identificador del producto que desea buscar: "
		busqueda=gets()

		if busqueda == @id_producto
			mostrar();
		else
			puts "\nNo existe"
	end

	def menu
		repetir=true
		while repetir
			puts "\n	PRODUCTOS"+
				"\n 1-Capturar"+ 
				"\n 2-Mostrar"+ 
				"\n 3-Buscar"+ 
				"\n 4-Salir"+ 
				"\n Opcion: "
			opcion=gets()

			case opcion 
				when 1
					capturar()
				when 2
					mostrar()
				when 3
					buscar()
				when 4
					repetir=false
			end
		end
	end
end
