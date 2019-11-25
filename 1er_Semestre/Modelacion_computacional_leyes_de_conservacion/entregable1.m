syms a0 a1 a2 a3 x
%-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

%%obtener funcion
x1=100;
y1=500;

x2=2800;
y2=200;

eq1= a3*x1^3+a2*x1^2+a1*x1+a0==y1;
eq2= a3*x2^3+a2*x2^2+a1*x2+a0==y2;

%Editables
x3=2600;
y3=2000;

x4=1000;
y4=700;

eq3= a3*x3^3+a2*x3^2+a1*x3+a0==y3;
eq4= a3*x4^3+a2*x4^2+a1*x4+a0==y4;

sol=solve([eq1,eq2,eq3,eq4],[a0,a1,a2,a3]);

v1=double(sol.a0);
v2=double(sol.a1);
v3=double(sol.a2);
v4=double(sol.a3);
%-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

%%longitud de curvatura

fx=v4*x^3+v3*x^2+v2*x+v1;
fxd=diff(fx);
fxl=sqrt(1+(fxd^2));
fprintf("y=%.9fx^3+%.9fx^2+%.9fx+%.9f\n",v4,v3,v2,v1);


lg=int(fxl,x,[x1,x2]);
fprintf("Longitud de arco: %0.4f\n",lg);
%-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

%%Radio de curvatura 1
min = 999999;
for i=x1:1:x2/2
    p = ((fxl)^(2/3)) / (diff(fxd));
    psub = subs(p,x,i);
    if (psub < 0)
        psub = psub * (-1);
    end
    
    if(psub<=min)
        min = psub;
        mini = i;
    end
    
    
    fprintf("Radio%i: %.6f\n", i, psub);
end

%%Radio de curvatura 2
min2 = 999999;
for i=(x2/2)+1:1:x2
    p = ((fxl)^(2/3)) / (diff(fxd));
    psub = subs(p,x,i);
    if (psub < 0)
        psub = psub * (-1);
    end
    
    if(psub<=min2)
        min2 = psub;
        mini2 = i;
    end
    
    
    fprintf("Radio%i: %.6f\n", i, psub);
end
fprintf("El valor minimo del radio %i de curvatura es de: %.12f\n",mini, min);
fprintf("El valor minimo del radio %i de curvatura es de: %.12f\n",mini2, min2);
%-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

%%Tangente y punto medio de la grada1
y=fx;
puntox= mini;
yprim=diff(y);
m = subs(yprim,x,puntox);
puntoy=subs(y,x,puntox);
fprintf("Pendiente: %.9f\n",m);
fprintf("Puntos: (%.9f,%.9f)\n",puntox,puntoy);
y2f=m*x-m*puntox+puntoy;
y2t = y2f;
fprintf("La funcion es: y=");
disp(y2t);
if(m>0)
    f1 =-20;
else
    f1 =20;
end
x2f= puntox+f1*sqrt(1/(1+m^2));
y2f= puntoy+m*f1*sqrt(1/(1+m^2));
fprintf("Puntos: (%.9f,%.9f)\n",x2f,y2f);
%%Tangente y punto medio de la grada2
y_2=fx;
puntox_2= mini2;
yprim_2=diff(y);
m_2 = subs(yprim,x,puntox_2);
puntoy_2=subs(y,x,puntox_2);
fprintf("Pendiente: %.9f\n",m_2);
fprintf("Puntos: (%.9f,%.9f)\n",puntox_2,puntoy_2);
y2f_2=m_2*x-m_2*puntox_2+puntoy_2;
y2t_2 = y2f_2;
fprintf("La funcion es: y=");
disp(y2t_2);
if(m_2>0)
    f1_2 =20;
else
    f1_2 =-20;
end
x2f_2= puntox_2+f1_2*sqrt(1/(1+m_2^2));
y2f_2= puntoy_2+m_2*f1_2*sqrt(1/(1+m_2^2));
fprintf("Puntos: (%.9f,%.9f)\n",x2f_2,y2f_2);
%-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
%obtener puntos de la barrera1
xgrada1_i=x2f-40;
ygrada1_i=y2f;

xgrada1_f=x2f+40;
ygrada1_f=y2f;

fprintf("Coordenadas barrera1: (%.9f,%.9f),(%.9f,%.9f)\n",xgrada1_i,ygrada1_i,xgrada1_f,ygrada1_f);
%obtener puntos de la barrera2
xgrada2_i=x2f_2-40;
ygrada2_i=y2f_2;

xgrada2_f=x2f_2+40;
ygrada2_f=y2f_2;

fprintf("Coordenadas barrera2: (%.9f,%.9f),(%.9f,%.9f)\n",xgrada2_i,ygrada2_i,xgrada2_f,ygrada2_f);
%-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

%Plot graph

%punto inicial
plot(x1,y1,'or');
hold on
%punto final
plot(x2,y2,'ob');
hold on
%funcion general
fplot(fx,[x1,x2],'color',[0 0 0]);
hold on
%tangente punto minimo1
fplot(y2t,[x1 x2], '--','color',[.32 .133 .9]);
hold on
%tangente punto minimo2
fplot(y2t_2,[x1 x2], '--','color',[.32 .133 .9]);
hold on

%%gradas1
plot(xgrada1_i,ygrada1_f,'o','color',[.79 .5 .181]);
hold on
plot(xgrada1_f,ygrada1_f,'o','color',[.79 .5 .181]);
hold on
plot(xgrada1_i,ygrada1_f-20,'o','color',[.79 .5 .181]);
hold on
plot(xgrada1_f,ygrada1_f-20,'o','color',[.79 .5 .181]);
hold on
%gradas 2
plot(xgrada2_i,ygrada2_f,'o','color',[.79 .5 .181]);
hold on
plot(xgrada2_f,ygrada2_f,'o','color',[.79 .5 .181]);
hold on
plot(xgrada2_i,ygrada2_f+20,'o','color',[.79 .5 .181]);
hold on
plot(xgrada2_f,ygrada2_f+20,'o','color',[.79 .5 .181]);

%plot(xlim, ygrada2_f*[xgrada2_i xgrada2_f]);
hold on

%punto1 radio<=100
plot(puntox, puntoy, 'or');
hold on

%punto2 radio<=100
plot(puntox_2, puntoy_2, 'or');
hold on

%punto1 gradas
plot(x2f, y2f, 'o', 'color',[.79 .5 .181]);
hold on

%punto2 gradas
plot(x2f_2, y2f_2, 'o','color',[.79 .5 .181]);
hold on

