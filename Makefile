#for all .o targets this will compile corresponding .cpp file
%.o: %.cpp Integer.hpp Float.hpp
	g++ -m64 -std=c++17  -c $<
#assignment4 executable 
calculate: main.o Integer.o Addition.o Subtraction.o SimpleMultiply.o DivMod.o SingleDiv.o SpecialShift.o ToomMultiply.o Division.o DivMod_special.o Float.o Newton.o Separate.o BaseConvert.o SetPrecision.o Borwein.o Base_convert_sqrt.o
	g++ -m64 -std=c++17  -o $@ $^
#clean all created executables
clean:
	rm *.o calculate