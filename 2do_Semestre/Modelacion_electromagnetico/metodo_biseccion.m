%Juan Carlos Garfias Tovar, A01652138

%% Clase
clc
clear all

f= @(x)(-1/10)*(x.^2)+3;
%x=-10:0.1:10;
x = 2:0.1:10;

Xi=2;
Xd=10;
Tolerancia=10^-20;
[raiz,Xm,Iteraciones]=Biseccion(f,Xi,Xd,Tolerancia);
disp(['El valor de y es =' num2str(raiz)]);
disp(['El valor de x es =' num2str(Xm)]);
disp(['El valor de iteraciones es =' num2str(Iteraciones)]);

y = f(x);
plot(x,y)
grid on

%si y=0 --> esta correcto

%% Tarea

%Funcion 1
x1 = -3:0.1:3;

Xi1=-3;
Xd1=3;
Tolerancia1=10^-21;

f1 = @(x)x-cos(x);
y1 = f1(x1);

BFull(Xi1,Xd1,Tolerancia1,f1); %BFull(Xi,Xd,Tolerancia,f)
figure(1);
plot(x1,y1)

%Funcion 2
x2 = 2:0.1:4;

Xi2=2;
Xd2=4;
Tolerancia2=10^-10;

f2 = @(x)x.^2.*sin(x);
y2 = f2(x2);

BFull(Xi2,Xd2,Tolerancia2,f2);
figure(2)
plot(x2,y2)

%Funcion 3
x3 = 0:0.1:2;

Xi3=0.2;
Xd3=3;
Tolerancia3=10^-10;

f3 = @(x)x.*log(x);
y3 = f3(x3);

BFull(Xi3,Xd3,Tolerancia3,f3);
figure(3)
plot(x3,y3)

%Funcion 4
x4 = -5:0.1:1;

Xi4=-5;
Xd4=1;
Tolerancia4=10^-10;

f4 = @(x)(exp(x.*0.3))-(x.^2);
y4 = f4(x4);

BFull(Xi4,Xd4,Tolerancia4,f4);
figure(4)
plot(x4,y4)

%Funcion 5
x5 = 0:0.1:4;

Xi5=0;
Xd5=4;

Tolerancia5=10^-10;

f5 = @(x)2*cos(x)-(sqrt(x)/2);
y5 = f5(x5);

BFull(Xi5,Xd5,Tolerancia5,f5);
figure(5)
plot(x5,y5)

%% Funciones

function BFull(Xi,Xd,Tolerancia,f)
    [raiz,Xm,Iteraciones]=Biseccion(f,Xi,Xd,Tolerancia);
    fprintf("\nFuncion :");
    disp(f)
    disp(['El valor de y es =' num2str(raiz)]);
    disp(['El valor de x es =' num2str(Xm)]);
    disp(['El valor de iteraciones es =' num2str(Iteraciones)]);
end


function [raiz,Xm,Iteraciones]=Biseccion(f,Xi,Xd,Tolerancia)
    Iteraciones = 0;
    raiz = NaN;
    Xm = (Xi+Xd)/2;
    if f(Xi)*f(Xd)<0
        while abs(f(Xm))>Tolerancia
            if(f(Xi)*f(Xm)<0)
                Xd=Xm;
            else
                Xi=Xm;
            end
            Iteraciones = Iteraciones +1;
            Xm = (Xi+Xd)/2;
        end
        raiz = f(Xm);
    else
        disp('Elige otro intervalo')
    end
end