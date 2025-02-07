%Juan Carlos Garfias Tovar A01652138

%% Actividad 1 clase
x= -10:0.01:10;
y=x.^2;

figure(1)

plot(x,y,'-r','LineWidth',3)

hold on
y=2.5*x.^2;
plot(x,y,'b--');
comet(x,y)%gracica de manera animada, funciona para 2D

y= 3.7 * x.^2;
plot(x,y,'g--');
%comet(x,y)

y=0.75*x.^2;
plot(x,y,'c--');
%comet(x,y)

y=0.50*x.^2;
plot(x,y,'K--')
%comet(x,y)

title('Ejemplo 1 Clase');
xlabel('Eje x');
ylabel('Eje y');
legend('x^2','2.5*x.^2','3.7 * x.^2','0.75*x.^2','0.50*x.^2');
hold off

%% Actividad 2
x=-10:0.01:10;
y=sin(x);

figure(2)

plot(x,y,'g','LineWidth',3);

hold on

y=sin(x)+x;
plot(x,y,'r--');

y=sin(x+10);
plot(x,y,'b--');

y=sin(x)+10;
plot(x,y,'c--');

y=sin(x)-20;
plot(x,y,'K--');


title('Ejemplo 2 Clase');
xlabel('Eje x');
ylabel('Eje y');
legend('sin(x)','sin(x)+x','sin(x+10)','sin(x)+10','sin(x)-20');



%% Problema 1
t = 1:0.1:1000;

x = t.^2+2.*t;
y = t.^10+t.^3+t.^2+t;
z = t;

figure(3)

plot3(x,y,z,'K-o');
title('Problema 1');
legend('Ecuacion 1');
xlabel('Eje x');
ylabel('Eje y');
zlabel('Eje z');
%% Problema 2
t = 1:0.1:600;

x=t.^5-10*t;
y=2*t-4;

figure(4)

plot(x,y,'g');
title('Problema 2');
xlabel('Eje x');
ylabel('Eje y');
legend('Ecuacion 2');

%% Problema 3
a=2;
b=0.25;
w=2;
t=0:0.001:12*pi;

x = a*cos(w*t);
y = a*sin(w*t);
z = b*t;

figure(5)

plot3(x,y,z,'r--');
title('Problema 3');
legend('Ecuacion 3');
xlabel('Eje x');
ylabel('Eje y');
zlabel('Eje z');

%% Problema 4

a = 1;
b = 1;
t = 0:0.001:2*pi;
u = 0:0.001:2*pi;

x=a.*cos(t).*cos(u);
y=b.*cos(t).*sin(u);
z=cos(t).^3;

figure(6)

plot3(x,y,z,'b-*');
title('Problema 4');
legend('Ecuacion 4');
xlabel('Eje x');
ylabel('Eje y');
zlabel('Eje z');

%% Problema 5

figure(7)

rectangle('Position',[2 4 1 1.2],'Curvature',[1,1],'FaceColor','r','EdgeColor',[0 0 1]);
rectangle('Position',[4 4 1 1.2],'Curvature',[1,1],'FaceColor','b','EdgeColor',[1 0 0]);
rectangle('Position',[6 4 0.5 0.6],'Curvature',[1,1],'FaceColor','k','EdgeColor',[0 0 1]);

rectangle('Position',[2 2 0.5 0.6],'Curvature',[1,1],'FaceColor','g','EdgeColor',[0 0 1]);
rectangle('Position',[4 1 0.5 0.6],'Curvature',[1,1],'FaceColor','y','EdgeColor',[1 0 0]);
rectangle('Position',[6 6 0.5 0.6],'Curvature',[1,1],'FaceColor','c','EdgeColor',[0 0 1]);

axis([0 8 0 8])
axis square %define la proporcion cuadrada
title('Problema 5');
xlabel('Eje x');
ylabel('Eje y');

%% Problema 6

figure(8)

[x,y] = meshgrid(0:0.2:1,0:0.2:2);
u = cos(x).*y*8;
v = sin(x).*y*-8+20;

h = quiver(x,y,u,v,'color',[1 0 1]);
set(h,'MaxHeadSize',1e5,'AutoScaleFactor',1.6);
title('Problema 6');
legend('Vectores');
xlabel('Eje x');
ylabel('Eje y');

