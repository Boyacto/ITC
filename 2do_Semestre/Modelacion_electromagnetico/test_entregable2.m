clear;
puntos = 55;%numero de puntos en la malla
cargas=[2,2,2,2,2,-2,-2,-2,-2,-2];%dos cargas de diferentes signos
radio = 4;%radio de las cargas

%Definir la posicion de las cargas
xcargas=[-2,-1,0,1,2,-2,-1,0,1,2];
ycargas=[0,0,0,0,0,15,15,15,15,15];


epsilon = 8.854e-12;%Escribir el valor de epsilon
%es un valor para hacer la ecuacion del campo electrico
k = 1/(4 * pi * epsilon);

%Dimensiones de la grafica
minx= -10;
maxx=10;

maxy = 30;
miny= -30;

%campo electrico
campoex = zeros(puntos);
campoey = zeros(puntos);

%Crear 2 vectores
     %minimo y maximo para numero de divisiones
x =linspace(minx,maxx,puntos);%va de menos -1.5 a 1.5 dividido en npuntos
y =linspace(miny,maxy,puntos);%estos son vectores

%crear malla de puntos
[xpuntosmalla,ypuntosmalla]=meshgrid(x,y);

%crear un for que recorra las cargas para poder obtener el calculo de campo
%electrico

for i=1:10
    dx = xpuntosmalla-xcargas(i);%obtiene distancias
    dy = ypuntosmalla-ycargas(i);%obtiene distancias
    
    r = sqrt(dx.^2+dy.^2);%distancias totales/ magnitud
    r3 = r.^3;%distnacias entre donde esta la carga y los elementos que rodean la carga
    
    %aqui es por componentes
    campoex=campoex+k.*cargas(i).*dx./r3;
    campoey=campoey+k.*cargas(i).*dy./r3;
    
end



campoe_total = sqrt(campoex.^2+campoey.^2);


%graficar
quiver(xpuntosmalla,ypuntosmalla,campoex./campoe_total,campoey./campoe_total);%se aplica normalizacion
hold on
for i=1:length(xcargas)
    x = xcargas(i);
    y = ycargas(i);
    disp(x)
    disp(y)
    rectangle('Position',[x-0.5 y-0.5 1 1.2],'Curvature',[1,1],'FaceColor','b');
end
%usar rectangulo, usando la posicion con radio
%axis para el tama�o de la grafica}
%para el nombre de la carga, poner sobre el rectangulo, usar text