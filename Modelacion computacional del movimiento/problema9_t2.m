%%Juan Carlos Garfias Tovar, A01652138

%%Anexo dos posibles soluciones, la primera tiene mas elementos la
%%segunda(sin comentar)esta con if nada mas
%%continuep = true;
%%questions = ["�Colon descubri� Am�rica?","�La independencia de M�xico fue en el a�o 1810? ","�The Doors fue un grupo de rock Americano?"];
%%counter = 1;
%%while continuep == true & counter <= 3
%%    answer=input(questions(counter)+": ",'s');
%%    counter = counter+1;
%%    if answer == "no" 
%%        disp("Perdiste :(")
%%        continuep = false;
%%    end
%%    if counter ==4
%%        disp("Ganaste!!")
%%    end
%%end 

disp("Bienvenid@ al juego de preguntas, Ingresa si o no");
answer = input("�Colon descubri� Am�rica? > ",'s');
if answer == "si"
    answer = input("�La independencia de M�xico fue en el a�o 1810? >",'s');
    if answer == "si"
        answer = input("�The Doors fue un grupo de rock Americano? >",'s');
        if answer == "si"
            disp("Ganaste!!")
        else
            disp("Perdiste")
        end
    else
        disp("Perdiste")
    end
else
    disp("Perdiste")
end