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
end