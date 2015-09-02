require './productos.rb'
require './servicios.rb'

class Main
	def initialize()
		puts "Seleccione una opcion" +
			"\n1.-Productos" +
			"\n2.-Servicios" +
			"\n0.-Salir"+
			"\n"+
			"\n Opcion"
		option = gets().to_i

		case option
			when 1
				productos = Productos.new()
				productos.Menu()
			when 2
				servicios = Servicios.new()
				servicios.capturar()
				servicios.mostrar()
		end
	end


end

main = Main.new()


