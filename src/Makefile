make: main.cpp vec3.cpp
	g++ main.cpp vec3.cpp -o rt

render: rt
	./rt > out.ppm

clean:
	rm -rf out.ppm
	rm -rf rt