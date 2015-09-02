require './productos.rb'
require './servicios.rb'

class Main
	def initialize()
		puts "Seleccione una opcion" +
			"\nProductos 1" +
			"\nServicios 2"
		option = gets().to_i

		case option
			when 1
				productos = Productos.new()
				productos.capturar()
				productos.mostrar()
			when 2
				servicios = Servicios.new();
				servicios.capturar()
				servicios.mostrar()
		end
	end


end

main = Main.new()


