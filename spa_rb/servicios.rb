class Servicios
	def initialize()
	end
	
	def capturar
		puts "\nDame el codigo de servicio: "
		@codigo =gets()
		puts "\nDame la descripcion: "
		@descripcion =gets()
		puts "\nDame el precio minimo: "
		@precio_minimo =gets()
		puts "\nDame el precio maximo: "
		@precio_maximo =gets()
	end
	
	def mostrar
		puts "\nCodigo de servicio: " + @codigo
		puts "\nDescripcion: " + @descripcion
		puts "\nPrecio minimo: " + @precio_minimo
		puts "\nPrecio maximo: " + @precio_maximo
	end
end