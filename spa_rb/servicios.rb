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

	def buscar
		puts "\n Escribe el codigo del servicio que desea encontrar"
		busqueda= gets()
		if(busqueda == @codigo)
			mostrar()
		else
			puts "\n No existe el producto"
		end
	end

	def menu
		repetir=true

		while repetir
			puts "\n	SERVICIOS"+
				"\n 1-Capturar"+ 
				"\n 2-Mostrar"+ 
				"\n 3-Buscar"+ 
				"\n 4-Salir"+ 
				"\n Opcion: "
			opcion=gets().to_i

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